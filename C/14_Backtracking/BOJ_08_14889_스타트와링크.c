#include <stdio.h>
#include <math.h>
#define math_min(a, b) a < b ? a : b
int n, min, arr[20][20], visited[20];
void dfs(int dpth, int idx) {
	if (dpth == n / 2) {
		int start = 0, link = 0;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (visited[i] && visited[j]) {
					start += arr[i][j];
					start += arr[j][i];
				}
				else if (!visited[i] && !visited[j]) {
					link += arr[i][j];
					link += arr[j][i];
				}
			}
		}
		min = math_min(min, abs(start - link));
		return;
	}
	for (int i = idx; i < n; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			dfs(dpth + 1, i + 1);
			visited[i] = 0;
		}
	}
}
main() {
	scanf("%d", &n);
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i][j]);
		}
	}
	min = 2147483647;
	dfs(0, 0);
	printf("%d", min);
}