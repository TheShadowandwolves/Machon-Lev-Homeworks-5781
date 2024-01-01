#include "Edge.h"

Edge::Edge(Vertex* destination)
{
    this->destination = destination;
}

bool Edge::operator==(Edge& v)
{
    return this->destination == v.destination;
}
