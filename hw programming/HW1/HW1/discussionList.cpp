#include "discussionList.h"
#include <list>
#include <string>
#include <iostream>
using namespace std;
discussionList::discussionList()
{
    this->trees = list<discussionTree*>();
}

discussionList::~discussionList()
{
    //delete all trees
    for (list<discussionTree*>::iterator it = this->trees.begin(); it != this->trees.end(); it++)
    {
        delete* it;
    }
}

void discussionList::addNewTree(string val)
{
    //create a new tree
    discussionTree* temp = new discussionTree(val);
    //add the tree to the list
    this->trees.push_front(temp);
}

//bool discussionList::delTree(discussionNode* tree, string node)
//{
//    
//    //create a list iterator
//    list<discussionNode*>::iterator it;
//    //iterate through the list
//    for (it = tree->responces.begin(); it != tree->responces.end(); it++)
//    {
//        //if the current tree's root is the tree to be deleted, delete the tree
//        if ((*it)->content == node)
//        {
//            delete *it;
//            
//            return true;
//        }
//    }
//    return false;
//}

void discussionList::searchAndPrint(string search_val)
{
    //if list is empty return null
    if (this->trees.empty())
    {
        return;
    }
    //if list is not empty, search in the list
    else
    {
       
        //iterate through the list
        for (list<discussionTree*>::iterator it = this->trees.begin(); it != this->trees.end(); it++)
        {
            ((*it)->print(search_val));
        }
    }
}

bool discussionList::addResponse(string root_node, string responce_to, string wants_delete)
{
    //if list is empty return null
    if (this->trees.empty())
    {
        return false;
    }
    //if list is not empty, search in the list
    else
    {
        //create a list iterator
        list<discussionTree*>::iterator it;
        //iterate through the list
        for (it = this->trees.begin(); it != this->trees.end(); it++)
        {
            if ((*it)->root->content == root_node)
            {
                
                if((*it)->add(responce_to, wants_delete))
                    return true;
            }
        }
        return false;
    }
}

bool discussionList::delResponse(string root_node, string wants_delete)
{   
    //if list is empty return null
    if (this->trees.empty())
    {
        return false;
    }
    //if list is not empty, search in the list
    else
    {
        
        //create a list iterator

        //iterate through the list
        for (list<discussionTree*>::iterator it = this->trees.begin(); it != this->trees.end(); it++)
        {
            //if the current tree's root is the tree to be deleted, delete the tree
            
            if ((*it)->root->content == root_node)
            {
                if ((*it)->del(wants_delete)) {
                    return true;
                }
                
            }
           
        }
        return false;
    }
}

void discussionList::printAllTrees()
{
    int num = 0;
    //receives a string which is the root of the tree, and prints the whole tree, in a hierarchical display
    if (this->trees.empty())
    {
        return;
    }
    else
    {
        
        //iterate through the list
        for (list<discussionTree*>::iterator it = this->trees.begin(); it != this->trees.end(); it++)
        {
            num++;
            cout << "Tree #" << num << endl;
                (*it)->print();
                cout << endl;
            
        }
    }
}

void discussionList::printSubTree(string root_node, string discussion_string)
{
    //prints the whole sub-tree of a given discussion
    if (this->trees.empty())
    {
        return;
    }
    else
    {
       
        //iterate through the list
        for (list<discussionTree*>::iterator it = this->trees.begin(); it != this->trees.end(); it++)
        {
            if ((*it)->root->content == root_node) {
                (*it)->print(discussion_string);
            }
        }
    }
}
