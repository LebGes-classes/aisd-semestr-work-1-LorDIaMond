#include <iostream>
#include "Treap.h"

using namespace std;

int main() {
    Treap t;
    t.insert(1);
    t.insert(15);
    t.insert(9);
    t.preOrder(); 

    return 0;
}