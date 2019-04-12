#include <iostream>
using namespace std;

int floyd_warshall(int **distance,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for (int k=0;k<n;k++)
            {
                if (distance[j][k]>distance[j][i]+distance[i][k])
                    distance[j][k]=distance[j][i]+distance[i][k];
            }
        }
    }
    for (int l = 0; l <n; ++l) {
        for (int i = 0; i <n; ++i) {
            cout<<distance[l][i];
        }
        cout<<"\n";
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
    floyd_warshall(initialDistance,n);
    return 0;
}