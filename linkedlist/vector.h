#pragma once
#include <stdlib.h>
#include <iostream>
#include <memory.h>
#include <initializer_list>
// #include <vector>

template<typename T>
class vec{
private:
	T* data;
    unsigned int size;
    unsigned int capacity;
    void T_swap(T* a, T* b){
        auto tmp = *a;
        *a = *b;
        *b = tmp;
    }
public:
	vec(): data(NULL), size(0), capacity(1){
        this->data = new T[capacity];
    }
    vec(unsigned int size){
        this->size = size;
        this->capacity = size;
        this->data = new T [this->capacity];
        memset(this->data, 0, this->capacity);
    }
    vec(T dat, unsigned int size){
        this->capacity = size;
        this->size = size;
        this->data = new T [this->capacity];
        for(unsigned int i = 0; i < size; i++){
            this->data[i] = dat;
        }
    }
    vec(const std::initializer_list<T>& l): data(NULL), size(0), capacity(1){
        this->data = new T[capacity];
        this->append(l);
    }
    vec(const vec<T>& v){
        this->size = v.get_size();
        this->capacity = v.get_capacity();
        this->data = new T [this->capacity];
        for(unsigned int i = 0; i < this->size; i++){
            this->data[i] = v.data[i];
        }
    }
    T& operator[](unsigned int index){
        return this->data[index];
    }
    vec<T>& operator=(const vec<T>& other){
        *this(other);
        return *this;
    }
    void push_back(T dat){
        if(this->size >= this->capacity){
            this->capacity = this->capacity << 1;
            T* new_dat = new T [this->capacity], *tmp = this->data;
            for(int i = 0; i < this->size; i++){
                new_dat[i] = this->data[i];
            }
            this->data = new_dat;
            delete [] tmp;
        }
        this->data[this->size++] = dat;
    }
    void clear(){
        this->size = 0;
    }
    int get_size() const {return this->size;}
    int get_capacity() const {return this->capacity;}
    void append(const std::initializer_list<T>& l){
        for(T x: l){
            this->push_back(x);
        }
    }
    void sort(int le, int ri, int (*cmp_rule)(T a, T b)){
        if(le < ri){
            T tmp = this->data[le];
            int i = le, j = ri;
            while(i < j){
                // 特别注意，比较顺序只能是从大端到小端，具体原因不明确
                while(i < j && cmp_rule(tmp, this->data[j])) {
                    j--;
                }
                while(i < j && cmp_rule(this->data[i], tmp)) {
                    i++;
                }
                if(i < j)
                    T_swap(&this->data[i], &this->data[j]);
            }
            T_swap(&this->data[le], &this->data[i]);
            this->sort(le, i - 1, cmp_rule);
            this->sort(i + 1, ri, cmp_rule);
        }
    }
    void print(){
        printf("\nVec[");
        unsigned int i = 0;
        for(; i < this->size - 1; i++){
            printf(" %d,", this->data[i]);
        }
        printf(" %d ]\n", this->data[i]);
    }
};

int lower(int a, int b){
    return a <= b;
}
template<typename T>
T min(T a, T b){
    return (a < b) ? a : b;
}

// int main(){
//     vec<int> v;
//     v.append({7, 2, 9, 4, 5, 8, 3, 1});
//     v.print();
//     v.sort(0, 7, lower);
//     v.print();
//     v.clear();
//     v.append({2,-1,0,1,3,1,3,5,6,8,9});
//     v.print();
//     v.sort(0, 10, lower);
//     v.print();
// }