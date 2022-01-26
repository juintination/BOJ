#include <stdio.h>
#include <math.h>
int d;
char* str;
long long int tx, ty;
void quadTree(long long int tx, long long int ty, long long int size) {
	if (size == 1) {
		exit(0);
	}
	size /= 2;
	if (tx < size && ty >= size) {
		printf("1");
		quadTree(tx, ty - size, size);
	}
	else if (tx < size && ty < size) {
		printf("2");
		quadTree(tx, ty, size);
	}
	else if (tx >= size && ty < size) {
		printf("3");
		quadTree(tx - size, ty, size);
	}
	else if (tx >= size && ty >= size) {
		printf("4");
		quadTree(tx - size, ty - size, size);
	}
}
void targeted(long long int x, long long int y, long long int size, int idx) {
	if (idx == d) {
		tx = x;
		ty = y;
		return;
	}
	size /= 2;
	if (str[idx] == '1') {
		targeted(x, y + size, size, idx + 1);
	}
	else if (str[idx] == '2') {
		targeted(x, y, size, idx + 1);
	}
	else if (str[idx] == '3') {
		targeted(x + size, y, size, idx + 1);
	}
	else if (str[idx] == '4') {
		targeted(x + size, y + size, size, idx + 1);
	}
}
main() {
	scanf("%d", &d);
	str = (char*)malloc(sizeof(char) * d);
	scanf("%s", str);
	long long int size = pow(2, d);
	targeted(0, 0, size, 0);
	long long int x, y;
	scanf("%lld %lld", &y, &x);
	tx -= x;
	ty += y;
	if (tx >= 0 && tx < size && ty >= 0 && ty < size) {
		quadTree(tx, ty, size);
	}
	else {
		printf("-1");
	}
}