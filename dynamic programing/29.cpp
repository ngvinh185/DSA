#include <bits/stdc++.h>
#define vinh ios::sync_with_stdio(false);cin.tie(nullptr);
#define anonymous main
#define int long long
#define my_for(i,a,b) for(int i=a;i<b;i++)
#define my_For(i,a,b) for(int i=a;i>=b;i--)
#define foreach(x,a) for(auto x:a)
#define forEach(x,a) for(auto &x:a)
using namespace std;
int dp[1001][1001];
anonymous()
{
	vinh
	int n;cin>>n;
	int s=0;
	my_for(i,1,n+1) s+=i;
	int a[n+1];
	my_for(i,0,n+1) a[i]=i;
	if(s%2!=0)
	{
		cout<<0;
		return 0;
	}
	s/=2;
	my_for(i,0,n+1) dp[i][0]=1;
	my_for(i,1,n+1)
	{
		my_for(j,1,s+1)
		{
			if(j>=a[i]) dp[i][j]=dp[i-1][j-a[i]]+dp[i-1][j];
			else dp[i][j]=dp[i-1][j];
		}
	}
	cout<<dp[n][s]/2;
}
