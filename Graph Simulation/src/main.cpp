#include <iostream>
#include "../include/Tree.h"
#include "../include/Graph.h"
#include "../include/Agent.h"
#include "../include/Session.h"
#include "../include/json.hpp"
#include <fstream>

using namespace std;
using json = nlohmann::json;

int main(int argc, char** argv){
    if(argc != 2){
        cout << "usage cTrace <config_path>" << endl;
        return 0;
    }

Session sess(argv[1]);
    sess.simulate();

    //output file
    vector<vector<int>> graph= sess.getGraph().getEdges();
    vector<int> infected(sess.getGraph().onlyInfected());//move
    json output;
    output["graph"]=graph;
    output["infected"]=infected;
    ofstream i("output.json");
    i<<output;
    cout << output << endl;
    return 0;

}
