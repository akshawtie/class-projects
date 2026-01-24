#include <iostream>
using namespace std;

class sparse{

    public:
     int rows, cols;
    int **matrix;
     void input();
     void check();

};
 void sparse::input()
 {
    cout<<"enter the amount of columns"<<endl;
    cin>>cols;
    cout<<"enter the amount of rows"<<endl; 
    cin>>rows;
    matrix=new int*[rows];
    for(int i=0;i<rows;i++)
    {
    matrix[i]=new int[cols];
    }
    cout<<"Matrix Created of"<<rows<<"*"<<cols<<endl;
    cout<<endl<<endl<<"=========Enter Values=========";

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
      cout<<endl<<"Rows "<<i+1<<" Column "<<j+1<<endl;
      cin>>matrix[i][j];
}}}
void sparse::check(){
int count=0;
int total=rows*cols;
for(int i=0;i<rows;i++)
{
    cout<<endl<<endl;
    for(int j=0;j<cols;j++)
    {
        cout<<matrix[i][j]<<" ";
        if(matrix[i][j]==0)
        {
            count++;
        }
    }
}
if(count>total/2)
cout<<endl<<"This is a Sparse Matrix";
else
cout<<endl<<"this is not a sparse matric";
}
int main()
{
    sparse s1;
    s1.input();
    s1.check();
    return 0;
}