#include <stdio.h>
int arr[8], n, m;
void dfs(int dpth) {
	if (dpth == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 0; i < n; i++) {
		arr[dpth] = i + 1;
		dfs(dpth + 1);
	}
}
main() {
	scanf("%d %d", &n, &m);
	dfs(0);
}