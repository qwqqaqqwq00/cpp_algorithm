#include <iostream>
#include <stdlib.h>

template<typename T>
class treenode{
private:
	T val;
    treenode *le, *ri;
public:
	treenode(){
        this->val = -1;
        this->le = NULL;
        this->ri = NULL;
    }
    treenode(T val) : val(val){
        this->le = NULL;
        this->ri = NULL;
    }
};

template<typename T>
class tree{
private:
	treenode<T> root;
    void node_push(treenode<T> *root, T val, int (*cmp_rule)(T a, T b)){
        if(cmp_rule(val, root->val)){
            if(root->le == NULL){
                root->le = new treenode<T>(val);
            }else{
                node_push(root->le, val, cmp_rule);
            }
        }else{
            if(root->ri == NULL){
                root->ri = new treenode<T>(val);
            }else{
                node_push(root->ri, val, cmp_rule);
            }
        }
    }
public:
	tree(){
        this->root = NULL;
    }
    tree(T val){
        this->root = new treenode<T>(val);
    }
    void push(T val, int (*cmp_rule)(T a, T b)){
        if(this->root == NULL){
            this->root = new treenode<T>(val);
        }else{
            node_push(this->root, val, cmp_rule);
        }
    }
};