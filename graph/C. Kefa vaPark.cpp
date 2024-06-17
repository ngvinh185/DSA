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
int visited[100001], d[100001];
int n, m;
int dfs(int v, int cnt)
{
	visited[v] = 1;
	if (d[v] == 1) cnt +=1;
	else cnt = 0;
	if (cnt > m) return 0;
	int res = 0;
	int ok = 0;
	foreach(x, a[v])
	{
		if (!visited[x]) 
		{
			ok = 1;
			res += dfs(x,cnt);
		}
	}
	if (!ok) return 1;
	else return res;
}
int main()
{
	vinh
	cin>>n>>m;
	myfor(i,1,n+1) cin>>d[i];
	myfor(i,0,n-1) 
	{
		int x, y; cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	cout<<dfs(1,0);
}
