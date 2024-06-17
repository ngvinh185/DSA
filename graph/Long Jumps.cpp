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
#define vii vector<pair<int,int>>
#define vil vector<pair<int,ll>>
#define vll vector<pair<ll,ll>>
#define vi vector<int>
#define vl vector<ll>
using namespace std;
void solve()
{
	int n; cin>>n;
	int a[n+1];
	int dp[n+1];
	myfor(i,1,n+1) cin>>a[i];
	myFor(i,n,1)
	{
		dp[i]=a[i];
		if(i+a[i] <= n)
		{
			dp[i]+=dp[i+a[i]];
		}
//		cout<<dp[i]<<" ";
	}
	cout<<*max_element(dp+1,dp+n+1)<<endl;
}
int main()
{
	int t;cin>>t;
	while(t--)
	{
		solve();
	}
}