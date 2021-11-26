#include <stdio.h>
#include <math.h>
#define math_max(a, b) a > b ? a : b
int arr[8], num[8], visited[8], n, max;
void dfs(int dpth) {
	if (dpth == n) {
		int sum = 0;
		for (int i = 1; i < n; i++) {
			sum += abs(arr[i] - arr[i - 1]);
		}
		max = math_max(max, sum);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			arr[dpth] = num[i];
			dfs(dpth + 1);
			visited[i] = 0;
		}
	}
}
main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	max = 0;
	dfs(0);
	printf("%d", max);
}