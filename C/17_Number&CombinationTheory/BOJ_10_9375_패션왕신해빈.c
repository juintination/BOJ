#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	char str[21];
	int cnt;
} cloth;
main() {
	int t, n, cnt = 0;
	char tmp[21], str[21];
	scanf("%d", &t);
	int* result = (int*)malloc(sizeof(int) * t);
	while (t--) {
		scanf("%d", &n);
		cloth* list = (cloth*)malloc(sizeof(cloth) * n);
		int idx = 0;
		for (int i = 0; i < n; i++) {
			scanf("%s %s", tmp, str);
			int j = 0;
			for (j; j < idx; j++) {
				if (strcmp(str, list[j].str) == 0) {
					break;
				}
			}
			if (j == idx) {
				idx++;
				list[j].cnt = 0;
				strcpy(list[j].str, str);
			}
			list[j].cnt++;
		}
		result[cnt] = 1;
		for (int i = 0; i < idx; i++) {
			result[cnt] *= (list[i].cnt + 1);
		}
		cnt++;
	}
	for (int i = 0; i < cnt; i++) {
		printf("%d\n", result[i] - 1);
	}
}