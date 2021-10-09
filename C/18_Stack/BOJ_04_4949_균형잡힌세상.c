#include <stdio.h>
#include <string.h>
int top = -1;
void push(char a, char* stack) {
	stack[++top] = a;
}
void pop(char* stack) {
	stack[top--] = 0;
}
main() {
	while (1) {
		char str[101], stack[101];
		int tst = 0;
		top = -1;
		gets(str); //scanf("%[^\n]s", str)를 사용해봤는데 오류가 난다
		if (str[0] == '.' && strlen(str) == 1) break;
		for (int j = 0; j < strlen(str); j++) {
			if (str[j] == '(' || str[j] == '[') push(str[j], stack);
			else if (str[j] == ')') {
				if (top == -1 || stack[top] == '[') {
					tst = 1;
					break;
				}
				else if (stack[top] == '(') pop(stack);
			}
			else if (str[j] == ']') {
				if (top == -1 || stack[top] == '(') {
					tst = 1;
					break;
				}
				else if (stack[top] == '[') pop(stack);
			}
		}
		if (tst == 0 && top == -1) printf("yes\n");
		else printf("no\n");
	}
}