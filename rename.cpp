#include <iostream>
using namespace std;

class INT
{
int x;
public:
INT()
{
x=0;
}

void operator++(int x)
{
x+1;
}
void display()
{
cout<<x;}
};

int main()
{
INT x;
x.display();
x++;
x.display();
return 0;
}