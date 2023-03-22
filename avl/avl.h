/***
 * @Description: 
 * @version: 1
 * @Author: Rundong Wang
 * @Date: 2022-11-25 23:34:22
 * @LastEditors: 
 * @LastEditTime: 2023-02-16 09:35:41
 */

#include <stdlib.h>
// #include <vector>

template<typename T>
class node{
private:
    T val;
    node *le, *ri;
public:
    node::node<T>(T val){
        this->val = val;
        this->le = NULL;
        this->ri = NULL;
    }
};

template<typename T>
class avl{
private:
	node<T> *root;
public:
	avl::avl<T>(){
        root = NULL;
    }
    avl::avl(node<T> *root){
        this->root = root;
    }
    avl::avl<T>(T val){
        this->root = new node<T>(val);
    }
    avl::push(T val){
        if(this->root){
            this
        }
    }
};