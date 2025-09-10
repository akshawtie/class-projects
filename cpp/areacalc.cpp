#include <iostream>
using namespace std;
class calc
{
    public:
    float result;
    void area2(float side);
    void area2(float side,float breadth);
    void area2(float radius,int i);
    void menu();

};
void calc::area2(float side)
{
 result=side*side;
 cout<<"area of square is"<<result;
}
void calc::area2(float length,float breadth)
{
    result=length*breadth;
    cout<<"area of rectangle is"<<result;
    cout<<"perimeter is"<<2*length*breadth;
}

void calc::area2(float radius,int i)
{
    result=radius*22/7*radius;
    cout<<"area of circle is"<<result;
}
void calc::menu(){
cout<<"1.Square"<<endl;
cout<<"2.Rectangle"<<endl;
cout<<"3.circle"<<endl;
cout<<"please eneter ur input"<<endl;
int a;
cin>>a;
switch (a)
{
    case 1:
    {
    cout<<"please enter side"<<endl;
    float side=0;
    cin>>side;
    area2(side);
    break;
    }

    case 2:
    {
    float length,breadth;
    cout<<"please enter length and breadth"<<endl;
    cin>>length>>breadth;
    area2(length,breadth);
    break;
}
    case 3:
    {
     float radius;
     
     cout<<"please enter radius"<<endl;
     cin>>radius;
     area2(radius,0);
    }
}


}
int main()
{
    calc c1;
    c1.menu();
    return 10;
}