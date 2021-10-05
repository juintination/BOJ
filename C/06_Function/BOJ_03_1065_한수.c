#include<stdio.h>
int hannum(int a) {
	int cnt = 0;
	for (int i = 1; i <= a; i++) {
		if (i < 100) {
			cnt++;
		}
		else if (i >= 100 && i < 1000) {
			if (i / 100 - (i % 100) / 10 == (i % 100) / 10 - i % 10) {
				cnt++;
			}
		}
	}
	return cnt;
}

main() {
	int a;
	scanf("%d", &a);
	printf("%d", hannum(a));
}