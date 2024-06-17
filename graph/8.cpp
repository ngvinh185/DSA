#include <bits/stdc++.h>
#define vinh ios::sync_with_stdio(false);cin.tie(nullptr);
#define anonymous main
#define int long long
#define my_for(i,a,b) for(int i=a;i<b;i++)
#define my_For(i,a,b) for(int i=a;i>=b;i--)
#define foreach(x,a) for(auto x:a)
#define forEach(x,a) for(auto &x:a)
using namespace std;
anonymous()
{
	vinh
	vector<pair<pair<int,int>,int>> d;
	int n;cin>>n;
	int a[n+1][n+1];
	my_for(i,1,n+1)
	{
		my_for(j,1,n+1)
		{
			cin>>a[i][j];
			if(a[i][j]!=0&&i<j)
			{
				d.push_back({{i,j},a[i][j]});
			}
		}
	}
	foreach(x,d)
	{
		cout<<x.first.first<<" "<<x.first.second<<" "<<x.second<<endl;
	}
}
