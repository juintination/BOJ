#include <stdio.h>
#include <math.h>
int cnt = 0;
void quadTree(int r, int c, int size) {
	if (size == 1) {
		printf("%d", cnt);
		exit(0);
	}
	size /= 2;
	if (r < size && c < size) {
		quadTree(r, c, size);
	}
	else if (r < size && c >= size) {
		cnt += pow(size, 2);
		quadTree(r, c - size, size);
	}
	else if (r >= size && c < size) {
		cnt += pow(size, 2) * 2;
		quadTree(r - size, c, size);
	}
	else if (r >= size && c >= size) {
		cnt += pow(size, 2) * 3;
		quadTree(r - size, c - size, size);
	}
}
main() {
	int n, r, c;
	scanf("%d %d %d", &n, &r, &c);
	int size = (int)pow(2, n);
	quadTree(r, c, size);
}