#include <stdio.h>
int stack[10];
int idx = -1;
void push(int value) {
	stack[++idx] = value;
}
int pop() {
	return stack[idx--];
}
main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int coin;
		scanf("%d", &coin);
		if (coin > k) continue;
		push(coin);
	}
	int cnt = 0;
	while (k > 0) {
		int tmp = pop();
		cnt += (k / tmp);
		k %= tmp;
	}
	printf("%d", cnt);
}