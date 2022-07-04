#include <stdio.h>
#include <stdlib.h>
int compare(const void* a, const void* b) {
	int o1 = *(int*)a;
	int o2 = *(int*)b;
	if (o1 > o2) return 1;
	else if (o1 < o2) return -1;
	else return 0;
}
main() {
	int n, m, o;
	scanf("%d %d", &n, &m);
	int cnt = n;
	int* set = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &set[i]);
	}
	qsort(set, n, sizeof(int), compare);
	while (m--) {
		scanf("%d", &o);
		if (bsearch(&o, set, n, sizeof(n), compare)) {
			cnt--;
		}
		else cnt++;
	}
	printf("%d", cnt);
}