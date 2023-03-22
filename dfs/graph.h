#include <stdlib.h>
#include <iostream>
#include <memory>
#include "vector.h"
#include "linkedlist.h"
#include "tuple.h"

template<typename T>
using edge_table = vec<linkedlist<tuple<unsigned int, unsigned int, T>>>;

template<typename T>
class graph{
private:
	edge_table<T> edges;
public:
	graph(): edges(edge_table<T>()) {}
    graph(edge_table<T>& tb): edges(tb) {}
    graph(graph<T>& other){
        this->edges = other.edges;
    }
    void print(){
        printf("\n");
        for(unsigned int i = 0; i < edges.get_size(); i++){
            for(unsigned int j = 0; j < edges[i].get_size(); j++){
                int begin = edges[i][j].head(), end = edges[i][j].tail().head(), weight = edges[i][j].tail().tail().head();
                printf("\n( %d ) -- %d -- ( %d )\n", begin, weight, end);
            }
        }
    }
};