#include <bits/stdc++.h>
#define vinh ios::sync_with_stdio(false);cin.tie(nullptr);
#define myfor(i,a,b) for(int i=a;i<b;i++)
#define myFor(i,a,b) for(int i=a;i>=b;i--)
#define foreach(x,a) for(auto x:a)
#define forEach(x,a) for(auto &x:a)
#define ll long long
#define ms(x,y) memset(x,y,sizeof(x))
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pair<int,int>>
#define vil vector<pair<int,ll>>
#define vll vector<pair<ll,ll>>
#define vi vector<int>
#define vl vector<ll>
using namespace std;
int dp[17][5001];
main()
{
	vinh
	int s, n; cin>>s>>n;
	int a[n+1]; 
	myfor(i,1,n+1) cin>>a[i];
	myfor(i,0,n+1)
	{
		dp[i][0] = true;
	}
	myfor(i,1,n+1)
	{  	
		myfor(j,1,s+1)
		{
			if(j>=a[i])
			{
				dp[i][j] = dp[i-1][j-a[i]] || dp[i-1][j];
			}
			else dp[i][j] = dp[i-1][j];
		}
	}
	myFor(i,s,0) 
	{
		if(dp[n][i]) 
		{
			cout<<i;
			return 0;
		}
	}
}
