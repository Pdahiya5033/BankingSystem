#include<fstream>
#include<iostream>
#include<iomanip>
#include<string.h>
#include<vector>
using namespace std;
struct user
{
    char name[20];
    long unsigned int mob_no,aadhar,balance=0,accno;
};
int new_acc()
{
    char ch;
    const char *ch1;
    int a=0,b,e;
    user unew_acc[50];
    srand(time(0));
    e=rand();
    cout << "enter your details" << endl;
    cout << "enter your name : ";
    cin >> unew_acc[a].name;
    cout << "enter your mobile number : ";
    cin >> unew_acc[a].mob_no;
    cout << "enter your aadhar number : ";
    cin >> unew_acc[a].aadhar;
    unew_acc[a].accno=e;
    a=1;
    cout << a;
    vector<string> detail;
    string line,word;
    ifstream fin1;
    fin1.open("banking_system.txt");
    while(fin1)
    {
        detail.clear();
        getline(fin1,line);
        stringstream s(line);
        while(getline(s,word,' '))
        {
            detail.push_back(word);
            ch1=detail[0].c_str();
            strcpy(unew_acc[a].name,ch1);
        }
        unew_acc[a].mob_no=stoi(detail[1]);
        unew_acc[a].aadhar=stoi(detail[2]);
        unew_acc[a].accno=stoi(detail[3]);
        a++;
        
        
    }
    
    /*fin1.close();
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<a;j++)
            {
                b=strcmp(unew_acc[i].name,unew_acc[j].name);
                if(b<0)
                {
                    strcpy(unew_acc[a-1].name,unew_acc[i].name);
                    strcpy(unew_acc[i].name,unew_acc[j].name);
                    strcpy(unew_acc[j].name,unew_acc[a-1].name);
                    unew_acc[a-1].mob_no=unew_acc[i].mob_no;
                    unew_acc[i].mob_no=unew_acc[j].mob_no;
                    unew_acc[j].mob_no=unew_acc[a-1].mob_no;
                    unew_acc[a-1].aadhar=unew_acc[i].aadhar;
                    unew_acc[i].aadhar=unew_acc[j].aadhar;
                    unew_acc[j].aadhar=unew_acc[a-1].aadhar;
                    unew_acc[a-1].accno=unew_acc[i].accno;
                    unew_acc[i].accno=unew_acc[j].accno;
                    unew_acc[j].accno=unew_acc[a-1].accno;
                    unew_acc[a-1].balance=unew_acc[i].balance;
                    unew_acc[i].balance=unew_acc[j].balance;
                    unew_acc[j].balance=unew_acc[a-1].balance;
                }
            }
        }
        ofstream fout1;
        fout1.open("banking_system.txt");
        if(a==1)
        {
            fout1 << unew_acc[0].name << " " << unew_acc[0].mob_no << " " << unew_acc[0].aadhar << " " << unew_acc[0].accno << " " << unew_acc[0].balance <<  endl;
        }
        else
        {
        for(int i=0;i<a-1;i++)
        {
            fout1 << unew_acc[i].name << " " << unew_acc[i].mob_no << " " << unew_acc[i].aadhar << " " << unew_acc[i].accno << " " << unew_acc[i].balance <<  endl;
        }
        }
        fout1.close();*/
        return 0;
}
void withdraw()
{
    user with_acc[50];
    int with_amo=0,a=0,accno,te=0,i;
    char with_choice,wr_acc;
    const char *with_name;
    cout << "enter your account number : ";
    cin >> accno;
    vector<string> with_detail;
    string line,word;
    ifstream fin_with;
    fin_with.open("banking_system.txt");
    while(fin_with)
    {
        with_detail.clear();
        getline(fin_with,line);
        stringstream s(line);
        while(getline(s,word,' '))
        {
            with_detail.push_back(word);
            with_name=with_detail[0].c_str();
            strcpy(with_acc[a].name,with_name);
        }
         with_acc[a].aadhar=stoi(with_detail[1]);
        with_acc[a].mob_no=stoi(with_detail[2]);
        with_acc[a].accno=stoi(with_detail[3]);
        with_acc[a].balance=stoi(with_detail[4]);
        a++;
    }
    for(i=0;i<a;i++)
    {
        if(with_acc[i].accno==accno)
        {
            cout << "enter amount you would like to withdraw : ";
            cin >> with_amo;
            if(with_acc[i].balance>=with_amo)
            {
                cout << "Rs. " << with_amo << "has been withdrawn from your account" << endl;
                with_acc[i].balance = with_acc[i].balance-with_amo;
                cout << "your current balance is " << with_acc[i].balance  << endl;
                break;
            }
            else
            {
                cout << "sorry, you do not have sufficient amount" << endl;
                cout << "would like to try again? (y/n)" << endl;
                cin >> with_choice;
                if(with_choice=='y'||with_choice=='Y')
                continue;
                else
                break;
            }
            
        }
    }
        if(i==a)
            {
                cout << "sorry, you have entered wrong account number" << endl;
                cout << "would like to try again? (y/n)" << endl;
                cin >> wr_acc;
                if(wr_acc=='y'||wr_acc=='Y')
                {
                    withdraw();
                    
                }
            }
            
                ofstream fout_with;
                fout_with.open("banking_system.txt");
                for(int j=0;j<a-1;j++)
                {
                    fout_with <<  with_acc[j].name << " " << with_acc[j].aadhar << " " << with_acc[j].mob_no << " " << with_acc[j].accno << " " << with_acc[j].balance << endl;
                }       
    }
void deposit()
{
    user depo_acc[50];
    int depo_amo=0,e=0,accno,te=0,i;
    char depo_choice,wr_acc;
    const char *depo_name;
    cout << "enter your account number : ";
    cin >> accno;
    vector<string> depo_detail;
    string line,word;
    ifstream fin_depo;
    fin_depo.open("banking_system.txt");
    while(fin_depo)
    {
        depo_detail.clear();
        getline(fin_depo,line);
        stringstream s(line);
        while(getline(s,word,' '))
        {
            depo_detail.push_back(word);
            depo_name=depo_detail[0].c_str();
            strcpy(depo_acc[e].name,depo_name);
        }
         depo_acc[e].aadhar=stoi(depo_detail[1]);
        depo_acc[e].mob_no=stoi(depo_detail[2]);
        depo_acc[e].accno=stoi(depo_detail[3]);
        depo_acc[e].balance=stoi(depo_detail[4]);
        e++;
    }
    for(i=0;i<e;i++)
    {
        if(depo_acc[i].accno==accno)
        {
            cout << "enter amount you would like to credit : ";
            cin >> depo_amo;
            depo_acc[i].balance=depo_acc[i].balance+depo_amo;
            break;
        }
    }
        if(i==e)
            {
                cout << "sorry, you have entered wrong account number" << endl;
                cout << "would like to try again? (y/n)" << endl;
                cin >> wr_acc;
                if(wr_acc=='y'||wr_acc=='Y')
                {
                    deposit();
                    
                }
            }
            
                ofstream fout_depo;
                fout_depo.open("banking_system.txt");
                for(int j=0;j<e-1;j++)
                {
                    fout_depo <<  depo_acc[j].name << " " << depo_acc[j].aadhar << " " << depo_acc[j].mob_no << " " << depo_acc[j].accno << " " << depo_acc[j].balance << endl;
                }   
}
void bal_inquiry()
{
    int inq_accno,a=0,i;
    user bal_inq[50];
    char inq_cho;
    cout << "enter your account number : ";
    cin >> inq_accno;
    vector<string> inq;
    string line,word;
    ifstream fin_inq;
    fin_inq.open("banking_system.txt");
    while(fin_inq)
    {
        inq.clear();
        getline(fin_inq,line);
        stringstream s(line);
        while(getline(s,word,' '))
        {
            inq.push_back(word);
        }
        bal_inq[a].accno=stoi(inq[3]);
        bal_inq[a].balance=stoi(inq[4]);
        a++;
    }
    for(i=0;i<a;i++)
    {
        if(bal_inq[i].accno==inq_accno)
        {
            cout << "your current balance is " << bal_inq[i].balance;
            break;
        }

    }
    if(i==a)
    {
        cout << "sorry, you have entered wrong account number" << endl;
        cout << "would like to try again? (y/n)" << endl;
        cin >> inq_cho;
        if(inq_cho=='y'||inq_cho=='Y')
        {
            bal_inquiry();
                    
        }
    }
    
}
void cus_list()
{
    int i=0;
    char ch,cus_name[50][20];
    const char *temp_data;
    cout << "here is the list of our customers" << endl;
    ifstream fin_l;
    fin_l.open("banking_system.txt");
    vector<string> cus_data;
    string line,word;
    while(fin_l)
    {
        cus_data.clear();
        getline(fin_l,line);
        stringstream s(line);
        while(getline(s,word,' '))
        {
            cus_data.push_back(word);
            temp_data=cus_data[0].c_str();
            strcpy(cus_name[i],temp_data);
        }
        cout << cus_name[i] << endl;
         i++;
    }
}
void close_acc()
{
    int b=0,cl_num,flag=0;
    const char *ch_na;
    char choice;
    user cl_acc[50];
    vector<string> cl_da;
    string line,word;
    ifstream fin_cl;
    fin_cl.open("banking_system.txt");
    while(fin_cl)
    {
        cl_da.clear();
        getline(fin_cl,line);
        stringstream s(line);
        while(getline(s,word,' '))
        {
            cl_da.push_back(word);
            ch_na=cl_da[0].c_str();
            strcpy(cl_acc[b].name,ch_na);
        }
        cl_acc[b].aadhar=stoi(cl_da[1]);
        cl_acc[b].mob_no=stoi(cl_da[2]);
        cl_acc[b].accno=stoi(cl_da[3]);
        cl_acc[b].balance=stoi(cl_da[4]);
        b++;
    }
    cout << "enter your account number : ";
    cin >> cl_num;
    ofstream fout_cl;
    fout_cl.open("banking_system.txt");
    for(int i=0;i<b-1;i++)
    {
        if(cl_num==cl_acc[i].accno)
        {
            flag=1;
            continue;
        }
        else
        {
            fout_cl << cl_acc[i].name << " " << cl_acc[i].aadhar << " " << cl_acc[i].mob_no << " " << cl_acc[i].accno << " " << cl_acc[i].balance << endl;
        }
        
    }
    if(flag==0)
    {
        cout << "you have entered wrong account number" << endl;
        cout << "would you like to try again (y/n) : ";
        cin >> choice;
        if(choice=='y'||choice=='Y')
        close_acc();
    }
    if(flag==1)
    cout << "your account has been removed successfully" << endl;
    
}
int main()
{
    int start_choice;
    cout << "WELCOME TO REGIONAL BANK OF INDIA" << endl;
    cout << "What you would like to do?\n" << "Here are some choices:" << endl;
    cout << "1. Open New Account" << endl;
    cout << "2. Deposit amount from your account." << endl;
    cout << "3. Withdraw amount from your account." << endl;
    cout << "4. Balance Inquiry" << endl;
    cout << "5. View all customers list" << endl;
    cout << "6. Close an account" << endl;
    cout << "Enter your choice as per serial number of choice : ";
    cin >> start_choice;
    if(start_choice==1)
    {
        new_acc();
    }
    if(start_choice==2)
    {
        deposit();
    }
    if(start_choice==3)
    {
        withdraw();
    }
    if(start_choice==4)
    {
        bal_inquiry();
    }
    if(start_choice==5)
    {
        cus_list();
    }
    if(start_choice==6)
    {
        close_acc();
    }
    return 0;
}