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
#define pii pair<int,int>
#define vii vector<pair<int,int>>
#define vil vector<pair<int,ll>>
#define vll vector<pair<ll,ll>>
#define vi vector<int>
#define vl vector<ll>
using namespace std;
int d[100005], visited[100001];
vector<int> a[100001];
int dfs(int v)
{
	int res = d[v];
	visited[v] = 1;
	foreach(x,a[v])
	{
		if(!visited[x])
		{
			res = min(res,dfs(x));	
		}	
	}	
	return res;
}
int main()
{
	vinh
	int n, m; cin>>n>>m;
	myfor(i,1,n+1) cin>>d[i];
	myfor(i,0,m)
	{
		int x,y; cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	ll ans = 0;
	myfor(i,1,n+1)
	{
		if(!visited[i])
		{
			ans+=dfs(i);
//			cout<<dfs(i);
		}
	}
	cout<<ans;
}
