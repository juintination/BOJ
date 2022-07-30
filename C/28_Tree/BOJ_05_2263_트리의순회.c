#include <stdio.h>
#include <stdlib.h>
int* in, * inIdx, * post;
void getPreorder(int inLeft, int inRight, int postLeft, int postRight) {
	if (inLeft > inRight || postLeft > postRight) return;
	int root = post[postRight];
	printf("%d ", root);
	int rootIdx = inIdx[root];
	int leftOfRoot = rootIdx - inLeft;
	getPreorder(inLeft, rootIdx - 1, postLeft, postLeft + leftOfRoot - 1);
	getPreorder(rootIdx + 1, inRight, postLeft + leftOfRoot, postRight - 1);
}
main() {
	int n;
	scanf("%d", &n);
	in = (int*)malloc(sizeof(int) * (n + 1));
	inIdx = (int*)malloc(sizeof(int) * (n + 1));
	post = (int*)malloc(sizeof(int) * (n + 1));
	for (int i = 1; i <= n; i++) {
		scanf("%d", &in[i]);
		inIdx[in[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &post[i]);
	}
	getPreorder(1, n, 1, n);
}