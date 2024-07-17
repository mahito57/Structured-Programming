#include<stdio.h>
int main()
{
    int i,n,sum=0,d;
    scanf("%d", &n);
    while(n>0)
    {
        d=n%10;
        n=n/10;
        if(d==2 || d==3 || d==5 || d==7 )
            sum=sum+d;

    }
    printf("%d", sum);

    return 0;
}
