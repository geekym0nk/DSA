#include "WordNode.h"

TrieNode::TrieNode(char data){
    this->data = data;
    children = new TrieNode*[TOTAL_ALPHA_COUNT];
    isEndOfWord = false;

}

TrieNode::~TrieNode() {
    cout << "Deleting all the children nodes.." << endl;

    delete[] *children;
}
