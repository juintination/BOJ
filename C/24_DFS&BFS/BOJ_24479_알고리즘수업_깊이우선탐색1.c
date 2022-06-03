#include <stdio.h>
#include <stdlib.h>
int n, m, r, cnt = 1, **arr, *size, *visited, *sequence; // 전역변수 설정
void dfs(int value) {
	visited[value] = 1;
	sequence[value] = cnt++;
	for (int i = 0; i < size[value]; i++) {
		int tmp = arr[value][i];
		if (!visited[tmp]) {
			dfs(tmp);
		}
	}
}
int compare(const void* a, const void* b) { // qsort를 위한 compare 함수
	int o1 = *(int*)a;
	int o2 = *(int*)b;
	if (o1 > o2) return 1;
	else if (o1 < o2) return -1;
	else return 0;
}
main() {
	scanf("%d %d %d", &n, &m, &r); // 정점의 수 N, 간선의 수 M, 시작 정점R
	arr = (int**)malloc(sizeof(int*) * (n + 1)); // 1부터 n까지의 정점
	size = (int*)malloc(sizeof(int) * (n + 1)); // 각 정점이 갖는 크기를 의미하는 size 배열
	visited = (int*)malloc(sizeof(int) * (n + 1)); // 각 정점의 방문 여부 확인 배열
	sequence = (int*)malloc(sizeof(int) * (n + 1)); // 각 정점의 방문 순서 배열
	for (int i = 1; i <= n; i++) {
		arr[i] = (int*)malloc(sizeof(int)); // 각 정점에 리스트 생성
		size[i] = visited[i] = sequence[i] = 0; // 각 배열의 원소 초기화
	}
	int x, y; // 입력값
	while (m--) {
		scanf("%d %d", &x, &y);
		arr[x] = (int*)realloc(arr[x], sizeof(int) * (size[x] + 1)); // arr[x]에 y를 추가하기 위한 배열 크기 realloc
		arr[y] = (int*)realloc(arr[y], sizeof(int) * (size[y] + 1)); // arr[y]에 x를 추가하기 위한 배열 크기 realloc
		arr[x][size[x]++] = y; // x 정점 리스트에 y 추가
		arr[y][size[y]++] = x; // y 정점 리스트에 x 추가
	}
	for (int i = 1; i <= n; i++) {
		qsort(arr[i], size[i], sizeof(int), compare); // 각 정점 리스트 원소 정렬
	}
	dfs(r); // 시작정점 r부터 dfs 실행
	for (int i = 1; i <= n; i++) {
		printf("%d\n", sequence[i]); // 각 순서 출력
	}
}