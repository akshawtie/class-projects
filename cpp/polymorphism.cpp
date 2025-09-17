#include <iostream>
using namespace std;
class base
{
public :
void display()
{
cout<<"\n Display base";
}
virtual void showoff()
{
cout<<"\n showoffy base";
}
};
class derived:public base
{
public:
void display()
{
cout<<"\n display derived";
}
virtual void showoff()
{
cout<<"\n showoff derived";
}};
int main()
{
base B;
derived D;
base *bptr;
bptr=&B;
bptr->display();
bptr->showoff();
bptr=&D;
bptr->display();
bptr->showoff();
}