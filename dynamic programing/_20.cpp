#include <bits/stdc++.h>
#define vinh ios::sync_with_stdio(false);cin.tie(nullptr);
#define anonymous main
#define int long long
#define my_for(i,a,b) for(int i=a;i<b;i++)
#define my_For(i,a,b) for(int i=a;i>=b;i--)
#define foreach(x,a) for(auto x:a)
#define forEach(x,a) for(auto &x:a)
using namespace std;
int a[505][505];
int dp[505][505];
anonymous()
{
	vinh
	int n,m;cin>>n>>m;
	int res=0;
	my_for(i,1,n+1)
	{
		my_for(j,1,n+1) cin>>a[i][j];
	}
	my_for(i,1,n+1)
	{
		my_for(j,1,n+1)
		{
			if(a[i][j]==1) 
			{
				dp[i][j]=min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]})+1;
				res=max(res,dp[i][j]);
			}
			else dp[i][j]=0;
		}
	}
	cout<<res;
}
