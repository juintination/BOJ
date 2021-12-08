#include <stdio.h>
int n, m, v, arr[1001][1001], visited[1001];
int queue[1000], f = 0, r = 0;
void push(int x) {
	queue[r++] = x;
}
int empty() {
	if (r == f) return 1;
	else return 0;
}
int pop() {
	if (!empty()) return queue[f++];
}
void dfs(int value) {
	printf("%d ", value);
	visited[value] = 1;
	for (int i = 1; i <= n; i++) {
		if (arr[value][i] && !visited[i]) {
			dfs(i);
		}
	}
}
void bfs(int value) {
	push(value);
	while (!empty()) {
		int tmp = pop();
		visited[tmp] = 1;
		for (int i = 1; i <= n; i++) {
			if (arr[tmp][i] && !visited[i]) {
				push(i);
				visited[i] = 1;
			}
		}
		printf("%d ", tmp);
	}
}
main() {
	scanf("%d %d %d", &n, &m, &v);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		arr[x][y] = arr[y][x] = 1;
	}
	dfs(v);
	printf("\n");
	for (int i = 1; i <= n; i++) {
		visited[i] = 0;
	}
	bfs(v);
}