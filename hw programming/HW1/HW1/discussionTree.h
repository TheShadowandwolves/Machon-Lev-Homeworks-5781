#pragma once
#include <string>
#include <list>
#include "discussionNode.h"

    //part 1,2
    class discussionTree : public discussionNode
    {
    private:
        discussionNode* root;
    public:
        //part 2a
        discussionTree();
        //part 2b
        ~discussionTree();
        void deleteTree(discussionNode*);
        //part 2c
        discussionTree(string);

        //part 2d
        discussionTree* find(string value);

        //part 2e
        bool add(string, string);

        //part 2f
        //given a string, deletes the subtree starting from the node that contains the string
        discussionNode* findParent(discussionNode*, discussionNode*);
        bool del(string);
        bool del(discussionNode*);
        void del();
        //part 2g
        void print();
        void print(string);
        void print(discussionNode*, int);
        
        //part 2h
        discussionNode* search(string);
        discussionNode* search(string, discussionNode*);

        friend class discussionList;
        friend class discussionNode;
    };

