#include <stdio.h>
int arr[5][5], visited[1000000], cnt = 0;
void dfs(int dpth, int sum, int x, int y) {
	if (dpth == 6) {
		if (!visited[sum]) {
			visited[sum] = 1;
			cnt++;
		}
		return;
	}
	int dx[] = { -1, 0, 1, 0 };
	int dy[] = { 0, -1, 0, 1 };
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
			dfs(dpth + 1, sum * 10 + arr[nx][ny], nx, ny);
		}
	}
}
main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dfs(0, 0, i, j);
		}
	}
	printf("%d", cnt);
}