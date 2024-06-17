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
vector<int> reva[1001];
int visited[1001];
stack<int> topo;

void dfs(int v)
{
	visited[v]=1;
	foreach(x,a[v])
	{
		if(!visited[x])
		{
			dfs(x);
		}
	}
	topo.push(v);
}

void _dfs(int v)
{
	visited[v]=1;
	cout<<v<<" ";
	foreach(x,reva[v])
	{
		if(!visited[x])
		{
			_dfs(x);
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
		reva[y].push_back(x);
	}
	myfor(i,1,n+1)
	{
		if(!visited[i])
		{
			dfs(i);
		}
	}
	ms(visited,0);
	int cnt=0;
	while(!topo.empty())
	{
		int v = topo.top();
		topo.pop();
		if(!visited[v])
		{
			_dfs(v);
			cout<<endl;
			cnt+=1;
		}
	}
	cout<<cnt;
}
