#include <stdio.h>
int n, m, arr[3], **mixed, cnt = 0;
void dfs(int dpth, int idx) {
	if (dpth == 3) {
		for (int i = 0; i < 3; i++) {
			if (mixed[arr[i]][arr[(i + 1) % 3]]) {
				return;
			}
		}
		cnt++;
		return;
	}
	for (int i = idx; i <= n; i++) {
		arr[dpth] = i;
		dfs(dpth + 1, i + 1);
	}
}
main() {
	scanf("%d %d", &n, &m);
	mixed = (int**)malloc(sizeof(int*) * (n + 1));
	for (int i = 0; i <= n; i++) {
		mixed[i] = (int*)malloc(sizeof(int) * (n + 1));
		for (int j = 0; j <= n; j++) {
			mixed[i][j] = 0;
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		mixed[x][y] = mixed[y][x] = 1;
	}
	dfs(0, 1);
	printf("%d", cnt);
}