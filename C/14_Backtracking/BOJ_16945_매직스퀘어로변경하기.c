#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#define math_min(a, b) a < b ? a : b
int arr[3][3], visited[10], min = INT_MAX;
int square(int diagonal) {
	for (int i = 0; i < 3; i++) {
		int horizontal = 0, vertical = 0;
		for (int j = 0; j < 3; j++) {
			horizontal += arr[i][j];
			vertical += arr[j][i];
		}
		if (horizontal != diagonal || vertical != diagonal) return 0;
	}
	return 1;
}
void dfs(int dpth, int idx, int sum) {
	if (idx == 3) {
		dfs(dpth + 1, 0, sum);
		return;
	}
	if (dpth == 3) {
		int diagonal = 0;
		for (int i = 0; i < 3; i++) {
			diagonal += arr[i][i];
		}
		if (diagonal == arr[2][0] + arr[1][1] + arr[0][2]) {
			if (square(diagonal)) {
				min = math_min(min, sum);
			}
		}
		return;
	}
	int tmp = arr[dpth][idx];
	for (int i = 1; i <= 9; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			arr[dpth][idx] = i;
			dfs(dpth, idx + 1, sum + abs(tmp - i));
			arr[dpth][idx] = tmp;
			visited[i] = 0;
		}
	}
}
main() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	dfs(0, 0, 0);
	printf("%d", min);
}