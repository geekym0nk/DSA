#include "WordNode.h"

class Dictionary {
    public :
        TrieNode * root;

        /* Constructor */
        Dictionary();
        
        /* Methods */
        bool addWord(string);
        void addWord(TrieNode *,string);

        bool checkWord(string);
        bool checkWord(TrieNode *,string);

        bool deleteWord(string);
        bool deleteWord(TrieNode *, string);
};