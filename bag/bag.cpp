#include "bag.h"


int main(){
    int p[] = {100, 10, 15, 20};
    int w[] = {2, 1, 2, 1};
    int n = 4;
    int *x = new int[4];
    for(int i = 0; i < n; i++) x[i] = 0;
    greedy(p, w, &x, n, 3);
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d ", x[i]);
    }
    free(x);
}