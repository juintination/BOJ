#include <stdio.h>
#include <string.h>
main() {
	char arr[101];
	int result[26];
	scanf("%s", &arr);
	for (int n = 0; n < 26; n++) {
		result[n] = -1;
	}
	for (int a = 0; a < 26; a++) {
		for (int i = 0; i < strlen(arr); i++) {
			if (97 + a == arr[i]) {
				result[a] = result[a] + i + 1;
				break;
			}
		}
	}
	for (int i = 0; i < 26; i++) {
		printf("%d ", result[i]);
	}
}