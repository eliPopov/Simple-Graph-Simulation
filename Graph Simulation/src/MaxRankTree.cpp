#include "../include/Tree.h"
#include <vector>
using namespace std;
MaxRankTree::MaxRankTree(int rootLabel) :Tree(rootLabel){};

Tree* MaxRankTree::clone() const{
    return new MaxRankTree(*this);
}

int MaxRankTree::traceTree() {
    Tree* maxRankNode = recTraceTree(this, this);
    return maxRankNode->getNode();
}
Tree* MaxRankTree:: recTraceTree(Tree* currNode, Tree* maxRankNode){
    if(currNode->getNumOfChildren()==0)
        return maxRankNode;
    for(int i=0;i<currNode->getNumOfChildren();i++){
        if(currNode->getChild(i)->getNumOfChildren() > maxRankNode->getNumOfChildren())
            maxRankNode = currNode->getChild(i);
        maxRankNode = recTraceTree(currNode->getChild(i), maxRankNode);
    }
    return maxRankNode;
}
