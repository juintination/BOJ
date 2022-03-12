#include <stdio.h>
#define math_min(a, b) a < b ? a : b
main() {
	int n, *arr, min = 2147483647;
	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	if (n == 1) {
		printf("0");
		exit(0);
	}
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			int cnt = 0;
			if (i != 0) {
				cnt++;
			}
			if (j != 0) {
				cnt++;
			}
			int a0 = arr[0] + i, a1 = arr[1] + j;
			int d = a0 - a1, cur = a1;
			int tst = 1;
			for (int k = 2; k < n; k++) {
				cur -= d;
				if (arr[k] == cur) {
					continue;
				}
				else if (arr[k] + 1 == cur || arr[k] - 1 == cur) {
					cnt++;
				}
				else {
					tst = !tst;
					break;
				}
			}
			if (tst) {
				min = math_min(min, cnt);
			}
		}
	}
	if (min == 2147483647) {
		printf("-1");
	}
	else {
		printf("%d", min);
	}
}