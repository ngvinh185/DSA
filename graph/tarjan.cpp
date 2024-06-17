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

vector<int> a[1001];
int visited[1001];
int disc[10001], low[10001];
int cnt=0;
void dfs(int v )
{
	visited[v]=1;
	cnt+=1; disc[v]=cnt, low[v]=cnt;
	foreach(x,a[v])
	{
		if(!visited[x])
		{
			dfs(x);
			low[v]=min(low[v],low[x]);
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
	int n, m; cin>>n>>m;
	myfor(i,0,m)
	{
		int x,y; cin>>x>>y;
		a[x].push_back(y);
	}
	myfor(i,1,n+1)
	{
		if(!visited[i])
		{
			dfs(i);
		}
	}
	
}
