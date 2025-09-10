#include <iostream>
using namespace std;
class student
{
private:
string name;
void starttakinginput()
{
cout<<"please enter the following values\n";
}
void endtakinginput()
{
    cout<<"thank u";

}
public:
void takeInput()
{
    starttakinginput();
    string s;
    cout<<"enter name-";
    cin>>name;
    endtakinginput();

}
void printdetails()
{
    cout<<"name-"<<name<<endl;
}};
int main()
{
    student s1;
    s1.takeInput();
    s1.printdetails();
return 0;
}