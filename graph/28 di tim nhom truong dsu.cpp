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

int n, m;
int parent[10001];
int bac[10001];
int find(int v)
{
	if(v==parent[v]) return v;
	return parent[v]=find(parent[v]);
}
void union_set(int u,int v)
{
	u=find(u);
	v=find(v);
	if(u==v) return ;
	else 
	{
		if(bac[u]>bac[v]||bac[u]==bac[v]&&u<v)
			parent[v]=u;
		else parent[u]=v;
	}
}
int main()
{
	vinh
	cin>>n>>m;
	myfor(i,1,n+1)
	{
		parent[i]=i;
	}
	vector<pair<int,int>> edges;
	myfor(i,0,m)
	{
		int x,y;cin>>x>>y;
		edges.push_back({x,y});
		bac[x]+=1,bac[y]+=1;
	}
	foreach(x,edges)
	{
		union_set(x.first,x.second);
	}
	set<int> res;
	myfor(i,1,n+1)
	{
		res.insert(find(i));
	}
	foreach(x,res) cout<<x<<" ";
}
