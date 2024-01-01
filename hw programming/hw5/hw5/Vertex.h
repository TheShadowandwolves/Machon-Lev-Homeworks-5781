#pragma once
#include <string>
#include <iostream>
#include <list>
#include "Edge.h"
using namespace std;

enum Color {White, Gray, Black};
class Vertex;
class Edge;
class Vertex
{
    string Key;
    Color color;
    list<Edge> EdgeList;
public:
    Vertex(string key);
    void adde(Edge);
    int numOfNeighbours();
    bool destinationExists(Vertex* v);
    void print();
    friend class Graph;
    friend class Edge;
};

