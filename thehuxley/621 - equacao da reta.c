#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
   int x1, y1, x2, y2, i;
    float a, b, c;

    scanf("%i %i %i %i", &x1, &y1, &x2, &y2);

    //m = (y2 - y1)/(x2 - x1);

    if (x1 == x2)
    {
        a = (y1 - y2);
        b = (x2 - x1);
        c = (x1*y2) - (x2*y1);
        
        if (a != 1)
        {
            c = c/a;
            a = a/a;                     
        }
        printf("(%.2fx) + (%.2fy) + (%.2f) = 0\n", a, b, c);
    }

    else 
    {    
        a = (y1 - y2);
        b = (x2 - x1);
        c = (x1*y2) - (x2*y1);
    
        if (b != 1)
        {
            a = a/b;
            c = c/b;
            b = b/b;
        }
        printf("(%.2fx) + (%.2fy) + (%.2f) = 0\n", a, b, c);
    }
    //(-0.50x) + (1.00y) + (-0.50) = 0
    
    return 0;
	return 0;
}