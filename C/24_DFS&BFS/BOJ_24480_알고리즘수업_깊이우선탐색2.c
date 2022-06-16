#include <stdio.h>
#include <stdlib.h>
int n, m, r, cnt = 1, ** arr, * size, * visited, * sequence;
void dfs(int value) {
	visited[value] = 1;
	sequence[value] = cnt++;
	for (int i = 0; i < size[value]; i++) {
		int tmp = arr[value][i];
		if (!visited[tmp]) {
			dfs(tmp);
		}
	}
}
int compare(const void* a, const void* b) {
	int o1 = *(int*)a;
	int o2 = *(int*)b;
	if (o1 > o2) return -1;
	else if (o1 < o2) return 1;
	else return 0;
}
main() {
	scanf("%d %d %d", &n, &m, &r);
	arr = (int**)malloc(sizeof(int*) * (n + 1));
	size = (int*)malloc(sizeof(int) * (n + 1));
	visited = (int*)malloc(sizeof(int) * (n + 1));
	sequence = (int*)malloc(sizeof(int) * (n + 1));
	for (int i = 1; i <= n; i++) {
		arr[i] = (int*)malloc(sizeof(int));
		size[i] = visited[i] = sequence[i] = 0;
	}
	int x, y;
	while (m--) {
		scanf("%d %d", &x, &y);
		arr[x] = (int*)realloc(arr[x], sizeof(int) * (size[x] + 1));
		arr[y] = (int*)realloc(arr[y], sizeof(int) * (size[y] + 1));
		arr[x][size[x]++] = y;
		arr[y][size[y]++] = x;
	}
	for (int i = 1; i <= n; i++) {
		qsort(arr[i], size[i], sizeof(int), compare);
	}
	dfs(r);
	for (int i = 1; i <= n; i++) {
		printf("%d\n", sequence[i]);
	}
}