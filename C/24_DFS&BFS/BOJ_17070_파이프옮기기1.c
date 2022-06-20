#include <stdio.h>
int n, **arr, cnt = 0;
const int horizontal = 0, vertical = 1, diagonal = 2;
void dfs(int x, int y, int dir) {
	if (x == n - 1 && y == n - 1) {
		cnt++;
		return;
	}
	if (dir == 0) {
		if (y + 1 < n && arr[x][y + 1] != 1) {
			dfs(x, y + 1, 0);
		}
	}
	else if (dir == 1) {
		if (x + 1 < n && arr[x + 1][y] != 1) {
			dfs(x + 1, y, 1);
		}
	}
	else if (dir == 2) {
		if (x + 1 < n && arr[x + 1][y] != 1) {
			dfs(x + 1, y, 1);
		}
		if (y + 1 < n && arr[x][y + 1] != 1) {
			dfs(x, y + 1, 0);
		}
	}
	if (x + 1 < n && y + 1 < n) {
		if (arr[x + 1][y] != 1 && arr[x][y + 1] != 1 && arr[x + 1][y + 1] != 1) {
			dfs(x + 1, y + 1, 2);
		}
	}
}
main() {
	scanf("%d", &n);
	arr = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = (int*)malloc(sizeof(int) * n);
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	dfs(0, 1, 0);
	printf("%d", cnt);
}