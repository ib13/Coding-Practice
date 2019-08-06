#include <bits/stdc++.h>
using namespace std;

// // array value change
// void f1(int b[], int c)
// {
//     // cout << sizeof(b);
//     b[0] = 1;
//     c = 6;
// }

// int main()
// {
//     int b[] = {0, 2, 3};
//     int c = 5;
//     f1(b, c);
//     cout << sizeof(b);
//     cout << b[0] << c;
//     return 0;
// }

// number to char
// int main()
// {
//     int a = 5;
//     char c;
//     c = char(48 + a);
//     cout << c;
//     return 0;
// }

// int main()
// {
//     char ch = 'a';
//     cout << ch - 'a';
//     return 0;
// }

// int main()
// {
//     string s = "Helloo";
//     cout << s.substr(0, 3) << " " << s.substr(3);
// }

// int main()
// {
//     while (true)
//     {
//         int *p = new int;
//         // delete p;
//     }
// }

// int main()
// {
//     int p = 5;
//     int const *q = &p;
//     p++;
//     cout << p << endl;
//     return 0;
// }

// void print(int n)
// {
//     if (n < 0)
//     {
//         return;
//     }
//     if (n == 0)
//     {
//         cout << n << " ";
//         return;
//     }
//     print(n--);
//     cout << n << " ";
// }

// int main()
// {
//     int num = 3;
//     print(num);
// }
// int main()
// {

//     const int p = 5;
//     int const *q = &p;
//     p++;
//     q++;
//     (*q)++;
// }

// #include <queue>
// int main()
// {
//     queue<int> *q = new queue<int>;
// }

// class BTree
// {
// public:
//     int data;
//     BTree *left;
//     BTree *right;

//     BTree(int data)
//     {
//         this->data = data;
//         left = NULL;
//         right = NULL;
//     }
// };

// BTree *takeInput()
// {
//     int data;
//     cout << "Enter data: ";
//     cin >> data;
//     if (data == -1)
//         return NULL;
//     BTree *newNode = new BTree(data);
//     cout << "Enter left of " << data << " : ";
//     newNode->left = takeInput();
//     cout << "Enter right of " << data << " : ";
//     newNode->right = takeInput();
//     return newNode;
// }

// void printTree(BTree *root)
// {
//     if (root == NULL)
//         return;
//     cout << root->data << " :";
//     if (root->left)
//         cout << " L" << root->left->data;
//     if (root->right)
//         cout << " R" << root->right->data;
//     cout << endl;
//     printTree(root->left);
//     printTree(root->right);
// }

// int main()
// {
//     BTree *root;
//     root = takeInput();
//     printTree(root);
// }

void bin(unsigned n)
{
    unsigned i;
    for (i = 1 << 31; i > 0; i = i / 2)
        (n & i) ? printf("1") : printf("0");
}

int main()
{
    int x = 0xAAAAAAAA;
    bin(x);
    cout << endl;
    bin(64);
}