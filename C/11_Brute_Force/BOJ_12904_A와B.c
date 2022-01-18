#include <stdio.h>
#include <string.h>
main() {
	char s[1001], t[1001];
	scanf("%s", s);
	getchar();
	scanf("%s", t);
	while (strlen(t) > strlen(s)) {
		char c = t[strlen(t) - 1];
		t[strlen(t) - 1] = 0;
		if (c == 'B') {
			char* tmp = (char*)malloc(sizeof(char) * strlen(t));
			for (int i = 0; i < strlen(t); i++) {
				tmp[i] = t[strlen(t) - 1 - i];
			}
			for (int i = 0; i < strlen(t); i++) {
				t[i] = tmp[i];
			}
		}
	}
	if (strcmp(t, s) == 0) {
		printf("1");
	}
	else {
		printf("0");
	}
}