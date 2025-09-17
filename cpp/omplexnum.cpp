#include <iostream>
using namespace std;
class vector{

    public:
    int a[6];
    void input();
    void add();
    void print(vector ab);
    vector(){
        int a[6]={1,2,3,4,5,6};
  
    }
};
void vector::print(vector ab)
{
for(int i=0;i<6;i++)
{
    cout<<a[i];
}
}

int main();
