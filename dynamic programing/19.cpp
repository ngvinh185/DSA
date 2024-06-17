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
	int n;cin>>n;
	char a[n+1][n+1];
	int dp[n+1][n+1];//luu tong so cach di toi o i,j
	my_for(i,1,n+1)
	{
		my_for(j,1,n+1) cin>>a[i][j];
	}
	dp[0][1]=dp[1][0]=1;
	my_for(i,1,n+1)
	{
		my_for(j,1,n+1)
		{
			if(a[i][j]=='.') 
			{
				if(i==1) dp[i][j]=dp[i][j-1];//th dac biet
				else if(j==1) dp[i][j]=dp[i-1][j];//th dac biet
				else if(a[i][j]=='.') dp[i][j]=dp[i-1][j]+dp[i][j-1];
			}
			else dp[i][j]=0;
		}
	}
	cout<<dp[n][n];
}
