#include <bits/stdc++.h>
#define vinh ios::sync_with_stdio(false);cin.tie(nullptr);
#define myfor(i,a,b) for(int i=a;i<b;i++)
#define myFor(i,a,b) for(int i=a;i>=b;i--)
#define foreach(x,a) for(auto x:a)
#define forEach(x,a) for(auto &x:a)
#define ll long long
#define ms(x,y) memset(x,y,sizeof(x))
#define first fi
#define second se

// n dinh thi co so canh max la nC2
using namespace std;
int visited[10001],dem;
void dfs(vector<int> a[],int v)
{
	visited[v]=1;
	dem+=1;
	foreach(x,a[v])
	{
		if(!visited[x])
		{
			dfs(a,x);
		}
	}
}
void xuli(vector<int> a[])
{
	int n,m; cin>>n>>m;
	myfor(i,0,m)
	{
		int x,y; cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	int cnt=0;
	myfor(i,1,n+1)
	{
		if(!visited[i])
		{
			dem=0;
			dfs(a,i);
			cnt+=dem*(dem-1)/2;
		}
	}
	if(cnt==m) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
int main()
{
	vinh
	int t;cin>>t;
	while(t--)
	{
		ms(visited,0);
		vector<int> a[10001];
		xuli(a);
	}	
}
