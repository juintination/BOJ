#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	char name[21];
} element;
int compare(const void* a, const void* b) {
	element o1 = *(element*)a;
	element o2 = *(element*)b;
	return strcmp(o1.name, o2.name);
}
main() {
	int n, m, cnt = 0;
	scanf("%d %d", &n, &m);
	element* hear = (element*)malloc(sizeof(element) * n);
	for (int i = 0; i < n; i++) {
		scanf("%s", hear[i].name);
	}
	qsort(hear, n, sizeof(element), compare);
	element* list = (element*)malloc(sizeof(element));
	for (int i = 0; i < m; i++) {
		element see;
		scanf("%s", see.name);
		if (bsearch(see.name, hear, n, sizeof(element), compare)) {
			list = (element*)realloc(list, sizeof(element) * (cnt + 1));
			list[cnt++] = see;
		}
	}
	printf("%d\n", cnt);
	qsort(list, cnt, sizeof(element), compare);
	for (int i = 0; i < cnt; i++) {
		printf("%s\n", list[i].name);
	}
}