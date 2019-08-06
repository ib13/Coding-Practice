#include <bits/stdc++.h>
using namespace std;
class LRUCache
{
public:
    LRUCache(int);

    int get(int);

    void set(int, int);
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        LRUCache *l = new LRUCache(n);
        int q;
        cin >> q;
        for (int i = 0; i < q; i++)
        {
            string a;
            cin >> a;
            if (a == "SET")
            {
                int aa, bb;
                cin >> aa >> bb;
                l->set(aa, bb);
            }
            else if (a == "GET")
            {
                int aa;
                cin >> aa;
                cout << l->get(aa) << " ";
            }
        }
        cout << endl;
    }
}

/*This is a function problem.You only need to complete the function given below*/
/*The structure of the class is as follows
class LRUCache
{
public:
    LRUCache(int );
    int get(int );
    void set(int , int );
};*/
/*You are required to complete below methods */
/*Inititalize an LRU cache with size N */

int CacheSize;
queue<pair<int, int>> q;
bool hashmap[1000] = {0};
LRUCache::LRUCache(int N)
{
    while (!q.empty())
        q.pop();
    CacheSize = N;
}
/*Sets the key x with value y in the LRU cache */
void LRUCache::set(int x, int y)
{
}
/*Returns the value of the key x if
present else returns -1 */
int LRUCache::get(int x)
{
    //Your code here
}