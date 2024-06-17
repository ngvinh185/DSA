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
	string s,t;cin>>s>>t;
	int n=s.size(),m=t.size();
	s="@"+s,t="@"+t;
	int dp[n+1][m+1];
	my_for(i,0,n+1)
	{
		my_for(j,0,m+1)
		{
			if(i==0||j==0) dp[i][j]=0;
			else if(s[i]==t[j]) dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	cout<<dp[n][m];
}
