#include <iostream>
using namespace std;
void dijkstra(int **initialDistance,int node,int n)
{
    for (int i = 0; i <n; ++i) {
        for (int j = 0; j <n; ++j) {
            cout<<initialDistance[i][j];
        }
    }
}

int main()
{
    int i,j,n;
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
    dijkstra(initialDistance, 0,n);
    return 0;
}



