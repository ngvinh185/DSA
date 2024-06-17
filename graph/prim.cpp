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
#define pair<int,int> ii
using namespace std;
vector<pair<int,int>> a;
int cnt=0;
int taken[100001];
void prim(int v)
{
	taken[v]=1;
	queue<ii,vector<ii>,greater<ii>> q;
	foreach(x,a[v])
	{
		if(!taken[x])
		{
			q.push({x.second,x.first});
		}
	}
	while(!q.empty())
	{
		auto it=q.front();q.pop();
		int u=it.second, w=it.first;
		if(!taken[u])
		{
			dem+=w;
			cnt+=1;
			taken[u]=1;
			foreach(x,a[u])
			{
				if(!taken[x.first])
				{
					q.push({x.second,x.first});
				}
			}
		}
	}
	if(cnt==n-1) cout<<dem;
}
int main()
{
	vinh
	int n,m;cin>>n>>m;
	myfor(i,0,m)
	{
		int x, y, z;cin>>x>>y>>z;
		a[x].push_back({y,z});
	}
}
