#include <bits/stdc++.h>
#define vinh ios::sync_with_stdio(false);cin.tie(nullptr);
#define myfor(i,a,b) for(int i=a;i<b;i++)
#define myFor(i,a,b) for(int i=a;i>=b;i--)
#define foreach(x,a) for(auto x:a)
#define forEach(x,a) for(auto &x:a)
#define ll long long
#define ms(x,y) memset(x,y,sizeof(x))
#define first fi
#define second se

using namespace std;
vector<int> a[10001];
int disc[10001];
int low[10001];
int visited[10001];
vector<int> ap;
int dem=0;
void dfs(int v,int par)
{
	int cnt=0;
	visited[v]=1;
	disc[v]=low[v]=++dem;
	foreach(x,a[v])
	{
		if(x==par) continue;
		if(!visited[x])
		{
			dfs(x,v);
			cnt+=1;
			low[v]=min(low[v],low[x]);
			if(par!=-1&&low[x]>=disc[v]) ap.push_back(v);
		}
		else low[v]=min(low[v],disc[x]);
	}
	if(cnt>=2&&par==-1) ap.push_back(v);
}
int main()
{
	vinh
	int n,m;cin>>n>>m;
	myfor(i,0,m) 
	{
		int x,y;cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	myfor(i,1,n+1)
	{
		if(!visited[i]) dfs(i,-1);
	}
	foreach(x,ap) cout<<x<<" ";
}
