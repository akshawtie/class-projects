#include <iostream>
using namespace std;
class time12
{
int hours;
int minutes;

public:
time12()
{
hours=12;
minutes=36;
}
void display()
{
cout<<hours<<":"<<minutes;
}
};

int main()
{
time12 t1;
time12 t2;
t1.display();

}