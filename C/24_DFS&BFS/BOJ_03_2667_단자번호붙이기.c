#include <stdio.h>
int n, arr[25][25], visited[25][25], cnt;
void quickSort(int arr[], int left, int right) {
	int i = left, j = right, pivot = arr[(left + right) / 2], temp;
	do {
		while (arr[i] < pivot) i++;
		while (arr[j] > pivot) j--;
		if (i <= j) {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);
	if (left < j) quickSort(arr, left, j);
	if (i < right) quickSort(arr, i, right);
}
void dfs(int x, int y) {
	visited[x][y] = 1;
	int dx[] = { -1, 0, 1, 0 };
	int dy[] = { 0, -1, 0, 1 };
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && arr[nx][ny] == 1) {
			cnt++;
			dfs(nx, ny);
		}
	}
}
main() {
	scanf("%d", &n);
	int* list = (int*)malloc(sizeof(int) * (n * n));
	char* str = (char*)malloc(sizeof(char) * (n + 1));
	for (int i = 0; i < n; i++) {
		getchar();
		scanf("%s", str);
		for (int j = 0; j < n; j++) {
			arr[i][j] = str[j] - '0';
		}
	}
	int idx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && arr[i][j] == 1) {
				cnt = 1;
				dfs(i, j);
				list[idx++] = cnt;
			}
		}
	}
	quickSort(list, 0, idx - 1);
	printf("%d\n", idx);
	for (int i = 0; i < idx; i++) {
		printf("%d\n", list[i]);
	}
}