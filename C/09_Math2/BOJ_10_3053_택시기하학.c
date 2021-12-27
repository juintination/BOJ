#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
main() {
	double r;
	scanf("%lf", &r);
	printf("%.6lf\n%.6lf", r * r * M_PI, r * r * 2);
}