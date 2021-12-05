#include <stdio.h>
int arr[9][9];
int sudoku(int dpth, int idx, int value) {
	for (int i = 0; i < 9; i++) {
		if (arr[dpth][i] == value) {
			return 0;
		}
		if (arr[i][idx] == value) {
			return 0;
		}
	}
	int row = (dpth / 3) * 3;
	int col = (idx / 3) * 3;
	for (int i = row; i < row + 3; i++) {
		for (int j = col; j < col + 3; j++) {
			if (arr[i][j] == value) {
				return 0;
			}
		}
	}
	return 1;
}
void dfs(int dpth, int idx) {
	if (idx == 9) {
		dfs(dpth + 1, 0);
		return;
	}
	if (dpth == 9) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				printf("%d ", arr[i][j]);
			}
			printf("\n");
		}
		exit(0);
	}
	if (arr[dpth][idx] == 0) {
		for (int i = 1; i <= 9; i++) {
			if (sudoku(dpth, idx, i)) {
				arr[dpth][idx] = i;
				dfs(dpth, idx + 1);
			}
		}
		arr[dpth][idx] = 0;
		return;
	}
	dfs(dpth, idx + 1);
}
main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	dfs(0, 0);
}