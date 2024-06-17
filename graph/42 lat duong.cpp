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
int n, m;
int res=1;
int parent[10001];
int sz[10001];
void ktao()
{
	cin>>n>>m;
	myfor(i,1,n+1) 
	{
		parent[i]=i;
		sz[i]=1;
	}
}
int find(int v)
{
	if(v==parent[v]) return v;
	return parent[v]=find(parent[v]);
}
bool union_set(int u,int v)
{
	u=find(u);
	v=find(v);
	if(u==v) return false;
	if(sz[u]<sz[v]) swap(u,v);
	sz[u]+=sz[v];
	res=max(res,sz[u]);
	parent[v]=u;
	return true;
}
int main()
{
	vinh
	ktao();
	int cnt=n;
	myfor(i,0,m)
	{
		int x,y;cin>>x>>y;
		if(union_set(x,y)) 
			cnt-=1;
		cout<<cnt<<" "<<res<<endl;
		
	}
}
