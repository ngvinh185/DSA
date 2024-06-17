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
struct edge{
	int x,y,d;	
};
int n, m;
int parent[10001];
int sz[10001];
vector<edge> e;
void ktao()
{
	myfor(i,1,n+1)
	{
		sz[i]=1;
		parent[i]=i;
	}
}
void nhap()
{
	cin>>n>>m;
	myfor(i,0,m)
	{
		int x,y,z;cin>>x>>y>>z;
		e.push_back((edge){x,y,z});
	}
}
int find(int u)
{
	if(u==parent[u]) return u;
	return parent[u]=find(parent[u]);
}

bool union_set(int u,int v)
{
	u=find(u); v=find(v);
	if(u==v) return false;
	if(sz[u]<sz[v]) swap(u,v);
	sz[u]+=sz[v];
	parent[v]=u;
	return true;
}
bool myfunc(edge a,edge b) 
{
	return a.d<b.d;
}
void kruskal()
{
	sort(e.begin(),e.end(),myfunc);
	int ans=0;
	vector<edge> MST;
	foreach(it,e)
	{
		if(MST.size()==n-1) break;
		if(union_set(it.x,it.y)) 
		{
			ans+=it.d;
			MST.push_back(it);
		}
	}
	if(MST.size()<n-1) 
	{
		cout<<"IMPOSSIBLE";
		return 0;
	}
	cout<<ans<<endl;
	foreach(it,MST) cout<<it.x<<" "<<it.y<<" "<<it.d<<endl;
}
int main()
{
	vinh
	nhap();
	ktao();
	kruskal();
}
