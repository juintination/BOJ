#include <stdio.h>
main() {
	int hour, minute;
	scanf("%d %d", &hour, &minute);
	if (hour == 0 && minute < 45) printf("23 %d", minute + 15);
	else if (minute >= 45) printf("%d %d", hour, minute - 45);
	else if (hour != 0 && minute < 45) printf("%d %d", hour - 1, minute + 15);
}