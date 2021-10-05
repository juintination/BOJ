#include <stdio.h>
main() {
	int n, xy[51][2] = { 0 }, cnt[51] = { 0 };
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			scanf("%d", &xy[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (xy[i][0] < xy[j][0]) {
				if (xy[i][1] < xy[j][1]) {
					cnt[i]++;
				}
			}
		}
		printf("%d ", cnt[i] + 1);
	}
}