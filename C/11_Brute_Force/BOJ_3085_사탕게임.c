#include <stdio.h>
#define math_max(a, b) a > b ? a : b
int n, max = 0;
void swap(char* a, char* b) {
	char tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void game(char** candy) {
	for (int i = 0; i < n; i++) {
		char color = candy[i][0];
		int cnt = 1;
		for (int j = 1; j < n; j++) {
			if (color == candy[i][j]) {
				cnt++;
			}
			else {
				color = candy[i][j];
				cnt = 1;
			}
			max = math_max(max, cnt);
		}
	}
	for (int j = 0; j < n; j++) {
		char color = candy[0][j];
		int cnt = 1;
		for (int i = 1; i < n; i++) {
			if (color == candy[i][j]) {
				cnt++;
			}
			else {
				color = candy[i][j];
				cnt = 1;
			}
			max = math_max(max, cnt);
		}
	}
}
main() {
	char** candy;
	scanf("%d", &n);
	candy = (char**)malloc(sizeof(char*) * (n + 1));
	for (int i = 0; i < n; i++) {
		candy[i] = (char*)malloc(sizeof(char) * (n + 1));
		scanf("%s", candy[i]);
		getchar();
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j < n - 1 && candy[i][j] != candy[i][j + 1]) {
				swap(&candy[i][j], &candy[i][j + 1]);
				game(candy);
				swap(&candy[i][j], &candy[i][j + 1]);
			}
			if (i < n - 1 && candy[i][j] != candy[i + 1][j]) {
				swap(&candy[i][j], &candy[i + 1][j]);
				game(candy);
				swap(&candy[i][j], &candy[i + 1][j]);
			}
		}
	}
	printf("%d", max);
}