#include <stdio.h>
int arr[2187][2187], cnt[3] = { 0 };
int paper(int x, int y, int size) {
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
	if (paper(x, y, size)) {
		if (arr[x][y] == -1) {
			cnt[0]++;
		}
		else if (arr[x][y] == 0) {
			cnt[1]++;
		}
		else {
			cnt[2]++;
		}
		return;
	}
	size /= 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
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
	for (int i = 0; i < 3; i++) {
		printf("%d\n", cnt[i]);
	}
}