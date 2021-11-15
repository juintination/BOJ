#include <stdio.h>
main() {
	int E, S, M, esm[3] = { 1, 1, 1 }, cnt = 1;
	scanf("%d %d %d", &E, &S, &M);
	while (1) {
		if (E == esm[0] && S == esm[1] && M == esm[2]) {
			printf("%d", cnt);
			break;
		}
		for (int i = 0; i < 3; i++) {
			esm[i]++;
		}
		cnt++;
		if (esm[0] == 16) esm[0] = 1;
		if (esm[1] == 29) esm[1] = 1;
		if (esm[2] == 20) esm[2] = 1;
	}
}