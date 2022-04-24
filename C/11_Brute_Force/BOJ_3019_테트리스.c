#include <stdio.h>
main() {
	int c, p;
	scanf("%d %d", &c, &p);
	int* arr = (int*)malloc(sizeof(int) * c);
	for (int i = 0; i < c; i++) {
		scanf("%d", &arr[i]);
	}
	int cnt = 0;
	if (p == 1) {
		cnt = c;
		for (int i = 0; i < c - 3; i++) {
			if (arr[i] == arr[i + 1] && arr[i] == arr[i + 2] && arr[i] == arr[i + 3]) {
				cnt++;
			}
		}
	}
	else if (p == 2) {
		for (int i = 0; i < c - 1; i++) {
			if (arr[i] == arr[i + 1]) {
				cnt++;
			}
		}
	}
	else if (p == 3) {
		for (int i = 0; i < c - 2; i++) {
			if (arr[i] == arr[i + 1] && arr[i] == arr[i + 2] - 1) {
				cnt++;
			}
		}
		for (int i = 0; i < c - 1; i++) {
			if (arr[i] == arr[i + 1] + 1) {
				cnt++;
			}
		}
	}
	else if (p == 4) {
		for (int i = 0; i < c - 2; i++) {
			if (arr[i] == arr[i + 1] + 1 && arr[i] == arr[i + 2] + 1) {
				cnt++;
			}
		}
		for (int i = 0; i < c - 1; i++) {
			if (arr[i] == arr[i + 1] - 1) {
				cnt++;
			}
		}
	}
	else if (p == 5) {
		for (int i = 0; i < c - 2; i++) {
			if (arr[i] == arr[i + 1] && arr[i] == arr[i + 2]) {
				cnt++;
			}
			else if (arr[i] == arr[i + 1] + 1 && arr[i] == arr[i + 2]) {
				cnt++;
			}
		}
		for (int i = 0; i < c - 1; i++) {
			if (arr[i] == arr[i + 1] + 1) {
				cnt++;
			}
			else if (arr[i] == arr[i + 1] - 1) {
				cnt++;
			}
		}
	}
	else if (p == 6) {
		for (int i = 0; i < c - 2; i++) {
			if (arr[i] == arr[i + 1] && arr[i] == arr[i + 2]) {
				cnt++;
			}
			else if (arr[i] == arr[i + 1] - 1 && arr[i] == arr[i + 2] - 1) {
				cnt++;
			}
		}
		for (int i = 0; i < c - 1; i++) {
			if (arr[i] == arr[i + 1]) {
				cnt++;
			}
			else if (arr[i] == arr[i + 1] + 2) {
				cnt++;
			}
		}
	}
	else if (p == 7) {
		for (int i = 0; i < c - 2; i++) {
			if (arr[i] == arr[i + 1] && arr[i] == arr[i + 2]) {
				cnt++;
			}
			else if (arr[i] == arr[i + 1] && arr[i] == arr[i + 2] + 1) {
				cnt++;
			}
		}
		for (int i = 0; i < c - 1; i++) {
			if (arr[i] == arr[i + 1]) {
				cnt++;
			}
			else if (arr[i] == arr[i + 1] - 2) {
				cnt++;
			}
		}
	}
}