#include <stdio.h>
#include <string.h>
main() {
	char group[101];
	int cnt = 0, n, m = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", &group);
		if (strlen(group) > 1) {
			for (int j = 0; j < strlen(group) - 1; j++) {
				for (int k = j + 1; k < strlen(group); k++) {
					if (group[j] == group[k]) {
						if (k != j + 1) {
							m = 0;
							break;
						}
						else {
							m = 1;
							break;
						}
					}
					else m = 1;
				}
				if (m == 0) break;
			}
			if (m == 1) cnt++;
		}
		else cnt++;
	}
	printf("%d", cnt);
}