#include<iostream>
using namespace std;
class INT
{
  int x;
  public:
  	INT()
  	{
  		x=0;
	  }
	  INT(int x)
	  {
	  	this->x=x;
	  }
	  void operator++()
	  {
	  	x = x+1;
	  }
	  void operator++(int)
	  {
	  	x= x+1;
	  
	  }
	  INT operator+(INT Y)
	  {
	  	INT temp;
	  	temp.x= x + Y.x;
	  	return temp;
	  } 
	  INT operator-(INT Y)
	  {
	  	INT temp;
	  	temp.x= x - Y.x;
	  	return temp;
	  
	  }
	  friend INT operator+(INT X, INT Y);
	  
	  
	  friend INT operator+(INT X, int y)
	  {
	  	INT temp;
	  	temp.x = X.x + y;
	  	return temp;
	  }
	  friend INT operator+(int x, INT Y)
	  {
	  	INT temp;
	  	temp.x=x + Y.x;
	  	return temp;
	  }
	  void display()
	  {
	  	cout << x;
	  }
};
INT operator+(INT X, INT Y)
{
		INT temp;
	  	temp.x = X.x + Y.x;
	  	return temp;
}
int main()
{
	INT X(10),Y(20), Z;
	Z= X + Y;
	Z.display();
	Z= X + 2;                  //This operation will not work with member function
	Z.display();
	Z= 2 + Y;                  //This operation will also not work with member function
	Z.display();
}
 