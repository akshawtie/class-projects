#include <stdio.h>
#include <math.h>
#include <stdbool.h>
int main()
{

    int a;
    scanf("%d",&a);
    for(int i=1;i<=a;i++)
    {
    int printed=(i+i)-1;
    int space=((a*2)-printed)/2;
    for(int j=1;j<=space;j++)
    {
        printf(" ");
    }
    bool reverse=false;
    int p=1;
    for(int j=1;j<=printed;j++)
    {
        if(j>=i)
        {
        reverse=true;
    }
        if(reverse==false)
        {
            printf("%d",p);
            p++;}
            else
            {
            printf("%d",p);
            p--;
            
            }
        }
    printf("\n");
    }

}