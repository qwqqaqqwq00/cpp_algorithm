// void swap(int *a, int *b){
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

void merge(int *low, int *mid, int *high){
    int *h = low, *j = mid + 1;
    int i = 0;
    int *B = new int[high - low + 1];
    while (h <= mid && j <= high){
        if(*h <= *j){
            B[i] = *h;
            h++;
        }else{
            B[i] = *j;
            j++;
        }
        i++;
    }
    if(h > mid){
        for(int *k = j;k <= high; k++, i++){
            B[i] = *k;
        }
    }else{
        for(int *k = h; k <= mid; k++, i++){
            B[i] = *k;
        }
    }
    for(int *k = low, i = 0; k <= high; k++, i++){
        *k = B[i];
    }
    delete[] B;
}

void merge_sort(int *low, int *high){
    if(low < high){
        int *mid = low + (high - low) / 2;
        merge_sort(low, mid);
        merge_sort(mid + 1, high);
        merge(low, mid, high);
    }
}
