#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char str[100000];
int compare(const void* a, const void* b) {
	int o1 = *(int*)a;
	int o2 = *(int*)b;
	return o1 - o2;
}
main() {
	scanf("%s", str);
	int n = strlen(str);
	int* arr = (int*)malloc(sizeof(int) * n);
	int tst = 0, sum = 0;
	for (int i = 0; i < n; i++) {
		arr[i] = str[i] - '0';
		if (arr[i] == 0) {
			tst = 1;
		}
		sum += arr[i];
	}
	if (sum % 3 != 0) {
		tst = 0;
	}
	if (tst) {
		qsort(arr, n, sizeof(int), compare);
		for (int i = n - 1; i >= 0; i--) {
			printf("%d", arr[i]);
		}
	}
	else {
		printf("-1");
	}
}