#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	char str[1001];
} element;
int compare(const void* a, const void* b) {
	element o1 = *(element*)a;
	element o2 = *(element*)b;
	return strcmp(o1.str, o2.str);
}
main() {
	element s;
	scanf("%s", s.str);
	int len = strlen(s.str), cnt = 0;
	element* set = (element*)malloc(sizeof(element) * len);
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len - i; j++) {
			memset(set[j].str, 0, sizeof(element));
			strncat(set[j].str, s.str + j, i + 1);
		}
		qsort(set, len - i, sizeof(element), compare);
		cnt++;
		for (int j = 1; j < len - i; j++) {
			if (strcmp(set[j - 1].str, set[j].str) != 0) {
				cnt++;
			}
		}
	}
	printf("%d", cnt);
}