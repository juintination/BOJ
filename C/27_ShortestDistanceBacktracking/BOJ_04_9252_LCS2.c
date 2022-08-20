#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define math_max(a, b) a > b ? a : b
char* stack;
int stackIdx = -1;
void push(char value) {
	stack[++stackIdx] = value;
}
int is_empty() {
	if (stackIdx < 0) return 1;
	else return 0;
}
char pop() {
	return stack[stackIdx--];
}
main() {
	char str1[1001], str2[1001];
	scanf("%s %s", str1, str2);
	int x = strlen(str1), y = strlen(str2);
	int** dp = (int**)malloc(sizeof(int*) * (x + 1));
	for (int i = 0; i <= x; i++) {
		dp[i] = (int*)malloc(sizeof(int) * (y + 1));
		for (int j = 0; j <= y; j++) {
			dp[i][j] = 0;
		}
	}
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = math_max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	printf("%d\n", dp[x][y]);
	stack = (char*)malloc(sizeof(char) * dp[x][y]);
	while (x > 0 && y > 0) {
		if (dp[x][y] == dp[x - 1][y]) x--;
		else if (dp[x][y] == dp[x][y - 1]) y--;
		else {
			push(str1[x - 1]);
			x--;
			y--;
		}
	}
	while (!is_empty()) {
		printf("%c", pop());
	}
}