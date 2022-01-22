#include <stdio.h>
#include <stdlib.h>
int compare(const void* a, const void* b) {
	long long int o1 = *(long long int*)a;
	long long int o2 = *(long long int*)b;
	if (o1 > o2) return 1;
	else if (o1 == o2) return 0;
	else return -1;
}
main() {
	int n;
	scanf("%d", &n);
	long long int* arr = (long long int*)malloc(sizeof(long long int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}
	qsort(arr, n, sizeof(long long int), compare);
	int cnt = 1, max = 1;
	long long int result = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] == arr[i - 1]) cnt++;
		else cnt = 1;
		if (cnt > max) {
			max = cnt;
			result = arr[i];
		}
	}
	printf("%lld", result);
}