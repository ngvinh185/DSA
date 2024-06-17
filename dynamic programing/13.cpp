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
	int dp1[n]={0};//luu tong day con tang tu 0->ket thuc chi so i
	int dp2[n]={0};//luu tong day con giam tu n-1->i
	my_for(i,0,n)
	{
		dp1[i]=a[i];
		my_for(j,0,i)
		{
			if(a[i]>a[j]) dp1[i]=max(dp1[i],a[i]+dp1[j]);
		}
	}
	my_For(i,n-1,0)
	{
		dp2[i]=a[i];
		my_for(j,i+1,n)
		{
			if(a[i]>a[j]) dp2[i]=max(dp2[i],dp2[j]+a[i]);
		}
	}
	int res=0;
	my_for(i,0,n)
	{
		res=max(res,dp1[i]+dp2[i]-a[i]);
	}
	cout<<res;
}
