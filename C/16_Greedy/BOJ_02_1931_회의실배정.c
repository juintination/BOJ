#include <stdio.h>
#include <stdlib.h>
int n, time[100000][2];
int compare(const void* a, const void* b) {
	int* o1 = (int*)a;
	int* o2 = (int*)b;
	if (o1[1] == o2[1]) {
		return o1[0] - o2[0];
	}
	return o1[1] - o2[1];
}
main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			scanf("%d", &time[i][j]);
		}
	}
	qsort(time, n, sizeof(int) * 2, compare);
	int cnt = 0, end = 0;
	for (int i = 0; i < n; i++) {
		if (end <= time[i][0]) {
			end = time[i][1];
			cnt++;
		}
	}
	printf("%d", cnt);
}