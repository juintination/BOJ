#include <stdio.h>
#include <string.h>
#define math_max(a, b) a > b ? a : b
int dp[1002][1002];
char str1[1001], str2[1001];
main() {
	scanf("%s", str1);
	getchar();
	scanf("%s", str2);
	for (int i = 1; i <= strlen(str1); i++) {
		for (int j = 1; j <= strlen(str2); j++) {
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = math_max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	printf("%d", dp[strlen(str1)][strlen(str2)]);
}