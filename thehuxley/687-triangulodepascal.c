#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

double fatorial(int n);

int main()
{
    int i,l,n;
    double termo;// C(i, l)

    scanf("%d",&n);

    for(i=0;i<n+1;i++)
    {
          printf("\n");

          for(l=0;l<=i;l++)
          {
                termo = fatorial(i) / (fatorial(l) * fatorial(i-l));
                if (l!=i)
                {
                printf("%.0lf ", termo);
                }
                else
                {
                  printf("%.0lf", termo);
                }
          }

    }

    return 0;
}

double fatorial(int n)
{
    double fatorial=1;

    while(n>=1)
    {
         fatorial = fatorial * n;
         n--;
    }
    return fatorial;
}