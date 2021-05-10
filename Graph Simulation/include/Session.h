#ifndef SESSION_H_
#define SESSION_H_
#include "../include/Agent.h"
#include <vector>
#include <string>
#include "Graph.h"
#include <queue>
using namespace std;

enum TreeType{
    Cycle,
    MaxRank,
    Root
};

class Session{
public:
    Session(const std::string& path);// done

    //destructor
    virtual ~Session();//ENDLESS LOOP? enable [noreturn]
    //copy constructor
    Session(const Session& other);//done
    //copy assignment operator
    Session& operator=(const Session& other);//done
    //move constructor
    Session ( Session&& other);//done
    //move assignment operator
    Session& operator=(Session&& other);

    void addAgent(const Agent& agent);// for Virus
    void simulate();
    int getCycleNum() const;
    TreeType getTreeType() const;//done
    void setCycleNum();//done
    Graph& getGraph();
    void disconnectNode(int nodeToDisconnect);
    void setGraph(const Graph& graph);// done- need to check : const?
    void enqueueInfected(int);//done
    int dequeueInfected();//done
    bool terminate();
private:
    Graph g;
    TreeType treeType;
    vector<Agent*> agents;
    queue<int> infected;
    int cycleNum;

    TreeType whichType(const std::string &jsonTree);//done
    static Agent* whichAgent(const string& a,const int num);//done
    void clear();//done
    void copy(const Session& other);//done
};


#endif
