#include <iostream>
using namespace std;

class b
{
int a;
public:
int b;
void get_ab();
int get_a();
void show_a();
};

class d : public b
{
int c;
public: 
void mul();
void display();
};

void b::get_ab()
{
a=10;
b=20;
cin>>a>>b;

}
int b::get_a()
{
return a;
}
void b::show_a()
{
cout<<"a="<<a<<endl;
}

void d::mul()
{
c=get_a()*b;
}
void d::display()
{
cout<<"a="<<get_a()<<"/n";
cout<<"b="<<b<<endl;
cout<<"c="<<c<<"/n";
}


int main()
{
d obj;
obj.get_ab();
obj.mul();
obj.display();
}