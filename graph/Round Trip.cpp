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
vector<int> a[100001];
int check=0;
int visited[100001];
int parent[100001];
int s,e;

int dfs(int v)
{
	visited[v]=1;
	foreach(x,a[v])
	{
		if(!visited[x])
		{
			parent[x]=v;
			if(dfs(x)) return 1;
		}
		else if(visited[x]&&x!=parent[v]) 
		{
			s=x;
			e=v;
			return 1;
		}
	}
	return 0;
}
void Print()
{
	vector<int> d;
	while(e!=s)
	{
		d.push_back(e);
		e=parent[e];
	}
	reverse(d.begin(),d.end()) ;
	cout<<d.size()+2<<endl;
	cout<<s<<" ";
	foreach(x,d) cout<<x<<" ";
	cout<<s<<endl;
}
int main()
{
	vinh
	int n, m; cin>>n>>m;
	myfor(i,0,m)
	{
		int x,y;cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	parent[1]=-1;
	int ok=0;
	myfor(i,1,n+1)
	{
		if(!visited[i])
		{
			if(dfs(i)) 
			{
				Print();
				ok=1;
			}
		}
	}
	if(!ok) cout<<"IMPOSSIBLE";
}
