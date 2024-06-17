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
int mod=1e9+7;
vector<ll> a[1000001];
vector<ll> topo;
ll dp[1000001];
void dfs(ll v)
{
	foreach(x,a[v])
	{
		dfs(x);
	}
	topo.push_back(v);
}
int main()
{
	vinh
	ll n, m; cin>>n>>m;
	myfor(i,0,m)
	{
		ll x, y;cin>>x>>y;
		a[x].push_back(y);
	}
	dfs(1);
	dp[n]=1;
	foreach(x,topo)
	{
		if(x!=n) dp[x]=0;
		foreach(y,a[x])
		{
			dp[x]+=dp[y];
			dp[x]%=mod;
		}
		dp[x]%=mod;
	}
	cout<<dp[1];
}
