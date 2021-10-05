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
		else if (strlen(A[i]) == strlen(A[j])) { //���ڿ��� ���̰� ���� ��
			if (*A[i] < *A[j]) B[k] = A[i++]; //�� �ձ��ڰ� i�� �� ���� ��
			else if (*A[i] > * A[j]) B[k] = A[j++]; //�� �ձ��ڰ� j�� �� ���� ��
			else if (*A[i] == *A[j]) { //i�� j�� �� �ձ��ڰ� ���� ��
				for (int z = 1; z <= strlen(A[i]); z++) { //���� ���ڸ� ���ϱ� ���� for��
					if (*(A[i] + z) < *(A[j] + z)) {
						B[k] = A[i++];
						break;
					}
					else if (*(A[i] + z) > * (A[j] + z)) {
						B[k] = A[j++];
						break;
					}
					else if (z == strlen(A[i])) { //���ڰ� ���� ���(������ �������� �� ���� ���)
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
		//mergeSort�� �� barr�� ���� warró�� �޸𸮸� �Ҵ��� �� �ʿ䰡 ����		
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