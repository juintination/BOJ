#include <stdio.h>
#define math_max(a, b) a > b ? a : b
main() {
	int n, m, max = 0, arr[4][4];
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		char str[5];
		scanf("%s", str);
		for (int j = 0; j < m; j++) {
			arr[i][j] = str[j] - '0';
		}
	}
	for (int i = 0; i < (1 << n * m); i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			int tmp = 0;
			for (int k = 0; k < m; k++) {
				int l = j * m + k;
				if ((i & (1 << l)) == 0) {
					tmp = tmp * 10 + arr[j][k];
				}
				else {
					sum += tmp;
					tmp = 0;
				}
			}
			sum += tmp;
		}
		for (int j = 0; j < m; j++) {
			int tmp = 0;
			for (int k = 0; k < n; k++) {
				int l = j + m * k;
				if ((i & (1 << l)) != 0) {
					tmp = tmp * 10 + arr[k][j];
				}
				else {
					sum += tmp;
					tmp = 0;
				}
			}
			sum += tmp;
			max = math_max(max, sum);
		}
	}
	printf("%d", max);
}