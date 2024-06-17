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

int visit[10001];
int d[10001];
vector<int> a[10001];
int n,m;
int dfs(int v,int dem)
{
	int res=0;
	visit[v]=1;
	if(d[v]==1) dem+=1;
	else dem=0;
	int ok=0;
	if(dem>m) return 0;
	foreach(x,a[v])
	{
		if(!visit[x])
		{
			res+=dfs(x,dem);
			ok=1;
		}	
	}	
	if(ok) cout<<v<<" "<<res<<endl;
	else cout<<v<<" "<<1<<endl;
	if(!ok) return 1;
	return res;
}
int main()
{
	vinh
	cin>>n>>m;
	myfor(i,0,n)
		cin>>d[i];
	myfor(i,0,n-1)
	{
		int x,y; cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	cout<<dfs(1,0);
}
