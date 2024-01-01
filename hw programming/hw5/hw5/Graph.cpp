#include "Graph.h"

Graph::Graph()
{
}

Graph::~Graph()
{
    for (Vertex* v : vertices) {
        delete v;
    }
    for (Edge* e : edges) {
        delete e;
    }
}

void Graph::addvertex(string str)
{
    vertices.insert(new Vertex(str));

}

bool Graph::delvertex(string str)
{
    for (Edge* e : edges) {
        if (e->destination->Key == str) {
            delete e;
            edges.erase(e);
        }
    }
    for (Vertex* v : vertices) {
        if (v->Key == str) {
           
            for (auto e = v->EdgeList.begin(); e != v->EdgeList.end(); e++) {
                delete &e;
            }
            v->EdgeList.clear();
            vertices.erase(v);
            delete v;
            return true;
        }
        
    }
    return false;
}

bool Graph::addedge(string from, string to)
{
    Vertex* vto;
    Vertex* vfrom;

    for (Vertex* s : vertices) {
        if (s->Key == from) {
            vfrom = s;
        }
        if (s->Key == to) {
            vto = s;
        }
    }
    if (vfrom != nullptr && vto != nullptr) {
        Edge* newt = new Edge(vto);
        vfrom->EdgeList.push_back(newt);
        edges.insert(newt);
        return true;
    }
    else
    {
        return false;
    }
}

bool Graph::deledge(string from, string to)
{
    for (Vertex* v : vertices) {
        for (auto f = v->EdgeList.begin(); f != v->EdgeList.end(); f++) {
            if (f->destination->Key == to) {
                delete &f;
            }
        }
    }
    for (Edge* e : edges) {
        if (e->destination->Key == from) {
            delete e;

        }
    }
}

void Graph::printNeighbors(string str)
{
    Vertex* v = searchVertex(str);

    cout << "Vertices with an edge from " << v->Key << ": ";
    for (auto e = v->EdgeList.begin(); e != v->EdgeList.end(); e++) {
        cout << e->destination->Key << " ";
    }
    cout << endl;
}

void Graph::printFollowers(string str)
{
    Vertex* v = searchVertex(str);
    cout << "Vertices with an edge to " << v->Key << ": ";
    for (Edge* e :edges) {
        if (e->destination == v)
            cout << e->destination->Key << " ";
    }
    cout << endl;
}

void Graph::printreachable(Vertex* v)
{
    cout << "Vertices reachable from " << v->Key << ": ";
    unordered_set<Vertex*> visited;
    dfs(v, visited);
    cout << endl;
}

void Graph::printAll()
{
    for (Vertex* v : vertices) {
        cout << v->Key << endl;
        for (auto e = v->EdgeList.begin(); e != v->EdgeList.end(); e++) {
            cout << "->" << e->destination->Key << endl;
        }
    }
}

void Graph::printDistance2NotFollowedYet(string str)
{
    Vertex* v = searchVertex(str);

}

Vertex* Graph::searchVertex(string s)
{
    for (auto i : vertices) {
        if (i->Key == s) {
            return i;
        }

    }
    return NULL;
}

void Graph::dfs(Vertex* v, unordered_set<Vertex*>& visited)
{

    visited.insert(v);
    cout << v->Key << " ";
    for (auto e = v->EdgeList.begin(); e != v->EdgeList.end(); e++) {
        Vertex* neighbor = e->destination;
        if (!visited.count(neighbor)) {
            dfs(neighbor, visited);
        }
    }
}


