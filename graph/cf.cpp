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
#define pii pair<int,int>
#define vii vector<pair<int,int>>
#define vil vector<pair<int,ll>>
#define vll vector<pair<ll,ll>>
#define vi vector<int>
#define vl vector<ll>
using namespace std;
int visited[100001];
int parent[100001];
void dfs(vector<int> a[],int v)
{
	visited[v]=1;
	foreach(x,a[v])
	{
		if(!visited[x])
		{
			parent[x]=v;
			dfs(a,x);
		}
	}
}
int main()
{
	vinh
	int t;cin>>t;
	while(t--)
	{
		ms(visited,0);
		ms(parent,0);
		int n; cin>>n;
		vector<int> a[n+2];
		int d[n+1];
		myfor(i,1,n+1)
		{
			cin>>d[i];
		}
		myfor(i,1,n+1)
		{
			if(i!=n) a[i].push_back(i+1);
			if(d[i] == 0) a[i].push_back(n+1);
			else a[n+1].push_back(i);
		}
		dfs(a,1);
		if(visited[n+1]) 
		{
			myfor(i,1,n+2) cout<<i<<" ";
			cout<<endl;
		}
		else 
		{
			cout<<n+1<<" ";
			myfor(i,1,n+1) cout<<i<<" ";
			cout<<endl;
		}
	}
}
