#include <stdio.h>
int n, m, visited[50][50], tst;
char arr[51][51];
void dfs(int x, int y, int idx) {
	if (tst) return;
	visited[x][y] = 1;
	int dx[] = { -1, 0, 1, 0 };
	int dy[] = { 0, -1, 0, 1 };
	for (int i = 0; i < 4; i++) {
		if (idx != i && idx % 2 == i % 2) continue;
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && arr[x][y] == arr[nx][ny]) {
			if (visited[nx][ny]) {
				tst = 1;
				return;
			}
			dfs(nx, ny, i);
		}
	}
}
main() {
	scanf("%d %d", &n, &m);
	char* str = (char*)malloc(sizeof(char) * (m + 1));
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		for (int j = 0; j < m; j++) {
			arr[i][j] = str[j];
		}
	}
	tst = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j]) {
				dfs(i, j, -1);
			}
			if (tst) {
				printf("Yes");
				exit(0);
			}
		}
	}
	printf("No");
}