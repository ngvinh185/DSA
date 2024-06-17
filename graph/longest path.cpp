#include <bits/stdc++.h>
#define vinh ios::sync_with_stdio(false);cin.tie(nullptr);
#define my_for(i,a,b) for(int i=a;i<b;i++)
#define my_For(i,a,b) for(int i=a;i>=b;i--)
#define foreach(x,a) for(auto x:a)
#define forEach(x,a) for(auto &x:a)
#define ll long long
using namespace std;
vector<int> a[100001];
vector<int> revtopo;
ll dp[100001];// luu do dai cua dinh cha (i) = max ( do dai cac dinh con cua dinh cha + 1)
void DFS(int v)
{
	foreach(x,a[v])
	{
		DFS(x);
	}
	revtopo.push_back(v);
}
int main()
{
	vinh
	int n,m;cin>>n>>m;
	while(m--)
	{
		int x,y; cin>>x>>y;
		a[x].push_back(y);
	}
	my_for(i,1,n+1)
	{
		DFS(i);
	}
	ll res=-1e18;
	foreach(v,revtopo)
	{
		foreach(x,a[v])
		{
			dp[v]=max(dp[v],dp[x]+1);
		}
		res=max(res,dp[v]);
	}
	if(res==-1e18) cout<<"IMPOSSIBLE";
	else cout<<res;
}
