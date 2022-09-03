#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 200000
typedef struct {
	char name[21];
	int idx;
} element;
typedef struct list {
	element item;
	struct list* link;
} list;
list* table[TABLE_SIZE];
void initTable(list* table[]) {
	for (int i = 0; i < TABLE_SIZE; i++) {
		table[i] = NULL;
	}
}
int hashFunction(char* key) {
	int number = 0, i = 0;
	while (key[i]) {
		number = (31 * number) % TABLE_SIZE + key[i++];
	}
	return number % TABLE_SIZE;
}
void hashChainAdd(element item, list* table[]) {
	int value = hashFunction(item.name);
	list* before = NULL;
	list* node = table[value];
	while (node != NULL) {
		if (!strcmp(node->item.name, item.name)) {
			return;
		}
		before = node;
		node = node->link;
	}
	list* ptr = (list*)malloc(sizeof(list));
	ptr->item = item;
	ptr->link = NULL;
	if (before) {
		before->link = ptr;
	}
	else {
		table[value] = ptr;
	}
}
int hashChainSearch(element item, list* table[]) {
	int value = hashFunction(item.name);
	for (list* node = table[value]; node; node = node->link) {
		if (!strcmp(node->item.name, item.name)) {
			return node->item.idx;
		}
	}
	return -1;
}
void initFriendCnt(int friends[], int cnt[], int n) {
	for (int i = 0; i < n; i++) {
		friends[i] = i;
		cnt[i] = 1;
	}
}
int findFriend(int friends[], int x) {
	if (friends[x] == x) return x;
	return friends[x] = findFriend(friends, friends[x]);
}
int unionFriend(int friends[], int cnt[], int a, int b) {
	a = findFriend(friends, a);
	b = findFriend(friends, b);
	if (a < b) {
		friends[b] = a;
		cnt[a] += cnt[b];
		return cnt[a];
	}
	else if (a > b) {
		friends[a] = b;
		cnt[b] += cnt[a];
		return cnt[b];
	}
	else return cnt[a];
}
typedef struct node {
	int data;
	struct node* link;
} node;
node* insertNode(node* head, int data) {
	node* p = (node*)malloc(sizeof(node));
	p->data = data;
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
void printList(node* head) {
	if (head == NULL) return;
	node* p = head->link;
	do {
		printf("%d\n", p->data);
		p = p->link;
	} while (p != head);
	printf("%d\n", p->data);
}
main() {
	int t, f;
	scanf("%d", &t);
	node* head = NULL;
	while (t--) {
		scanf("%d", &f);
		int* friends = (int*)malloc(sizeof(int) * (f * 2));
		int* cnt = (int*)malloc(sizeof(int) * (f * 2));
		initFriendCnt(friends, cnt, f * 2);
		initTable(table);
		int idx = 0;
		while (f--) {
			element a, b;
			scanf("%s %s", a.name, b.name);
			a.idx = hashChainSearch(a, table);
			if (a.idx == -1) {
				a.idx = idx++;
				hashChainAdd(a, table);
			}
			b.idx = hashChainSearch(b, table);
			if (b.idx == -1) {
				b.idx = idx++;
				hashChainAdd(b, table);
			}
			head = insertNode(head, unionFriend(friends, cnt, a.idx, b.idx));
		}
	}
	printList(head);
}