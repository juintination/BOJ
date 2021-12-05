#include <stdio.h>
#include <math.h>
int n, cnt = 0, arr[15], visited[15];
void dfs(int dpth) {
	if (dpth == n) {
		cnt++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			arr[dpth] = i;
			visited[i] = 1;
			int tst = 0;
			for (int j = 1; j <= dpth; j++) {
				if (abs(arr[dpth] - arr[dpth - j]) == j) {
					tst = 1;
					break;
				}
			}
			if (tst == 0) dfs(dpth + 1);
			visited[i] = 0;
		}
	}
}
main() {
	scanf("%d", &n);
	dfs(0);
	printf("%d", cnt);
}