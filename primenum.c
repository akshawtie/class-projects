#include <stdio.h>
#include <math.h>
int main()
{
int num;
int num2;

printf("please enter a range from \n");
printf("please enter start \n");
scanf("%d",&num);
printf("please enter end of range\n");
scanf("%d",&num2);
for(int j=num;j<num2;j++)
{
    int count=1;
for(int i=1;i<=sqrt(j);i++)
{
    if(j%i==0)
    {
        count++;
    }
}
if(count==2){
    printf("%d \n",j);

}
}
}
