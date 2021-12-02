#include <stdio.h>
int k, first = 1, arr[10], visited[10], max[11], min[11];
char inequal[11];
void dfs(int dpth) {
	if (dpth == k + 1) {
		if (first) {
			for (int i = 0; i <= k; i++) {
				min[i] = arr[i];
			}
			first = !first;
		}
		else {
			for (int i = 0; i <= k; i++) {
				max[i] = arr[i];
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		if (!visited[i]) {
			if (inequal[dpth] == '>' && arr[dpth - 1] > i) {
				visited[i] = 1;
				arr[dpth] = i;
				dfs(dpth + 1);
				visited[i] = 0;
			}
			else if (inequal[dpth] == '<' && arr[dpth - 1] < i) {
				visited[i] = 1;
				arr[dpth] = i;
				dfs(dpth + 1);
				visited[i] = 0;
			}
		}
	}
}
main() {
	scanf("%d", &k);
	for (int i = 1; i <= k; i++) {
		getchar();
		scanf("%c", &inequal[i]);
	}
	for (int i = 0; i < 10; i++) {
		visited[i] = 1;
		arr[0] = i;
		dfs(1);
		visited[i] = 0;
	}
	for (int i = 0; i <= k; i++) {
		printf("%d", max[i]);
	}
	printf("\n");
	for (int i = 0; i <= k; i++) {
		printf("%d", min[i]);
	}
}