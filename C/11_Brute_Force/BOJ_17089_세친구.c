#include <stdio.h>
#define math_min(a, b) a < b ? a : b
main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int* cnt = (int*)malloc(sizeof(int) * (n + 1));
	int** friended = (int**)malloc(sizeof(int*) * (n + 1));
	for (int i = 1; i <= n; i++) {
		friended[i] = (int*)malloc(sizeof(int) * (n + 1));
		for (int j = 1; j <= n; j++) {
			friended[i][j] = 0;
		}
		cnt[i] = -2;
	}
	while (m--) {
		int x, y;
		scanf("%d %d", &x, &y);
		friended[x][y] = friended[y][x] = 1;
		cnt[x]++;
		cnt[y]++;
	}
	int min = 2147483647;
	for (int i = 1; i <= n - 2; i++) {
		for (int j = i + 1; j <= n - 1; j++) {
			if (friended[i][j]) {
				for (int k = j + 1; k <= n; k++) {
					if (friended[j][k] && friended[k][i]) {
						int sum = cnt[i] + cnt[j] + cnt[k];
						min = math_min(min, sum);
					}
				}
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