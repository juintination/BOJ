#include <stdio.h>
main() {
	char chess[51][51];
	int x, y, cnt = 0, cnt2, min = 64;
	scanf("%d %d", &x, &y);
	for (int i = 0; i < x; i++) {
		scanf("%s", &chess[i]);
	}
	for (int i = 0; i <= x - 8; i++) {
		for (int j = 0; j <= y - 8; j++) {
			if (chess[i][j] == 'W') {
				for (int k = 0; k < 8; k++) {
					for (int l = 0; l < 8; l++) {
						if (k % 2 != l % 2) {
							if (chess[i + k][j + l] != 'B') cnt++;
						}
						else if (k % 2 == l % 2) {
							if (chess[i + k][j + l] != 'W') cnt++;
						}
					}
				}
				cnt2 = 64 - cnt;
				if (cnt < cnt2) {
					if (cnt < min) min = cnt;
				}
				else {
					if (cnt2 < min) min = cnt2;
				}
				cnt = 0;
			}
			else if (chess[i][j] == 'B') {
				for (int k = 0; k < 8; k++) {
					for (int l = 0; l < 8; l++) {
						if (k % 2 != l % 2) {
							if (chess[i + k][j + l] != 'W') cnt++;
						}
						else if (k % 2 == l % 2) {
							if (chess[i + k][j + l] != 'B') cnt++;
						}
					}
				}
				cnt2 = 64 - cnt;
				if (cnt < cnt2) {
					if (cnt < min) min = cnt;
				}
				else {
					if (cnt2 < min) min = cnt2;
				}
				cnt = 0;
			}
		}
	}
	printf("%d", min);
}