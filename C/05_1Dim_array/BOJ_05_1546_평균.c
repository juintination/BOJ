#include <stdio.h>
main() {
	int n, score[1000];
	double sum = 0;
	scanf("%d", &n);
	int max = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &score[i]);
		if (score[i] > max) {
			max = score[i];
		}
	}
	for (int j = 0; j < n; j++) {
		sum += (double)score[j] / max * 100;
	}
	printf("%lf\n", sum / n);
}