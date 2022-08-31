#include <stdio.h>
#include <stdlib.h>
const int mod = 1000000007;
long long int** matrixMult(long long int** o1, long long int** o2) {
	long long int** mat = (long long int**)malloc(sizeof(long long int*) * 2);
	for (int i = 0; i < 2; i++) {
		mat[i] = (long long int*)malloc(sizeof(long long int) * 2);
		for (int j = 0; j < 2; j++) {
			mat[i][j] = 0;
			for (int k = 0; k < 2; k++) {
				mat[i][j] += o1[i][k] * o2[k][j];
				mat[i][j] %= mod;
			}
		}
	}
	return mat;
}
long long int** matrixPow(long long int** A, long long int exp) {
	if (exp == 1 || exp == 0) {
		return A;
	}
	long long int** mat = matrixPow(A, exp / 2);
	mat = matrixMult(mat, mat);
	if (exp % 2 == 1) {
		mat = matrixMult(mat, A);
	}
	return mat;
}
main() {
	long long int n;
	scanf("%lld", &n);
	long long int** A = (long long int**)malloc(sizeof(long long int*) * 2);
	for (int i = 0; i < 2; i++) {
		A[i] = (long long int*)malloc(sizeof(long long int) * 2);
		for (int j = 0; j < 2; j++) {
			A[i][j] = 1;
		}
	}
	A[1][1] = 0;
	printf("%lld", matrixPow(A, n - 1)[0][0]);
}