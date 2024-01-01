#include "Vertex.h"

Vertex::Vertex(string key)
{
    this->Key = key;
    this->color = White;
    this->EdgeList.clear();
}

void Vertex::adde(Edge e)
{
    EdgeList.push_back(e);
}

int Vertex::numOfNeighbours()
{
    return EdgeList.size();
}

bool Vertex::destinationExists(Vertex* v)
{
    for (auto e = v->EdgeList.begin(); e != v->EdgeList.end(); e++) {
        if (e->destination == v) {
            return true;
        }
    }
    return false;
}

void Vertex::print()
{
    cout << "Vertex: " << Key << endl;
    cout << "Neighbors: ";
    for (auto e = this->EdgeList.begin(); e != this->EdgeList.end(); e++) {
        cout << e->destination->Key << " ";
    }
    cout << endl;
}
