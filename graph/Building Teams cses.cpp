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
vector<int> a[100001];
int visited[100001];
int color[100001];
bool dfs(int v)
{
	visited[v]=1;
	foreach(x,a[v])
	{
		if(!visited[x])
		{
			if(color[v]==1) color[x]=2;
			else color[x]=1;
			if(!dfs(x)) return false;
		}
		else
		{
			if(color[x]==color[v]) return false;
		}
	}
	return true;
}
int main()
{
	vinh
	int n , m; cin>>n>>m;
	myfor(i,0,m) 
	{
		int x,y; cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);	
	}
	int ok=1;
	myfor(i,1,n+1)
	{
		if(!visited[i])
		{
			color[i]=1;
			if(!dfs(i))
			{
				ok = 0;
			}
		}
	}
	if(!ok) cout<<"IMPOSSIBLE";
	else
	{
		myfor(i,1,n+1) cout<<color[i]<<" ";
	}
}
