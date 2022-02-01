#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int compare(const void* a, const void* b) {
	int o1 = *(int*)a;
	int o2 = *(int*)b;
	return o1 - o2;
}
main() {
	int n;
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	qsort(arr, n, sizeof(int), compare);
	int d = arr[1] - arr[0];
	for (int i = 2; i < n; i++) {
		d = gcd(d, arr[i] - arr[i - 1]);
	}
	int* list = (int*)malloc(sizeof(int) * (2 * sqrt(d) + 1));
	int cnt = 0;
	for (int i = 2; i <= sqrt(d); i++) {
		if (pow(i, 2) == d) {
			list[cnt++] = i;
		}
		else if (d % i == 0) {
			list[cnt++] = i;
			list[cnt++] = d / i;
		}
	}
	list[cnt++] = d;
	qsort(list, cnt, sizeof(int), compare);
	for (int i = 0; i < cnt; i++) {
		printf("%d ", list[i]);
	}
}