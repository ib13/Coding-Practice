#include <iostream>
#include <string>
using namespace std;
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
    /////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////
    bool search(TrieNode *root, string pattern)
    {
        if (pattern.size() == 0)
            return true;

        int index = pattern[0] - 'a';
        if (root->children[index] && search(root->children[index], pattern.substr(1)))
            return true;
        return false;
    }

    bool patternMatching(vector<string> vect, string pattern)
    {
        for (int i = 0; i < vect.size(); i++)
        {
            for (int j = 0; j < vect[i].size(); j++)
            {
                insertWord(vect[i].substr(j));
            }
        }
        return search(root, pattern);
    }
    /////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////
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
    if (t.patternMatching(vect, pattern))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}