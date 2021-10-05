#include <stdio.h>
#include <string.h>
main() {
	char s[21];
	int t, r;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &r);
		scanf("%s", &s);
		for (int j = 0; j < strlen(s); j++) {
			for (int k = 0; k < r; k++) {
				printf("%c", s[j]);
			}
		}
		printf("\n");
	}
}