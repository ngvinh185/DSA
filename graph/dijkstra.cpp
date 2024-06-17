#include <bits/stdc++.h>
#define vinh ios::sync_with_stdio(false);cin.tie(nullptr);
#define myfor(i,a,b) for(int i=a;i<b;i++)
#define myFor(i,a,b) for(int i=a;i>=b;i--)
#define foreach(x,a) for(auto x:a)
#define forEach(x,a) for(auto &x:a)
#define ll long long
#define ms(x,y) memset(x,y,sizeof(x))
//#define pair<int,int> pii
//#define first fi
//#define second se
//#define ll long long
//#define nvinh main
using namespace std;
ll n, m;
vector<pair<ll,ll>> a[100001];
void dijkstra(ll s)
{
	vector<ll> d(n+1,1e18);// luu kc ngan nhat tu 1 dinh toi dinh nguon(s)
	d[s]=0;
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, greater<pair<ll,ll>>> q;
	q.push({0,s});
	while(!q.empty())
	{
		auto it = q.top(); q.pop();
		ll v = it.second, kc = it.first ;
		if (kc > d[v]) continue;
		foreach(x,a[v])
		{
			ll u = x.first, w=x.second;
			if(d[u] > d[v] + w) 
			{
				d[u] = d[v] + w;
				q.push({d[u], u});	
			}	
		}  
	}
	myfor(i,1,n+1) cout<<d[i]<<" ";
}
main()
{
	vinh
	cin>>n>>m;
	myfor(i,0,m)
	{
		ll x, y, z; cin>>x>>y>>z;
		a[x].push_back({y,z});
//		a[y].push_back({x,z});
	}
	dijkstra(1);
	return 0;
}
