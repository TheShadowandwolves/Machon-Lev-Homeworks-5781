#pragma once
#include <string>
#include <list>
using namespace std;
class discussionNode
{

private:
    string content;
    list<discussionNode*> responces;
    

public:
    discussionNode();
    discussionNode(string);
   
    discussionNode(const discussionNode&);
    friend class discussionTree;
    friend class discussionList;
};

