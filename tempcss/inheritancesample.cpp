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
public:
void getmarks(float s1,float s2,float s3,float s4,float s5)
{
sub1=s1;
sub2=s2;
sub3=s3;
sub4=s4;
sub5=s5;
}
void putmarks()
{
cout<<endl<<sub1;
cout<<endl<<sub2;
cout<<endl<<sub3;
cout<<endl<<sub4;
cout<<endl<<sub5;
}};

//new class
class result:public test
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
student1.getmarks(99,99,11,78,100);
student1.display();
return 0;
}