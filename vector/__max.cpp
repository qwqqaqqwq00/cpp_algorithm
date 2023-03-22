// #include <iostream>
#include <stdio.h>

void __max_idx(int *vec, int n, int *idx){
    if (n < 1) return;
    int xmax = vec[0];
    *idx = 0;
    for(int i=1; i<n; i++){
        if(xmax < vec[i]) {
            xmax = vec[i];
            *idx = i;
        }
    }
}
void __max(int *vec, int n, int *val){
    int *idx = nullptr;
    __max_idx(vec, n, idx);
    *val = vec[*idx];
}
int main(){
    int v[10] = {1,2,3,4,5,6,7,8,9,10};
    int idx = 0;
    __max_idx(v, 10, &idx);
    printf("%d\n", idx);
    __max(v, 10, &idx);
    printf("%d\n", idx);
    return 0;
}