#include <stdio.h>
int n, k, arr[100001], parent[100001];
int queue[100002], f = 0, r = 0;
void push(int x) {
	queue[r++] = x;
}
int empty() {
	if (r == f) return 1;
	else return 0;
}
int pop() {
	return queue[f++];
}
void bfs(int idx) {
	push(idx);
	while (!empty()) {
		int x = pop();
		if (x == k) break;
		int dx[] = { x - 1, x + 1, x * 2 };
		for (int i = 0; i < 3; i++) {
			int nx = dx[i];
			if (nx >= 0 && nx <= 100000 && arr[nx] == 0) {
				push(nx);
				arr[nx] = arr[x] + 1;
				parent[nx] = x;
			}
		}
	}
}
main() {
	scanf("%d %d", &n, &k);
	bfs(n);
	printf("%d\n", arr[k]);
	int stack[100001], idx = -1;
	int tmp = k;
	while (tmp != n) {
		stack[++idx] = tmp;
		tmp = parent[tmp];
	}
	stack[++idx] = tmp;
	while (idx >= 0) {
		printf("%d ", stack[idx--]);
	}
}