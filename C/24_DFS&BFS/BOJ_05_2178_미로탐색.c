#include <stdio.h>
int n, m, arr[100][100], visited[100][100];
int queue_x[10000], queue_y[10000], popped[2], f = 0, r = 0;
void push(int x, int y) {
	queue_x[r] = x;
	queue_y[r++] = y;
}
int empty() {
	if (r == f) return 1;
	else return 0;
}
void pop() {
	if (!empty()) {
		popped[0] = queue_x[f];
		popped[1] = queue_y[f++];
	}
}
void bfs(int x, int y) {
	push(x, y);
	visited[x][y] = 1;
	int dx[] = { -1, 0, 1, 0 };
	int dy[] = { 0, -1, 0, 1 };
	while (!empty()) {
		pop();
		x = popped[0];
		y = popped[1];
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && arr[nx][ny] != 0) {
				visited[nx][ny] = 1;
				arr[nx][ny] = arr[x][y] + 1;
				push(nx, ny);
			}
		}
	}
}
main() {
	scanf("%d %d", &n, &m);
	char* str = (char*)malloc(sizeof(char) * (m + 1));
	for (int i = 0; i < n; i++) {
		getchar();
		scanf("%s", str);
		for (int j = 0; j < m; j++) {
			arr[i][j] = str[j] - '0';
		}
	}
	bfs(0, 0);
	printf("%d", arr[n - 1][m - 1]);
}