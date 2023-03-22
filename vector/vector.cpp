#include "vector.h"

int main(){
    vec<int> v({6});
    v.append({7, 2, 9, 4, 5, 8, 3, 1});
    v.print();
    v.sort(0, 8, lower);
    v.print();
    v.clear();
    v.append({2,-1,0,1,3,1,3,5,6,8,9});
    v.print();
    v.sort(0, 10, lower);
    v.print();
    vec<vec<int>> vx({vec<int>({1, 2})});
    // vx.print();
    auto vt = std::move(vx);
    return 0;
}