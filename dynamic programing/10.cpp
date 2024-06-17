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
	int dp[n]={0};// tong day con khong lien ke lon nhat ket thuc tai chi so i
	priority_queue<int> d;
	dp[0]=a[0];
	my_for(i,1,n)
	{
		if(i==1) dp[i]=a[i];
		else
		{
			d.push(dp[i-2]);
			int x=d.top();
			dp[i]=a[i]+x;
		}
	}
	cout<<dp[n-1];
}
