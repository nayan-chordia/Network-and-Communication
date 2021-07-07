#include <bits/stdc++.h>
using namespace std;

string decToBinary(int n) 
{ 
    string s;
    for (int i = 15; i >= 0; i--) 
    { 
        int k = n >> i; 
        if (k & 1) 
            s.push_back('1'); 
        else
            s.push_back('0');
        s.push_back(' '); 
    }
    return(s); 
}


int main()
{
    string name;
    char ch;
    int i,rsum;
    int sum=0;
    vector <string> v;
    cin>>name;
    cout<<"\n";
    cout<<"------------------------------------------"<<"\n\n";
    for(int i=0;i<name.size();i++)
    {
        cout<<name[i]<<"        - "<<decToBinary(int(name[i]))<<"\n\n";  
    }
    for(int i=0;i<name.size();i++)
    {
        sum=sum+int(name[i]);  
    }
    int checksum = ~sum;
    int cs=checksum;
    cout<<"----------------------------"<<"\n";
    cout<<"Sum      - "<<decToBinary(sum)<<"\n";
    cout<<"----------------------------"<<"\n";
    cout<<"Checksum - "<<decToBinary(checksum)<<"\n\n\n";
    cout<<"-------------------------------------------------------------"<<"\n\n\n";
    cout<<"Reciever's Side :- "<<"\n\n";
    cout<<"Do you want to change a bit to verify checksum ? (y/n) ";
    cin>>ch;
    cout<<"\n\n";
    if(tolower(ch)=='y')
    {
        cout<<"Which position of bit do you want to change ? ";
        cin>>i;
        cout<<"\n\n";
        if(int(checksum&(1<<(i-1)))!=0)
        {
            checksum=checksum&(~(1<<(i-1)));
        }
        else
        {
            checksum=checksum|(1<<(i-1));
        }
        cout<<"The checksum without changed bit : "<<decToBinary(cs)<<"\n\n";
        cout<<"The checksum with changed bit :    "<<decToBinary(checksum)<<"\n\n";
        rsum=sum+checksum;
    }
    else
    {
        rsum=sum+checksum;
    }
    for(int i=0;i<name.size();i++)
    {
        cout<<name[i]<<"             - "<<decToBinary(int(name[i]))<<"\n\n";  
    }
    cout<<"Checksum      - "<<decToBinary(checksum)<<"\n\n";
    cout<<"-----------------------------------"<<"\n";
    cout<<"Addition      - "<<decToBinary(rsum)<<"\n";
    cout<<"-----------------------------------"<<"\n";
    cout<<"1s compliment - "<<decToBinary(~rsum)<<"\n\n";
    if(~rsum==0)
    {
        cout<<"Since at the reciever's end we get zero the code is accepted"<<"\n\n";
    }
    else
    {
        cout<<"Since at the reciever's end we are not getting zero hence the code is rejected"<<"\n\n";
    }
}