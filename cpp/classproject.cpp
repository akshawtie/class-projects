#include <iostream>
#include <string>
using namespace std;
class user
{
    public:
    int roll;
    int age;
    int bcount;
    string name;
    void inputuser();
    void displayuser();


};
void user::inputuser()
{
    cout<<"=====Welcome=======";
    cout<<"Enter Username"<<endl;
    getline(cin,name);
    cout<<endl;
    cout<<"Enter Roll Number"<<endl;
    cin>>roll;
        cout<<"Enter Age";
        cin>>age;

    
}
void user::displayuser()
{
    cout<<"Name:"<<name;
    cout<<"Age:"<<age;
    cout<<"Roll"<<roll;
}
class library
{
    public:
    int id;
    string bname;
    int author;
    void enterbooks(library arr[],int n)
    {
        for(int i=1;i<=n;i++)
        {
            cout<<"enter bookname"<<endl;
            cin>>arr[i].bname;
        }
    }
    void printbooks(library arr[],int n)
    {
        for(int i=1;i<=n;i++)
        {
            cout<<"book no "<<i<<arr[i].bname;
        }
    }
};

int main()
{
 
 int n;
 cout<<"enter amounts of book"<<endl;
 cin>>n;
 library lib;
  library book[n];
  lib.enterbooks(book,n);
  lib.printbooks(book,n);
  return 0;
}