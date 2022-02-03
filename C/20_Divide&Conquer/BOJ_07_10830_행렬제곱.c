#include <stdio.h>
#include <stdlib.h>
const int mod = 1000;
int n, **arr;
long long int b;
int** multiply(int** o1, int** o2) {
	int** tmp = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		tmp[i] = (int*)malloc(sizeof(int) * n);
		for (int j = 0; j < n; j++) {
			tmp[i][j] = 0;
			for (int k = 0; k < n; k++) {
				tmp[i][j] += o1[i][k] * o2[k][j];
				tmp[i][j] %= mod;
			}
		}
	}
	return tmp;
}
int** cal(int** mat, long long int exp) {
	if (exp == 1) {
		return arr;
	}
	int** tmp = cal(mat, exp / 2);
	tmp = multiply(tmp, tmp);
	if (exp % 2 == 1) {
		tmp = multiply(tmp, arr);
	}
	return tmp;
}
main() {
	scanf("%d %lld", &n, &b);
	arr = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = (int*)malloc(sizeof(int) * n);
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
			arr[i][j] %= mod;
		}
	}
	arr = cal(arr, b);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}