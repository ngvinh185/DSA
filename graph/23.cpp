#include <bits/stdc++.h>
#define vinh ios::sync_with_stdio(false);cin.tie(nullptr);
#define anonymous main
#define int long long
#define my_for(i,a,b) for(int i=a;i<b;i++)
#define my_For(i,a,b) for(int i=a;i>=b;i--)
#define foreach(x,a) for(auto x:a)
#define forEach(x,a) for(auto &x:a)
using namespace std;
vector<int> a[1001];
int visited[100];
int n,m;
void DFS(int v)
{
	visited[v]=1;;
	foreach(x,a[v])
	{
		if(!visited[x])
		{
			DFS(x);
		}
	}
}
bool check()
{
	my_for(i,1,n+1)
	{
		if(!visited[i]) return false;
	}
	return true;
}
anonymous()
{
	vinh
	cin>>n>>m;
	my_for(i,0,m)
	{
		int x,y;cin>>x>>y;
		a[x].push_back(y);
	}
	my_for(i,1,n+1)
	{
		memset(visited,0,sizeof(visited));
		DFS(i);
		if(check()==0) 
		{
			cout<<0;return 0;
		}
	}
	cout<<1;
}
