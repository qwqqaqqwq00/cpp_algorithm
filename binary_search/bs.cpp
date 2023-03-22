#include "bs.h"

int main() {
    int l[] = {
        1,2,3,4,7,9,10,11,12,14,15,20
    };
    int res;
    printf("\n");
    binary_search(l, l+12, 13, &res);
    printf("%d\n", res);
}