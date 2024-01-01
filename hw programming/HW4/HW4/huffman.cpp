#include "huffman.h"
// Default constructor
HuffmanNode::HuffmanNode() {}

// Parameterized constructor
HuffmanNode::HuffmanNode(char s, int f) : str(s), frequency(f){}

HuffmanNode::HuffmanNode(HuffmanNode* right, HuffmanNode* left)
{
    this->right = right;
    this->left = left;
}

HuffmanNode::HuffmanNode(char s, int f, HuffmanNode* right, HuffmanNode* left) : str(s), frequency(f), left(left), right(right)
{
}

// Destructor
/*HuffmanNode::~HuffmanNode() {
    delete left;
    delete right;
}*/

// Copy constructor
HuffmanNode::HuffmanNode(const HuffmanNode* other) {
    str = other->str;
    frequency = other->frequency;
    if (other->left) {
        left = other->left;
    }
    if (other->right) {
        right = other->right;
    }
}
// Copy assignment operator
HuffmanNode& HuffmanNode::operator=(const HuffmanNode* other)
{
    this->str = other->str;
    this->frequency = other->frequency;
    this->left = (other->left) ? new HuffmanNode(other->left) : nullptr;
    this->right = (other->right) ? new HuffmanNode(other->right) : nullptr;
    return *this;
}

void HuffmanNode::setRight(HuffmanNode* right)
{
    this->right = right;
}

void HuffmanNode::setLeft(HuffmanNode* left)
{
    this->left = left;
}

void HuffmanNode::setFrequency(int freq)
{
    this->frequency = freq;
}

void HuffmanNode::setChar(char str)
{
    this->str = str;
}

HuffmanNode* HuffmanNode::getRight()
{
    return this->right;
}

HuffmanNode* HuffmanNode::getLeft()
{
    return this->left;
}

int HuffmanNode::getFrequency()
{
    return this->frequency;
}

char HuffmanNode::getChar()
{
    return this->str;
}


