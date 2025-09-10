#include <stdio.h>
#include <math.h>
int main()

{
    int a;
    printf("Please enter a Number \n");
    scanf("%d",&a);
    int digits=(log10(a))+1;
    printf("%d",digits);

    int armsum=0;
    int num=a;
    int sum;
    for(int i=1;i<=digits;i++)
    {
        armsum=armsum+(pow(num%10,digits));
        num=num/10;
    
    }
    if(armsum==a){
        printf("\n The number is armstrong %d",a);
    }
    else
    printf("not an armstrong num %d",a);
}