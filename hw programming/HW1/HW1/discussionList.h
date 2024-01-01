#pragma once
#include <string>
#include "discussionTree.h"
using namespace std;

class discussionList
{
private:
    list<discussionTree*> trees;
public:
    //part 3a
    //done
    discussionList();
    //part 3b

    ~discussionList();
    //part 3c
    //done
    void addNewTree(string);
    //part 3d
    //deletes a discussion tree given a pointer to the tree's root
    /*bool delTree(discussionNode*, string);*/
    //part 3e
    //done
    void searchAndPrint(string);
    //part 3f
    //adds a discussion to a given tree, given the tree's root and the father's content
    //done
    bool addResponse(string, string, string);
    //part 3g
    //deletes a discussion from a given tree, given the tree's root and the father's content
    bool delResponse(string, string);
    //part 3h
    //done
    void printAllTrees();
    //part 3i
    //done, problem with secondary subtrees not showing up
    void printSubTree(string, string);
};



