#include <stdio.h>
#include <stdlib.h>
#define math_max(a, b) a > b ? a : b
#define math_min(a, b) a < b ? a : b
int n, l, r, x, cnt = 0, *arr;
int compare(const void* a, const void* b) {
	int o1 = *(int*)a;
	int o2 = *(int*)b;
	if (o1 > o2) return 1;
	else if (o1 < o2) return -1;
	else return 0;
}
void dfs(int idx, int dpth, int min, int max, int sum) {
	if (dpth >= 2) {
		if (l <= sum && sum <= r && max - min >= x) {
			cnt++;
		}
	}
	for (int i = idx; i < n; i++) {
		int tmp_min = math_min(min, arr[i]), tmp_max = math_max(max, arr[i]);
		dfs(i + 1, dpth + 1, tmp_min, tmp_max, sum + arr[i]);
	}
}
main() {
	scanf("%d %d %d %d", &n, &l, &r, &x);
	arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	qsort(arr, n, sizeof(int), compare);
	dfs(0, 0, 1000000, 0, 0);
	printf("%d", cnt);
}