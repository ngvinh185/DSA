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
	int n,s;cin>>n>>s;
	int a[n];forEach(x,a) cin>>x;
	int dp[s+1]={1};
	my_for(i,0,n)
	{
		my_For(j,s,a[i])//dung moi phan tu 1 lan , con dung 1 phan tu nhieu lan thi duyet j=a[i]->s
		{
			if(dp[j-a[i]])
			{
				dp[j]=1;
				if(dp[s]==1) 
				{
					cout<<1;
					return 0;
				}
			}
		}
	}
	cout<<0;
}
