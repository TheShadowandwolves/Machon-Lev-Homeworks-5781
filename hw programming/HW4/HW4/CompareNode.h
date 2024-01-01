#pragma once
#include "huffman.h"
class CompareNode
{

public:
    bool operator()(HuffmanNode* const& n1, HuffmanNode* const& n2)
    {
        return n1->frequency > n2->frequency;
    }


};