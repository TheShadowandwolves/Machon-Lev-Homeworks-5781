#pragma once
#include <string>
#include<iostream>
using namespace std;


class HuffmanNode
{
private:
    friend class CompareNode;
    char str;
    int frequency;
    HuffmanNode* left = nullptr;
    HuffmanNode* right = nullptr;
public:
    

    // Default constructor
    HuffmanNode();

    // Parameterized constructor
    HuffmanNode(char s, int f);

    // leaf constructor
    HuffmanNode(HuffmanNode* right, HuffmanNode* left);
    // full constructor
    HuffmanNode(char s, int f, HuffmanNode* right, HuffmanNode* left);

    // Destructor
    //~HuffmanNode();

    // Copy constructor
    HuffmanNode(const HuffmanNode* other);

    // Copy assignment operator
    HuffmanNode& operator=(const HuffmanNode* other);


    // get and set functions
    void setRight(HuffmanNode* right);
    void setLeft(HuffmanNode* left);
    void setFrequency(int freq);
    void setChar(char str);
    HuffmanNode* getRight();
    HuffmanNode* getLeft();
    int getFrequency();
    char getChar();
};
