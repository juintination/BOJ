#include <stdio.h>
int n, arr[9][9], visited[10][10], sudominoku;
int sudoku(int dpth, int idx, int value) {
	for (int i = 0; i < 9; i++) {
		if (arr[dpth][i] == value) {
			return 0;
		}
		if (arr[i][idx] == value) {
			return 0;
		}
	}
	int row = (dpth / 3) * 3;
	int col = (idx / 3) * 3;
	for (int i = row; i < row + 3; i++) {
		for (int j = col; j < col + 3; j++) {
			if (arr[i][j] == value) {
				return 0;
			}
		}
	}
	return 1;
}
void dfs(int dpth, int idx) {
	if (sudominoku) return;
	if (idx == 9) {
		dfs(dpth + 1, 0);
		return;
	}
	if (dpth == 9) {
		sudominoku = 1;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				printf("%d", arr[i][j]);
			}
			printf("\n");
		}
		return;
	}
	int dx[] = { 0, 1 };
	int dy[] = { 1, 0 };
	if (arr[dpth][idx] == 0) {
		for (int i = 1; i <= 9; i++) {
			if (sudoku(dpth, idx, i)) {
				arr[dpth][idx] = i;
				for (int k = 0; k < 2; k++) {
					int nx = dpth + dx[k];
					int ny = idx + dy[k];
					if (nx < 9 && ny < 9 && arr[nx][ny] == 0) {
						for (int j = 1; j <= 9; j++) {
							if (i != j && !visited[i][j] && sudoku(nx, ny, j)) {
								arr[nx][ny] = j;
								visited[i][j] = visited[j][i] = 1;
								dfs(dpth, idx + 1);
								arr[nx][ny] = 0;
								visited[i][j] = visited[j][i] = 0;
							}
						}
					}
				}
				arr[dpth][idx] = 0;
			}
		}
		return;
	}
	dfs(dpth, idx + 1);
}
main() {
	int cnt = 1;
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				arr[i][j] = visited[i + 1][j + 1] = 0;
			}
		}
		for (int i = 0; i < n; i++) {
			int u, v, lu, lv;
			char tmp1, tmp2;
			scanf("%d %c%d %d %c%d", &u, &tmp1, &lu, &v, &tmp2, &lv);
			visited[u][v] = visited[v][u] = 1;
			arr[tmp1 - 'A'][lu - 1] = u;
			arr[tmp2 - 'A'][lv - 1] = v;
		}
		getchar();
		for (int i = 1; i <= 9; i++) {
			int num;
			char tmp;
			scanf("%c%d ", &tmp, &num);
			arr[tmp - 'A'][num - 1] = i;
		}
		sudominoku = 0;
		printf("Puzzle %d\n", cnt++);
		dfs(0, 0);
	}
}