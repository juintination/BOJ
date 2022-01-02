#include <stdio.h>
#define math_max(a, b) a > b ? a : b
int n, max = 0, arr[101], visited[101];
void dfs(int dpth, int sum) {
	if (dpth == n - 2) {
		max = math_max(max, sum);
		return;
	}
	for (int i = 1; i < n - 1; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			int l = i, r = i;
			while (visited[l]) l--;
			while (visited[r]) r++;
			dfs(dpth + 1, sum + arr[l] * arr[r]);
			visited[i] = 0;
		}
	}
}
main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	dfs(0, 0);
	printf("%d\n", max);
}