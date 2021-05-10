#include <vector>
#include <queue>
#include "..//include/Graph.h"
#include "../include/Tree.h"
using namespace std;
class Agent;

Graph::Graph() : edges(),nodesState(){}
Graph::Graph(std::vector<std::vector<int>> matrix, std::vector<int> nodesState):edges(matrix),nodesState(nodesState) {}
Graph::Graph(const Graph &graph): edges{},nodesState{} {
    setEdges(graph.edges);
    setNodeState(graph.nodesState);
}

//getters
const vector<vector<int>>& Graph::getEdges() const {
    return edges;
}
vector<int> Graph::getNodesState() const{
    return nodesState;
}
vector<int> Graph::getNeighbors(int node) const{
    std::vector<int> neighbors;
    int size = edges.size();
    for(int i=0;i<size;i++){
        if(edges[node][i]==1)
            neighbors.push_back(i);
    }
    return neighbors;
}
int Graph::getNumOfNodes() const{
    return nodesState.size();
}
//setters
void Graph::setNodeState(const vector<int>& state) {
    nodesState=state;
}

void Graph::setEdges(const vector<vector<int>> &matrix) {
    edges=matrix;
}
void Graph::removeEdges(int node,vector<int> &nodeNeighbors) {
    for(int index:nodeNeighbors){
        edges.at(node).at(index) = 0;
        edges.at(index).at(node) = 0;
    }
}
vector<int> Graph::onlyInfected() {
    vector<int> output;
    int nodeSize = nodesState.size();
    for(int i=0;i<nodeSize;i++){
        if(nodesState.at(i)==3)
            output.push_back(i);
    }
    return output;
}
//set the nodesState
void Graph::occupyNode(int nodeInd) {
    nodesState[nodeInd]=2;
}
void Graph::infectNode(int nodeInd) {
    nodesState[nodeInd]=3;
}

bool Graph::isInfected(int nodeInd) {
    if(nodesState[nodeInd]==3)
        return true;
    return false;

}
void Graph::BFS(const Session &session, const Graph& graph, int nodeInd, Tree* bfsTree){
    queue<Tree*> bfsQ;
    int nodes = graph.getNumOfNodes();
    vector<bool> visited(nodes,false);
    bfsQ.push(bfsTree);
    visited[nodeInd] = true;
    vector<int> neighbors;
    while(!bfsQ.empty()){
        Tree* currTree(bfsQ.front());//pointer on the stack
        neighbors = graph.getNeighbors(currTree->getNode());
        for(int neighbor:neighbors) {
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                Tree* currChild = Tree::createTree(session,neighbor);
                bfsQ.push(currChild);
                currTree->addChild(currChild);
            }
        }
        bfsQ.pop();
    }
}
