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

using namespace std;
int parent[100001];
int visit[100001];
vector<int> a[100001];
void Print(int v)
{
//	cout<<v<<" ";

	vector<int> path;
	while(v!=1)
	{
		path.push_back(v);
		v=parent[v];
	}
	reverse(path.begin(),path.end());
	cout<<path.size()+1<<endl;
	cout<<1<<" ";
	foreach(x,path) cout<<x<<" ";
}
int main()
{
	vinh
	int n,m; cin>>n>>m;
	myfor(i,0,m)
	{
		int x,y; cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	queue<pair<int,int>> q;
	q.push({1,0});
	visit[1]=1;
	int ok=0;
	while(!q.empty())
	{
		auto it=q.front();q.pop();
		int d=it.second;

//		cout<<it.first<<" "<<d<<endl;
		if(it.first==n) 
		{
			Print(n);
			ok=1;
			break;
		}
		foreach(x,a[it.first])
		{
			if(!visit[x])
			{
				visit[x]=1;
				parent[x]=it.first;
				q.push({x,d+1});
			}
		}
	}
	if(!ok) cout<<"IMPOSSIBLE";
}
