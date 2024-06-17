#include <bits/stdc++.h>
#define vinh ios::sync_with_stdio(false);cin.tie(nullptr);
#define my_for(i,a,b) for(int i=a;i<b;i++)
#define my_For(i,a,b) for(int i=a;i>=b;i--)
#define foreach(x,a) for(auto x:a)
#define forEach(x,a) for(auto &x:a)
#define ll long long
using namespace std;
int visited[10001];
vector<int> a[10001];
ll cnt[10001];
void DFS(int v)
{
	visited[v]=1;
	cnt[v]+=1;
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
	int k,n,m;cin>>k>>n>>m;
	int k1=k;
	vector<int> ans;
	while(k--)
	{
		int tmp;cin>>tmp;
		ans.push_back(tmp);	
	}
	while(m--)
	{
		int x,y;cin>>x>>y;
		a[x].push_back(y);
	}
	foreach(x,ans)
	{
		memset(visited,0,sizeof(visited));
		DFS(x);
	}
	ll dem=0;
	my_for(i,1,n+1)
	{
		if(cnt[i]==k1) 
		{
			dem++;
//			cout<<dem<<endl;
		}
	}
	cout<<dem;
//	my_for(i,1,n+1) cout<<cnt[i]<<" ";
}