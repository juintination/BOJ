#include <stdio.h>
#include <string.h>
main() {
	char word[16];
	int time = 0;
	scanf("%s", &word);
	for (int i = 0; i < strlen(word); i++) {
		if (word[i] >= 65 && word[i] <= 79) {
			time += ((word[i] - 65) / 3 + 3);
		}
		else if (word[i] >= 80 && word[i] <= 83) {
			time = time + 8;
		}
		else if (word[i] >= 84 && word[i] <= 86) {
			time = time + 9;
		}
		else if (word[i] >= 87 && word[i] <= 90) {
			time = time + 10;
		}
	}
	printf("%d\n", time);
}