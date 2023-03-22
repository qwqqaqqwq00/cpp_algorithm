void sswap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int selection_sort(int *low, int *high){
    int n = high - low;
    for(int i=0;i<n-1;i++){
        int mi=i;
        for(int j=i+1;j<n;j++){
            if(*(low+j) < *(low+mi))
                mi = j;
        }
        if(i != mi) swap(low+i, low+mi);
    }
}