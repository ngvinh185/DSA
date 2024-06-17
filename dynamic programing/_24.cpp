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
	int dp[n+1]={0};// luu so luong so it nhat co tong binh phuong bang i
	my_for(i,1,n+1)
	{
		dp[i]=1e9;
		my_for(j,1,sqrt(i)+1)
		{
			
			dp[i]=min(dp[i],dp[i-j*j]+1);
		}
		cout<<i<<" "<<dp[i]<<endl;
	}
	cout<<dp[n];
}
