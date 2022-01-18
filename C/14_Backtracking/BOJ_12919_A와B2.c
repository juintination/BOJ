#include <stdio.h>
#include <string.h>
char s[1001], t[1001];
void dfs(char* t) {
	if (strlen(t) == strlen(s)) {
		if (strcmp(t, s) == 0) {
			printf("1");
			exit(0);
		}
	}
	else if (strlen(t) == 0) return;
	char* str = (char*)malloc(sizeof(char) * strlen(t));
	strcpy(str, t);
	if (t[0] == 'B') {
		char* tmp = (char*)malloc(sizeof(char) * strlen(t));
		for (int i = 0; i < strlen(t); i++) {
			tmp[i] = t[strlen(t) - 1 - i];
		}
		for (int i = 0; i < strlen(t); i++) {
			t[i] = tmp[i];
		}
		t[strlen(t) - 1] = 0;
		dfs(t);
	}
	strcpy(t, str);
	if (t[strlen(t) - 1] == 'A') {
		t[strlen(t) - 1] = 0;
		dfs(t);
	}
}
main() {
	scanf("%s", s);
	getchar();
	scanf("%s", t);
	dfs(t);
	printf("0");
}