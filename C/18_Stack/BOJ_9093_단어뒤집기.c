#include <stdio.h>
#include <string.h>
char stack[1001];
int idx = -1;
void push(char value) {
	stack[++idx] = value;
}
char pop() {
	return stack[idx--];
}
main() {
	int n;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		char str[1001];
		int j = 0, cnt = 0;
		while ((str[j] = getchar()) != '\n') {
			if (str[j] == ' ') {
				if (cnt == 0) {
					while (idx != -1) {
						printf("%c", pop());
					}
					printf(" ");
				}
				else {
					while (idx != -1) {
						printf("%c", pop());
					}
				}
				cnt++;
			}
			push(str[j]);
			j++;
		}
		while (idx != -1) {
			printf("%c", pop());
		}
		printf("\n");
	}
}