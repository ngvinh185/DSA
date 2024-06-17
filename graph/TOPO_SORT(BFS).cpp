#include <bits/stdc++.h>
#define vinh ios::sync_with_stdio(false);cin.tie(nullptr);
#define anonymous main
#define int long long
#define my_for(i,a,b) for(int i=a;i<b;i++)
#define my_For(i,a,b) for(int i=a;i>=b;i--)
#define foreach(x,a) for(auto x:a)
#define forEach(x,a) for(auto &x:a)
using namespace std;
vector<int> a[10001];
int degree[1001];
anonymous()
{
	vinh
	int n,m;cin>>n>>m;
	my_for(i,0,m)
	{
		int x,y;cin>>x>>y;
		a[x].push_back(y);
		degree[y]+=1;
	}
	queue<int> q;
	my_for(i,1,n+1)
	{
		if(degree[i]==0) q.push(i);
	}
	vector<int> topo;
	while(!q.empty())
	{
		int v=q.front();
		topo.push_back(v);
		q.pop();
		foreach(x,a[v])
		{
			degree[x]-=1;
			if(degree[x]==0) q.push(x);
		}
	}
	if(topo.size()!=n) cout<<"Co chu trinh";
	else foreach(x,topo) cout<<x<<" ";
	// code nay danh cho ca nhieu tp lien thong 
}
