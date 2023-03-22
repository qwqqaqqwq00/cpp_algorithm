#include "vector.h"
#include "linkedlist.h"

int main(){
    linkedlist<int> ll;
    ll.push_back(1);
    ll.push_front(2);
    ll.print();
    ll.delete_node(2);
    ll.delete_node(1);
    ll.print();
    vec<int> nums({4, 1, 3, 8, 7, 6, 5});
    ll.append(nums);
    ll.print();
    printf("\n%d\n", ll[2]);
    ll[1] = 2;
    ll.print();
    ll.sort();
    ll.print();
    auto vx = vec<linkedlist<int>>({ll});
    // vec<linkedlist<int>> vx = 
    return 0;
}