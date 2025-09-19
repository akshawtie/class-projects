#include <iostream>
#include <string>
#include <iomanip>
//name and code are left justified. price is right justified with precision of two digits. trailing zeros are shown above
using namespace std;
class lst{
    public:
    string name;
    int code;
    float price;

    void input()
    {
    
        cout<<"Enter Name"<<endl;
        cin>>name;
        cout<<"Enter Code"<<endl;
        cin>>code;
        cout<<"Enter Price"<<endl;
        cin>>price;
    }
    void print() {
    cout.setf(ios::left, ios::adjustfield); // left-align
    cout.width(20);
    cout << name;

    cout.setf(ios::left, ios::adjustfield); // left-align again
    cout.width(10);
    cout << code;

    cout.setf(ios::right, ios::adjustfield); // right-align
    cout.width(10);
    cout << fixed << setprecision(2) << price << endl;
}

};

    int main()
    {
    int j;
    cout<<"Enter the number of enteries"<<endl;
    cin>>j;

    lst list[j];
    for(int i=0;i<j;i++)
    {
        list[i].input();
    }
system("cls");
cout.setf(ios::left); 
    cout.width(20);
    cout << "Name";

    cout.width(10);
    cout << "Code";

    cout.setf(ios::right); 
    cout.width(10);
    cout << "Price" << endl;

    cout << string(40, '-') << endl;
     for(int i=0;i<j;i++)
    {
        list[i].print();
    }

}
