#include <stdio.h>
int a[500001], b[500001];
void mergeSort(int A[], int low, int high, int B[]) {
	if (low >= high) return;
	int mid = (low + high) / 2;
	mergeSort(A, low, mid, B);
	mergeSort(A, mid + 1, high, B);
	int i = low, j = mid + 1, k = low;
	for (k; k <= high; k++) {
		if (j > high) B[k] = A[i++];
		else if (i > mid) B[k] = A[j++];
		else if (A[i] <= A[j]) B[k] = A[i++];
		else B[k] = A[j++];
	}
	for (i = low; i <= high; i++) {
		A[i] = B[i];
	}
}
main() {
	int n, cnt[8001] = { 0 }, max = 0, frequent;
	double sum = 0;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		cnt[a[i] + 4000]++;
		sum = sum + a[i];
	}
	for (int i = 0; i < 8001; i++) {
		if (cnt[i] > max) {
			max = cnt[i];
			frequent = i;
		}
	}
	mergeSort(a, 0, n - 1, b);
	for (int j = 0; j < 8001; j++) {
		if (j != frequent) {
			if (cnt[j] == max) {
				frequent = j;
				break;
				//frequent의 값이 cnt[i]가 max인 값중에서 가장 작은 값이므로
				//위 조건에서 그 다음에 나오는 값이 두 번째로 큰 값이 된다
			}
		}
	}
	printf("%.0lf\n%d\n%d\n%d", sum / n, a[n / 2], frequent - 4000, a[n - 1] - a[0]);
}