#include<stdio.h>
int main()
{
    int i;
    float x,sum=1.0,res,t=1.0;
    scanf("%f", &x);
    x=x*3.1416/180;
    for(i=1;i<100;i++)
    {
        res=(2*i)*(2*i-1);
        t=-t*x*x/res;
        sum=sum+t;
    }
    printf("%.6f", sum);

    return 0;
}
