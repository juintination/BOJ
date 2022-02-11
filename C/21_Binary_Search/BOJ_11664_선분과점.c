#include <stdio.h>
#include <math.h>
#define math_min(a, b) a < b ? a : b
double math_abs(double abs) {
	if (abs < 0) abs = -abs;
	return abs;
}
main() {
	double ax, ay, az, bx, by, bz, cx, cy, cz, lx, ly, lz, rx, ry, rz, min;
	scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf", &ax, &ay, &az, &bx, &by, &bz, &cx, &cy, &cz);
	lx = ax, ly = ay, lz = az, rx = bx, ry = by, rz = bz;
	min = 2147483647;
	while (1) {
		double mx = (lx + rx) / 2, my = (ly + ry) / 2, mz = (lz + rz) / 2;
		double md = sqrt(pow(mx - cx, 2) + pow(my - cy, 2) + pow(mz - cz, 2));
		if (math_abs(md - min) <= 0.000001) {
			printf("%.10lf", min);
			break;
		}
		min = math_min(min, md);
		double ld = sqrt(pow(lx - cx, 2) + pow(ly - cy, 2) + pow(lz - cz, 2));
		double rd = sqrt(pow(rx - cx, 2) + pow(ry - cy, 2) + pow(rz - cz, 2));
		if (rd < ld) {
			lx = mx;
			ly = my;
			lz = mz;
		}
		else {
			rx = mx;
			ry = my;
			rz = mz;
		}
	}
}