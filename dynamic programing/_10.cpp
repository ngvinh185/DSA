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
	my_for(i,1,n+1) cin>>a[i];
	int dp[n+1]={0};// luu tong lon nhat ket thuc o chi so i sao cho khong co 2 phan tu canh nhau
	dp[1]=a[1];
	my_for(i,2,n+1)
	{
		dp[i]=max(dp[i-1],dp[i-2]+a[i]);
	}
	cout<<dp[n];
}
