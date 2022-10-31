//
// Created by saman on 10/27/2022.
//

#ifndef ALGOS_PROGRAM_2_MYGRAPH_H
#define ALGOS_PROGRAM_2_MYGRAPH_H
#include <fstream>
#include <vector>

class MyGraph {
private:
    int n;



public:
    MyGraph(int n); //creates a graph with n vertices, labelled 1..n
    MyGraph(const MyGraph & g); //construct a new graph that is a copy of g
    bool AddEdge(int a, int b, float w); //add an edge between vertex a and b, with weight w
                                        //if the edge already exists or a vertex is not on the graph, do nothing and return false, otherwise return true
    void Output(std::ostream& os);  // Output the graph to the ostream& specified.
    std::pair<std::vector<int>, float>HW2Prog(int s, int t); //main function that finds least annoying path from s to t.
                                                                // Will return a pair(vector path from s to t, float actual annoyance)
};


//function definitions:
MyGraph::MyGraph(int n){
    this -> n = n;
}

MyGraph::MyGraph(const MyGraph &g) {
    n = g.n;
}

bool MyGraph::AddEdge(int a, int b, float w) {
    return false;
}

void MyGraph::Output(std::ostream &os) {

}

std::pair<std::vector<int>, float> MyGraph::HW2Prog(int s, int t) {
    return std::pair<std::vector<int>, float>();
}


#endif //ALGOS_PROGRAM_2_MYGRAPH_H
