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
    int fn=0;
    void currentplayer(arc s1);
    string userpassword;
    int gno; //future use
    string username;
    double userbalance;
    string gamelst[2];

    //constructors 
    arc() {   
        gamelst[0] = "Number guesser";  //function name num_gss
        gamelst[1] = "Black Jack";      //functon name blackjck
        username="PlayerOne";
        userbalance=100;
    }
    arc(string s1,double s2)
    {
         gamelst[0] = "Number guesser";  //function name num_gss
        gamelst[1] = "Black Jack";      //functon name blackjck
        username=s1;
        userbalance=s2;
    }

    void gamelist();
    void functrepeat();
    void operator-();
    friend bool chck(arc s1);
    int game_selecter(int n);
    
    //static bool valid(arc s1);


    static void tapl();
    void tapl2();
    void tapl3();
    void useraccount();
     static bool takeinput();



    //void cardset();
    //void cardpicker();
    // methods that actually have working of games. 
    void num_gss();
    void blackjck();
    
};
void arc:: functrepeat()
{
 if(fn==1)
 {
    num_gss();
 }
 if(fn==2)
 {
    tapl3();
}
}
 void arc::tapl()
 {
    system("cls");
    cout<<endl<<"       Welcome To Akshat's Arcade"<<endl;
    cout<<"______________________________________________________"<<endl;
     
    cout<<"Please Sign In before continuing";
    arc::flag=takeinput();
 }

void arc::tapl2() {
    cout << "Available Games:\n";
    int n = 0;
    for (int i = 0; i < 2; i++) {
        cout << i + 1 << ". " << gamelst[i] << endl;
    }
    cout << "Enter game number to play" << endl;
    cin.clear();
    cin >> n;
    if (n > 2 || n < 1)
        cout << "Enter valid input";
    if (n < 3 && n > 0)
        game_selecter(n);
}
void arc::tapl3(){
    fn=2;
    cout<<endl<<"Thanks for Playing"<<endl<<"Avaialble Balance:"<<userbalance<<endl<<endl;
    cout<<endl<<"Do you want to Play again y/n"<<endl;
    char c;
    cin>>c;
    if(c!='y'&&c!='Y')
    {
        functrepeat();
    }
    if(c=='y'||c=='Y'){
    if(userbalance<50)
    {
       -(*this); 
       num_gss();
    }
}
    if(c=='n'||c=='N'){
        return;
    }
}
void arc::operator-()
{
    int w;
    cout<<"enter the amount to add to wallet ";
    cin>>w;
    userbalance+=w;
    cout<<endl<<"available balance"<<userbalance<<endl;

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
    fn=1;
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
        functrepeat();
    else {
        if (inpnumber == secretnum){

        
            cout << "congrats u won: " << bet_amt*4;
            userbalance=userbalance+(bet_amt*4);
        }
        else{
            cout << "sorry u lost" << endl << "the lottery number was " << secretnum;
            userbalance=userbalance-bet_amt;
    }}
}
int arc::game_selecter(int n) {
    if (n == 1)
        num_gss();
    if (n == 2)
        blackjck();
    return 0;
}

//inheritance programs

class crd
{
  public:
  static int card[53];
  
  std::string status="valid";
  int user_total=0;
  void print();
  void turn();
  int cardpicker(int n);
  int carddrawer(int pno);
  crd(){
    std::fill(card, card + 53, 0);
 }
  
};
void crd::print()
{
for(int i=0;i<53;i++)
  {
    std::cout<<card[i]<<std::endl;
  }
}
int crd::cardpicker(int n)//n denotes who passed the card
{ 
  int pick;
  bool flag=true;
  while(flag==true)
  {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> number(0, 52);
    pick= number(gen);
    if(card[pick]==0)
    {
    card[pick]=n;
    flag=false;
    }
  }
  return pick;
}
int crd::carddrawer(int pno)
{
  int card1=cardpicker(pno);
  if(card1%13>9)
  { 
    std::cout<<"Card Drawn: "<<card1%13<<"    ";
    user_total=user_total+10;
  }
  else
  {
  std::cout<<"Card Drawn: "<<card1%13<<"    ";
  user_total=user_total+card1%13;
  
  }
  return 0;
}

int crd::card[53];

class prs: public virtual crd { 
  public:
   void playerstat(int pno);
   void player1(int pno);

   bool operator>(const prs &other) {
       return this->user_total>other.user_total;
   }
   bool operator<(const prs &other) {
       return this->user_total<other.user_total;
   }
   bool operator==(const prs &other) {
       return this->user_total==other.user_total;
   }
};
void prs::playerstat(int pno)
{
  std::cout<<"Player "<<pno<<":"<<std::endl;
  std::cout<<"Status "<<status<<"  User Total " << user_total;

}
void prs::player1(int pno){

  std::cout<<"Current Player "<<pno<<std::endl;
  bool flag=true;
  int drawn=0;
  int i=0;
  while(i<2||flag==true)
  {

    if(i<2)
    {
      carddrawer(pno);
    std::cout<<"User Total: "<<user_total<<std::endl;
    i++;
    }
    if(i>1)
    {
      char c;
      std::cout<<"Hit Or Stand (h/s)"<<std::endl;
      std::cin>>c;
      if(c=='s'||c=='S')
      {
        flag=false;
      }
       if(c=='h'||c=='H'){
        carddrawer(pno);
        std::cout<<"User Total :"<<user_total<<std::endl;
        if(user_total>21)
        {
        flag=false;
        status="flop";
       }}
      }

  
}}

class bluf: public prs, public virtual crd,public arc
{
  public:
  void welcome(){
      std::cout<<"welcome to akshat's Arcade";
  }
};
int main()
{
  int n=1;
  bluf p1;
  bluf p2;
  p1.player1(n);
  std::cout<<std::endl<<std::endl<<std::endl;
  system("cls");
  p2.player1(n+1);
  system("cls");
  p1.playerstat(n);
  std::cout<<std::endl<<std::endl<<std::endl;
  p2.playerstat(n+1);

 if(p1.status==p2.status)
{
  if(p1.status=="valid")
  {
    if(p1==p2)
    {
    std::cout<<std::endl<<std::endl<< "Both Won";}
    else{
      if(p1>p2||p2>p1){
    int a=p1>p2?1:2;
  std::cout<<std::endl<<std::endl<< "Winner:Player"<<a;}
   else{
  std::cout<<std::endl<<std::endl<< "Both Flopped";}}}}

  else{
 int a=p1.user_total<22?1:2;
  std::cout<<"Winner is Player "<<a;}
}





bool arc::flag;
int main() { 

    bool x=true;
    string a1;
    double a2;
    arc::tapl();
    cout<<arc::flag;
    if(arc::flag==true)
    {
        cout << "please enter your name";
        cin >> a1;
        cout << "please enter your balance";
        cin >> a2;
        arc s1(a1,a2);
        s1.currentplayer(s1);
        s1.tapl2();
    s1.tapl3();
    return 0;
    }
    else
    {
        arc s1;
        s1.currentplayer(s1);
        s1.tapl2();
        s1.tapl3();
    return 0;
    }
}

