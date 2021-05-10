#ifndef TREE_H_
#define TREE_H_

#include <vector>
#include <string>
using namespace std;
class Session;

class Tree{
public:
    Tree(int rootLabel); //constuctor
    Tree(const Tree &other);//copy
    Tree(Tree &&other); //move constructor
    Tree & operator=(const Tree &other); // copy =operator
    Tree &operator=(Tree &&other); // move =operator
    virtual ~Tree(); //destructor

    int getNode() const;
    void addChild(const Tree &child);
    void addChild(Tree *child);
    int getNumOfChildren() const;
    Tree* getChild(int index) const;
    static Tree* createTree(const Session &session, int rootLabel);
    virtual int traceTree()=0;
    virtual Tree *clone() const=0;

protected:
    int node;
    std::vector<Tree*> children;
    void clear();
};

class CycleTree: public Tree{
public:
    CycleTree(int rootLabel, int currCycle);
    virtual int traceTree();
    int recTraceTree(int cycle, Tree* tree);
    virtual Tree* clone() const;

private:
    int currCycle;

};

class MaxRankTree: public Tree{
public:
    MaxRankTree(int rootLabel);
    virtual int traceTree();
    Tree* recTraceTree(Tree* currNode, Tree* maxRankNode);
    virtual Tree* clone() const;

};

class RootTree: public Tree{
public:
    RootTree(int rootLabel);
    virtual int traceTree();
    virtual Tree* clone() const;
};

#endif
