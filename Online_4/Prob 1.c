#include <stdio.h>

struct rectangle
{
    float 1st;
    float 2nd;
    float 3rd;
    float 4th;
};

int main()
{   struct rectangle r1;
    int i;
    float area;
    printf("give the points ");

    scanf("%f",&r1.1st);
    scanf("%f",&r1.2nd);
    scanf("%f",&r1.3rd);
    scanf("%f",&r1.4th);

    area=(abs(r1.1st-r1.3rd)*abs(r1.2nd-r1.4th))

    printf("area is %f", area);
    return 0;
}
