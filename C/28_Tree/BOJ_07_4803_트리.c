#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void initParent(int parent[], int n) {
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}
}
int findParent(int parent[], int x) {
	if (parent[x] == x) return x;
	return parent[x] = findParent(parent, parent[x]);
}
void unionParent(int parent[], int a, int b) {
	a = findParent(parent, a);
	b = findParent(parent, b);
	if (a == b) {
		parent[a] = 0;
	}
	else if (a < b) parent[b] = a;
	else parent[a] = b;
}
main() {
	for (int cnt = 1; ; cnt++) {
		int n, m;
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0) break;
		int* parent = (int*)malloc(sizeof(int) * (n + 1));
		initParent(parent, n);
		while (m--) {
			int a, b;
			scanf("%d %d", &a, &b);
			unionParent(parent, a, b);
		}
		int* visited = (int*)malloc(sizeof(int) * (n + 1));
		memset(visited, 0, sizeof(int) * (n + 1));
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			int pi = findParent(parent, i);
			if (pi > 0 && !visited[pi]) {
				visited[pi] = 1;
				sum++;
			}
		}
		free(parent);
		free(visited);
		printf("Case %d: ", cnt);
		if (sum == 0) printf("No trees.\n");
		else if (sum == 1) printf("There is one tree.\n");
		else printf("A forest of %d trees.\n", sum);
	}
}