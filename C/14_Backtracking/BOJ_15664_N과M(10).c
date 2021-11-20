#include <stdio.h>
int arr[8], visited[8], num[8], n, m;
void quickSort(int arr[], int left, int right) {
	int i = left, j = right, pivot = arr[(left + right) / 2], temp;
	do {
		while (arr[i] < pivot) i++;
		while (arr[j] > pivot) j--;
		if (i <= j) {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);
	if (left < j) quickSort(arr, left, j);
	if (i < right) quickSort(arr, i, right);
}
void dfs(int dpth) {
	if (dpth == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		if (visited[i] == 0 && tmp != num[i]) {
			if (dpth > 0 && arr[dpth - 1] > num[i]) continue;
			visited[i] = 1;
			arr[dpth] = num[i];
			tmp = arr[dpth];
			dfs(dpth + 1);
			visited[i] = 0;
		}
	}
}
main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	quickSort(num, 0, n - 1);
	dfs(0);
}