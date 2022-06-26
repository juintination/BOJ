#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	char str[501];
} data;
int compare(const void* a, const void* b) {
	data o1 = *(data*)a;
	data o2 = *(data*)b;
	return strcmp(o1.str, o2.str);
}
main() {
	int n, m, cnt = 0;
	char str[501];
	scanf("%d %d", &n, &m);
	data* s = (data*)malloc(sizeof(data) * n);
	for (int i = 0; i < n; i++) {
		scanf("%s", s[i].str);
	}
	qsort(s, n, sizeof(data), compare);
	while (m--) {
		scanf("%s", str);
		if (bsearch(str, s, n, sizeof(data), compare)) {
			cnt++;
		}
	}
	printf("%d", cnt);
}