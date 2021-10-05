#include <stdio.h>
main() {
	int t, n;
	scanf("%d", &t);
	double* result = (double*)malloc(sizeof(double) * t);
	for (int i = 0; i < t; i++) {
		int score[1000];
		double sum = 0, cnt = 0;
		scanf("%d", &n);
		for (int j = 0; j < n; j++) {
			scanf("%d", &score[j]);
			sum += score[j];
		}
		double avg = (sum / n);
		for (int k = 0; k < n; k++) {
			if (score[k] > avg) {
				cnt++;
			}
		}
		result[i] = ((cnt / n) * 100);
	}
	for (int i = 0; i < t; i++) {
		printf("%.3lf%%\n", result[i]);
	}
}