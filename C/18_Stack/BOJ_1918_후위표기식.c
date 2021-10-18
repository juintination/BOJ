#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char stack[100];
int idx = -1;
void push(char value) {
	stack[++idx] = value;
}
char pop() {
	if (idx < 0) return -1;
	else return stack[idx--];
}
int size() {
	return idx + 1;
}
int empty() {
	if (size() == 0) return 1;
	else return 0;
}
char top() {
	if (empty()) {
		return 0;
	}
	else {
		return stack[idx];
	}
}
int comp(char c) {
	if (c == '(') return -1;
	else if (c == '+' || c == '-') return 0;
	else return 1;
}
main() {
	int cnt = 0;
	char str[101];
	scanf("%s", str);
	char* result = (char*)malloc(sizeof(char) * strlen(str));
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			result[cnt++] = str[i];
		}
		else if (str[i] == '(') {
			push(str[i]);
		}
		else if (str[i] == ')') {
			while (top() != '(') {
				result[cnt++] = pop();
			}
			pop();
		}
		else {
			while (!empty() && comp(top()) >= comp(str[i])) {
				result[cnt++] = pop();
			}
			push(str[i]);
		}
	}
	while (!empty()) {
		result[cnt++] = pop();
	}
	for (int i = 0; i < cnt; i++) {
		printf("%c", result[i]);
	}
}