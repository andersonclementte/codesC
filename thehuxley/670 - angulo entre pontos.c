#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
   
   
    double x1, y1, x2, y2, x3, y3;
	double X1, Y1, X2, Y2, rad, graus, produto, moduloU, moduloV;

	scanf("%lf %lf", &x1, &y1); //A
	scanf("%lf %lf", &x2, &y2); //B
	scanf("%lf %lf", &x3, &y3); //C

	//vetores u = X1, Y1, v = X2, Y2
	X1 = x1 - x2;
	X2 = x3 - x2;

	Y1 = y1 - y2;
	Y2 = y3 - y2;

	//Produto u.v
	produto = (X1*X2)+(Y1*Y2);

	moduloU = sqrt((X1*X1)+(Y1*Y1));
	moduloV = sqrt((X2*X2)+(Y2*Y2));

	//printf("U:%f,%f\nV:%f,%f\n", X1, Y1, X2, Y2);
	//printf("produto: %f\nModuloU:%f\nModuloV:%f\n", produto, moduloU, moduloV);

	rad = acos(produto/(moduloU*moduloV));
	graus = (rad*180)/3.141592;

	printf("%.2lf", graus);
	return 0;
}