#include <stdio.h>
int arr[8], n, m;
void dfs(int dpth, int idx) {
	if (dpth == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}
	for (int i = idx; i < n; i++) {
		arr[dpth] = i + 1;
		dfs(dpth + 1, i);
	}
}
main() {
	scanf("%d %d", &n, &m);
	dfs(0, 0);
}