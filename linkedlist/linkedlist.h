#pragma once
#include <stdlib.h>
#include "vector.h"
#include <iostream>
#include <stdbool.h>
#include <initializer_list>

template<typename T>
class listnode{
public:
    T data;
    listnode<T>* nxt, *pre;
    listnode(T dat){
        this->data = dat;
        this->nxt = NULL;
        this->pre = NULL;
    };
    listnode(listnode<T> &&rhs)
    : data(rhs.data), nxt(rhs.nxt), pre(rhs.pre)
    {
        rhs.data = rhs.nxt = rhs.pre = nullptr;
    }
    listnode<T>& operator=(listnode<T> &&rst){
        this->data = rst.data;
        this->nxt = rst.nxt;
        this->pre = rst.pre;
        rst.data = rst.nxt = rst.pre = nullptr;
    }
};

template<typename T>
class linkedlist{
private:
    listnode<T>* head;
    unsigned int size;
    void merge_sort(listnode<T>* low, listnode<T>* high, listnode<T> *head, int i){
        listnode<T> *mid = low, *p = low;
        if(low != high){
            int m = i / 2, n = i / 2;
            while (m--){
                mid = mid->nxt;
            }
            merge_sort(low, mid, head, n);
            merge_sort(mid->nxt, high, head, i - n + 1);
            merge(low, mid, high, i + 1, head);
        }
    }
    void merge(listnode<T> *low, listnode<T> *mid, listnode<T> *high, int size, listnode<T> *head){
        listnode<T> *p = low, *q = mid->nxt, *r = head;
        int a[size], i = 0, j = 0, k;
        while (p != mid->nxt && q != high->nxt){
            if(p->data <= q->data){
                a[i++] = p->data;
                p = p->nxt;
            } else{
                a[i++] = q->data;
                q = q->nxt;
            }
        }
        while(p != mid->nxt){
            a[i++] = p->data;
            p = p->nxt;
        }
        while(q != high->nxt){
            a[i++] = q->data;
            q = q->nxt;
        }
        while (r != low){
            r = r->nxt;
            j++;
        }
        i = 0;
        for(k = j; k < j + size; k++){
            (*this)[k] = a[i++];
        }
    }
public:
    linkedlist(){
        this->head = NULL;
        this->size = 0;
    }
    linkedlist(T dat){
        listnode<T> *head = new listnode<T>(dat);
        this->head = head;
        this->size = 1;
    }
    linkedlist(linkedlist<T> &&rhs)
    :head(rhs.head), size(rhs.get_size())
    {
        rhs.set_head(nullptr);
        rhs.set_size(0);
    }
    linkedlist<T>& operator=(linkedlist<T> &ll){
        if(this != &ll){
            if(this->head){
                while(!this->is_empty()) this->pop_front();
            }
            this->head = ll.head;
            this->size = ll.size;
            ll.set_head(NULL);
            ll.set_size(0);
        }
        return *this;
    }
    linkedlist(const linkedlist<T>& other): head(NULL), size(0) {
        // this->size = other.size;
        listnode<T> *tmp = other.head;
        for(int i = 0; i < other.size; i++){
            this->push_front(tmp->data);
            tmp = tmp->nxt;
            // other.pop_front();
        }
    }
    int is_empty(){
        return this->head == NULL;
    }
    void set_head(listnode<T> *_head){
        this->head = _head;
    }
    unsigned int get_size(){
        return this->size;
    }
    void set_size(int _size){
        this->size = _size;
    }
    listnode<T>& index(unsigned int i){
        listnode<T> *tmp = this->head;
        while (i > 0 && tmp->nxt != this->head){
            tmp = tmp->nxt;
            i--;
        }
        return tmp;
    }
    T& operator[](unsigned int i){
        listnode<T> *tmp = this->head;
        while (i > 0 && tmp->nxt != this->head){
            tmp = tmp->nxt;
            i--;
        }
        return tmp->data;
    }
    void push_back(T dat){
        this->size++;
        if(this->is_empty()){
            this->head = new listnode<T>(dat);
            this->head->nxt = this->head;
            this->head->pre = this->head;
        } else {
            listnode<T> *tmp = this->head->pre;
            tmp->nxt = new listnode<T>(dat);
            this->head->pre = tmp->nxt;
            tmp->nxt->nxt = this->head;
            tmp->nxt->pre = tmp;
        }
    }
    void push_front(T dat){
        this->size++;
        if(this->is_empty()){
            this->head = new listnode<T>(dat);
            this->head->nxt = this->head;
            this->head->pre = this->head;
        } else {
            listnode<T>* tmp = new listnode<T>(dat);
            tmp->nxt = this->head;
            tmp->pre = this->head->pre;
            this->head->pre->nxt = tmp;
            this->head->pre = tmp;
            this->head = tmp;
        }
    }
    void append(std::initializer_list<T> dat){
        this->size += dat.size();
        for(int i = 0; i < dat.size(); i++){
            this->push_back(dat[i]);
        }
    }
    void delete_node(T dat){
        this->size--;
        if(this->is_empty()){
            return;
        }else{
            this->push_front(INT_MAX);
            listnode<T>* tmp = this->head;
            while(tmp->data != dat && tmp->nxt != this->head){
                tmp = tmp->nxt;
            }
            if(tmp->data = dat){
                tmp->pre->nxt = tmp->nxt;
                tmp->nxt->pre = tmp->pre;
                if(tmp)
                    delete tmp;
                listnode<T>* guard = this->head;
                this->head = (guard->nxt == guard)? NULL : guard->nxt;
                guard->pre->nxt = guard->nxt;
                guard->nxt->pre = guard->pre;
                if(guard)
                    delete guard;
            }else{
                return;
            }
        }
    }
    void pop_front(){
        this->size--;
        this->delete_node(this->head->data);
    }
    ~linkedlist(){
        this->size = 0;
        while(!this->is_empty()){
            this->pop_front();
        }
    }
    void print(){
        if(this->is_empty()) return;
        listnode<T>* tmp = this->head;
        printf("\n");
        while(tmp->nxt && tmp->nxt != this->head){
            printf("[%d] -> ", tmp->data);
            tmp = tmp->nxt;
        }
        printf("[%d]\n", tmp->data);
    }
    void append(vec<T> nums){
        for(int i = 0; i < nums.get_size(); i++){
            this->push_back(nums[i]);
        }
    }
    void sort(){
        vec<T> v = vec<T>();
        while(!this->is_empty()){
            v.push_back(this->head->data);
            this->pop_front();
        }
        v.sort(0, v.get_size() - 1, lower);
        for(int i = 0; i < v.get_size(); i++){
            this->push_back(v[i]);
        }
    }
};





