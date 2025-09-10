#include <iostream>
using namespace std;


class Alpha
{
int x;
public :
Alpha(int x)
{
this->x=x;
}
void display(void){
cout<<"x="<<x<<endl;
}};




class beta
{
float y;
public:
beta(float a)
{
y=a;}
void showy(void)
{
cout<<"y="<<y<<endl;
}
};



class gamma:public beta,public Alpha
{
int m,n;
public:
gamma(int a,float b,int c,int d):beta(b),Alpha(a)
{m=c;
n=d;}
void showz(void)
{
cout<<"m="<<m<<"n="<<n<<endl;
}
};


int main()
{
    
gamma g(5,10.5,20,30);
g.display();
g.showy();
g.showz();
}
