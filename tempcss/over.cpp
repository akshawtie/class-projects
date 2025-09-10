#include <iostream>
using namespace std;
class space
{
    int x,y,z;
    public:
    space()
    {
        x=10;
        y=20;
        z=-60;
    }
    space(int x,int y,int z)
    {
       this->x=1;
        this->y=50;
        z=-78;
    }
    void operator-()
    {
        x=x+100;
        y=-y;
        z=-z;
    }
    void display()
    {
        cout<<x<<y<<z;
    }
};
int main()
{
    
    space x;
    -x;
    int a=20-10;
    x.display();
    return 10;
}