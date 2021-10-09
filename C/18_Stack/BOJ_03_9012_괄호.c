#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int idx, sum;
int stack[50];
void push() {
	stack[++idx] = 1;
}
void erase() {
	sum -= stack[idx--];
}
void plus() {
	sum += stack[idx];
}
main() {
	int n;
	scanf("%d", &n);
	char str[51];
	int* result = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		sum = 0;
		idx = -1;
		if (strlen(str) % 2 == 0) { //글자 수가 짝수인 경우에만 아래 for문이 돌아가게 만들었다
			for (int j = 0; j < strlen(str); j++) {
				push();
				if (str[j] == '(') {
					plus();
				}
				else {
					erase();
					if (sum < 0) {
						result[i] = 0;
						break;
					}
				}
			}
			if (sum == 0) result[i] = 1;
			else if (sum > 0) result[i] = 0;
		}
		else result[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		if (result[i] == 1) {
			printf("YES\n");
		}
		else printf("NO\n");
	}
	free(result);
}