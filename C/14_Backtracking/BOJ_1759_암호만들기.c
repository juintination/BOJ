#include <stdio.h>
int visited[15], l, c;
char arr[15], password[15];
void quickSort(char arr[], int left, int right) {
	int i = left, j = right, pivot = arr[(left + right) / 2];
	char temp;
	do {
		while (arr[i] < pivot) i++;
		while (arr[j] > pivot) j--;
		if (i <= j) {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);
	if (left < j) quickSort(arr, left, j);
	if (i < right) quickSort(arr, i, right);
}
void dfs(int dpth) {
	if (dpth == l) {
		int vowel = 0, consonant = 0;
		for (int i = 0; i < l; i++) {
			if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') {
				vowel++;
			}
			else consonant++;
		}
		if (vowel > 0 && consonant >= 2) {
			for (int i = 0; i < l; i++) {
				printf("%c", arr[i]);
			}
			printf("\n");
		}
		return;
	}
	for (int i = 0; i < c; i++) {
		if (visited[i] == 0) {
			if (dpth > 0 && arr[dpth - 1] > password[i]) continue;
			visited[i] = 1;
			arr[dpth] = password[i];
			dfs(dpth + 1);
			visited[i] = 0;
		}
	}
}
main() {
	scanf("%d %d", &l, &c);
	for (int i = 0; i < c; i++) {
		getchar();
		scanf("%c", &password[i]);
	}
	quickSort(password, 0, c - 1);
	dfs(0);
}