#include <iostream>
using namespace std;
void dijkstra(int **initialDistance,int node,int n) {
    int min;
    int check=0;
    int start_node=node;
    bool visited[n] = {false};
    int v=0;
    int finalDistance[n];
    for(int i=0;i<n;i++)
        finalDistance[i] = INT_MAX;
    finalDistance[node] = 0;
    visited[node] = true;
    v++;
    while (v<n){
        for (int i = 0; i < n; i++)
        {
            if (initialDistance[node][i] != 0 && !visited[i])
            {
                check=1;
                if (finalDistance[i] > initialDistance[node][i]+finalDistance[node])
                    finalDistance[i] = initialDistance[node][i]+finalDistance[node];
            }

        }
        if(check==0)
            v++;
        check=0;
        min=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(finalDistance[i]<min && !visited[i] )
            {
                min=finalDistance[i];
                node=i;
            }
        }
        if(!visited[node])
        {
            v++;
            visited[node]=true;
        }
    }
    cout<<"Shortest distances of all nodes from "<<start_node<<" is: ";
    for (int i = 0; i <n; ++i) {
        cout<<finalDistance[i]<<"  ";
    }
}

int main()
{
    int i,j,n,node;
    cout<<"Enter number of nodes: ";
    cin>>n;
    int **initialDistance;
    initialDistance=new int*[n];
    for(i = 0; i <n; i++)
        initialDistance[i] = new int[n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>initialDistance[i][j];
        }
    }
    cout<<"Enter starting node: ";
    cin>>node;
    dijkstra(initialDistance,node,n);
    return 0;
}



