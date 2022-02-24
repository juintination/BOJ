#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long int* b, *arr;
int n, *visited;
int compare(const void* a, const void* b) {
	long long int o1 = *(long long int*)a;
	long long int o2 = *(long long int*)b;
	if (o1 > o2) return 1;
	else if (o1 < o2) return -1;
	else return 0;
}
void dfs(int idx, int dpth) {
	if (!visited[idx]) {
		visited[idx] = 1;
		arr[dpth] = b[idx];
		if (dpth == n - 1) {
			for (int i = 0; i < n; i++) {
				printf("%lld ", arr[i]);
			}
			exit(0);
		}
		if (arr[dpth] % 3 == 0) {
			for (int i = idx - 1; i >= 0; i--) {
				if (b[i] == arr[dpth] / 3) {
					dfs(i, dpth + 1);
				}
			}
		}
		for (int i = idx + 1; i < n; i++) {
			if (b[i] == arr[dpth] * 2) {
				dfs(i, dpth + 1);
			}
		}
		visited[idx] = 0;
	}
}
main() {
	scanf("%d", &n);
	b = (long long int*)malloc(sizeof(long long int) * n);
	arr = (long long int*)malloc(sizeof(long long int) * n);
	visited = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &b[i]);
	}
	qsort(b, n, sizeof(long long int), compare);
	for (int i = 0; i < n; i++) {
		memset(visited, 0, sizeof(int) * n);
		dfs(i, 0);
	}
}