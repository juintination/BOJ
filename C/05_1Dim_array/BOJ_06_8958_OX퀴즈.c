#include <stdio.h>
main() {
	int n, cnt, score;
	char answer[80];
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		cnt = 0;
		score = 0;
		int j = 0;
		while (1) {
			scanf("%c", &answer[j]);
			if (answer[j] == 'O') {
				cnt++;
				score += cnt;
			}
			else if (answer[j] == 'X') {
				cnt = 0;
			}
			else break;
			j++;
		}
		printf("%d\n", score);
	}
}