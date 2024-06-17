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
stack<int> topo;
vector<int> a[100001];
int visited[100001];
void dfs(int v)
{
	visited[v]=1;
	foreach(x,a[v])
	{
		if(!visited[x])
		{
			dfs(x);
		}
		else if(visited[x]==1) 
		{
			cout<<"IMPOSSIBLE";
			exit(0);
		}
	}
	visited[v]=2;
	topo.push(v);
}
int main()
{
	vinh
	int n, m; cin>>n>>m;
	myfor(i,0,m)
	{
		int x, y; cin>>x>>y;
		a[x].push_back(y);
//		a[y].push_back(x);
	}
	myfor(i,1,n+1)
	{
		if(!visited[i])
		{
			dfs(i);
		}
	}
	while(!topo.empty())
	{
		cout<<topo.top()<<" ";
		topo.pop();
	}
}
