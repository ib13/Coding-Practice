#include <iostream>
#include <queue>
#include <vector>
using namespace std;
/*
IN CASE OF ADJACENCY LIST WE GENERALLY USE LINKED LIST.
WE CAN USE ARRAY IF NO NEW ELEMENT IS ADDED
SO IN THE LINKED LIST WE CREATE THE OBJECT OF HEAD BY Node *A[n];
CHECK MYCODESCHOOL VIDEO FOR MORE
*/
// int main()
// {
//     int *A[8];
//     A[0]=new int[3];
//     A[0][0]=3;
//     A[0][1]=3;
//     A[0][2]=3;
//     queue<int> q;
//     return 0;
// }

void add_edge(vector<int> v[],int u,int w)
{
    v[u].push_back(w);
    v[w].push_back(u);
}

void print_list(vector<int> v[])
{
    for(int i=0;i<4;i++)
    {
        cout << "\n Adjacency list of vertex "<< i << "\n head ";
        for(auto x:v[i])
        {
            cout<<"->"<<x;
        }
    }
}

int main()
{
	vector<int> v[4];
	add_edge(v,0,1);
	add_edge(v,1,3);
	print_list(v);
	return 0;
}