#include <stdio.h>
int main() {
    int n, rev = 0, remainder, flag=0 , i ;
    printf("Enter an integer: ");
    scanf("%d", &n);
    while (n != 0) {
        remainder = n % 10;
        rev = rev * 10 + remainder;
        n /= 10;
    }
    for (i = 2; i <= rev / 2; ++i) {


        if (rev% i == 0) {
            flag = 1;
            break;
        }
    }


     if (rev== 1) {
        printf("1 is neither prime nor composite.");}
    else  {
        if (flag == 0)
            printf("%d is a prime number.", rev);
        else
            printf("%d is not a prime number.", rev);
    }

    return 0;
}

