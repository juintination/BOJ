#include <stdio.h>
#include <string.h>
main() {
	//'=' = 61 , '-' = 45
	//c = 99 , d = 100 , z = 122 , l = 108 , j = 106 , n = 110, s = 115
	char croa[101];
	int cnt = 0;
	scanf("%s", &croa);
	for (int i = 0; i < strlen(croa); i++) {
		cnt++;
		if (croa[i] == 61) {
			if (croa[i - 1] == 99) cnt--;
			else if (croa[i - 1] == 122 && croa[i - 2] == 100) cnt = cnt - 2;
			else if (croa[i - 1] == 115) cnt--;
			else if (croa[i - 1] == 122) cnt--;
		}
		else if (croa[i] == 45) {
			if (croa[i - 1] == 99) cnt--;
			else if (croa[i - 1] == 100) cnt--;
		}
		else if (croa[i] == 106) {
			if (croa[i - 1] == 108) cnt--;
			else if (croa[i - 1] == 110) cnt--;
		}
	}
	printf("%d", cnt);
}