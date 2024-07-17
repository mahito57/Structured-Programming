#include<stdio.h>

int prime(int a){

    int i,j,count=0,flag=0;

    for(i=2; i>0; i++)
    {
        flag=0;
        for(j=2; j<i; j++)
        {
            if(i%j==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            count++;

        }
        if(count==a)
        {
           return i;
            break;
        }

    }


}
int fact(int z)
{
    int f = 1, i;


        for (i = 1; i <= z; i++)
	{
            f = f * i;
	}

    return f;
}

int main()
    int i,j, flag, n,p,result;
    scanf("%d",&n);
    p=prime(n);
     for(i=p+1;i<=10000;i++)
   {

      flag=0;

      for(j=2;j<i;j++)
      {
         if(i%j==0)
         {
            flag=1;
            break;
         }
      }

      if(flag==0)
      {
         printf("next prime is:%d",i);
         break;
      }
   }

    result=(fact(i)/(fact(p)*fact(i-p)));

    printf("%d", result);

