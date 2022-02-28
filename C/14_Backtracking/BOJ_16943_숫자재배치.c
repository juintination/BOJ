#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* a;
int b, *arr, *visited;
int compare(const void* a, const void* b) {
	int o1 = *(int*)a;
	int o2 = *(int*)b;
	if (o1 > o2) return 1;
	else if (o1 < o2) return -1;
	else return 0;
}
void dfs(int dpth, int sum) {
	if (dpth == strlen(a)) {
		printf("%d", sum);
		exit(0);
	}
	for (int i = strlen(a) - 1; i >= 0; i--) {
		if (dpth == 0 && arr[i] == 0) continue;
		if (!visited[i]) {
			if (sum * 10 + arr[i] < b) {
				visited[i] = 1;
				dfs(dpth + 1, sum * 10 + arr[i]);
				visited[i] = 0;
			}
		}
	}
}
main() {
	a = (char*)malloc(sizeof(char) * 10);
	scanf("%s %d", a, &b);
	arr = (int*)malloc(sizeof(int) * strlen(a));
	visited = (int*)malloc(sizeof(int) * strlen(a));
	for (int i = 0; i < strlen(a); i++) {
		arr[i] = a[i] - '0';
		visited[i] = 0;
	}
	qsort(arr, strlen(a), sizeof(int), compare);
	dfs(0, 0);
	printf("-1");
}