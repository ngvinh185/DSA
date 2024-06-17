#include <bits/stdc++.h>
#define vinh ios::sync_with_stdio(false);cin.tie(nullptr);
#define anonymous main
#define int long long
#define my_for(i,a,b) for(int i=a;i<b;i++)
#define my_For(i,a,b) for(int i=a;i>=b;i--)
#define foreach(x,a) for(auto x:a)
#define forEach(x,a) for(auto &x:a)
using namespace std;
vector<int> F[10001];
anonymous()
{
	vinh
	int n;cin>>n;
	int a[n+1][n+1];
	vector<pair<int,int>> d;
	my_for(i,1,n+1)
	{
		my_for(j,1,n+1)
		{
			cin>>a[i][j];
			if(a[i][j]==1&&i>j) d.push_back({i,j});
			if(a[i][j]==1) 	F[i].push_back(j);
		}
	}
	foreach(x,d)
	{
		cout<<x.first<<" "<<x.second;
		cout<<endl;
	}
	cout<<endl;
	my_for(i,1,n+1)
	{
		cout<<i<<" : ";
		foreach(x,F[i]) cout<<x<<" ";
		cout<<endl;
	}
}
