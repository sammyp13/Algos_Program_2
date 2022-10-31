//
// Created by saman on 10/27/2022.
//

/*
I will use an extension for this programming assignment
*/


#ifndef ALGOS_PROGRAM_2_MYGRAPH_H
#define ALGOS_PROGRAM_2_MYGRAPH_H
#include <fstream>
#include <list>
#include <vector>

class MyGraph {
private:
    int n;
    int e;

    typedef std::pair<int, int> vertexPair;


public:
    MyGraph(int n);
    MyGraph(const MyGraph & g);
    bool AddEdge(int a, int b, float w);
    void Output(std::ostream& os);
    std::pair<std::vector<int>, float>HW2Prog(int s, int t);
};


/*
function definitions:
*/

MyGraph::MyGraph(int n){
    n = n;
}

MyGraph::MyGraph(const MyGraph &g) {
    n = g.n;
}

bool MyGraph::AddEdge(int a, int b, float w) {
    std::vector<std::pair<float, vertexPair>> edge;
    edge.push_back({w, {a, b}});
    //TODO:add edge between vertex a and b, with weight w
    //TODO:if edge already exists or a vertex is not on graph
    return false;
    //TODO:else
    return true;
}

void MyGraph::Output(std::ostream &os) {
    //TODO:Line 1: number of vertices
    //TODO:Line 2: two vertices associated with edge (smallest first), weight of edge. One space character between numbers, no space at the end

}

std::pair<std::vector<int>, float> MyGraph::HW2Prog(int s, int t) {
    //TODO:find least annoying path from s to t
    // return a pair ((vector) path from s to t, (float) actual annoyance))
    return std::pair<std::vector<int>, float>();
}


#endif //ALGOS_PROGRAM_2_MYGRAPH_H
