#include <string.h>
#include <iostream>

using namespace std;

#define TOTAL_ALPHA_COUNT 26

class TrieNode {
    public :

        char data;
        TrieNode **children;
        bool isEndOfWord;

        /* Constructor */
        TrieNode(char);

        /* Destructor */
        ~TrieNode();
};