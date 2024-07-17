#include<stdio.h>
#include<math.h>
int main()
{
    int x1,x2,y1,y2,r1,r2,big,small,d;
    printf("enter first and second circle's info respectively");
    scanf("%d%d%d%d%d%d", &x1,&y1,&r1,&x2,&y2,&r2);
    d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    if(r1>r2){
        big=r1;
        small=r2; }
    else{
        big=r2;
        small=r1; }
    if(big>=d+small)
        printf("one is inside the other");
    else if(d>big+small)
        printf("do not intersect");
    else
        printf("intersect");
    return 0;
}
