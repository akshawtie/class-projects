#include <iostream>
using namespace std;
class M
{
public:
void display()
{
cout<<"class M"<<endl;
}};



class N
{
public:
void display()
{
cout<<"class N"<<endl;
}};


class MN:public M,public N
{
    public:
void display()
{
M::display();
}
};


int main()
{
MN X;
X.display();
return 0;
};
