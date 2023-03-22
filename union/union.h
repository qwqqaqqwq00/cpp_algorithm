#include <iostream>
#include <stdlib.h>
#include <unordered_map>

#define __MY_N1 100

class Union{
    int uf[__MY_N1];
    int cnt[__MY_N1];
    void _register(int a){
        this->uf[a] = a;
        this->cnt[a] = 1;
    }
public:
    void _init(){
        for(int i=0; i<__MY_N1; i++){
            this->uf[i] = -1;
            this->cnt[i] = 0;
        }
    }
    void _union(int a, int b) {
        if(a < 0 || b < 0) return;
        if(this->uf[b] < 0) this->_register(b);
        if(this->uf[a] < 0) this->_register(a);
        int x = this->_find(a), y = this->_find(b), k = this->cnt[x] + this->cnt[y];
        if(this->cnt[x] > this->cnt[y]){
            this->uf[y] = x;
            this->cnt[x] = k;
        } else {
            this->uf[x] = y;
            this->cnt[y] = k;
        }
    }
    int _find(int a){
        if(a < 0 || this->uf[a] < 0) {
            // this->_register(a);
            // return a;
            return -1;
        }
        int b = a;
        while(this->uf[b] != b){
            b = this->uf[b];
        }
        int c = a;
        while(c != b){
            int d = this->uf[c];
            this->uf[c] = b;
            this->cnt[c] = 0;
            c = d;
        }
        return b;
    }
    int _cmp(int a, int b) {
        return this->_find(a) == this->_find(b);
    }
    void _print(){
        for(int i=0;i<__MY_N1;i++){
            if(this->_find(i) == i){
                printf("\n[%d]\t%d", i, i);
                for(int j=0;j<__MY_N1;j++){
                    if(j != i && this->_find(j) == i){
                        printf("\n|-\t%d", j);
                    }
                }
            }
        }
    }
};