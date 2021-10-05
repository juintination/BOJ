#include <stdio.h>
void quickSort(int arrx[], int arry[], int left, int right) {
	int i = left, j = right, pivot = arry[(left + right) / 2], temp;
	//arrx로 하면 계속 원위치돼서 무한루프가 된다
	do {
		while (arry[i] < pivot) i++;
		while (arry[j] > pivot) j--;
		if (i <= j) {
			temp = arrx[i];
			arrx[i] = arrx[j];
			arrx[j] = temp;
			temp = arry[i];
			arry[i] = arry[j];
			arry[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);
	if (left < j) quickSort(arrx, arry, left, j);
	if (i < right) quickSort(arrx, arry, i, right);
}
main() {
	int x[100000], y[100000], n, tmp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d %d", &x[i], &y[i]);
	quickSort(x, y, 0, n - 1);
	while (1) {
		int cnt = 0;
		for (int i = 0; i < n - 1; i++) {
			if (y[i] == y[i + 1]) {
				if (x[i] > x[i + 1]) {
					tmp = x[i + 1];
					x[i + 1] = x[i];
					x[i] = tmp;
					cnt++;
				}
			}
		}
		if (cnt == 0) break;
	}
	for (int i = 0; i < n; i++) printf("%d %d\n", x[i], y[i]);
}