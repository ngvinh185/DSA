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
vector<int> a[100001];
int ok;
int visited[100001];
void dfs(int v)
{
	if(ok) return ;
	visited[v]=1;
	foreach(x,a[v])
	{
		if(!visited[x]) dfs(x);
		else 
		{
			cout<<x<<" ";
			ok=1;
			return;
		}
	}
}
int main()
{
	vinh
	int n; cin>>n;
	myfor(i,1,n+1)
	{
		int x; cin>>x;
		a[i].push_back(x);
	}
	myfor(i,1,n+1)
	{
		ms(visited,0);
		ok=0;
		dfs(i);
	}
}
