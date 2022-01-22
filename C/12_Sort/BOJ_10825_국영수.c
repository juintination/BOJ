#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	char name[10];
	int k, e, m;
} student;
int compare(const void* a, const void* b) {
	student o1 = *(student*)a;
	student o2 = *(student*)b;
	if (o1.k != o2.k) {
		return o2.k - o1.k;
	}
	else {
		if (o1.e != o2.e) {
			return o1.e - o2.e;
		}
		else {
			if (o1.m != o2.m) {
				return o2.m - o1.m;
			}
			else {
				return strcmp(o1.name, o2.name);
			}
		}
	}
}
main() {
	int n;
	scanf("%d", &n);
	student* arr = (student*)malloc(sizeof(student) * n);
	for (int i = 0; i < n; i++) {
		scanf("%s %d %d %d", arr[i].name, &arr[i].k, &arr[i].e, &arr[i].m);
	}
	qsort(arr, n, sizeof(student), compare);
	for (int i = 0; i < n; i++) {
		printf("%s\n", arr[i].name);
	}
}