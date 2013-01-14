#include "tree.h"
#include <iostream>
#include <cstdlib>

int main() {
    const int num = 100;
    srand(time(0));
    tree::tree myTree;
    
    for(int i=0; i<num; ++i) {
        int r = rand() % num; 
        myTree.insert(r);
    }
    myTree.traverse();
    
    for(int i=0; i<num; ++i) {
        int r = rand() % num;
        myTree.remove(r);
    } 
    myTree.traverse();
    
    return 0;
}

