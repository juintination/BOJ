#include <stdio.h>
#define math_max(a, b) a > b ? a : b
int n, m, arr[1000][1000];
int queue_x[1000000], queue_y[1000000], popped[2], f = 0, r = 0;
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
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1) {
				push(i, j);
			}
		}
	}
	int dx[] = { -1, 0, 1, 0 };
	int dy[] = { 0, -1, 0, 1 };
	while (!empty()) {
		pop();
		x = popped[0];
		y = popped[1];
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < m && ny >= 0 && ny < n && arr[nx][ny] == 0) {
				arr[nx][ny] = arr[x][y] + 1;
				push(nx, ny);
			}
		}
	}
}
main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	bfs(0, 0);
	int max = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0) {
				printf("-1");
				exit(0);
			}
			max = math_max(max, arr[i][j]);
		}
	}
	printf("%d", max - 1);
}