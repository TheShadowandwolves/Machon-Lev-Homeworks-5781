// HW4.cpp : 
/*
Leonard Blam 900086
HW 4 Huffman Code
*/

#include <iostream>
#include "HuffmanTree.h"

using namespace std;

int main()
{
    int choice, n;
    string word, letter, order, code;
    HuffmanTree* Tree = new HuffmanTree();
   
    cout << "enter 1 to encode a text\n";
    cout << "enter 2 to decode a text\n";
    cout << "enter 3 to exit\n";

    do
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            // Prompt the user for the input text
            cout << "Enter the original text:" << endl;
            cin >> word;

            // Build a frequency table for each character in the input text
            Tree->init(word);
            
            break;
        case 2:
            
            //build the Huffman Tree according to the tree strcture. put the letters in the leaves according to the given order. 
            Tree->re_init();
            break;
        }
    } while (choice != 3);
    return 0;
}
