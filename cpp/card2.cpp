#include <iostream>
#include <random>
#include <string>
using namespace std;
class crd
{
public:
    static int card[53];
    void print();
    int cardpicker(int n);
    crd(){fill(card, card+53,0);}
};
int crd::card[53];
void crd::print()
{
    for(int i=0;i<53;i++){cout<<card[i]<<endl;}
}
int crd::cardpicker(int n)
{
    int pick;
    bool flag=true;
    while(flag)
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> number(1,52);
        pick=number(gen);
        if(card[pick]==0){card[pick]=n; flag=false;}
    }
    return pick;
}
class prs
{
public:
    int user_total=0;
    string status="valid";
    void playerstat(int pno);
    bool operator>(const prs &other)
    {return user_total>other.user_total;}
    bool operator<(const prs &other)
    {return user_total<other.user_total;}
    bool operator==(const prs &other)
    {return user_total==other.user_total;}
};
void prs::playerstat(int pno)
{
    cout<<"Player "<<pno<<":"<<endl;
    cout<<"Status: "<<status<<"  User Total: "<<user_total<<endl;
}
class bluf: public prs, public crd
{
public:
    void welcome(){cout<<"welcome to akshat's Arcade"<<endl;}
    int carddrawer(int pno);
    void play_turn(int pno);
};
int bluf::carddrawer(int pno)
{
    int card_val=cardpicker(pno);
    int face_value=(card_val-1)%13+1;
    if(face_value>10)
    {cout<<"Card Drawn: "<<face_value<<" (Value: 10)    "; user_total+=10;}
    else 
    if(face_value==1)
    {cout<<"Card Drawn: "<<face_value<<" (Value: 1)     "; user_total+=1;}
    else{cout<<"Card Drawn: "<<face_value<<"    "; user_total+=face_value;}
    return 0;
}
void bluf::play_turn(int pno)
{
    cout<<"Current Player "<<pno<<endl;
    bool flag=true;
    int i=0;
    while(i<2){carddrawer(pno); cout<<"User Total: "<<user_total<<endl; i++;}
    while(flag && user_total<=21)
    {
        char c;
        cout<<"Hit Or Stand (h/s)"<<endl<<"Any Other Input Leads to Stand"<<endl;
        cin>>c;
        if(c=='s'||c=='S'){flag=false;}
        else if(c=='h'||c=='H'){carddrawer(pno); cout<<"User Total: "<<user_total<<endl; 
            if(user_total>21){flag=false; status="flop"; cout<<"Player "<<pno<<" busts!"<<endl;}}
        else{flag=false;}
    }
}

int main()
{
    int n=1;
    bluf p1,p2;
    p1.welcome();
    p1.play_turn(n);
    cout<<endl<<"----------------------------------"<<endl<<endl;
    p2.play_turn(n+1);
    cout<<endl<<"========== GAME OVER =========="<<endl<<endl;
    p1.playerstat(n);
    cout<<endl;
    p2.playerstat(n+1);
    cout<<endl;
    if(p1.status=="flop" && p2.status=="flop")
    {cout<<"Both players busted. No winner."<<endl;}
    else 
    if(p1.status=="flop"){cout<<"Winner is Player 2!"<<endl;}
    else
     if(p2.status=="flop"){cout<<"Winner is Player 1!"<<endl;}
    else
    {if(p1>p2){cout<<"Winner is Player 1!"<<endl;} 
    else
     if(p2>p1){cout<<"Winner is Player 2!"<<endl;}
     else{cout<<"It's a draw!"<<endl;}}
    return 0;
}
