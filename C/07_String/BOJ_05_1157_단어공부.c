#include <stdio.h>
//#include <string.h>
char str[1000000];
main() {
	int cnt[26] = { 0 };
	scanf("%s", str);
	//i < strlen(a)를 사용했지만 시간초과로 오답처리돼서 str[i] != NULL로 변경했다
	for (int i = 0; str[i] != NULL; i++) {
		if (str[i] >= 97) {
			str[i] -= 32;
			cnt[str[i] - 65]++;
		}
		else cnt[str[i] - 65]++;
	}
	int tmp, max = 0;
	for (int i = 0; i < 26; i++) {
		if (cnt[i] > max) {
			max = cnt[i];
			tmp = i;
		}
	}
	int tst = 0;
	for (int i = 0; i < 26; i++) {
		if (max == cnt[i]) tst++;
	}
	if (tst > 1)printf("?");
	else printf("%c", tmp + 65);
}