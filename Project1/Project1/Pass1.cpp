/*
  THIS FILE CONTAINS THE CODE FOR THE FIRST PASS OF THE ASSEMBLER.
  PRODUCES INTERMEDIATE FILE.

  @AUTHOR: Himanshu Jariyal
  B.TECH, CSE 2ND YEAR
  IIT ROORKEE
*/
#include "Pass1.h"


 int block_num, line;
 hexa loc_ctr;
 string curr_block;
 bool error_flag = 0;
 ofstream error;

ifstream fin1;
ofstream fout1;


bool isWhiteSpace(char a)
{
    if(a==' ')  return true;
    if(a=='\t') return true;
    return false;
}

void extract(string a,string word[],int& count)
{
    int i;
    for(i=0;i<5;++i) word[i]="";
    count=0;
    i=0;
    while(isWhiteSpace(a[i])&&i<a.length()) {++i;continue;}
    if(i==a.length()||a[i]=='.')   return;
    for(;i<a.length();)
    {
        while(isWhiteSpace(a[i])&&i<a.length()) {++i;continue;}
        if(i==a.length()) break;
        for(;!isWhiteSpace(a[i])&&i<a.length();++i) word[count]+=a[i];
        ++count;
    }
}



void pass1()
{
    create();
    char ch;
    string s,word[5],inputfilename;
	cout << "파일 이름을 입력하시오(.txt만,확장자명 생략) :";
	cin >> inputfilename;
	inputfilename += ".txt";
    int count=0;
    fin1.open(inputfilename);
    fout1.open("intermediate.txt");
    error.open("error.txt");
    line=5;
    getline(fin1,s);
    extract(s,word,count);
    while(count==0)
    {
        fout1<<line<<endl;
        fout1<<"$";
        fout1<<s<<endl;
        fout1<<""<<endl;
        fout1<<""<<endl;
        line+=5;
        cout<<"s: "<<s<<endl;
    }
    loc_ctr="0";//opcode가 start가 아닐경우 locctr 0으로 initialize
    BLOCK["DEFAULT"].num=0;//block 초기화
    BLOCK["DEFAULT"].address=loc_ctr;
    BLOCK["DEFAULT"].length="0";
    BLOCK["DEFAULT"].exist='y';
    curr_block="DEFAULT";
    block_num=1;
    line=5;
    if(word[0]=="START")//0에서 start할 때
    {
        loc_ctr=word[1];
        fout1<<line<<endl;
        fout1<<""<<endl;
        fout1<<"START"<<endl;
        fout1<<loc_ctr<<endl;
        fout1<<loc_ctr<<endl;
        fout1<<""<<endl;
        cout<<"0 is start!"<<endl;
    }
    else if(word[1]=="START")//1에서 strat할 때
    {
        loc_ctr=word[2];
        fout1<<line<<endl;
        fout1<<word[0]<<endl;
        fout1<<"START"<<endl;
        fout1<<loc_ctr<<endl;
        fout1<<loc_ctr<<endl;
        fout1<<""<<endl;
        cout<<"1 is start!"<<endl;
    }
    else
        execute(word,count);

    while(true)
    {
        getline(fin1,s);
        extract(s,word,count);
        line+=5;
        cout<<"s: "<<s<<endl;
        fout1<<line<<endl;
        if(count==0)
        {
            cout<<"Comment detected!"<<endl;
            fout1<<"$"<<endl;
            fout1<<s<<endl;
            fout1<<""<<endl;
            fout1<<""<<endl;
            fout1<<""<<endl;
            continue;
        }
        if(word[0]=="END")//end일 때
        {
            BLOCK[curr_block].length=loc_ctr;//block의 길이=locctr
            fout1<<""<<endl;//intermediatefile에 출력
            fout1<<word[0]<<endl;
            fout1<<word[1]<<endl;
            fout1<<loc_ctr<<endl;
            fout1<<""<<endl;
            break;
        }
        execute(word,count);
       // cin>>ch;
     }
     hexa addr,len;
     string temp=find_block(0);
     addr=BLOCK[temp].address;
     len=BLOCK[temp].length;
     for(int i=1;i<block_num;++i)
     {
            temp=find_block(i);
            BLOCK[temp].address=toHex(toDec(addr)+toDec(len));//block adress=locctr
            addr=BLOCK[temp].address;
            len=BLOCK[temp].length;

     }
}

void execute(string word[],int count)
{
    cout<<"word[0]: "<<word[0]<<" pc: "<<loc_ctr<<endl;
    if(word[0]=="USE")
    {
        cout<<"USE detected!"<<endl;
        BLOCK[curr_block].length=loc_ctr;
        if(word[1]=="")
        {
            curr_block="DEFAULT";
            loc_ctr=BLOCK["DEFAULT"].length;//locctr에 defaul block의 길이로 초기화
        }
        else if(BLOCK[word[1]].exist=='y')
        {
            curr_block=word[1];
            loc_ctr=BLOCK[word[1]].length;
        }
        else//block[word[1]]이 없을 경우
        {
            BLOCK[word[1]].num=block_num;
            BLOCK[word[1]].exist='y';
            BLOCK[word[1]].length="0";
            curr_block=word[1];
            loc_ctr="0";
            ++block_num;//block을 하나 민다.
        }
        fout1<<""<<endl;
        fout1<<word[0]<<endl;
        fout1<<word[1]<<endl;
        fout1<<loc_ctr<<endl;
        fout1<<""<<endl;
        return;
    }
    if(word[0][0]=='+')//+로 시작할 경우 4형식
    {
        cout<<"Format 4"<<endl;
        fout1<<""<<endl;
        fout1<<word[0]<<endl;
        fout1<<word[1]<<endl;
        fout1<<loc_ctr<<endl;
        loc_ctr=toHex(toDec(loc_ctr)+4);
        fout1<<loc_ctr<<endl;
        return;
    }
    if(OPTAB[word[0]].exist=='y')
    {
        cout<<"0 is opcode!"<<endl;
        fout1<<""<<endl;
        fout1<<word[0]<<endl;
        fout1<<word[1]<<endl;
        fout1<<loc_ctr<<endl;
        loc_ctr=toHex(toDec(loc_ctr)+OPTAB[word[0]].format);
        fout1<<loc_ctr<<endl;
        return;
    }
    if(OPTAB[word[0]].exist=='n')
    {
        if(SYMTAB[word[0]].exist=='y')
        {
            error<<"Line "<<line<<": Duplicate Symbol"<<endl;
            error_flag=1;
        }
        else
        {
            SYMTAB[word[0]].address=loc_ctr;
            SYMTAB[word[0]].block=curr_block;
            SYMTAB[word[0]].exist='y';
            fout1<<word[0]<<endl;
            fout1<<word[1]<<endl;
            fout1<<word[2]<<endl;
            fout1<<loc_ctr<<endl;
            if(word[1][0]=='+')
                loc_ctr=toHex(toDec(loc_ctr)+4);
            else if(OPTAB[word[1]].exist=='y')
                loc_ctr=toHex(toDec(loc_ctr)+OPTAB[word[1]].format);
            else if(word[1]=="WORD")      loc_ctr=toHex(toDec(loc_ctr)+3);
            else if(word[1]=="RESW")      loc_ctr=toHex(toDec(loc_ctr)+(atoi(word[2].c_str())*3));
            else if(word[1]=="RESB")      loc_ctr=toHex(toDec(loc_ctr)+atoi(word[2].c_str()));
            else if(word[1]=="BYTE")
            {
                 int len=word[1].length()-3;
                 if(word[1][0]=='X') len/=2;
                 loc_ctr=toHex(toDec(loc_ctr)+len);
            }
            else
            {
                error<<"Line "<<line<<": Opcode not found"<<endl;
                error_flag=1;
            }
            fout1<<loc_ctr<<endl;
        }
    }
}


