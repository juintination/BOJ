#include <stdio.h>
#define math_max(a, b) a > b ? a : b
int n, max = -2147483648, *number, op_size = 0, num_size = 0;
char* operator;
int cal(int n1, char op, int n2) {
	if (op == '+') return n1 + n2;
	else if (op == '-') return n1 - n2;
	else return n1 * n2;
}
void dfs(int dpth, int sum) {
	if (dpth == op_size) {
		max = math_max(max, sum);
		return;
	}
	int tmp1 = cal(sum, operator[dpth], number[dpth + 1]);
	dfs(dpth + 1, tmp1);
	if (dpth + 1 < op_size) {
		int tmp2 = cal(number[dpth + 1], operator[dpth + 1], number[dpth + 2]);
		tmp2 = cal(sum, operator[dpth], tmp2);
		dfs(dpth + 2, tmp2);
	}
}
main() {
	scanf("%d", &n);
	number = (int*)malloc(sizeof(int) * (n / 2 + 1));
	operator = (char*)malloc(sizeof(char) * (n / 2));
	char* str = (char*)malloc(sizeof(char) * n);
	scanf("%s", str);
	for (int i = 0; i < n; i++) {
		char c = str[i];
		if (c == '+' || c == '-' || c == '*') {
			operator[op_size++] = c;
		}
		else {
			number[num_size++] = c - '0';
		}
	}
	dfs(0, number[0]);
	printf("%d", max);
}