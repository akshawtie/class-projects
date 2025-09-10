#include <iostream>
#include <limits> //currently no use, will be implemented in blackjack for simulating bot behaviour 
#include <random> // random is used in method num_gss.
#include <string>
#include <cstdlib>
using namespace std;

class arc 
{
private:
    string pass = "helsinki@1";
public:
    static bool flag;
    void currentplayer(arc s1);
    string userpassword;
    int gno; //future use
    string username;
    double userbalance;
    string gamelst[2];

    //constructors 
    arc() {   
        gamelst[0] = "number guesser";  //function name num_gss
        gamelst[1] = "Black Jack";      //functon name blackjck
        username="PlayerOne";
        userbalance=100;
    }
    arc(string s1,double s2)
    {
         gamelst[0] = "number guesser";  //function name num_gss
        gamelst[1] = "Black Jack";      //functon name blackjck
        username=s1;
        userbalance=s2;
    }

    void gamelist();
    friend bool chck(arc s1);
    int game_selecter(int n);
    //static bool valid(arc s1);


    static void menu();
    void menu(bool& flag);
    void menu(const bool& flag);
    void useraccount();
     static bool takeinput();



    //void cardset();
    //void cardpicker();
    // methods that actually have working of games. 
    void num_gss();
    void blackjck();
    
};
 void arc::menu(){
    system("cls");
    cout<<endl<<"       Welcome To Akshat's Arcade"<<endl;
    cout<<"______________________________________________________"<<endl;
     
    cout<<"Please Sign In before continuing";
    arc::flag=takeinput();
 }

void arc::menu(const bool& flag) {
    cout << "Available Games:\n";
    int n = 0;
    for (int i = 0; i < 2; i++) {
        cout << i + 1 << ". " << gamelst[i] << endl;
    }
    cout << "enter game number to play" << endl;
    cin.clear();
    cin >> n;
    if (n > 2 || n < 1)
        cout << "enter valid input";
    if (n < 3 && n > 0)
        game_selecter(n);
}
void arc::menu(bool& flag){
    cout<<endl<<"third menu was called"<<endl<<"thanks for playing";
}
bool arc::takeinput(){char inp;
     cout<< "do you want to enter your name "<<endl;
    cout << " y/n" << endl;
    cin >> inp;
    if(inp=='y')
    {
        return true;
    }
        else{
        return false;}


}
/* bool arc::valid(arc s1)
 {
    
    string name;
    char inp;
     cout<< "do you want to enter your name "<<endl;
    cout << " y/n" << endl;
    cin >> inp;
    if(inp=='d')
    {
    cout<<"please enter secret code"<<endl;
    cin>>s1.userpassword;
    if(chck(s1)==true)
    {
        system("cls");
     cout<<"youre in developer mode"<<endl;
     cout<<"____________________"<<endl<<endl;
     cout<<"1.Ban Player"<<endl;
     cout<<"2.Show Player History"<<endl;
     cout<<"3.whitelist Player"<<endl<<endl<<endl;
        return false;
    }
else
 {
cout<<"program terminated";
return false;}



}
    if (inp == 'y') {
        takeinput();
    }
    else {
        s1.currentplayer();
        return false;
    }
 }*/
void arc::currentplayer(arc s1) {
    system("cls");
    cout << "current player is " << s1.username<< endl;
    cout<<"balance:"<<s1.userbalance<<endl;
}
void arc::useraccount(){
    {
        cin>>username;
        cin>>userbalance;
    }

}
bool chck(arc s1)
 {
    arc d1;
     if (d1.pass == s1.userpassword) {
        return true;
    }
    else 
        return false;
}
void arc::blackjck() {
    cout << "we are playing blackjack" << endl;
    cout << "sorry but black jack is not available at this moment";
}


void arc::num_gss() {
    //....code for number guesser....
    cout << "we are playing number guesser" << endl;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> number(1, 10);
    int secretnum = number(gen);
    int bet_amt = 0;
    int inpnumber = 0;
    cout << "please enter your bet amount " << endl;
    cin >> bet_amt;
    cout << endl << "please enter your guess number between 1 to 10" << endl;
    cin >> inpnumber;
    if (inpnumber > 10 || inpnumber < 1)
        cout << "invalid input" << endl << "your money is returned";
    else {
        if (inpnumber == secretnum)
            cout << "congrats u won: " << bet_amt*4;
        else
            cout << "sorry u lost" << endl << "the lottery number was " << secretnum;
    }
}
int arc::game_selecter(int n) {
    if (n == 1)
        num_gss();
    if (n == 2)
        blackjck();
    return 0;
}

bool arc::flag;
int main() { 

    bool x=true;
    string a1;
    double a2;
    arc::menu();
    cout<<arc::flag;
    if(arc::flag==true)
    {
        cout << "please enter your name";
        cin >> a1;
        cout << "please enter your balance";
        cin >> a2;
        arc s1(a1,a2);
        s1.currentplayer(s1);
        s1.menu(true);
    s1.menu(x);
    return 0;
    }
    else
    {
        arc s1;
        s1.currentplayer(s1);
        s1.menu(true);
    s1.menu(x);
    return 0;
    }
}

