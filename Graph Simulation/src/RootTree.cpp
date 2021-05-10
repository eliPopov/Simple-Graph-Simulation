#include "../include/Tree.h"
#include <vector>
using namespace std;

RootTree::RootTree(int rootLabel) :Tree(rootLabel){};

Tree * RootTree::clone() const{
    return new RootTree(*this);
}

int RootTree::traceTree() {
    return node;
}

