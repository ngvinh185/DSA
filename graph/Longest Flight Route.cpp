#include <bits/stdc++.h>
#define vinh ios::sync_with_stdio(false);cin.tie(nullptr);
#define myfor(i,a,b) for(int i=a;i<b;i++)
#define myFor(i,a,b) for(int i=a;i>=b;i--)
#define foreach(x,a) for(auto x:a)
#define forEach(x,a) for(auto &x:a)
#define ll long long
#define ms(x,y) memset(x,y,sizeof(x))
//#define first fi
//#define second se
using namespace std;
ll d[100001];
ll n, m;
ll parent[100001];
vector<ll> a[100001];
void dfs(ll v, ll kc)
{
	d[v] = kc ;
	foreach(x, a[v])
	{
		if(d[v] + 1 > d[x]) 
		{
			parent[x] = v;
			dfs(x, d[v] + 1);
		}
	}
}
void Print(ll v)
{
	vector<ll> path;
	while(v != 1)
	{
		path.push_back(v);
		v = parent[v];
	}
	path.push_back(1);
	reverse(path.begin(), path.end());
	cout<<d[n]+1<<endl;
//	foreach(x,path) cout<<x<<" ";
}
int main()
{
	vinh
	cin>>n>>m;
	myfor(i,0,m)
	{
		ll x, y; cin>>x>>y;
		a[x].push_back(y);
	}
	dfs(1,0);
	if(d[n] != 0)
	{
		Print(n);
	}
	else cout<<"IMPOSSIBLE";
}