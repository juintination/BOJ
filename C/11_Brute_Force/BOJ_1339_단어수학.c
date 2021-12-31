#include <stdio.h>
#include <string.h>
#include <math.h>
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
	int n, alph[26] = { 0 };
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char arr[10];
		scanf("%s", arr);
		int len = strlen(arr);
		int pos = (int)pow(10, len - 1);
		for (int j = 0; j < len; j++) {
			alph[arr[j] - 'A'] += pos;
			pos /= 10;
		}
	}
	quickSort(alph, 0, 25);
	int sum = 0;
	for (int i = 1; i <= 10; i++) {
		sum += alph[26 - i] * (10 - i);
	}
	printf("%d", sum);
}