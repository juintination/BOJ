#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void mergeSort(char* A[], int low, int high, char* B[]) {
	if (low >= high) return;
	int mid = (low + high) / 2;
	mergeSort(A, low, mid, B);
	mergeSort(A, mid + 1, high, B);
	int i = low, j = mid + 1, k = low;
	for (k; k <= high; k++) {
		if (j > high) B[k] = A[i++];
		else if (i > mid) B[k] = A[j++];
		else if (strlen(A[i]) < strlen(A[j])) B[k] = A[i++];
		else if (strlen(A[i]) == strlen(A[j])) { //문자열의 길이가 같을 때
			if (*A[i] < *A[j]) B[k] = A[i++]; //맨 앞글자가 i가 더 작을 때
			else if (*A[i] > * A[j]) B[k] = A[j++]; //맨 앞글자가 j가 더 작을 때
			else if (*A[i] == *A[j]) { //i와 j의 맨 앞글자가 같을 때
				for (int z = 1; z <= strlen(A[i]); z++) { //뒤의 글자를 비교하기 위한 for문
					if (*(A[i] + z) < *(A[j] + z)) {
						B[k] = A[i++];
						break;
					}
					else if (*(A[i] + z) > * (A[j] + z)) {
						B[k] = A[j++];
						break;
					}
					else if (z == strlen(A[i])) { //글자가 같은 경우(끝까지 비교했지만 다 같은 경우)
						B[k] = A[i++];
						B[++k] = A[j++];
						break;
					}
				}
			}
		}
		else B[k] = A[j++];
	}
	for (i = low; i <= high; i++) {
		A[i] = B[i];
	}
}
main() {
	int n;
	char* warr[20000];
	char* barr[20000];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		warr[i] = (char*)malloc(sizeof(char) * 50);
		//mergeSort에 들어갈 barr은 위에 warr처럼 메모리를 할당해 줄 필요가 없다		
		scanf("%s", warr[i]);
	}
	mergeSort(warr, 0, n - 1, barr);
	int* rank = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		rank[i] = 0;
	}
	for (int i = 0; i < n - 1; i++) {
		if ((strlen(warr[i]) == strlen(warr[i + 1])) && !memcmp(warr[i], warr[i + 1], strlen(warr[i]))) {
			rank[i + 1]++;
		}
	}
	for (int i = 0; i < n; i++) if (rank[i] == 0) printf("%s\n", warr[i]);
}