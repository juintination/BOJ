#include <stdio.h>
int n, s, cnt = 0, arr[20], visited[20];
void dfs(int dpth, int sum) {
	if (dpth == n) {
		if (sum == s) {
			int tst = 0;
			for (int i = 0; i < n; i++) {
				if (visited[i]) {
					tst = 1;
					break;
				}
			}
			if (tst) {
				cnt++;
			}
		}
		return;
	}
	if (!visited[dpth]) {
		dfs(dpth + 1, sum);
		visited[dpth] = 1;
		dfs(dpth + 1, sum + arr[dpth]);
		visited[dpth] = 0;
	}
}
main() {
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	dfs(0, 0);
	printf("%d", cnt);
}