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
void solve()
{
	string s,t;cin>>s>>t;
	int n=s.size(),m=t.size();
	s='0'+s,t='0'+t;
	my_for(i,1,n+1) dp[i][0]=i;
	my_for(i,1,m+1) dp[0][i]=i;
	my_for(i,1,n+1)
	{
		my_for(j,1,m+1)
		{
			if(s[i]!=t[j])
				dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
			else dp[i][j]=dp[i-1][j-1];
		}
	}
	cout<<dp[n][m]<<endl;
}
anonymous()
{
	vinh
	int t; cin>>t;
	while(t--)
	{
		solve();
	}
}
