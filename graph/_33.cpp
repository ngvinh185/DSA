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
using namespace std;
int visited[10001];
set<int> a[10001];
int dfs(int v,int par,int check,int cnt)
{
	visited[v]=1;
	foreach(x,a[v])
	{
		if(!visited[x])
		{
			if(!dfs(x,v,0,cnt+1)) return 0;
		}
		else if(visited[x]==1 && x!=par) 
		{
			check=1;
		}
	}
//	cout<<v<<" "<<check<<" "<<cnt<<endl;
	if(check==1) return 1;
	else if(check==0&&cnt==1||check==0&&cnt==2) return 1;
	else return 0;
}
int main()
{
	vinh
//	ms(visited,0);
	int n,m; cin>>n>>m;
	myfor(i,0,m)
	{
		int x,y; cin>>x>>y;
		a[x].insert(y);
		a[y].insert(x);
	}
//	myfor(i,1,n+1) 
//	{
//		sort(a[i].begin(),a[i].end());
//	}
	int ok=0;
	myfor(i,1,n+1)
	{
		if(!visited[i])
		{
			if(dfs(i,-1,0,1)==0) 
			{
				cout<<"NO";
				ok=1;
				break;
			}
		}
	}
	if(!ok) cout<<"YES";
}
