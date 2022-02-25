#include <stdio.h>
#include <stdlib.h>
#define math_max(a, b) a > b ? a : b
typedef struct {
	int r, c;
} point;
point* arr;
int h, w, n;
int paste(int r1, int c1, int r2, int c2) {
	int c = math_max(c1, c2);
	if (r1 + r2 <= h && c <= w) return 1;
	int r = math_max(r1, r2);
	if (r <= h && c1 + c2 <= w) return 1;
	return 0;
}
int sticker(int r1, int c1, int r2, int c2) {
	if (paste(r1, c1, r2, c2)) return 1;
	if (paste(c1, r1, r2, c2)) return 1;
	if (paste(r1, c1, c2, r2)) return 1;
	if (paste(c1, r1, c2, r2)) return 1;
	return 0;
}
main() {
	scanf("%d %d %d", &h, &w, &n);
	arr = (point*)malloc(sizeof(point) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].r, &arr[i].c);
	}
	int max = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			int r1 = arr[i].r, c1 = arr[i].c;
			int r2 = arr[j].r, c2 = arr[j].c;
			if (sticker(r1, c1, r2, c2)) {
				int area = r1 * c1 + r2 * c2;
				max = math_max(max, area);
			}
		}
	}
	printf("%d", max);
}