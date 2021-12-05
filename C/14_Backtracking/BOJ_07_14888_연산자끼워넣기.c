#include <stdio.h>
#define math_max(a, b) a > b ? a : b
#define math_min(a, b) a < b ? a : b
int n, max, min, arr[11], operator[4];
void dfs(int dpth, int result) {
	if (dpth == n) {
		max = math_max(max, result);
		min = math_min(min, result);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (operator[i] > 0) {
			operator[i]--;
			if (i == 0) {
				dfs(dpth + 1, result + arr[dpth]);
			}
			else if (i == 1) {
				dfs(dpth + 1, result - arr[dpth]);
			}
			else if (i == 2) {
				dfs(dpth + 1, result * arr[dpth]);
			}
			else {
				dfs(dpth + 1, result / arr[dpth]);
			}
			operator[i]++;
		}
	}
}
main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < 4; i++) {
		scanf("%d", &operator[i]);
	}
	max = -2147483648;
	min = 2147483647;
	dfs(1, arr[0]);
	printf("%d\n%d", max, min);
}