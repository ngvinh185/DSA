#include <bits/stdc++.h>
#define vinh ios::sync_with_stdio(false);cin.tie(nullptr);
#define anonymous main
#define int long long
#define my_for(i,a,b) for(int i=a;i<b;i++)
#define my_For(i,a,b) for(int i=a;i>=b;i--)
#define foreach(x,a) for(auto x:a)
#define forEach(x,a) for(auto &x:a)
using namespace std;
int n,m;
char a[100][100];
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
int cnt;
void DFS(int i,int j)
{
	a[i][j]='#';
	cnt+=1;
	my_for(k,0,4)
	{
		int i1=i+dx[k],j1=j+dy[k];
		if(i1>=0&&i1<n&&j1>=0&&j1<n&&a[i1][j1]=='.') 
		{
			DFS(i1,j1);
		}
	}
}
anonymous()
{
	vinh
	cin>>n>>m;
	my_for(i,0,n)
	{
		my_for(j,0,m) cin>>a[i][j];
	}
	my_for(i,0,n)
	{
		my_for(j,0,m)
		{
			if(a[i][j]=='.') 
			{
				cnt=0;
				DFS(i,j);
				cout<<cnt<<" ";
			}
		}
	}
}
