#include <stdio.h>
#include <stdlib.h>
int a, b, parent[10000], visited[10000];
int queue[40000];
int f = 0, r = 0;
void push(int x) {
	queue[r++] = x;
}
int pop() {
	if (r == f) return -1;
	else return queue[f++];
}
int empty() {
	if (r == f) return 1;
	else return 0;
}
void initvisited(int n) {
	for (int i = 0; i < n; i++) {
		visited[i] = 0;
	}
}
void bfs(int a) {
	char str[10001], reverse[10001];
	f = r = 0;
	push(a);
	initvisited(10000);
	visited[a] = 1;
	while (!empty()) {
		int tmp = pop();
		int d = (2 * tmp) % 10000;
		if (!visited[d]) {
			str[d] = 'D';
			parent[d] = tmp;
			visited[d] = 1;
			push(d);
		}
		int s = (tmp == 0) ? 9999 : tmp - 1;
		if (!visited[s]) {
			str[s] = 'S';
			parent[s] = tmp;
			visited[s] = 1;
			push(s);
		}
		int l = (tmp % 1000) * 10 + tmp / 1000;
		if (!visited[l]) {
			str[l] = 'L';
			parent[l] = tmp;
			visited[l] = 1;
			push(l);
		}
		int r = (tmp % 10) * 1000 + tmp / 10;
		if (!visited[r]) {
			str[r] = 'R';
			parent[r] = tmp;
			visited[r] = 1;
			push(r);
		}
		if (visited[b]) {
			int c = b, cnt = 0;
			while (c != a) {
				reverse[cnt++] = str[c];
				c = parent[c];
			}
			for (int i = cnt - 1; i >= 0; i--) {
				printf("%c", reverse[i]);
			}
			printf("\n");
			return;
		}
	}
}
main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		scanf("%d %d", &a, &b);
		bfs(a);
	}
}