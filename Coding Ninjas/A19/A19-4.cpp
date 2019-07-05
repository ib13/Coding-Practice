#include <iostream>
#include <string>
using namespace std;
#include <vector>

// #include "TrieNode.h"
#include <string>
#include <vector>
class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
    TrieNode *root;

public:
    int count;

    Trie()
    {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word)
    {
        // Base case
        if (word.size() == 0)
        {
            if (!root->isTerminal)
            {
                root->isTerminal = true;
                return true;
            }
            else
            {
                return false;
            }
        }

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    // For user
    void insertWord(string word)
    {
        if (insertWord(root, word))
        {
            this->count++;
        }
    }

    /////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////
    void autoCompleteHelper(string pattern, TrieNode *root, vector<char> &v)
    {
        if (root->isTerminal)
        {
            for (int i = 0; i < v.size(); i++)
            {
                cout << v[i];
            }
            cout << endl;
        }
        for (int i = 0; i < 26; i++)
        {
            if (root->children[i])
            {
                v.push_back(root->children[i]->data);
                autoCompleteHelper(pattern, root->children[i], v);
                v.pop_back();
            }
        }
    }

    void autoComplete(vector<string> input, string pattern)
    {
        for (int i = 0; i < input.size(); i++)
            insertWord(input[i]);

        TrieNode *temp = root;
        for (int i = 0; i < pattern.size(); i++)
        {
            int index = pattern[i] - 'a';
            if (temp->children[index])
            {
                temp = temp->children[index];
            }
            else
                return;
        }
        vector<char> v;
        for (int i = 0; i < pattern.size(); i++)
        {
            v.push_back(pattern[i]);
        }

        autoCompleteHelper(pattern, temp, v);
    }
    /////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////
};

int main()
{
    Trie t;
    int N;
    cin >> N;
    string pattern;
    vector<string> vect;
    for (int i = 0; i < N; i++)
    {
        string word;
        cin >> word;
        vect.push_back(word);
    }
    cin >> pattern;
    t.autoComplete(vect, pattern);
}
