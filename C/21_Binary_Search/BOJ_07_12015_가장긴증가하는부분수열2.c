#include <stdio.h>
main() {
	int n, top = -1;
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * (n + 1));
	arr[++top] = 0;
	for (int i = 0; i < n; i++) {
		int value;
		scanf("%d", &value);
		if (value > arr[top]) {
			arr[++top] = value;
		}
		else {
			int left = 0, right = top, idx = 0;
			while (left <= right) {
				int mid = (right + left) / 2;
				if (arr[mid] >= value) {
					idx = mid;
					right = mid - 1;
				}
				else {
					left = mid + 1;
				}
			}
			arr[idx] = value;
		}
	}
	printf("%d", top);
}