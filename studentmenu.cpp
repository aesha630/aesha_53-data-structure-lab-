#include<iostream>
using namespace std;
int main()
{

int n=0;
int choice;
int student;
float marks;
int search Rollno;
do
{
 cout<<"\n\n=======student mengment system=========";
cout<<"\n1.Add student";
cout<<"\n2.Display student";
cout<<"\n3.search student using Rollno";
cout<<"\n exit";
cout<<"\n Enter your choice:";
cin>>choice;
if(choice==1)
{
cout<<"Enter Rollno:";
cin>>Roll no[n];
cout<<"Rollnoadded!";
cout<<" Enter marks";
cin>>marks [n];
n++;
}
else if(choice==2)
{
cout<<"\n Roll no of students:\n";
for(int i=0;i<n;i++)
{
cout<<Roll no[i]<<endl;
}
}
else if(choice==3)
{
cout<<"Enter Roll no to search:";
cin>>Roll no;
bool found=false;
for(int i=0;i<n;i++)
{
if(student[i]=Roll no)
{
found true;
}
}
if(found)
{
cout<<"Roll no found:";
else if(choice==4)
{
cout<<"Thank you!";
}
}
while (choice!=4);
return 0;
}
