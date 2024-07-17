#include<stdio.h>
int main()
{
    float inc,tax;
    int d;
    scanf("%f",&inc);
    d=inc/10000.0;
    switch(d){
    case 0:
        tax=(0.1*inc);
        break;
    case 1:
    case 2:
        tax=1000+0.15*(inc-10000);
        break;
    case 3:
    case 4:
        tax=4500+.2*(inc-30000);
        break;
    default:
        tax=10000+.25*(inc-50000);
    }
    printf("%f", tax);
    return 0;
}
