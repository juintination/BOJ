#include <stdio.h>
#include <string.h>
#define math_max(a, b) a > b ? a : b
int n, k, max = 0, word[50];
void dfs(int dpth, int idx, int mask) {
	if (dpth == k - 5) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			int tmp = (word[i] | mask);
			if (tmp == mask) {
				cnt++;
			}
		}
		max = math_max(max, cnt);
		return;
	}
	for (int i = idx; i < 26; i++) {
		if ((mask & 1 << i) == 0) {
			dfs(dpth + 1, i + 1, mask | 1 << i);
		}
	}
}
main() {
	scanf("%d %d", &n, &k);
	int mask = 0;
	char init[5] = "antic";
	for (int i = 0; i < 5; i++) {
		mask |= 1 << (init[i] - 'a');
	}
	char* str = (char*)malloc(sizeof(char) * 15);
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		int bit = mask;
		for (int j = 4; j < strlen(str) - 4; j++) {
			bit |= 1 << (str[j] - 'a');
		}
		word[i] = bit;
	}
	if (k < 5) {
		printf("0");
	}
	else if (k == 26) {
		printf("%d", n);
	}
	else {
		dfs(0, 0, mask);
		printf("%d", max);
	}
}