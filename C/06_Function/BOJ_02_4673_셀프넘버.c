#include<stdio.h>
int a[10000];
void selfnum() {
	int x = 0;
	for (int i = 0; i < 10000; i++) {
		a[i] = 0;
	}
	for (int i = 0; i < 10000; i++) {
		if (i < 10) {
			x = i + i;
			a[x] = 1;
		}
		else if (i < 100) {
			x = i + (i / 10) + (i % 10);
			a[x] = 1;
		}
		else if (i < 1000) {
			x = i + (i / 100) + ((i % 100) / 10) + (i % 10);
			a[x] = 1;
		}
		else if (i < 10000) {
			x = i + (i / 1000) + ((i % 1000) / 100) + (((i % 1000) % 100) / 10) + (((i % 1000) % 100) % 10);
			if (x < 10000) {
				a[x] = 1;
			}
		}
	}
	for (int k = 0; k < 10000; k++) {
		if (a[k] != 1) {
			printf("%d\n", k);
		}
	}
}

main() {
	selfnum();
}