#include <stdio.h>
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
main() {
	int arr[9], sum = 0;
	for (int i = 0; i < 9; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	int tst = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			int tmp = arr[i] + arr[j];
			if (sum - tmp == 100) {
				arr[i] = arr[j] = 0;
				tst = !tst;
				break;
			}
		}
		if (tst == 1) break;
	}
	quickSort(arr, 0, 8);
	for (int i = 2; i < 9; i++) {
		printf("%d\n", arr[i]);
	}
}