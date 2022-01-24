#include <stdio.h>
int arr[64][64];
int compressed(int x, int y, int size) {
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
	if (compressed(x, y, size)) {
		printf("%d", arr[x][y]);
		return;
	}
	printf("(");
	size /= 2;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			quadTree(x + i * size, y + j * size, size);
		}
	}
	printf(")");
}
main() {
	int n;
	scanf("%d", &n);
	char* str = (char*)malloc(sizeof(char) * n);
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		for (int j = 0; j < n; j++) {
			arr[i][j] = str[j] - '0';
		}
	}
	quadTree(0, 0, n);
}