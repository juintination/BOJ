#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
main() {
	int n, top = -1;
	scanf("%d", &n);
	int* list = (int*)malloc(sizeof(int) * (n + 1));
	list[++top] = INT_MIN;
	while (n--) {
		int value;
		scanf("%d", &value);
		if (value > list[top]) {
			list[++top] = value;
		}
		else {
			int left = 1, right = top, idx = 1;
			while (left <= right) {
				int mid = (right + left) / 2;
				if (list[mid] >= value) {
					idx = mid;
					right = mid - 1;
				}
				else {
					left = mid + 1;
				}
			}
			list[idx] = value;
		}
	}
	printf("%d", top);
}