#include <stdio.h>
int n, arr[10];
char sign[11][11];
int check(int dpth) {
	int sum = 0;
	for (int i = dpth; i >= 0; i--) {
		sum += arr[i];
		if (sign[i][dpth] == '+' && sum <= 0) {
			return 0;
		}
		else if (sign[i][dpth] == '-' && sum >= 0) {
			return 0;
		}
		if (sign[i][dpth] == '0' && sum != 0) {
			return 0;
		}
	}
	return 1;
}
void dfs(int dpth) {
	if (dpth == n) {
		for (int i = 0; i < n; i++) {
			printf("%d ", arr[i]);
		}
		exit(0);
	}
	for (int i = 0; i <= 20; i++) {
		arr[dpth] = i - 10;
		if (check(dpth)) {
			dfs(dpth + 1);
		}
		arr[dpth] = 0;
	}
}
main() {
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			scanf("%c", &sign[i][j]);
		}
	}
	dfs(0);
}