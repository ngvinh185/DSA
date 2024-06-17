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
int visited[10001];
int cnt;
int res;
int index=0;
void DFS(int v,int cnt)
{
	visited[v]=1;
	foreach(x,a[v])
	{
		
		if(!visited[x])
		{
			DFS(x,0);
		}
		cnt+=1;
//		cout<<v<<" "<<x<<" "<<cnt<<endl;
	}
//	cout<<endl;
	if(cnt>res)
	{
		res=cnt;
		index=v;
	}
	else if(cnt==res) index=v;
//	cout<<v<<" "<<cnt<<endl;
}
anonymous()
{
	vinh
	int n,m;cin>>n>>m;
	my_for(i,0,m)
	{
		int x,y;cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
//	foreach(x,a[1]) cout<<x<<" ";
//	cout<<endl;
	my_for(i,1,n+1)
	{
		if(!visited[i])
		{
			cnt=0;
			res=-1e9;
			DFS(i,cnt);
			cout<<index<<" ";
		}
	}
	
}
