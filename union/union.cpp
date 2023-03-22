#include "union.h"

void auto_union(Union *u, int *x, int n){
    for(int i=0; i<n; i++){
        u->_union(x[2*i], x[2*i+1]);
    }
}

int main(){
    Union u;
    u._init();
    int x[] = {
        1,2,
        3,4,
        12,3,
        8,4,
        7,2,
        9,1,
        7,10,
        4,11,
        12,13,
        17,19,
        18,12,
        16,17,
        6,16,
        5,6,
        14,17,
        15,20
    };
    auto_union(&u, x, 16);
    printf("\nfind(1)=%d\n", u._find(1));
    // printf("find(6)=%d\n", u._find(6));
    if(u._cmp(2, 4)){
        printf("True\n");
    }else{
        printf("False\n");
    }
    u._print();
}