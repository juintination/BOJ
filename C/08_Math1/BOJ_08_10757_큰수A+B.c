#include <stdio.h>
#include <string.h>
#define math_max(a, b) a > b ? a : b
char a[10001], b[10001], result[10001];
void reverse(char* str) {
	int len = strlen(str) - 1;
	for (int i = 0; i < strlen(str) / 2; i++) {
		char tmp = str[i];
		str[i] = str[len - i];
		str[len - i] = tmp;
	}
}
main() {
	scanf("%s %s", a, b);
	reverse(a);
	reverse(b);
	int len = math_max(strlen(a), strlen(b)), ten = 0;
	for (int i = 0; i < len; i++) {
		int sum = a[i] - '0' + b[i] - '0' + ten;
		while (sum < 0) {
			sum += '0';
		}
		if (sum > 9) ten = 1;
		else ten = 0;
		result[i] = sum % 10 + '0';
	}
	if (ten == 1) result[len] = '1';
	reverse(result);
	printf("%s", result);
}