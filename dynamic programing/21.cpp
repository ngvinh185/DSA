#include <bits/stdc++.h>
#define vinh ios::sync_with_stdio(false);cin.tie(nullptr);
#define anonymous main
#define int long long
#define my_for(i,a,b) for(int i=a;i<b;i++)
#define my_For(i,a,b) for(int i=a;i>=b;i--)
#define foreach(x,a) for(auto x:a)
#define forEach(x,a) for(auto &x:a)
using namespace std;
int dp[10001];
anonymous()
{
	vinh
	int n;cin>>n;
	int a[n];forEach(x,a) cin>>x;
	dp[0]=1;
	my_for(i,0,n)
	{
		my_For(j,10001,a[i]) // dc lap lai nhieu lan //moi phan tu trong mang xet 1 lan
		{
			if(dp[j-a[i]]) dp[j]=1;
		}
	}
	my_for(i,0,10001)
	{
		if(dp[i]) cout<<i<<" ";
	}	
}