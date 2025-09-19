#include <iostream>
#include <random>
#include <string>

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

class bluf: public prs, public virtual crd
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
