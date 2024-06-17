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
	int a[n+1];
	int s=0;
	my_for(i,1,n+1)
	{
		cin>>a[i];
		s+=a[i];
	}
	int dp[s+1]={0};
	dp[0]=1;
	my_for(i,1,n+1)
	{
		my_For(j,s,a[i])
		{
			if(dp[j-a[i]]) dp[j]=1;
		}
	}
	my_for(i,0,s+1)
	{
		if(dp[i]) cout<<i<<" ";
	}
}
