/***
 * @Description: 
 * @version: 
 * @Author: Rundong Wang
 * @Date: 2023-01-16 12:51:44
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2023-02-18 20:46:26
 */
#include <iostream>
#include <stdlib.h>
#include "merge_sort.h"
#include "quick_sort.h"
#include "bubble.h"
#include "selection.h"

int main() {
    int arr[] = {
        310, 285, 179, 652, 351, 423, 861, 254, 450, 520
    };
    printf("\n");
    for(int i=0; i<10; i++){
        printf("%d ", arr[i]);
    }
    merge_sort(arr, arr+9);
    printf("\nmerge sort\n");
    for(int i=0; i<10; i++){
        printf("%d ", arr[i]);
    }
    int arr2[] = {
        310, 285, 179, 652, 351, 423, 861, 254, 450, 520
    };
    printf("\nquick sort\n");
    qsort(arr2, arr2 + 9);
    for(int i=0; i<10; i++){
        printf("%d ", arr2[i]);
    }
    int arr3[] = {
        310, 285, 179, 652, 351, 423, 861, 254, 450, 520
    };
    printf("\nbubble sort\n");
    bubble_sort(arr3, arr3 + 10);
    for(int i=0; i<10; i++){
        printf("%d ", arr3[i]);
    }
    int arr4[] = {
        310, 285, 179, 652, 351, 423, 861, 254, 450, 520
    };
    printf("\nselection sort\n");
    selection_sort(arr4, arr4 + 10);
    for(int i=0; i<10; i++){
        printf("%d ", arr4[i]);
    }
}