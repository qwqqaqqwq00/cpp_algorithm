#include <iostream>
#include <stdlib.h>

void binary_search(int *begin, int *end, int target, int *x){
    int *low = begin, *high = end - 1, *mid;
    if(low > high) return;
    while (low <= high){
        mid = low + (high - low) / 2;
        // printf("%d ", *mid);
        if(target < *mid) high = mid - 1;
        if(target > *mid) low = mid + 1;
        else{
            *x = *mid;
            return;
        }
    }
    *x = -1;
}
