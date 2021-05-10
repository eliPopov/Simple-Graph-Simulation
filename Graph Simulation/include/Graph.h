#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>

using namespace std;
class Session;
class Tree;
class Graph{
public:
    Graph();//done -empty vectors
    Graph(std::vector<std::vector<int>> matrix, std::vector<int> nodesState);//CHECK
    Graph(const Graph& graph);//copy constructor-CHECK
    vector<int> getNodesState() const;//done- not const//CHECK
    const vector<vector<int>>& getEdges() const;//done-not const//CHECK
    vector<int> getNeighbors(int node) const;
    int getNumOfNodes() const;
    void setEdges(const vector<vector<int>>& matrix );// done- override edges//CHECK
    void setNodeState(const vector<int>& state);//done- override nodesState//CHECK
    void removeEdges(int node,vector<int> &nodeNeighbors);
    vector<int> onlyInfected();
    void occupyNode(int nodeInd);//done- make it '2' in the nodesState
    void infectNode(int nodeInd);//done- make it '3' in the nodesState
    bool isInfected(int nodeInd);//done- is it '3' in the nodesState
    static void BFS(const Session &session, const Graph& graph, int nodeInd, Tree* bfsTree);
private:
    vector<vector<int>> edges;
    vector<int> nodesState;// 1 is healthy 2 is occupied and 3 is infected

};

#endif
