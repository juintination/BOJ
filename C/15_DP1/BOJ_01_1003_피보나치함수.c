#include <stdio.h>
int f0[41], f1[41];
int fibo_0(int n) {
	if (f0[n] == -1) {
		f0[n] = fibo_0(n - 1) + fibo_0(n - 2);
	}
	return f0[n];
}
int fibo_1(int n) {
	if (f1[n] == -1) {
		f1[n] = fibo_1(n - 1) + fibo_1(n - 2);
	}
	return f1[n];
}
main() {
	int t, n, cnt = 0;
	for (int i = 0; i < 41; i++) {
		f0[i] = -1;
		f1[i] = -1;
	}
	f0[0] = 1;
	f0[1] = 0;
	f1[0] = 0;
	f1[1] = 1;
	scanf("%d", &t);
	int* result_0 = (int*)malloc(sizeof(int) * t);
	int* result_1 = (int*)malloc(sizeof(int) * t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		fibo_0(n);
		fibo_1(n);
		result_0[cnt] = f0[n];
		result_1[cnt++] = f1[n];
	}
	for (int i = 0; i < cnt; i++) {
		printf("%d %d\n", result_0[i], result_1[i]);
	}
}