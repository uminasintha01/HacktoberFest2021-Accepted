#include <stdio.h>
int main() {
    int i, num, j = 0, k = 1, nextTerm;
    scanf("%d", &num);

    for (i = 1; i <= num; ++i) {
        printf("%d\n", j);
        nextTerm = j + k;
        j = k;
        k = nextTerm;
    }

    return 0;
}
