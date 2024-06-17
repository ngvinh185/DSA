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
int d[10001];
vector<int> a[10001];
int n, m;
int dfs(int v,int dem)
{
	int res=0;
	if(d[v]==1) dem+=1;
	else if(d[v]==0) dem=0;
	if(dem>m) return 0;// branch of bound
	int ok=0;
	foreach(x,a[v])
	{
		res+=dfs(x,dem);
		ok=1;
	}
	if(ok) cout<<v<<" "<<res<<endl;
	else cout<<v<<" "<<1<<endl;
	if(!ok) return 1;// day la 1 node la vi node la khong vao vong for
	else return res;
}
int main()
{
	vinh
	cin>>n>>m;
	myfor(i,1,n+1) cin>>d[i];
	myfor(i,0,n-1)
	{
		int x,y;cin>>x>>y;
		a[x].push_back(y);
	}
//	if(d[1]==1) cout<<dfs(1,1);
//	else cout<<dfs(1,0);
	cout<<dfs(1,0);
}
