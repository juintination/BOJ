#include <stdio.h>
main() {
	char num1[4], num2[4];
	int renum1 = 0, renum2 = 0;
	scanf("%s", &num1);
	getchar();
	scanf("%s", &num2);
	int z = 100;
	for (int i = 3; i > 0; i--) {
		renum1 += (num1[i - 1] - 48) * z;
		renum2 += (num2[i - 1] - 48) * z;
		z = z / 10;
	}
	if (renum1 > renum2) {
		printf("%d", renum1);
	}
	else if (renum1 < renum2) {
		printf("%d", renum2);
	}
}