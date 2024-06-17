#include <bits/stdc++.h>
#define vinh ios::sync_with_stdio(false);cin.tie(nullptr);
#define anonymous main
#define int long long
#define my_for(i,a,b) for(int i=a;i<b;i++)
#define my_For(i,a,b) for(int i=a;i>=b;i--)
#define foreach(x,a) for(auto x:a)
#define forEach(x,a) for(auto &x:a)
using namespace std;
vector<int> a[10001];
anonymous()
{
	vinh
	int n,m;cin>>n>>m;
	my_for(i,1,m+1)
	{
		int x,y;cin>>x>>y;
		a[x].push_back(y);
	}
	my_for(i,1,n+1)
	{
		cout<<i<<" : ";
		sort(a[i].begin(),a[i].end());
		foreach(x,a[i]) cout<<x<<" ";
		cout<<endl;
	}
}
