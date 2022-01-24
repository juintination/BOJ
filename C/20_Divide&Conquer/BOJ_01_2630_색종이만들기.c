#include <stdio.h>
int arr[128][128], white = 0, blue = 0;
int coleredPaper(int x, int y, int size) {
	int color = arr[x][y];
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (arr[i][j] != color) {
				return 0;
			}
		}
	}
	return 1;
}
void quadTree(int x, int y, int size) {
	if (coleredPaper(x, y, size)) {
		if (arr[x][y] == 0) {
			white++;
		}
		else {
			blue++;
		}
		return;
	}
	size /= 2;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			quadTree(x + i * size, y + j * size, size);
		}
	}
}
main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	quadTree(0, 0, n);
	printf("%d\n%d", white, blue);
}