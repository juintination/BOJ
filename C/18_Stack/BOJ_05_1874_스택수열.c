#include <stdio.h>
#include <stdlib.h>
int stack[100001];
int idx = -1;
void push(int value) {
	stack[++idx] = value;
}
void pop() {
	stack[idx--] = 0;
}
int top() {
	return stack[idx];
}
main() {
	int n, num, cnt = 0, tst = 0;
	scanf("%d", &n);
	char* result = (char*)malloc(sizeof(char) * 2 * n);
	int j = 1;
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		if (num < top()) {
			tst++;
		}
		if (tst == 0) {
			while (1) {
				if (num != top()) {
					push(j++);
					result[cnt++] = '+';
				}
				else if (num == top()) {
					pop();
					result[cnt++] = '-';
					break;
				}
			}
		}
	}
	if (tst == 0) {
		for (int i = 0; i < cnt; i++) {
			printf("%c\n", result[i]);
		}
	}
	else printf("NO\n");
	free(result);
}