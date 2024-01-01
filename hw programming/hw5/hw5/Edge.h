#pragma once
#include "Vertex.h"
class Edge
{
public:
    Vertex* destination;
public:
    Edge(Vertex* destination);
    bool operator==(Edge& v);
    friend class Vertex;
    friend class Graph;
};

