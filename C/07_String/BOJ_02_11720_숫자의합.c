#include <stdio.h>
main() {
	int n, sum = 0;
	char arr[100];
	scanf("%d", &n);
	scanf("%s", &arr);
	for (int i = 0; i < n; i++) {
		sum += arr[i] - '0';
	}
	printf("%d\n", sum);
}