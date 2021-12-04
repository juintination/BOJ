#include <stdio.h>
#define math_max(a, b) a > b ? a : b
int n, m, max = 0, arr[4][4], visited[4][4];
void dfs(int dpth, int idx) {
	if (dpth == n) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			int tmp = 0;
			for (int j = 0; j < m; j++) {
				if (visited[i][j]) {
					tmp = tmp * 10 + arr[i][j];
				}
				else {
					sum += tmp;
					tmp = 0;
				}
			}
			sum += tmp;
		}
		for (int i = 0; i < m; i++) {
			int tmp = 0;
			for (int j = 0; j < n; j++) {
				if (!visited[j][i]) {
					tmp = tmp * 10 + arr[j][i];
				}
				else {
					sum += tmp;
					tmp = 0;
				}
			}
			sum += tmp;
		}
		max = math_max(max, sum);
		return;
	}
	if (idx == m) {
		dfs(dpth + 1, 0);
		return;
	}
	dfs(dpth, idx + 1);
	visited[dpth][idx] = 1;
	dfs(dpth, idx + 1);
	visited[dpth][idx] = 0;
}
main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		char str[5];
		scanf("%s", str);
		for (int j = 0; j < m; j++) {
			arr[i][j] = str[j] - '0';
		}
	}
	dfs(0, 0);
	printf("%d", max);
}