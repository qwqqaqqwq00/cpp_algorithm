void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void qsort(int *low, int *high){
    if(low < high){
        // int *temp = low + (high - low) / 2;
        int *temp = low;
        int *i = low, *j = high;
        while(i < j){
            while(i < j && *temp <= *j) j--;
            while(i < j && *i <= *temp) i++;
            if(i < j) swap(i, j);
        }
        swap(temp, i);
        qsort(low, i-1);
        qsort(i+1, high);
    }
}