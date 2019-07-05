#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#include <vector>

class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
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
            root->childCount++;
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

    //O(n^2k) Without Trie
    // bool isPalindrome(string s)
    // {
    //     for (int i = 0; i < s.length() / 2; i++)
    //     {
    //         if (s[i] != s[s.length() - i - 1])
    //             return false;
    //     }
    //     return true;
    // }

    // bool findIfPalindromePair(vector<string> arr)
    // {
    //     for (int i = 0; i < arr.size(); i++)
    //     {
    //         if (isPalindrome(arr[i]))
    //             return true;
    //     }
    //     for (int i = 0; i < arr.size(); i++)
    //     {
    //         for (int j = i + 1; j < arr.size(); j++)
    //         {
    //             string s = arr[i] + arr[j];
    //             if (isPalindrome(s))
    //                 return true;
    //             s = arr[j] + arr[i];
    //             if (isPalindrome(s))
    //                 return true;
    //         }
    //     }
    //     return false;
    // }

    //With Trie - not complete
    int search(TrieNode *root, string word)
    {
        if (word.length() == 0)
            return 0;
        int index = word[0] - 'a';
        if (root->children[index])
        {
            return 1 + search(root->children[index], word.substr(1));
        }
        else
            return 1;
    }
    bool findIfPalindromePair(vector<string> arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            reverse(arr[i].begin(), arr[i].end());
            insertWord(arr[i]);
            reverse(arr[i].begin(), arr[i].end());
        }

        for (int i = 0; i < arr.size(); i++)
        {
        }
    }
    /////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////
};

int main()
{
    Trie t;
    vector<string> vect;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string word;
        cin >> word;
        vect.push_back(word);
    }

    bool ans = t.findIfPalindromePair(vect);
    if (ans)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}