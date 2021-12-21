#include <stdio.h>
#include <stdlib.h>
int v, e, tst, ** arr, * visited, * checked, * cnt;
void dfs(int idx, int side) {
	if (!tst) return;
	visited[idx] = 1;
	checked[idx] = side;
	for (int i = 0; i < cnt[idx]; i++) {
		int tmp = arr[idx][i];
		if (!visited[tmp]) {
			dfs(tmp, !side);
		}
		else if (checked[tmp] == side) {
			tst = 0;
			return;
		}
	}
}
main() {
	int k, idx = 0;
	scanf("%d", &k);
	int* result = (int*)malloc(sizeof(int) * k);
	while (k--) {
		int* xi, * yi;
		scanf("%d %d", &v, &e);
		arr = (int**)malloc(sizeof(int*) * (v + 1));
		cnt = (int*)malloc(sizeof(int) * (v + 1));
		visited = (int*)malloc(sizeof(int) * (v + 1));
		checked = (int*)malloc(sizeof(int) * (v + 1));
		xi = (int*)malloc(sizeof(int) * (e + 1));
		yi = (int*)malloc(sizeof(int) * (e + 1));
		for (int i = 1; i <= e; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			cnt[x]++;
			cnt[y]++;
			xi[i] = x;
			yi[i] = y;
		}
		for (int i = 1; i <= v; i++) {
			arr[i] = (int*)malloc(sizeof(int) * cnt[i]);
			visited[i] = 0;
			cnt[i] = 0;
		}
		for (int i = 1; i <= e; i++) {
			arr[xi[i]][cnt[xi[i]]++] = yi[i];
			arr[yi[i]][cnt[yi[i]]++] = xi[i];
		}
		tst = 1;
		for (int i = 1; i <= v; i++) {
			if (!visited[i]) {
				dfs(i, 1);
			}
		}
		if (tst) {
			result[idx++] = 1;
		}
		else {
			result[idx++] = 0;
		}
	}
	for (int i = 0; i < idx; i++) {
		if (result[i]) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
}