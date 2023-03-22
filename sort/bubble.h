/***
 * @Description: 
 * @version: 
 * @Author: Rundong Wang
 * @Date: 2023-02-18 19:28:00
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2023-02-18 19:46:15
 */

void bswap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubble_sort(int *low, int *high){
    int n=high-low;
    // printf("n:%d\n", n);
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(*(low+j)>*(low+j+1)){
                bswap(low+j,low+j+1);
            }
        }
    }
}