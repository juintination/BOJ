#include <stdio.h>
char star[2187][2187];
char point(int n, int x, int y) {
	if (n == 3) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				star[x + i][y + j] = '*';
				if ((n - i) % 3 == 2 && (n - j) % 3 == 2) {
					star[x + i][y + j] = ' ';
				}
			}
		}
	}
	else {
		//f(9)�� f(3)�� 3ĭ�� �о ����, f(27)�� f(9)�� 9ĭ�� �о ����
		for (int i = 0; i < n; i = i + 3 * (n / 9)) {
			for (int j = 0; j < n; j = j + 3 * (n / 9)) {
				point(n / 3, x + i, y + j);
				//�Ʒ� ��Ģ�� ã�µ� �� ���� �ɷȴ�
				if (i >= n / 3 && j >= n / 3 && i <= n / 3 * 2 - 1 && j <= n / 3 * 2 - 1) {
					for (int k = n / 3; k <= n / 3 * 2 - 1; k++) {
						for (int l = n / 3; l <= n / 3 * 2 - 1; l++) {
							star[x + k][y + l] = ' ';
						}
					}
				}
			}
		}
	}
}

main() {
	int n;
	scanf("%d", &n);
	point(n, 0, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%c", star[i][j]);
		}
		printf("\n");
	}
}