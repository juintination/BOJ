#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char str[1001];
int compare(int* a, int* b) {
	return strcmp(str + *a, str + *b);
}
main() {
	int tmp[1000];
	scanf("%s", str);
	for (int i = 0; i < strlen(str); i++) {
		tmp[i] = i;
	}
	qsort(tmp, strlen(str), sizeof(int), compare);
	for (int i = 0; i < strlen(str); i++) {
		printf("%s\n", str + tmp[i]);
	}
}