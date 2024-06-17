#include <bits/stdc++.h>
#define vinh ios::sync_with_stdio(false);cin.tie(nullptr);
//#define anonymous main
//#define int long long
#define my_for(i,a,b) for(int i=a;i<b;i++)
#define my_For(i,a,b) for(int i=a;i>=b;i--)
#define foreach(x,a) for(auto x:a)
#define forEach(x,a) for(auto &x:a)
using namespace std;
vector<int> a[300];
int visited[300];
void DFS(int v)
{
	visited[v]=1;
	foreach(x,a[v])
	{
		if(!visited[x])
		{
			DFS(x);
		}
	}
}
int main()
{
	vinh
	int n,m;cin>>n>>m;
	my_for(i,0,m)
	{
		int x,y;cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	DFS(1);
	int check=1;
	my_for(i,1,n+1)
	{
		if(!visited[i]) 
		{
			cout<<i<<endl;
			check=0;
		}
	}
	if(check) cout<<0;
}
