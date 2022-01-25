#include <stdio.h>
main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int* a = (int*)malloc(sizeof(int) * n);
	int* b = (int*)malloc(sizeof(int) * m);
	int* arr = (int*)malloc(sizeof(int) * (n + m));
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &b[i]);
	}
	int i = 0, j = 0, cnt = 0;
	while (i < n && j < m) {
		if (a[i] < b[j]) {
			arr[cnt++] = a[i++];
		}
		else {
			arr[cnt++] = b[j++];
		}
	}
	while (i < n) arr[cnt++] = a[i++];
	while (j < m) arr[cnt++] = b[j++];
	for (int i = 0; i < cnt; i++) {
		printf("%d ", arr[i]);
	}
}