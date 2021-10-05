#include <stdio.h>
void hanoi(int n, int start, int goal) {
	int mid = 6 - start - goal;
	if (n == 1) {
		printf("%d %d\n", start, goal);
	}
	else {
		hanoi(n - 1, start, mid);
		hanoi(1, start, goal);
		hanoi(n - 1, mid, goal);
	}
}
main() {
	int n, m = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		m *= 2;
	}
	//하노이 탑 이동 횟수는 2 ^ n - 1이다
	printf("%d\n", m - 1);
	hanoi(n, 1, 3);
}