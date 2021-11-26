#include <stdio.h>
int arr[8], visited[8], n;
void dfs(int dpth) {
	if (dpth == n) {
		for (int i = 0; i < n; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 0; i < n; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			arr[dpth] = i + 1;
			dfs(dpth + 1);
			visited[i] = 0;
		}
	}
}
main() {
	scanf("%d", &n);
	dfs(0);
}