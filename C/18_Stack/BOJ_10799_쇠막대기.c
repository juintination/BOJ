#include <stdio.h>
#include <string.h>
int stack[100000];
int idx = -1;
void push(int value) {
	stack[++idx] = value;
}
int pop() {
	if (idx < 0) return -1;
	else return stack[idx--];
}
int size() {
	return idx + 1;
}
main() {
	int sum = 0;
	char str[100001];
	scanf("%s", str);
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == '(') {
			if (str[i + 1] == ')') {
				sum += size();
				i++;
			}
			else push(1);
		}
		else {
			sum++;
			pop();
		}
	}
	printf("%d", sum);
}