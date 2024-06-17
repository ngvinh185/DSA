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
	int a[n];
	forEach(x,a) cin>>x;
	int dp[n]={0};//luu tong day con tang dan ket thuc o chi so i
	my_for(i,0,n)
	{
		dp[i]=a[i];
		my_for(j,0,i)
		{
			if(a[i]>a[j]) dp[i]=max(dp[i],a[i]+dp[j]);
		}
	}
	cout<<*max_element(dp,dp+n);
}
