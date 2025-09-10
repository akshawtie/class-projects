#include <iostream>
#include <string>

using namespace std;
class student
{
int rollnumber;
public:
void getnumber(int x);
void putnumber();
};
void student::getnumber(int x)
{
rollnumber=x;
}
void student::putnumber()
{
cout<<"rollnumber: "<<rollnumber;
}


//new class
class test:public student
{
protected:
float sub1;
float sub2;
float sub3;
float sub4;
float sub5;
float sport1;
public:
void getmarks(float s1,float s2,float s3,float s4,float s5,float sport)
{
sub1=s1;
sub2=s2;
sub3=s3;
sub4=s4;
sub5=s5;
sport1=sport;

}
void putmarks()
{
cout<<endl<<sub1;
cout<<endl<<sub2;
cout<<endl<<sub3;
cout<<endl<<sub4;
cout<<endl<<sub5;
float sum=sub1+sub2+sub3+sub4+sub5;
cout<<sum<<"  sport score is:"<<sport1;
}};

class sport
{
public:
float getsport(){
 cout<<"did u score state level or above? y/n";

 char c;
 cin>>c;
 if(c=='y')
 {
 cout<<"please enter your marks";
 float b;
 cin>>b;
 return b;
}
else
return 0;
}
};


class result:public test,public sport
{
float total;
public:
void display()
{
total=sub1+sub2;
putnumber();
putmarks();
cout<<"total="<<total<<endl;
}
};

//main
int main()
{
result student1;
student1.getnumber(111);

float sport=student1.getsport();
student1.getmarks(99,99,11,78,100,sport);
student1.display();
return 0;
}