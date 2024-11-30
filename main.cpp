#include <iostream>
#include "include/SLL.h"
using namespace std ;

int main() {
    SLL<int> s;

    s.push_front(1);
//    s.pop_front();
    s.push_back(1);
    s.push_back(1);
//    s.pop_back();
    s.push_at(1,0);
    s.push_at(1,4);
    s.pop_at(11);
    cout << s.empty() << endl;
    cout << s.size();
}
