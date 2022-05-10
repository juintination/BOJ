#include <stdio.h>
#define math_min(a, b) a < b ? a : b
int n, m, min, board, **visited;
int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };
char** arr;
void dfs(int dpth, int x, int y, int moved) {
	if (moved == board) {
		min = math_min(min, dpth);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x, ny = y, cnt = 0;
		while (1) {
			nx += dx[i];
			ny += dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] != '*' && !visited[nx][ny]) {
				visited[nx][ny] = 1;
				cnt++;
			}
			else break;
		}
		if (cnt == 0) continue;
		nx -= dx[i];
		ny -= dy[i];
		dfs(dpth + 1, nx, ny, moved + cnt);
		for (int j = 0; j < cnt; j++) {
			visited[nx][ny] = 0;
			nx -= dx[i];
			ny -= dy[i];
		}
	}
}
main() {
	int cnt = 1;
	while (scanf("%d %d", &n, &m) != EOF) {
		visited = (int**)malloc(sizeof(int*) * n);
		arr = (char**)malloc(sizeof(char*) * n);
		min = 1000000, board = 0;
		for (int i = 0; i < n; i++) {
			visited[i] = (int*)malloc(sizeof(int) * m);
			arr[i] = (char*)malloc(sizeof(char) * m);
			char* str = (char*)malloc(sizeof(char) * m);
			scanf("%s", str);
			for (int j = 0; j < m; j++) {
				visited[i][j] = 0;
				arr[i][j] = str[j];
				if (arr[i][j] == '.') {
					board++;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == '.') {
					visited[i][j] = 1;
					dfs(0, i, j, 1);
					visited[i][j] = 0;
				}
			}
		}
		if (min == 1000000) {
			printf("Case %d: -1\n", cnt++);
		}
		else {
			printf("Case %d: %d\n", cnt++, min);
		}
	}
}