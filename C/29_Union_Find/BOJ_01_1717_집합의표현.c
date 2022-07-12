#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node {
	char str[4];
	struct node* link;
} node;
node* insert_node(node* head, char str[]) {
	node* p = (node*)malloc(sizeof(node));
	strcpy(p->str, str);
	if (head == NULL) {
		head = p;
		p->link = head;
	}
	else {
		p->link = head->link;
		head->link = p;
		head = p;
	}
	return head;
}
void print_list(node* head) {
	if (head == NULL) return;
	node* p = head->link;
	do {
		printf("%s\n", p->str);
		p = p->link;
	} while (p != head);
	printf("%s\n", p->str);
}
void initParent(int parent[], int n) {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
}
int findParent(int parent[], int x) {
	if (parent[x] == x) return x;
	return parent[x] = findParent(parent, parent[x]);
}
void unionParent(int parent[], int a, int b) {
	a = findParent(parent, a);
	b = findParent(parent, b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}
int isUnion(int parent[], int a, int b) {
	a = findParent(parent, a);
	b = findParent(parent, b);
	if (a == b) return 1;
	else return 0;
}
main() {
	int n, m, op, a, b;
	scanf("%d %d", &n, &m);
	int* parent = (int*)malloc(sizeof(int) * (n + 1));
	initParent(parent, n);
	node* head = NULL;
	while (m--) {
		scanf("%d %d %d", &op, &a, &b);
		if (op == 0) {
			unionParent(parent, a, b);
		}
		else if (isUnion(parent, a, b)) {
			head = insert_node(head, "YES");
		}
		else {
			head = insert_node(head, "NO");
		}
	}
	print_list(head);
}