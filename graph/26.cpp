#include <bits/stdc++.h>
#define vinh ios::sync_with_stdio(false);cin.tie(nullptr);
#define anonymous main
#define int long long
#define my_for(i,a,b) for(int i=a;i<b;i++)
#define my_For(i,a,b) for(int i=a;i>=b;i--)
#define foreach(x,a) for(auto x:a)
#define forEach(x,a) for(auto &x:a)
using namespace std;
vector<int> a[100005];
int visited[100005];
void DFS(int u)
{
	visited[u]=1;
	foreach(x,a[u])
	{
		if(visited[x]==0)
		{
			DFS(x);
		}
	}
}
anonymous()
{
	vinh
	int n,m;
	cin>>n>>m;
	my_for(i,1,m+1)
	{
		int x,y;cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	int cnt=0;
	vector<int> tmp;
	my_for(i,1,n+1)
	{
		if(!visited[i])
		{
			tmp.push_back(i);
			cnt+=1;
			DFS(i);
		}
	}
	if(cnt==0) cout<<0;
	else
	{
		cout<<cnt-1<<endl;
		my_for(i,0,tmp.size()-1)
		{
			cout<<tmp[i]<<" "<<tmp[i+1]<<endl;
		}
	}
}
