#include <stdio.h>
#define math_max(a, b) a > b ? a : b
int n, max, dir[5], arr[20][20], tmp[20][20], visited[20][20];
void move(int i, int j, int k) {
	int dx[] = { -1, 0, 1, 0 };
	int dy[] = { 0, -1, 0, 1 };
	if (tmp[i][j] == 0) return;
	while (1) {
		int nx = i + dx[k], ny = j + dy[k];
		if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
			if (tmp[nx][ny] == tmp[i][j]) {
				visited[nx][ny] = 1;
				tmp[nx][ny] += tmp[i][j];
				tmp[i][j] = 0;
				break;
			}
			else if (tmp[nx][ny] != 0) {
				break;
			}
			tmp[nx][ny] = tmp[i][j];
			tmp[i][j] = 0;
			i = nx;
			j = ny;
		}
		else break;
	}
}
void game() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmp[i][j] = arr[i][j];
		}
	}
	for (int k = 0; k < 5; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				visited[i][j] = 0;
			}
		}
		if (dir[k] == 0) {// ╩С(-1,0)
			for (int i = 1; i < n; i++) {
				for (int j = 0; j < n; j++) {
					move(i, j, dir[k]);
				}
			}
		}
		else if (dir[k] == 1) {// аб(0,-1)
			for (int j = 1; j < n; j++) {
				for (int i = 0; i < n; i++) {
					move(i, j, dir[k]);
				}
			}
		}
		else if (dir[k] == 2) {// го(1,0)
			for (int i = n - 2; i >= 0; i--) {
				for (int j = 0; j < n; j++) {
					move(i, j, dir[k]);
				}
			}
		}
		else {// ©Л(0,1)
			for (int j = n - 2; j >= 0; j--) {
				for (int i = 0; i < n; i++) {
					move(i, j, dir[k]);
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			max = math_max(max, tmp[i][j]);
		}
	}
}
void dfs(int dpth) {
	if (dpth == 5) {
		game();
		return;
	}
	for (int i = 0; i < 4; i++) {
		dir[dpth] = i;
		dfs(dpth + 1);
	}
}
main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	dfs(0);
	printf("%d", max);
}