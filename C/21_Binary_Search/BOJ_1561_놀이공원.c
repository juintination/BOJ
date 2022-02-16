#include <stdio.h>
#define math_max(a, b) a > b ? a : b
main() {
	int n, m;
	long long int max = 0;
	scanf("%d %d", &n, &m);
	int* arr = (int*)malloc(sizeof(int) * m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &arr[i]);
		max = math_max(max, arr[i]);
	}
	if (n <= m) {
		printf("%d", n);
		return 0;
	}
	max *= n;
	long long int min = 0, time = 0;
	while (min <= max) {
		long long int mid = (max + min) / 2;
		long long int sum = m;
		for (int i = 0; i < m; i++) {
			sum += mid / arr[i];
		}
		if (sum >= n) {
			time = mid;
			max = mid - 1;
		}
		else {
			min = mid + 1;
		}
	}
	long long int cnt = m;
	for (int i = 0; i < m; i++) {
		cnt += (time - 1) / arr[i];
	}
	for (int i = 0; i < m; i++) {
		if (time % arr[i] == 0) {
			cnt++;
		}
		if (cnt == n) {
			printf("%d", i + 1);
			break;
		}
	}
}