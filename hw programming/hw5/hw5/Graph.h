#pragma once
#include <list>
#include <iostream>
#include <string>
#include <unordered_set>
#include "Edge.h"
#include "Vertex.h"
using namespace std;
class Graph
{
    unordered_set<Vertex*> vertices;
    unordered_set<Edge*> edges;
public:
    Graph(); // initializes the graph to a graph
    ~Graph();// delete graph
    void addvertex(string); // add a vertex to the graph
    bool delvertex(string); // delete a vertex and all edges that are incident (to or from) it
    bool addedge(string, string); // add and edge to the graph (making sure that it is not yet there)
    bool deledge(string, string); // delete an edge
    void printNeighbors(string str); // given v print all vertices u that have an edge from v to u
    void printFollowers(string); // print all vertices u that have an edge from u to v
    void printreachable(Vertex*); // prints all vertices that are reachable from v
    void printAll(); // print entire graph
    void printDistance2NotFollowedYet(string);
    Vertex* searchVertex(string);
private:
    void dfs(Vertex*, unordered_set<Vertex*>&);
};

