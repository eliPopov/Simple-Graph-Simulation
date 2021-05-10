#include <vector>
#include "../include/Agent.h"
#include "../include/Session.h"
#include "../include/Tree.h"
using namespace std;

ContactTracer::ContactTracer() :Agent(){}


Agent* ContactTracer::clone() const {
    return new ContactTracer();// no internal state
}

void ContactTracer::act(Session &session) {
    int node = session.dequeueInfected();
    if (node != -1) {//if the queue is not empty
    Tree *bfsTree = Tree::createTree(session, node);
    Graph::BFS(session, session.getGraph(), node, bfsTree);
    int nodeToDisconnect = bfsTree->traceTree();
    session.disconnectNode(nodeToDisconnect);
    //delete bfsTree
    delete bfsTree;
    }
}



