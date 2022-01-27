#include <stdio.h>
char** arr;
void point(int x, int y, int size) {
	if (size == 3) {
		arr[x][y] = '*';
		arr[x + 1][y - 1] = arr[x + 1][y + 1] = '*';
		for (int i = -2; i <= 2; i++) {
			arr[x + 2][y + i] = '*';
		}
	}
	else {
		size /= 2;
		point(x, y, size);
		point(x + size, y - size, size);
		point(x + size, y + size, size);
	}
}
main() {
	int n;
	scanf("%d", &n);
	arr = (char**)malloc(sizeof(char*) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = (char*)malloc(sizeof(char) * (2 * n - 1));
		for (int j = 0; j < 2 * n - 1; j++) {
			arr[i][j] = ' ';
		}
	}
	point(0, n - 1, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n - 1; j++) {
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
}