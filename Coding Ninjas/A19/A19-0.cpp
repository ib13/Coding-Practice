#include <iostream>
using namespace std;

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
            children[i] = NULL;
        isTerminal = false;
    }
};

class Trie
{
    TrieNode *root;

    void deleteWordHelper(string word, TrieNode *root)
    {
        if (word.size() == 0)
        {
            root->isTerminal = false;
            return;
        }

        int index = word[0] - 'a';
        if (root->children[index] == NULL)
            return;

        deleteWordHelper(word.substr(1), root->children[index]);
        if (root->isTerminal == false)
        {
            for (int i = 0; i < 26; i++)
            {
                if (root->children[index]->children[i] != NULL)
                    return;
            }
            delete root->children[index];
            root->children[index] = NULL;
        }
    }

    void insertHelper(string word, TrieNode *root)
    {
        if (word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }
        int charIndex = word[0] - 'a';
        if (root->children[charIndex] == NULL)
        {
            TrieNode *newNode = new TrieNode(word[0]);
            root->children[charIndex] = newNode;
        }
        insertHelper(word.substr(1), root->children[charIndex]);
    }

    bool searchHelper(string word, TrieNode *root)
    {
        if (word.size() == 0)
            return root->isTerminal;
        int index = word[0] - 'a';
        if (root->children[index] && searchHelper(word.substr(1), root->children[index]))
            return true;
        return false;
    }

public:
    Trie()
    {
        root = new TrieNode('\0');
    }

    // void insert(string word)
    // {
    //     TrieNode *temp = root;
    //     for (int i = 0; i < word.length(); i++)
    //     {
    //         int charIndex = word[i] - 'a';
    //         if (temp->children[charIndex] == NULL)
    //         {
    //             TrieNode *newNode = new TrieNode(word[i]);
    //             temp->children[charIndex] = newNode;
    //         }
    //         temp = temp->children[charIndex];
    //     }
    //     temp->isTerminal = true;
    // }

    void insert(string word)
    {
        insertHelper(word, root);
    }

    void deleteWord(string word)
    {
        deleteWordHelper(word, root);
    }

    bool search(string word)
    {
        return searchHelper(word, root);
    }
};

int main()
{
    Trie t;
    t.insert("abc");
    t.insert("ab");
    t.insert("abde");
    t.insert("abdf");
    t.insert("acd");
    cout << t.search("abc") << endl;
    cout << t.search("ab") << endl;
    cout << t.search("abde") << endl;
    cout << t.search("abdf") << endl;
    cout << t.search("acd") << endl;
    cout << "----" << endl;
    t.deleteWord("abc");
    t.deleteWord("ab");
    t.deleteWord("abde");
    t.deleteWord("abdf");
    t.deleteWord("acd");
    cout << t.search("abc") << endl;
    cout << t.search("ab") << endl;
    cout << t.search("abde") << endl;
    cout << t.search("abdf") << endl;
    cout << t.search("acd") << endl;
}