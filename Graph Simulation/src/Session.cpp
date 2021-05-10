#include <iostream>
#include "../include/Session.h"
#include <vector>
#include <string>
#include <fstream>
#include "../include/json.hpp"
using json = nlohmann::json;
using namespace std;



//json file - Session constructor
Session::Session(const std::string &path):g(), treeType(), agents(), infected(), cycleNum(0) {
    //initialize default constructor for g(), treeType, a vector, an empty queue and CycleNUm equals zero.
    ifstream json_file(path);
    json j;
    json_file>>j;
    //change the type of tree
    treeType= whichType(j["tree"]);

    //set the Graph
    vector<vector<int>> edges=j["graph"];
    int size= edges[0].size();
    vector<int> nodesState(size, 1);


    //set the agents vector
    for (auto& elem : j["agents"]){
        agents.push_back(whichAgent(elem[0],elem[1]));
        if ((elem[0]=='V')){
            nodesState[elem[1]]=2; //mark the node as occupied
        }
    }
    g.setNodeState(nodesState);
    g.setEdges(edges);

    //the queue remains empty for now

}

//copy constructor
Session::Session(const Session& other):g(other.g), treeType(other.treeType), agents(), infected(), cycleNum(other.cycleNum)
{ copy(other);}

//destructor
Session::~Session() {
    clear();

}
//copy assignment operator
Session & Session::operator=(const Session &other) {
    if(this != &other)
    {
        clear();
        copy(other);//agents and infected
        setGraph(other.g);
        treeType=other.treeType;
        cycleNum=other.cycleNum;

    }
    return *this;

}

//move constructor
Session::Session( Session &&other): g(other.g), treeType(other.treeType), agents(move(other.agents)),infected(move(other.infected)), cycleNum(other.cycleNum) {
	int agentSize = other.agents.size();
	for(int i=0;i<agentSize;i++)
            other.agents.at(i) = nullptr;
}

//move assignment operator
Session & Session::operator=(Session &&other) {
    if(this!=&other){
        clear();//delete agents and infected
        setGraph(other.g);
        treeType=other.treeType;
        infected=other.infected;
        cycleNum=other.cycleNum;
        agents=other.agents;
        int agentSize = agents.size();
        for(int i=0;i<agentSize;i++)
            other.agents.at(i) = nullptr;
    }
    return *this;
}
void Session::copy(const Session &other) {
    //deep copy of infected queue
    infected=other.infected;
    //copy the agents vector
    for (Agent* agent:other.agents)
        addAgent(*agent);
}

void Session::clear() {
    for (Agent* agent:agents)
    {
        if (agent) {
            delete agent;
            agent=nullptr;
        }
    }
    while(!infected.empty())
        infected.pop();
    //the vectors in g have their own clear method when exiting a scope
}

//for constructor
Agent* Session::whichAgent(const string& a, const int num) {
    if (a=="V")
        return new Virus(num);
    else
        return new ContactTracer();
}

TreeType Session::whichType(const std::string &jsonTree) {
    if(jsonTree=="M")
        return MaxRank;
    else if(jsonTree=="R")
        return Root;
    else
        return Cycle;
}
//getters

TreeType Session::getTreeType() const {
    return treeType;
}
int Session::getCycleNum() const {
    return cycleNum;
}

Graph& Session::getGraph() {
    return g;
}
//setters

void Session::setGraph(const Graph &graph) {
    g.setEdges(graph.getEdges());
    g.setNodeState(graph.getNodesState());

}

void Session::setCycleNum() {
    cycleNum=cycleNum+1;
}
void Session::disconnectNode(int nodeToDisconnect) {
    vector<int> neighbors =g.getNeighbors(nodeToDisconnect);
    g.removeEdges(nodeToDisconnect,neighbors);
}

//queue
void Session::enqueueInfected(int a) {
    infected.push(a);
}

int Session::dequeueInfected() {
    if(infected.empty())
        return -1;
    else {
        int value = infected.front();
        infected.pop();
        return value;
    }
}
//for Virus
void Session::addAgent(const Agent &agent) {
    Agent* newAgent= agent.clone();
    agents.push_back(newAgent);

}

//Flow
void Session::simulate() {
    while(!terminate()) {
        int size = agents.size();
        for(int i=0;i<size;i++) {
            agents[i]->act(*this);
        }
        setCycleNum();
    }
}
bool Session:: terminate() {
    if (cycleNum != 0) {
        vector<int> nodeStates = g.getNodesState();
        int size = nodeStates.size();
        for (int i=0;i<size;i++) {
            vector<int> neighbors = g.getNeighbors(i);
            for (int neighbor:neighbors) {
                if (nodeStates.at(neighbor) != nodeStates.at(i))
                    return false;
            }
        }
        return true;
    }
    return false;
}






