#include <stdio.h>
#include <string.h>
char lstack[600001], rstack[600001], str[100001];
int lidx = -1, ridx = -1;
void lpush(char value) {
	lstack[++lidx] = value;
}
void rpush(char value) {
	rstack[++ridx] = value;
}
char lpop() {
	if (lidx < 0) return 0;
	else return lstack[lidx--];
}
char rpop() {
	if (ridx < 0) return 0;
	else return rstack[ridx--];
}
main() {
	int m;
	scanf("%s", str);
	for (int i = 0; i < strlen(str); i++) lpush(str[i]);
	scanf("%d", &m);
	getchar();
	char commander[4];
	for (int i = 0; i < m; i++) {
		gets(commander);
		if (commander[0] == 'L') {
			if (lidx > -1) {
				char x = lpop();
				rpush(x);
			}
		}
		else if (commander[0] == 'D') {
			if (ridx > -1) {
				char x = rpop();
				lpush(x);
			}
		}
		else if (commander[0] == 'P') lpush(commander[2]);
		else if (commander[0] == 'B') lpop();
	}
	while (lidx > -1) rpush(lpop());
	while (ridx > -1) printf("%c", rpop());
	printf("\n");
}