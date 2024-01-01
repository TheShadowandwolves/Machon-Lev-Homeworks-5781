#include "discussionNode.h"
#include "discussionTree.h"
discussionNode::discussionNode(){}


discussionNode::discussionNode(string content)
{
    this->content = content;
    
    
}



discussionNode::discussionNode(const discussionNode& node)
{
    this->content = node.content;
    this->responces = node.responces;
    
}



