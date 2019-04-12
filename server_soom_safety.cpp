//https://www.hackerrank.com/contests/rookierank-4/challenges/server-room-safety
#include <bits/stdc++.h>
using namespace std;

string checkAll(int n, vector <int> height, vector <int> position) 
{
	string s;
	int i,j;
	int flag[2]={0,0};
	int flag1[n]={0};
	int flag2[n]={0};
	flag1[0]=1;
	flag2[n-1]=1;
	sort(position.begin(),position.end());
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(position[i]+height[i]>=position[j])
				flag1[j]=1;
		}
	}    
	for(i=n-1;i>0;i--)
	{
		for(j=i-1;j>=0;j--)
		{
			if(position[i]-height[i]<=position[j])
				flag2[j]=1;
		}
	}  
	for(i=0;i<n;i++)
	{
		if(flag1[i]==0)
			flag[0]=1;
		if(flag2[i]==0)
			flag[1]=1;
	}
	if(flag[0]==0 && flag[1]==0)
		s="BOTH";
	if(flag[0]==0 && flag[1]==1)
		s="LEFT";
	if(flag[0]==1 && flag[1]==0)
		s="RIGHT";
	if(flag[1]==1 && flag[0]==1)
		s="NONE";
	return s;
}

int main() {
    int n;
    cin >> n;
    vector<int> position(n);
    for(int position_i = 0; position_i < n; position_i++){
       cin >> position[position_i];
    }
    vector<int> height(n);
    for(int height_i = 0; height_i < n; height_i++){
       cin >> height[height_i];
    }
    string ret = checkAll(n, height, position);
    cout << ret;
    return 0;
}
