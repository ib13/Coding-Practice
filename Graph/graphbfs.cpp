#include <iostream>
#include <queue>

using namespace std;

//      FOR COMMENTS CHECK GRAPHDFS.CPP

int main()
{
    int n,i,j;
    cout<<"Enter number of nodes: ";
    cin>>n;
    int A[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>A[i][j];
        }
    }

    int visited[n]={0};
//    for(i=0;i<n;i++)
//    {
//        cout<<visited[i];
//    }

    queue <int> q;
    q.push(0);
    int node;
    node=q.front();
    cout<<node;
    q.pop();
    visited[0]=1;
    while(true)
    {
        for(i=0;i<n;i++)
        {
            if(A[node][i]==1 && visited[i]==0)
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
            node=q.front();
            cout<<node;
            q.pop();
        }

    }

    return 0;
}

