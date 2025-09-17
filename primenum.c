#include <stdio.h>
#include <math.h>
int main()
{
int num;
int num2;
int count=1;
printf("please enter a range \n");

scanf("%d",&num);
for(int j=0;j<num2;j++)
for(int i=1;i<=sqrt(num);i++)
{
    if(num%i==0)
    {
        count++;
    }
}
if(count==2){
    printf("prime number");

}
else
printf("not a prime");}
