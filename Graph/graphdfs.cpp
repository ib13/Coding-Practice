#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n,i,j;
    cout<<"Enter number of nodes: ";
    cin>>n;
    int A[n][n];
    // FILL THE ADJACENCY MATRIX
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>A[i][j];               //FOR WEIGHTED GRAPH INSTEAD OF 1 WE PUT WEIGHT AND IF NOT CONNECTED THAN 0
        }
    }
    int visited[n]={0};
//    for(i=0;i<n;i++)
//    {
//        cout<<visited[i];
//    }

    stack <int> q;

    //WE PUT 0 AS WE START FROM HERE

    q.push(0);
    int node;
    node=q.top();
    cout<<node;
    q.pop();
    visited[0]=1;                    //AS WE VISITED WE MARK IT 1 SO THAT WE DO NOT VISIT AGAIN
    while(true)
    {
        for(i=0;i<n;i++)
        {
            if(A[node][i]==1 && visited[i]==0)              //IF ADJACENT AND NOT VISITED THEN PUSH IN STACK AND MARK VISITED
            {
                visited[i]=1;
                q.push(i);
            }
        }
        if(q.empty())
        {
            break;
        }
        else
        {
            node=q.top();
            cout<<node;
            q.pop();
        }

    }

    return 0;
}


