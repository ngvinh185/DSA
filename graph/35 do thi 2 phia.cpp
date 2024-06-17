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
int visited[10001];
int color[10001];

int dfs(int v)
{
	visited[v]=1;
	foreach(x,a[v])
	{
		if(!visited[x])
		{
			if(color[v]==1) color[x]=0;
			else color[x]=1;
			if(!dfs(x)) return 0;
		}
		else 
		{
			if(color[v]==color[x]) return 0;
		} 
	}
	return 1;
}
int main()
{
	vinh
	int n, m; cin>>n>>m;
	myfor(i,0,m)
	{
		int x, y;cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	myfor(i,1,n+1)
	{
		if(!visited[i])
		{
			color[i]=1;
			if(dfs(i)) cout<<"YES";
			else cout<<"NO";
			return 0;
		}
	}
}
