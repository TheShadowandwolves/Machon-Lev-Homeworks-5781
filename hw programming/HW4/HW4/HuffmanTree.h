#pragma once
#include <iostream>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <string>
#include <math.h>
#include "huffman.h"
#include "CompareNode.h"
#define nullptr NULL
using namespace std;

typedef priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareNode> huffmanQueue;

class HuffmanTree
{
private:
    huffmanQueue queue;
	map<char, int> freq_map;
	map<char, string> encode_map;
	map<string, char> decode_map;
	HuffmanNode* root;
	string sort, ecode, eTree, dcode;

	//calculates the frequency
	void calculateFreq(const string );
	// builds the tree (instead having it in the main file, moved it to the class
	void buildTree();
	
	void sortLetters(HuffmanNode* , string& );
	// encode functions
	void encodeTreeStruct( HuffmanNode* , string& );
	void encodeTree( HuffmanNode* , string );
	// decode functions
	void calculateCode(const string );
	void rebuildTree(HuffmanNode* , const string , const string , int& , int& );
	void decodeTree( HuffmanNode* , string );
	void decodeText(string );
	// clearing the tree with all maps
	void clearTree(HuffmanNode* );

public:
	//default constructor
	HuffmanTree();

	// start init.
	void init(const string);
	// start of rebuilding 
	bool re_init();
};

