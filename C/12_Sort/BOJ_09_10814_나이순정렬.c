#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int age;
	char name[101];
}people;
int compare(const void* p1, const void* p2) {
	if (((people*)p1)->age != ((people*)p2)->age) return ((people*)p1)->age - ((people*)p2)->age;
	else return ((people*)p1)->name - ((people*)p2)->name;
}
main() {
	int n;
	scanf("%d", &n);
	people* p = (people*)malloc(sizeof(people) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d %s", &p[i].age, p[i].name);
	}
	qsort(p, n, sizeof(people), compare);
	for (int i = 0; i < n; i++) {
		printf("%d %s\n", p[i].age, p[i].name);
	}
}