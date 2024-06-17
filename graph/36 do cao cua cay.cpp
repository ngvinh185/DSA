#include <bits/stdc++.h>
#define vinh ios::sync_with_stdio(false);cin.tie(nullptr);
#define myfor(i,a,b) for(int i=a;i<b;i++)
#define myFor(i,a,b) for(int i=a;i>=b;i--)
#define foreach(x,a) for(auto x:a)
#define forEach(x,a) for(auto &x:a)
#define ll long long
#define ms(x,y) memset(x,y,sizeof(x))
//#define first fi
//#define second se
// cay giua 2 dinh chi co 1 duong di duy nhat
using namespace std;
vector<int> a[10001];
set<pair<int,int>> se;
void dfs(int v,int h)
{
	se.insert({v,h});
	visited[v]=1;
	foreach(x,a[v])
	{
		dfs(x,h+1);	
	}
}
int main()
{
	vinh
	int n; cin>>n;
	myfor(i,1,n)
	{
		int x,y;cin>>x>>y;
		a[x].push_back(y);
	}
	myfor(i,1,n+1)
	{
		if(!visited[i])
		{
			dfs(i,0);
		}
	}
	foreach(x,se) cout<<x.second<<" ";
}
