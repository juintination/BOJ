#include <stdio.h>
void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
main() {
	int n;
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	int i = n - 1;
	while (1) {
		if (i == 0 || arr[i - 1] < arr[i]) break;
		i--;
	}
	if (i == 0) {
		printf("-1");
		return 0;
	}
	int j = n - 1;
	while (1) {
		if (arr[i - 1] < arr[j]) break;
		j--;
	}
	swap(&arr[i - 1], &arr[j]);
	int k = n - 1;
	while (i < k) {
		swap(&arr[i], &arr[k]);
		i++;
		k--;
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}