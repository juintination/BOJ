#include <stdio.h>
main() {
	int t, cnt = 0;
	scanf("%d", &t);
	int* result = (int*)malloc(sizeof(int) * t);
	while (t--) {
		int h, w, n, H = 1, W = 1;
		scanf("%d %d %d", &h, &w, &n);
		while (1) {
			if (n > h) {
				W++;
				n -= h;
			}
			else {
				while (n != 0) {
					n--;
					H++;
				}
				result[cnt++] = (H - 1) * 100 + W;
				break;
			}
		}
	}
	for (int i = 0; i < cnt; i++) {
		printf("%d\n", result[i]);
	}
}