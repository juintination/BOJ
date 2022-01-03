#include <stdio.h>
#define math_max(a, b) a > b ? a : b
int n, m, max = 1, arr[20][20], visited[26];
void dfs(int x, int y, int dpth) {
	visited[arr[x][y]] = 1;
	int dx[] = { -1, 0, 1, 0 };
	int dy[] = { 0, -1, 0, 1 };
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[arr[nx][ny]]) {
			max = math_max(max, dpth + 1);
			dfs(nx, ny, dpth + 1);
			visited[arr[nx][ny]] = 0;
		}
	}
}
main() {
	scanf("%d %d", &n, &m);
	char* str = (char*)malloc(sizeof(char) * (m + 1));
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		for (int j = 0; j < m; j++) {
			arr[i][j] = str[j] - 'A';
		}
	}
	dfs(0, 0, 1);
	printf("%d", max);
}