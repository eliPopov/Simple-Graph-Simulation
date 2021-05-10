#include "../include/Tree.h"
#include <vector>
using namespace std;
CycleTree::CycleTree(int rootLabel, int currCycle) :Tree(rootLabel),currCycle(currCycle){};

Tree* CycleTree::clone() const{
    return new CycleTree(*this);
}

int CycleTree::traceTree() {
    return recTraceTree(currCycle, this);
}
int CycleTree::recTraceTree(int cycle, Tree* tree) {
    if(tree->getNumOfChildren()==0 || cycle == 0)
        return tree->getNode();
    return recTraceTree(cycle-1, tree->getChild(0));
}
