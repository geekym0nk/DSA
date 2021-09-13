#include "Dictionary.h"

Dictionary::Dictionary() {
    this->root = new TrieNode('*');
}

bool isalphabet(string & s) {

    for (auto c : s) {
        if (!isalpha(c))
            return false;
    }

    return true;
}

bool  Dictionary::checkWord(TrieNode *t, string s) {
    if (s.length() == 0)
        return (t->isEndOfWord);

    int index = s[0] - 'a';
    TrieNode * child = t->children[index];

    if ((child == NULL) || (child->data != s[0]))
        return false;
    else
        return checkWord(child,s.substr(1));
}

bool  Dictionary::checkWord(string s) {

    int index = s[0] - 'a';
    TrieNode * n = root->children[index];

    if (n == NULL)
        return false;
    else
    {
        if (s.length() == 1)
            return (n->isEndOfWord);
        else 
            return checkWord(n,s.substr(1));
    }
}

void Dictionary::addWord(TrieNode *d, string s) {
    if (s.length() == 0)
    {
        d->isEndOfWord = true;
        return;
    }

    int index = s[0] - 'a';

    if (d->children[index] == NULL)
        d->children[index] = new TrieNode(s[0]);

    addWord(d->children[index],s.substr(1));

    return;
}

bool Dictionary::addWord(string s){
    if (!isalphabet(s)){
        cout << "Please enter alphabets only" << endl;
        return false;
    }
    else if (checkWord(s)) {
        cout << "The word \"" << s << "\" already exists in the dictionary." << endl;
        return false;
    }
    
    addWord(root,s);

    return true;
}

bool Dictionary::deleteWord(TrieNode *n, string s) 
{
    if (s.length() == 0)
    {
        if (n->isEndOfWord)
            n->isEndOfWord = false;
        else
        {
            cout << "The word doesnt exist!" << endl;
            return false;
        }

        return true;
    }
    else
    {
        int index = s[0] - 'a';
        
        if (n->children[index] == NULL)
        {
            cout << "The word doesnt exist!" << endl;
            return false;            
        }

        return deleteWord(n->children[index],s.substr(1));
    }
}

bool Dictionary::deleteWord(string s) {
    return deleteWord(root,s);
}