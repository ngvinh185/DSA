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
	int dp[n+1]={0};//luu so cach tao ra so cham = i
	dp[0]=1;
	my_for(i,1,n+1)
	{
		my_for(j,1,7)
		{
			if(i>=j) dp[i]+=dp[i-j];
		}
	}
	cout<<dp[n];
}
