#include <iostream>
using namespace std;

class item
{
int code;
float price;
public:
void getdata(int code,float price)
{
this->code=code;
this->price=price;
}
void display()
{
cout<<code<<endl<<price<<endl;
}};

int main()
{
item X;
X.getdata(1,100);
X.display();

item *ptr;
ptr=&X;
ptr->getdata(1,100);
ptr->display();
cout<<endl;
(*ptr).getdata(1,100);
(*ptr).display();
}