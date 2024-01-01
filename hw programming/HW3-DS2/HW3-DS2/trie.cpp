#include "trie.h"


// Returns true if root has no children, else false 
bool isEmpty(TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return false;
    return true;
}



TrieNode* getNode(void)
{
    return new TrieNode();
}

bool isLastNode(TrieNode* root)
{
    if (root->isWordEnd) {
        return false;
    }
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i]) {
            return false;
        }
    }
    return true;
}

bool insertT(TrieNode* root, string key)
{
    // base case: reached the end of the word
    if (key.empty()) {
        // mark the current node as the end of the word
        root->isWordEnd = true;
        return true;
    }

    int index = CHAR_TO_INDEX(key[0]);

    // create a new node if the path does not exist
    if (!root->children[index]) {
        root->children[index] = getNode();
    }

    // recurse to the next level
    return insertT(root->children[index], key.substr(1));
}
bool delT(TrieNode* root, string key)
{
    if (!root) {
        return false;
    }
    if (!searchT(root, key))
    {
        return false;
    }
    if (key == "") {
        return false;
    }
    TrieNode* prev = nullptr;
    delR(prev, root, key, 0);
    return true;
}


TrieNode* delR(TrieNode * prev, TrieNode * root, string key, int ind = 0)
{
    // If tree is empty 
    if (!root)
        return NULL;

    // If last character of key is being processed 
    if (ind == key.size()) {

        // This node is no more end of word after 
        // removal of given key 
        if (root->isWordEnd)
            root->isWordEnd = false;

        // If given is not prefix of any other word 
        if (isEmpty(root)) {
            delete (root);
            root = NULL;
        }

        return root;
    }

    // If not last character, recur for the child 
    // obtained using ASCII value 
    prev = root;
    int index = key[ind] - 'a';
    root->children[index] =
        delR(prev,root->children[index], key, ind + 1);

    // If root does not have any child (its only child got  
    // deleted), and it is not end of another word. 
    if (isEmpty(root) && root->isWordEnd == false) {
        delete (root);
        root = NULL;
    }

    return root;
}

 bool searchT(TrieNode * root, string key)
{
    int len = key.length();
    TrieNode* curr = root;

    for (int i = 0; i < len; i++) {
        int index = CHAR_TO_INDEX(key[i]);
        if (!curr->children[index]) {
            return false;
        }
        curr = curr->children[index];
    }
    // if the current node is a leaf node, then the key exists in the Trie
    return curr->isWordEnd;
}

void suggestionsRec(TrieNode * root, string currPrefix)
{
    // if this is a leaf node, then it represents the end of a word
    if (root->isWordEnd) {
        cout << currPrefix << endl;
    }
    // traverse all children of the current node
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i]) {
            // append the current character to the current prefix
            currPrefix.push_back(97 + i);

            // recursively get the suggestions for the current prefix
            suggestionsRec(root->children[i], currPrefix);

            // remove the last character from the prefix
            currPrefix.pop_back();
        }
    }
}

// function to get all suggestions for the given query
int printAutoSuggestionsT(TrieNode* root, string query) {
    TrieNode* curr = root;
    int len = query.length();
    string currPrefix;

    // traverse the Trie
    for (int i = 0; i < len; i++) {
        int index = CHAR_TO_INDEX(query[i]);

        // if the current character is not present in the Trie, then return 0
        if (!curr->children[index]) {
            return 0;
        }

        // append the current character to the current prefix
        currPrefix.push_back(query[i]);
        curr = curr->children[index];
    }

    // if the current node is a leaf node, then the query exists in the Trie
    if (curr->isWordEnd) {
        cout << query << endl;
    }

    // get all the suggestions for the current prefix
    suggestionsRec(curr, currPrefix);

    // return 1 to indicate that the query exists in the Trie
    return 1;
}

//print tree
void printT(TrieNode* t, int level)
{
    string line = "";
    for (int l = 1; l <= level; l++) {
        line += " ";
    }

    // traverse through all of the children of the current node
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (t && t->children[i] != nullptr) {
            // print the current letter
            cout << line << (char)('a' + i) << ":" << endl;
            // call the function recursively on the child node
            printT(t->children[i], level + 1);
        }
    }
}
