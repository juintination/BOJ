#include <stdio.h>
int n, k, arr[100001];
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
	arr[idx] = 1;
	push(idx);
	while (!empty()) {
		int x = pop();
		if (x == k) break;
		int dx[] = { x * 2, x - 1, x + 1 };
		for (int i = 0; i < 3; i++) {
			int nx = dx[i];
			if (nx >= 0 && nx <= 100000 && arr[nx] == 0) {
				push(nx);
				if (i == 0) {
					arr[nx] = arr[x];
				}
				else {
					arr[nx] = arr[x] + 1;
				}
			}
		}
	}
}
main() {
	scanf("%d %d", &n, &k);
	bfs(n);
	printf("%d", arr[k] - 1);
}