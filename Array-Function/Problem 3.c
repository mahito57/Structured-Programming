#include<stdio.h>

int main(){
    int a[100], i , n , j , max;
        printf("how many integers");
        scanf("%d", &n);
        printf("print them");
    for(i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
    }
    max=a[0];

    for(i=1;i<n;i++)

        {
            if(a[i]>max)
            max=a[i];
        }
    printf("\n%d is max\n\n",max);

    for(i=1;i<=max;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i<=max-a[j-1])
                printf("  ");
            else
                printf("**");

            printf(" ");
        }
        printf("\n");
    }
}
