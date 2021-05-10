#include <vector>
#include "../include/Agent.h"
#include "../include/Session.h"
using namespace std;

Virus::Virus(int nodeInd): Agent(), nodeInd(nodeInd){}

Agent* Virus::clone() const {
    return new Virus(nodeInd);
}

void Virus::act(Session &session) {
    vector<int> nodeState = session.getGraph().getNodesState();
    if(nodeState.at(nodeInd)!=3) {//infect node
        session.getGraph().infectNode(nodeInd);
        nodeState.at(nodeInd) = 3;
        session.enqueueInfected(nodeInd);
    }
    vector<int> neighbors=session.getGraph().getNeighbors(nodeInd);
    int i=0;
    int neighborSize = neighbors.size();
//search for the first neighbor that is healthy
    while(i<neighborSize && nodeState.at(neighbors.at(i))!=1)
        i++;
    if(i<neighborSize)//if found
    {
        session.getGraph().occupyNode(neighbors.at(i));
        Virus newVirus(neighbors.at(i));
        session.addAgent(newVirus);
    }
}






