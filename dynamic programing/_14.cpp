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
	int s;cin>>s;
	int dp[s+1]={0};
	dp[0]=1;
	my_for(i,1,s+1)
	{
		my_for(j,1,7)
		{
			if(i>=j)
				dp[i]+=dp[i-j];
		}
	}
	cout<<dp[s];
}
