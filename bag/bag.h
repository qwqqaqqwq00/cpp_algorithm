#include <iostream>
#include <stdlib.h>

// int x[100];

void greedy(int *p, int *w, int **x, int n, int m){
    int cu = m, i;
    // int *x = new int[n + 1];
    for(i=0;i<n;i++){
        if(w[i] > cu) break;
        (*x)[i] = 1;
        cu -= w[i];
    }
    if(i < n) (*x)[i] = cu / w[i];
}

// void greedy_job(int *d, int **j, int n){
//     (*j)[0] = 0;
//     for(int i=1;i<n;i++){
//         if((*j)[i] = i) (*j)[i] = i;
//     }
// }