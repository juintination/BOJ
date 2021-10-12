#include <stdio.h>
int arr[20000];
int f = 10000;
int r = 10000;
void push_front(int x) {
	arr[f--] = x;
}
void push_back(int x) {
	arr[++r] = x;
}
int size() {
	return r - f;
}
int empty() {
	if (size() == 0) return 1;
	else return 0;
}
int pop_front() {
	if (empty()) return -1;
	else {
		int re = arr[f + 1];
		arr[++f] = 0;
		return re;
	}
}
int pop_back() {
	if (empty()) return -1;
	else {
		int re = arr[r];
		arr[r--] = 0;
		return re;
	}
}
int front() {
	if (empty()) return -1;
	else return arr[f + 1];
}
int back() {
	if (empty()) return -1;
	else return arr[r];
}

main() {
	char input[18];
	int n, cnt = 0;
	scanf("%d", &n);
	getchar();
	int* result = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%s", &input);
		if (input[0] == 'p' && input[5] == 'f') {
			int x;
			scanf("%d", &x);
			push_front(x);
		}
		else if (input[0] == 'p' && input[5] == 'b') {
			int x;
			scanf("%d", &x);
			push_back(x);
		}
		else if (input[0] == 'p' && input[4] == 'f') {
			result[cnt++] = pop_front();
		}
		else if (input[0] == 'p' && input[4] == 'b') {
			result[cnt++] = pop_back();
		}
		else if (input[0] == 's') {
			result[cnt++] = size();
		}
		else if (input[0] == 'e') {
			result[cnt++] = empty();
		}
		else if (input[0] == 'f') {
			result[cnt++] = front();
		}
		else if (input[0] == 'b') {
			result[cnt++] = back();
		}
	}
	for (int i = 0; i < cnt; i++) {
		printf("%d\n", result[i]);
	}
}