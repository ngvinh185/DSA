#include <bits/stdc++.h>
#define vinh ios::sync_with_stdio(false);cin.tie(nullptr);
#define myfor(i,a,b) for(int i=a;i<b;i++)
#define myFor(i,a,b) for(int i=a;i>=b;i--)
#define foreach(x,a) for(auto x:a)
#define forEach(x,a) for(auto &x:a)
#define ll long long
#define ms(x,y) memset(x,y,sizeof(x))
#define fi first
#define se second

using namespace std;

int n, m;
vector<int> a[10001];
int visited[10001], disc[10001], low[10001];
int cnt=0;
vector<pair<int,int>> bridge;

void nhap()
{
	cin>>n>>m;
	myfor(i,0,m)
	{
		int x,y;cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);	
	}
}

void dfs(int v,int parent) //parent la bo cua v
{
	visited[v]=1;
	disc[v] = low[v] = ++cnt;
	foreach(x,a[v])
	{
		if(x==parent) continue;
		else if(!visited[x])
		{
			dfs(x,v);
			low[v]=min(low[v],low[x]);
			if(low[x]>disc[v]) bridge.push_back({v,x}); 
		}
		else 
		{
			low[v]=min(low[v],disc[x]);
		}
	}
}
int main()
{
	vinh
	nhap();
	myfor(i,1,n+1) 
	{
		if(!visited[i]) dfs(i,-1);
	}
	foreach(x,bridge) cout<<x.first<<" "<<x.second<<endl;
}
