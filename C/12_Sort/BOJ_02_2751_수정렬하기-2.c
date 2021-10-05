#include <stdio.h>
int a[1000000] = { 0 }, b[1000000] = { 0 };
int TopDownMergeSort(int A[], int B[], int n)
{
	CopyArray(A, 0, n, B);
	TopDownSplitMerge(B, 0, n, A);
}
int TopDownSplitMerge(int B[], int iBegin, int iEnd, int A[])
{
	if (iEnd - iBegin < 2)
		return;
	int iMiddle = (iEnd + iBegin) / 2;
	TopDownSplitMerge(A, iBegin, iMiddle, B);
	TopDownSplitMerge(A, iMiddle, iEnd, B);
	TopDownMerge(B, iBegin, iMiddle, iEnd, A);
}
int TopDownMerge(int A[], int iBegin, int iMiddle, int iEnd, int B[])
{
	int i = iBegin, j = iMiddle;
	for (int k = iBegin; k < iEnd; k++) {
		if (i < iMiddle && (j >= iEnd || A[i] <= A[j])) {
			B[k] = A[i];
			i = i + 1;
		}
		else {
			B[k] = A[j];
			j = j + 1;
		}
	}
}
int CopyArray(int A[], int iBegin, int iEnd, int B[])
{
	for (int k = iBegin; k < iEnd; k++)
		B[k] = A[k];
}

main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	TopDownMergeSort(a, b, n);
	for (int i = 0; i < n; i++) {
		printf("%d\n", a[i]);
	}
}