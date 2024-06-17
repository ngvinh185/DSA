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
int ans=0;
int dfs(int v)
{
	visited[v]=1;
	int res=0;	
	foreach(x,a[v])
	{
		if(!visited[x])
		{
			res+=dfs(x);
		}
	}
	ans+=res+1;
	return res+1;
}
int main()
{
	vinh
	int n; cin>>n;
	int m=n-1;
	myfor(i,0,m)
	{
		int x, y;cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1);
	cout<<ans;
}
