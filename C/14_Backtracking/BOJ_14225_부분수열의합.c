#include <stdio.h>
int n, arr[20], visited[2000001];
void dfs(int dpth, int sum) {
	if (dpth == n) {
		visited[sum] = 1;
		return;
	}
	dfs(dpth + 1, sum);
	dfs(dpth + 1, sum + arr[dpth]);
}
main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	dfs(0, 0);
	int result = 1;
	while (1) {
		if (!visited[result++]) {
			printf("%d", result - 1);
			break;
		}
	}
}