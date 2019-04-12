#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    while(t--)
    {
        int coord[3][2];
        for(int i=0;i<3;i++)
            for(int j=0;j<2;j++)
                cin>>coord[i][j];
        int slope_1;
        int count=0;
        if(coord[0][0] - coord[1][0]==0)
        {
            for(int i=coord[0][1];i<=coord[1][1];i++)
                count++;
        }
        else
        {
            slope_1 = (coord[0][1] - coord[1][1]) / (coord[0][0] - coord[1][0]);
            int c=coord[0][1]-slope_1*coord[0][0];
            for(int i=coord[0][0];i<=coord[0][0];i++)
            {
                float y=slope_1*i+c;

            }
        }

    }
}
