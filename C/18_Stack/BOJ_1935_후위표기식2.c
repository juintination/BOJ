#include <stdio.h>
#include <string.h>
double stack[100];
int idx = -1;
void push(double value) {
	stack[++idx] = value;
}
double pop() {
	double re = stack[idx];
	stack[idx--] = 0;
	return re;
}
main() {
	int n, cnt = -1;
	char str[101];
	scanf("%d", &n);
	int* value = (int*)malloc(sizeof(int) * n);
	scanf("%s", str);
	for (int i = 0; i < n; i++) {
		scanf("%d", &value[i]);
	}
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] >= 65 && str[i] <= 90) {
			push(value[str[i] - 65]);
		}
		else if (str[i] == '+') {
			double b = pop();
			double a = pop();
			push(a + b);
		}
		else if (str[i] == '-') {
			double b = pop();
			double a = pop();
			push(a - b);
		}
		else if (str[i] == '*') {
			double b = pop();
			double a = pop();
			push(a * b);
		}
		else if (str[i] == '/') {
			double b = pop();
			double a = pop();
			push(a / b);
		}
	}
	printf("%.2lf", pop());
}