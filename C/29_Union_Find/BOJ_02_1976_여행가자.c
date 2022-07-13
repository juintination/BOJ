#include <stdio.h>
#include <stdlib.h>
void initParent(int parent[], int n) {
	for (int i = 1; i <= n; i++) {
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
	if (a < b) parent[b] = a;
	else parent[a] = b;
}
int isUnion(int parent[], int a, int b) {
	a = findParent(parent, a);
	b = findParent(parent, b);
	if (a == b) return 1;
	else return 0;
}
main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int* parent = (int*)malloc(sizeof(int) * (n + 1));
	int* root = (int*)malloc(sizeof(int) * (n + 1));
	initParent(parent, n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &root[j]);
			if (root[j] == 1) {
				unionParent(parent, i, j);
			}
		}
	}
	int pre, next;
	scanf("%d", &pre);
	for (int i = 1; i < m; i++) {
		scanf("%d", &next);
		if (!isUnion(parent, pre, next)) {
			printf("NO");
			exit(0);
		}
	}
	printf("YES");
}