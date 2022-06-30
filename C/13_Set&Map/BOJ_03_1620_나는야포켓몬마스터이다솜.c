#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	char name[21];
	int num;
} poke;
int compare(const void* a, const void* b) {
	poke o1 = *(poke*)a;
	poke o2 = *(poke*)b;
	return strcmp(o1.name, o2.name);
}
int pokeSearch(poke* map, int n, char name[]) {
	int low = 0, high = n - 1;
	while (high >= low) {
		int mid = (low + high) / 2;
		if (strcmp(map[mid].name, name) == 0) return map[mid].num;
		else if (strcmp(map[mid].name, name) > 0) high = mid - 1;
		else low = mid + 1;
	}
	return -1;
}
main() {
	int n, m;
	scanf("%d %d", &n, &m);
	poke* map = (poke*)malloc(sizeof(poke) * n);
	poke* tmp = (poke*)malloc(sizeof(poke) * n);
	for (int i = 0; i < n; i++) {
		scanf("%s", map[i].name);
		map[i].num = i + 1;
		tmp[i] = map[i];
	}
	qsort(tmp, n, sizeof(poke), compare);
	poke* list = (poke*)malloc(sizeof(poke) * m);
	for (int i = 0; i < m; i++) {
		char find[21];
		scanf("%s", find);
		if ('0' <= find[0] && find[0] <= '9') {
			int num = atoi(find) - 1;
			strcpy(list[i].name, map[num].name);
			list[i].num = -1;
		}
		else {
			memset(list[i].name, 0, sizeof(map[i].name));
			list[i].num = pokeSearch(tmp, n, find);
		}
	}
	for (int i = 0; i < m; i++) {
		if (list[i].num == -1) printf("%s\n", list[i].name);
		else printf("%d\n", list[i].num);
	}
}