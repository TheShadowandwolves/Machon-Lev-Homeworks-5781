#include "discussionTree.h"
#include <iostream>
using namespace std;
discussionTree::discussionTree()
{
    this->root = new discussionNode();
}

/// destructor deletes if node->responces is empty, if not call deleteTree function with each node
discussionTree::~discussionTree()
{

    /*delete this->root;*/
    /*this->root->responces.clear();*/

}
// calls the nodes destructor
// the destructor will check if it is empty and if not it will call the deleteTree function inside the nodes again
void discussionTree::deleteTree(discussionNode* node)
{
    delete node;
}

discussionTree::discussionTree(string content)
{
    this->root = new discussionNode(content);
}

// find function, searches same node as string
discussionTree* discussionTree::find(string searched_Value)
{
    //if the root is the searched value, return the root
    if (this->root->content == searched_Value)
    {
        return this;
    }
    //if the root is not the searched value, search in the responces
    else
    {
        //if the responces list is empty, return null
        if (this->root->responces.empty())
        {
            return NULL;
        }
        //if the responces list is not empty, search in the responces
        else
        {

            // create a list iterator
            list<discussionNode*>::iterator it;
            //create a pointer to a discussionTree
            discussionTree* temp;
            //iterate through the responces list
            for (it = this->root->responces.begin(); it != this->root->responces.end(); it++)
            {
                //create a discussionTree with the current node as root
                temp = new discussionTree((*it)->content);

                if (find(temp->content)) {
                    return temp;
                }
            }
           
        }
    }
    return NULL;
}

// add function
bool discussionTree::add(string father, string child)
{
    //if the root is the father, add the child to the responces list
    discussionNode* fatherNode = search(father);

    if (fatherNode)
    {
        fatherNode->responces.push_back(new discussionNode(child));
        return true;
    }
    
    else
        return false;
}


//that should find the parent of a given node
discussionNode* discussionTree::findParent(discussionNode* child, discussionNode* father)
{

    discussionNode* temp = nullptr;
    // if child is already on top and there isn't a father above - return nullptr
    if (child == this->root) { 
        return temp;
    }
    // finds the father of the child
    temp = search(child->content);
    if (temp) {
        if (father->responces.size() > 0) {
            for (list<discussionNode*>::iterator it = father->responces.begin(); it != father->responces.end(); it++) {

                if ((*it)->content == child->content) {
                    return father;
                }
                else if ((*it)->responces.size() > 0) {
                      temp = findParent(child, (*it));
                }
                    
            }
        }
    }
    return temp;
    
}


//deletes a node with the same string name

bool discussionTree::del(string subtree)
{
    discussionNode* node = search(subtree);
    if (node && node != this->root) { 
        return del(node);
    }
    return false;
    

}
// deletion function, given a node that needs to be deleted 
bool discussionTree::del(discussionNode* node)
{
    discussionNode* father = findParent(node, this->root);
    for (list<discussionNode*>::iterator it = father->responces.begin(); it != father->responces.end(); ++it)
        if ((*it)->content == node->content) {
            //should erase the responce that is the string
            father->responces.erase(it);
            /*delete* it;*/
            return true;
        }
    return false;
}
//if not given a string or not, just call deletion on that object
void discussionTree::del()
{
    del(this);
}
//print
void discussionTree::print()
{
    print(root, 0);
}
//print with a string that corresponce a content of a node
void discussionTree::print(string comment)
{
    return print(search(comment), 0);
}
//print of a node, counter is the spacing 
void discussionTree::print(discussionNode* node, int counter)
{
    for (int i = 0; i < counter; ++i) {
        cout << " ";
    }

    //looking if content is nothing
    /*if (!node->responces.size())
        return;*/
    cout << node->content << endl;
    if (node->responces.size() == 0)  
    {
        return;
    }
    //if the responces list is not empty, search in the responces
    else
    {
        if (node->responces.size() > 0) {
            for (list<discussionNode*>::iterator it = node->responces.begin(); it != node->responces.end(); it++) {
                
                print((*it), counter+1);
            }
        }
    }
}
//search function, similar to find
discussionNode* discussionTree::search(string node) {
    return search(node, this->root);
}

discussionNode* discussionTree::search(string searched_Value, discussionNode* node)
{
    //if the root is the searched value, print the root
    discussionNode* n = nullptr;
    if (node->content == searched_Value)
    {
        return node;
    }

    //if the responces list is not empty, search in the responces
    else
    {
        if (node->responces.size() > 0) { //nullptr callout problem!!!

            for (list<discussionNode*>::iterator it = node->responces.begin(); it != node->responces.end(); ++it) {
                if ((*it)->content == searched_Value) {
                    return (*it);
                }
                else
                {
                    //return
                    n = search(searched_Value, (*it));
                    if (n)
                        return n;
                }

            }
        }
    }
    return n;
}
