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
#define pll pair<ll,ll>
#define vii vector<pair<int,int>>
#define vil vector<pair<int,ll>>
#define vll vector<pair<ll,ll>>
#define vi vector<int>
#define vl vector<ll>
using namespace std;
int p[101][101], visited[1001], color[1001];
bool dfs(int v,vector<int> a)
{
	visited[v] = 1;
	foreach(x,a[v])
	{
		if(!visited[x]) 
		{
			color[x] = 3 - color[v];
			if(!dfs(x,a)) return false;
		}
		else if(color[x] == color[v]) return false;
	}
	return true;
}
int main()
{
	vinh
	while(1)
	{
		int n; cin>>n;
		if (n==0) break;
		ms(p,0);
		vector<int> a[n+1];
		ms(visited,0);
		ms(color,0);
		myfor(i,1,n+1)
		{
			myfor(j,1,n+1) cin>>p[i][j];
		}
		myfor(i,1,n+1)
		{
			myfor(j,1,n+1)
			{
				if(p[i][j]) a[i].push_back(j);
			}
		}
		myfor(i,1,n+1)
		{
			if(!visited[i])
			{
				color[i] = 1;
				if(!dfs(i,a)) 
				{
					cout<<"NO"<<endl;
					break;
				}
			}
		}
		cout<<"YES"<<endl;
	}
	
}
