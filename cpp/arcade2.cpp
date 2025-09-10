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
    void playerdetails(string Pname = "Player One");
    string userpassword;
    int gno; //future use
    string username;
    float userbalance;
    string gamelst[2];
    arc() {   
        gamelst[0] = "number guesser";  //function name num_gss
        gamelst[1] = "Black Jack";      //functon name blackjck
    }
    void gamelist();
    friend bool chck(arc s1);
    int game_selecter(int n);


    /* void menu();
    void cardset();
    void cardpicker();
    void userprof(string a,double amt);*/
    // methods that actually have working of games. 


    void num_gss();
    void blackjck();
};


/* void arc::userprof(string a,double amt)
{
    username=a;
    userbalance=amt;
}
*/


void arc::playerdetails(string Pname) {
    system("cls");
    cout << "current player is " << Pname << endl;
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
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> number(1, 10);
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
void arc::gamelist() {
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

int main() { 
    arc s1;
    char inp;
    string name;
    cout << "do you want to enter your name " << endl;
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
        return 0;
    }
else
 {
cout<<"program terminated";
return 0;}



}
    if (inp == 'y') {
        cout << "please enter your name";
        cin >> name;
        s1.playerdetails(name);
    }
    else {
        s1.playerdetails();
    }
    s1.gamelist();
    return 0;
}
