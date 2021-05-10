#include "../include/Tree.h"
#include "../include/Session.h"
#include <vector>


using namespace std;
//constructor
Tree::Tree(int rootLabel) :node(rootLabel),children(){}

//deep copy constructor
Tree::Tree(const Tree &other) :node(other.node),children{}{
    for(const Tree* child:other.children){
        Tree* clone = child->clone();
        children.push_back(clone);
    }
}
//move constructor

Tree::Tree(Tree &&other) :node(other.node),children(other.children){
    int childrenSize = other.children.size();
    for(int i=0;i<childrenSize;i++){
        other.children.at(i) = nullptr;
    }
    other.children.clear();
}
//copy assignment
Tree& Tree::operator=(const Tree& other){
    if(this == &other){
        return *this;
    }
    node = other.node;
    clear();
    for(Tree* child:other.children){
        Tree* clone = child->clone();
        children.push_back(clone);
    }
    return *this;
}
//move assignment
Tree& Tree::operator=(Tree &&other) {
    if(this != &other) {
        clear();
        node = other.node;
        children = other.children;
        int childrenSize = other.children.size();
        for(int i=0;i<childrenSize;i++){
            other.children.at(i) = nullptr;
        }
        other.children.clear();
    }
    return *this;
}
//destructor
Tree:: ~Tree(){
    clear();
}
void Tree::clear() {
    for(Tree* child:children) {
            delete child;
    }
    children.clear();
}
void Tree::addChild(const Tree& child){
    Tree* newChild = child.clone();
    addChild(newChild);
}
void Tree::addChild(Tree *child) {
    children.push_back(child);
}
int Tree::getNode() const {
    return node;
}
Tree* Tree::getChild(int index) const{
    return children.at(index);
}
int Tree::getNumOfChildren() const{
    return children.size();
}

Tree* Tree::createTree(const Session &session, int rootLabel){
    TreeType type = session.getTreeType();
    if(type == Root){
        Tree* tree = new RootTree(rootLabel);
        return tree;
    }
    else if(type == MaxRank){
        Tree* tree = new MaxRankTree(rootLabel);
        return tree;
        }
    else {
        Tree *tree = new CycleTree(rootLabel, session.getCycleNum());
        return tree;
    }
}


