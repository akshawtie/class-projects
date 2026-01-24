#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    cout<<setw(10)<<setprecision(2)<<1.2345
    <<setw(10)<<setprecision(4)<<sqrt(2)
    <<setw()
} 
int main()
{

    cout.setf(ios::showpoint);
    cout<<setw(5)<<"n"<<setw(15)<<"Inverse of n"<<setw(15)<<"Sum of terms\n\n";
    double term,sum=0;
    for(int i=1;i<=10;i++)
    {
        term=1.0/float(i);
        sum=sum+term;
        cout<<setw(5)<<i
        <<setw(14)<<setprecision(4)
        <<setiosflags(ios::scientific)<<term<<setw(13)<<resetiosflags(ios::scientific)
        <<sum<<endl;
    }
}

/*
ostream & currency(ostream & output)
{
    output<<"Rs.";
    return output;
}
ostream & form(ostream & output)
{
    output.setf(ios::showpos);
    output.setf(ios::showpoint);
    output.fill('*');
    output.precision(2);
    output<<setiosflags(ios::fixed);
)

};*/