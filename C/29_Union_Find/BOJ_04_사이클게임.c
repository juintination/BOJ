#include <stdio.h>
#include <stdlib.h>
void initParent(int parent[], int n) {
	for (int i = 0; i < n; i++) {
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
	int n, m, a, b, cnt = 0, isFirst = 1;
	scanf("%d %d", &n, &m);
	int* parent = (int*)malloc(sizeof(int) * n);
	initParent(parent, n);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &a, &b);
		if (!isUnion(parent, a, b)) {
			unionParent(parent, a, b);
		}
		else if (isFirst) {
			isFirst = !isFirst;
			cnt = i;
		}
	}
	printf("%d", cnt);
}