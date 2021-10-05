#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int num;
	int idx;
}strct;
int compare(const void* p1, const void* p2) {
	return ((strct*)p1)->num - ((strct*)p2)->num;
}
main() {
	int n;
	scanf("%d", &n);
	strct* e = (strct*)malloc(sizeof(strct) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &e[i].num);
		e[i].idx = i;
	}
	qsort(e, n, sizeof(strct), compare);
	int* output = (int*)malloc(sizeof(int) * n);
	int cnt = -1, min = -1000000001;
	for (int i = 0; i < n; i++) {
		if (e[i].num != min) cnt++;
		output[e[i].idx] = cnt;
		min = e[i].num;
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", output[i]);
	}
}