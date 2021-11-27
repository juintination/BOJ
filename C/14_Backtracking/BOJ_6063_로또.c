#include <stdio.h>
int arr[6], lotto[12], visited[12], n;
void dfs(int dpth) {
	if (dpth == 6) {
		for (int i = 0; i < 6; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 0; i < n; i++) {
		if (visited[i] == 0) {
			if (dpth > 0 && arr[dpth - 1] > lotto[i]) continue;
			visited[i] = 1;
			arr[dpth] = lotto[i];
			dfs(dpth + 1);
			visited[i] = 0;
		}
	}
}
main() {
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			scanf("%d", &lotto[i]);
		}
		dfs(0);
		printf("\n");
	}
}