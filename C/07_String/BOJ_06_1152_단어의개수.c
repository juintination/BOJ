#include <stdio.h>
#include <string.h>
main() {
	char arr[1000000];
	int cnt = 1, last;
	scanf("%[^\n]s", &arr);
	//%[^/n]s를 통해 엔터에만 문자열 입력이 종료되게 설정한다
	for (int i = 0; i < strlen(arr); i++) {
		if (arr[i] == 32) cnt++;
	}
	for (int i = strlen(arr) - 1; i >= 0; i--) {
		if (arr[i] == 32) cnt--;
		else {
			last = i;
			break;
		}
	}
	int start = 0;
	if (arr[0] == 32) {
		while (arr[start] == 32) {
			cnt--;
			start++;
		}
	}
	for (int i = start; i < last; i++) {
		if (arr[i] == 32 && arr[i - 1] == 32) cnt--;
	}
	printf("%d\n", cnt);
}