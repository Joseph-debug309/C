#include <stdio.h>
#include <math.h>
int main()
    {
        int a,b,c;
        float d,x1,x2;
        printf("enter value a");
        scanf("%i",&a);
        printf("enter value b");
        scanf("%i",&b);
        printf("enter value c");
        scanf("%i",&c);
        d=pow(b,2)-(4*a*c);
        if (d<0)
        {
            printf("No roots");
        }
        else if (d==0)
        {
            x1=x2=-b/(2*a);
        }
        else
        {
            x1=(-b+sqrt(d)/(2*a));
            x2=(-b-sqrt(d)/(2*a));
        }
        printf("%f,%f", x1,x2);
        return 0; 
    }