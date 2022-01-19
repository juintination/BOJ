#include <stdio.h>
#include <math.h>
int n, m, matA[50][50], matB[50][50];
void reverse(int r, int c) {
	for (int i = r; i < r + 3; i++) {
		for (int j = c; j < c + 3; j++) {
			matA[i][j] = abs(matA[i][j] - 1);
		}
	}
}
int check() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matA[i][j] != matB[i][j]) {
				return 0;
			}
		}
	}
	return 1;
}
main() {
	scanf("%d %d", &n, &m);
	char* str = (char*)malloc(sizeof(char) * m);
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		for (int j = 0; j < m; j++) {
			matA[i][j] = str[j] - '0';
		}
	}
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		for (int j = 0; j < m; j++) {
			matB[i][j] = str[j] - '0';
		}
	}
	int cnt = 0;
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			if (matA[i][j] != matB[i][j]) {
				reverse(i, j);
				cnt++;
			}
		}
	}
	if (check()) {
		printf("%d", cnt);
	}
	else {
		printf("-1");
	}
}