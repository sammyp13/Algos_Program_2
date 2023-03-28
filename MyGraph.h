//
// Created by saman on 10/27/2022.
//


#ifndef ALGOS_PROGRAM_2_MYGRAPH_H
#define ALGOS_PROGRAM_2_MYGRAPH_H
#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <unordered_set>
#include <algorithm>

/*
I will use an extension for this programming assignment
*/

struct Edge{
    int startEdge;
    int nextEdge;
    float weight;
};

class MyGraph {
private:
    int sumVertex;
    float finalAnnoy;
    std::vector<int> disjSet;
    std::vector<int> finalPath;
    std::vector<Edge> edgeVector;
    std::vector<std::vector<Edge>> mst;
    std::unordered_set<int> edgeSet;
    int findRoot(int n);
    void unionNodes(int vertexA, int vertexB);
    void DFS(std::unordered_set<int> &visitedNodes, int currNode, int endNode, float annoy, std::vector<int> &currPath);

public:
    MyGraph(int size);
    MyGraph(const MyGraph &g);
    bool AddEdge(int vertexA, int vertexB, float edgeWeight);
    void Output(std::ostream& os);
    void Kruskals();
    std::pair<std::vector<int>, float>HW2Prog(int start, int end);
};


/*
function definitions:
*/

MyGraph::MyGraph(int size){
    disjSet.resize(size +1);
    for(int i = 0; i < disjSet.size(); i++){
        disjSet[i] = i;
    }
    sumVertex = size;
    mst.resize(size + 1);
}

MyGraph::MyGraph(const MyGraph &g) {

}

bool MyGraph::AddEdge(int vertexA, int vertexB, float edgeWeight) {
    //vertices must be in ascending order:
    if(vertexA > vertexB){
        std::swap(vertexA, vertexB);
    }
    // if edge alrady exixts, return false:
    if(edgeSet.find(vertexA * sumVertex + vertexB) != edgeSet.end()){
        return false;
    } else{
        //if edge does not already exist, insert between vertexA and vertexB with edgeWeight:
        edgeSet.insert(vertexA * sumVertex + vertexB);
        //create Edge object to add to vector:
        Edge addEdge;
        addEdge.startEdge = vertexA;
        addEdge.nextEdge = vertexB;
        addEdge.weight = edgeWeight;
        //add new edge to vector:
        edgeVector.push_back(addEdge);
        return true;
    }
}

std::pair<std::vector<int>, float> MyGraph::HW2Prog(int start, int end) {
    std::unordered_set<int> visited;
    std::vector<int> path;
    DFS(visited, start, end, 0.0, path);
    return{finalPath, finalAnnoy};
}

int MyGraph::findRoot(int n) {
    while(n != disjSet[n]){
        n = disjSet[n];
    }
    return n;
}

void MyGraph::unionNodes(int vertexA, int vertexB) {
    disjSet[vertexA] = vertexB;
}

void MyGraph::Kruskals() {
    std::sort(edgeVector.begin(), edgeVector.end(),[](const Edge &edge1, const Edge &edge2){
        return edge1.weight < edge2.weight;
    });
    int edgeCount = 0;
    for(int i = 0; i < edgeVector.size() && (edgeCount) < (sumVertex - 1) ; i++){
        Edge e = edgeVector[i];
        int uSet = findRoot(e.startEdge);
        int vSet = findRoot(e.nextEdge);

        if(uSet != vSet){
            mst[e.startEdge].push_back(e);
            std::swap(e.startEdge, e.nextEdge);
            mst[e.startEdge].push_back(e);
            unionNodes(uSet, vSet);
        }
    }
}

void MyGraph::DFS(std::unordered_set<int> &visitedNodes, int currNode, int endNode, float annoy, std::vector<int> &currPath) {
    currPath.push_back(currNode);
    //if current node is already completed:
    if(currNode == endNode){
        finalPath = currPath;
        finalAnnoy = annoy;
        currPath.pop_back();
        return;
        //if contains a cycle:
    } else if(visitedNodes.find(currNode) != visitedNodes.end()){
        currPath.pop_back();
        return;
    }
    visitedNodes.insert(currNode);
    for(auto &edge :mst[currNode]){
        DFS(visitedNodes, edge.nextEdge, endNode, std::max(annoy, edge.weight), currPath);
    }
    currPath.pop_back();
}

void MyGraph::Output(std::ostream &os) {
    os << sumVertex << std::endl;
    for(int i = 0; i < mst.size(); i++){
        for(int j = 0; j < mst[i].size(); j++){
            os << mst[i][j].startEdge << " " << mst[i][j].nextEdge << " " << mst [i][j].weight << std::endl;
        }
    }
}

#endif //ALGOS_PROGRAM_2_MYGRAPH_H
