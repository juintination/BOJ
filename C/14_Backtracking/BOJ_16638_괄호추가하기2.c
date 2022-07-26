#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define math_max(a, b) a > b ? a : b
int n, max = INT_MIN, * number, op_size = 0, num_size = 0;
char* operator;
int prec(char op) {
	if (op == '(') return -1;
	else if (op == '+' || op == '-') return 0;
	else return 1;
}
int cal(int n1, char op, int n2) {
	if (op == '+') return n1 + n2;
	else if (op == '-') return n1 - n2;
	else return n1 * n2;
}
int getResult(char str[]) {
	int len = strlen(str), idxNum = -1, idxOp = -1;
	int* stackNum = (int*)malloc(sizeof(int) * len);
	char* stackOp = (char*)malloc(sizeof(char) * len);
	for (int i = 0; i < len; i++) {
		char c = str[i];
		if ('0' <= c && c <= '9') {
			stackNum[++idxNum] = c - '0';
		}
		else if (c == '(') {
			stackOp[++idxOp] = c;
		}
		else if (c == ')') {
			while (stackOp[idxOp] != '(') {
				int n2 = stackNum[idxNum--], n1 = stackNum[idxNum--];
				stackNum[++idxNum] = cal(n1, stackOp[idxOp--], n2);
			}
			idxOp--;
		}
		else {
			while (idxOp >= 0 && prec(stackOp[idxOp]) >= prec(c)) {
				int n2 = stackNum[idxNum--], n1 = stackNum[idxNum--];
				stackNum[++idxNum] = cal(n1, stackOp[idxOp--], n2);
			}
			stackOp[++idxOp] = c;
		}
	}
	while (idxOp >= 0) {
		int n2 = stackNum[idxNum--], n1 = stackNum[idxNum--];
		stackNum[++idxNum] = cal(n1, stackOp[idxOp--], n2);
	}
	return stackNum[idxNum--];
}
void dfs(int dpth, char str[]) {
	int len = strlen(str);
	if (dpth == op_size) {
		if (str[len - 1] != ')') {
			char n = number[dpth] + '0';
			str[len++] = n;
		}
		int tmp = getResult(str);
		max = math_max(max, tmp);
		return;
	}
	char tmp[30];
	memset(tmp, 0, sizeof(tmp));
	strcpy(tmp, str);
	tmp[len++] = number[dpth] + '0';
	tmp[len++] = operator[dpth];
	dfs(dpth + 1, tmp);
	memset(tmp, 0, sizeof(tmp));
	strcpy(tmp, str);
	len = strlen(str);
	tmp[len++] = '(';
	tmp[len++] = number[dpth] + '0';
	tmp[len++] = operator[dpth];
	tmp[len++] = number[dpth + 1] + '0';
	tmp[len++] = ')';
	if (dpth + 1 < op_size) {
		tmp[len++] = operator[dpth + 1];
		dfs(dpth + 2, tmp);
	}
	else {
		dfs(dpth + 1, tmp);
	}
}
main() {
	scanf("%d", &n);
	number = (int*)malloc(sizeof(int) * (n / 2 + 1));
	operator = (char*)malloc(sizeof(char) * (n / 2));
	char* str = (char*)malloc(sizeof(char) * n);
	scanf("%s", str);
	if (n == 1) {
		printf("%s", str);
		exit(0);
	}
	for (int i = 0; i < n; i++) {
		char c = str[i];
		if (c == '+' || c == '-' || c == '*') {
			operator[op_size++] = c;
		}
		else {
			number[num_size++] = c - '0';
		}
	}
	char tmp[30];
	memset(tmp, 0, sizeof(tmp));
	dfs(0, tmp);
	printf("%d", max);
}