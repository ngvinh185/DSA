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
#define vii vector<pair<int,int>> 
#define vll vector<pair<ll,ll>>
#define vi vector<int>
#define vl vector<ll>
using namespace std;
struct edge{
	ll x, y, w;
};
vector<edge> e;
ll n, m;
ll parent[100001], sz[100001];
void ktao()
{
	myfor(i,1,n+1)
	{
		sz[i]=1;
		parent[i]=i;
	}
}

ll Find(ll v)
{
	if (v==parent[v]) return v;
	return parent[v]=Find(parent[v]);
}

bool Union_set(ll u, ll v)
{
	u=Find(u);
	v=Find(v);
	if(u==v) return false;
	if(sz[u] < sz[v]) swap(u,v);
	sz[u]+=sz[v];
	parent[v]=u;
	return true;
}

bool myfunc(edge a, edge b)
{
	return a.w < b.w ;
}
int main()
{
	vinh
	cin>>n>>m;
	myfor(i,0,m)
	{
		ll x, y, z; cin>>x>>y>>z;
		edge ed=edge({x,y,z});
		e.push_back(ed);
	}
	ktao();
	sort(e.begin(),e.end(),myfunc);
	ll dis = 0;
	ll dem = 0;
	myfor(i,0,e.size())
	{
		ll u = e[i].x, v = e[i].y, wei = e[i].w;
		if(Union_set(u,v))
		{
			dis += wei;
			dem+=1;
		}
		if(dem == n-1) break;
	}
	if(dem != n-1) cout<<"IMPOSSIBLE";
	else cout<<dis;
}
