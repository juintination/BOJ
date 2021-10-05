#include <stdio.h>
main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int k = 0; k <= i; k++) {
            printf("*");
        }
        printf("\n");
    }
}