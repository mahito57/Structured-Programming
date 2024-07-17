#include<stdio.h>
int perfect(int p){
    int i, sum=0;
    for(i=1;i<p;i++)
    {
        if(p%i==0)
            sum=sum+i;
    }

    if(sum==p)
        return 1;
    else
        return 0;
}

int main(){
    int n,i,total=0,k;
    printf("print a nonnegative integer");
    scanf("%d", &n);
        for(i=1;i<=n;i++)
        {
            k=perfect(i);
                if(k==1)
                    total=total+i;
        }

    printf("sum of the perfect numbers are %d", total);
return 0;
}
