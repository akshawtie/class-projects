#include <iostream>
#include <string>
#include <random>
#include <cstdlib> 
using namespace std;

class markc
{
    public:
     int regNo;
     string Name;
     int marks[5];

    void readdata();
    void display();
    float average();
    bool grace();
    
    markc() {
        regNo=0;
        Name="Student";
        marks[0]=0;
        marks[1]=0;
        marks[2]=0;
        marks[3]=0;
        marks[4]=0;
    }

};

float markc::average()
{
    float avg=0;
 for(int i=0;i<5;i++)
 {
    avg=avg+marks[i];
 }
 avg=avg/5;
 return avg;   
}

void markc :: readdata(){
    cout<<"please enter your Name"<<endl;
    cin>>Name;
cout<<"please enter your Registration Number"<<endl;
    cin>>regNo;
for(int i=0;i<5;i++)
{
    cout<<"please enter marks for subject:"<<i+1<<endl;
    cin>>marks[i];
}
}
void markc :: display(){
    system("cls");
    cout<<"Name:"<<Name<<endl;
    cout<<"Registration Number"<<regNo<<endl;
    float aver=average();
    bool flag=grace();
    if(flag==true)
    {
    aver=35;}

    cout<<"Percentage Scored: "<<aver<<endl;
    if(aver>=35)
    cout<<"status:"<<"pass";
    else
    cout<<"status"<<"fail";
    cout<<endl;
    if(flag==true)
    cout<<"grace status:"<<"awarded";
    else
    cout<<"grace status: "<<"not awarded";
    
    

}
bool markc::grace()
{
    float ave=average();
    if(ave<35&&ave>31)
    return true;
    else 
    return false;
}

int main(){
    markc s1;
    s1.readdata();
    s1.grace();
    s1.average();
    s1.display();
}