#include <stdio.h>
#define math_min(a, b) a < b ? a : b
int arr1[100000], arr2[100000], bulb[100000];
main() {
	int n;
	scanf("%d", &n);
	char* str = (char*)malloc(sizeof(char) * n);
	scanf("%s", str);
	for (int i = 0; i < n; i++) {
		arr1[i] = arr2[i] = str[i] - '0';
	}
	scanf("%s", str);
	for (int i = 0; i < n; i++) {
		bulb[i] = str[i] - '0';
	}
	int cnt1 = 0, cnt2 = 1;
	for (int i = 0; i <= 1; i++) {
		arr2[i] = 1 - arr2[i];
	}
	for (int i = 1; i < n; i++) {
		if (arr1[i - 1] != bulb[i - 1]) {
			arr1[i - 1] = 1 - arr1[i - 1];
			arr1[i] = 1 - arr1[i];
			cnt1++;
			if (i != n - 1) {
				arr1[i + 1] = 1 - arr1[i + 1];
			}
		}
		if (arr2[i - 1] != bulb[i - 1]) {
			arr2[i - 1] = 1 - arr2[i - 1];
			arr2[i] = 1 - arr2[i];
			cnt2++;
			if (i != n - 1) {
				arr2[i + 1] = 1 - arr2[i + 1];
			}
		}
	}
	int INF = 2147483647;
	if (arr1[n - 1] != bulb[n - 1]) cnt1 = INF;
	if (arr2[n - 1] != bulb[n - 1]) cnt2 = INF;
	if (cnt1 == INF && cnt2 == INF) {
		printf("-1");
	}
	else {
		printf("%d", math_min(cnt1, cnt2));
	}
}