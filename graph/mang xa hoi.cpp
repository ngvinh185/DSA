#include <bits/stdc++.h>
#define vinh ios::sync_with_stdio(false);cin.tie(nullptr);
#define my_for(i,a,b) for(int i=a;i<b;i++)
#define my_For(i,a,b) for(int i=a;i>=b;i--)
#define foreach(x,a) for(auto x:a)
#define forEach(x,a) for(auto &x:a)
#define ll long long
using namespace std;
vector<int> a[100001];
int visited[100001];
int parent[100001];
bool DFS(int v)
{
	visited[v]=1;
	foreach(x,a[v])
	{
		if(!visited[x])
		{
			parent[x]=v;
			if(!DFS(x)) return false
		}
		else if(parent[v]==x&&)	
	}
}
int main()
{
	vinh
	int t;cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		my_for(i,1,n+1)
		{
			a[i].clear();
		}
		memset(visited,0,sizeof(visited));
		my_for(i,0,m)
		{
			int x,y;cin>>x>>y;
			a[x].push_back(y);
			a[y].push_back(x);
		}
		cnt=0;
		DFS(1);
		if(cnt!=n) cout<<"NO\n";
		else cout<<"YES\n";
	}
}
