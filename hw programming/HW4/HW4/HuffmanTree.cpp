#include "HuffmanTree.h"


void HuffmanTree::calculateFreq(const string sentence)
{
	// gets each letters frequency
	for (int i = 0; i < sentence.size(); i++)
		freq_map[sentence[i]]++;
}
// This is responsible for building the Huffman tree based on the frequency of the characters in the input string.
void HuffmanTree::buildTree()
{
	HuffmanNode* left,* right,* top;

	//create a pair and add it to the priority queue
	for (map<char, int>::iterator it = freq_map.begin(); it != freq_map.end(); ++it)
		queue.push(new HuffmanNode(it->first, it->second));

	//iterates over the queue and each time pops two nodes and creates a top
	while (queue.size() != 1)
	{
		left = queue.top();
		queue.pop();
		right = queue.top();
		queue.pop();
		//create new HuffmanNode with both
		
		top = new HuffmanNode('%', (left->getFrequency() + right->getFrequency()), right, left);
		queue.push(top);
	}

	root = queue.top();
}
// This is used to traverse the tree in-order and append the characters of each leaf node, 
//which represents an alphabet from the original sentence, to a given string, in the order that they appear in the tree.
void HuffmanTree::sortLetters(HuffmanNode* curr, string& str)
{
	if (!curr)
		return;

	sortLetters(curr->getLeft(), str);

	if (curr->getChar() != '%')
		str += curr->getChar();

	sortLetters(curr->getRight(), str);
}
//This is used to traverse the tree and encode its structure by appending a "0" to the given string for each internal node
//and a "1" for each leaf node, to keep track of the tree structure while decoding.
void HuffmanTree::encodeTreeStruct(HuffmanNode* curr, string& str)
{
	if (!curr)
		return;

	if (curr->getLeft() || curr->getRight())
	{
		str += "0";
		encodeTreeStruct(curr->getLeft(), str);
		encodeTreeStruct(curr->getRight(), str);
	}
	else str += "1";
}

void HuffmanTree::encodeTree(HuffmanNode* curr, string str)
{
	if (!curr)
		return;

	encodeTree(curr->getLeft(), str + "0");

	//if the curr HuffmanNode is a leaf then adds it to the map of _encodedMap
	if (curr->getChar() != '%')
		encode_map[curr->getChar()] = str;

	encodeTree(curr->getRight(), str + "1");
}

void HuffmanTree::calculateCode(const string sentence)
{
	for (int i = 0; i < sentence.size(); i++)
		eTree += encode_map[sentence[i]];
}

void HuffmanTree::rebuildTree(HuffmanNode* curr, const string letters, const string encodedStructure, int& i, int& j)
{
	// '0' -> is a leaf
	if (encodedStructure[j] == '0')
	{
		curr->setChar('%');
		curr->setFrequency(1);
		curr->setLeft(new HuffmanNode());
		curr->setRight(new HuffmanNode());
		//recursive call with increment
		rebuildTree(curr->getLeft(), letters, encodedStructure, i, ++j);
		rebuildTree(curr->getRight(), letters, encodedStructure, i, ++j);
	}
	// '1' -> is a parent
	else if (encodedStructure[j] == '1')
	{
		//sets it to the letter at the ith place 
		curr->setChar(letters[i++]);
		curr->setFrequency(1);
	}
}

void HuffmanTree::decodeTree(HuffmanNode* curr, string str)
{
	if (!curr)
		return;

	decodeTree(curr->getLeft(), str + "0");

	// if is a leaf
	if (curr->getChar() != '%')
		decode_map[str] = curr->getChar();

	decodeTree(curr->getRight(), str + "1");
}

void HuffmanTree::decodeText(string encodedText)
{
	string temp;

	for (string::iterator it = encodedText.begin(); it != encodedText.end(); ++it)
	{
		temp += *it;

		//if the prefix exists 
		if (decode_map.find(temp) != decode_map.end())
		{
			this->dcode += decode_map[temp];
			temp.clear();
		}
	}
}

void HuffmanTree::clearTree(HuffmanNode* curr)
{
	// Recursively deletes the tree
	if (curr)
	{
		if (curr->getLeft())
			clearTree(curr->getLeft());
		if (curr->getRight())
			clearTree(curr->getRight());
		delete curr;
	}
		this->queue = huffmanQueue();

		freq_map.clear();
	encode_map.clear();
	decode_map.clear();
	sort.clear();
	ecode.clear();
	eTree.clear();
	dcode.clear();
	root = nullptr;
}

HuffmanTree::HuffmanTree() : root(nullptr) {}

void HuffmanTree::init(const string sentence)
{
	if (root)
		clearTree(root); //clears the previous HuffmanTree

	cout << "The encoded string is" << endl;

	calculateFreq(sentence);
	cout << freq_map.size() << "\n";

	buildTree();

	sortLetters(root, sort);
	cout << sort << "\n";

	encodeTreeStruct(root, ecode);
	cout << ecode << "\n";

	encodeTree(root, "");

	calculateCode(sentence);
	cout << eTree << "\n";
}

bool HuffmanTree::re_init()
{
	int n;
	string letters, encodedStructure, encodedText;
	//input the number of leaves, the  order of letters, tree structure and the encoded text.
	cin >> n;
	cin >> letters;
	cin >> encodedStructure;
	cin >> encodedText;



	//the length must be 2n-1
	if ((2 * n - 1) != encodedStructure.length())
	{
		cout << "ERROR" << endl;
		return false;
	}

	if (root)
		clearTree(root);

	root = new HuffmanNode();

	int firstIndex = 0, secondIndex = 0;

	rebuildTree(root, letters, encodedStructure, firstIndex, secondIndex);

	for (auto i = encodedText.begin(); i != encodedText.end() ; i++)
	{
		if (*i != '0' || *i != '1') {
			return false;
		}
	}

	decodeTree(root, "");
	decodeText(encodedText);

	cout << "The decoded string is\n" << dcode << "\n";
	return true;
}
