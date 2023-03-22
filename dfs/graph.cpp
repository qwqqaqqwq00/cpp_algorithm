/***
 * @Description: 
 * @version: 
 * @Author: Rundong Wang
 * @Date: 2022-11-25 23:49:38
 * @LastEditors: 
 * @LastEditTime: 2023-02-16 23:30:41
 */
#include "graph.h"
#include <iostream>
#include <memory>

typedef tuple<unsigned int, unsigned int, int> ti;

int main(){
    linkedlist<ti> l0, l1;
    l0.push_back(ti(0, 1, 1));
    l0.push_back(ti(0, 2, 2));
    // l0.pop_front();
    // l0.pop_front();
    l1.push_back(ti(1, 2, 2));
    vec<linkedlist<ti>> vt;
    vt.append({l0, l1});
    // vt.push_back(l0);
    // vt.push_back(l1);
    graph<int> g(vt);
    g.print();
}