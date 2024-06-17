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
int cnt[100002];
ll dp[100002];
int main()
{
	vinh
	int n; cin>>n;
	int a[n];
	myfor(i,0,n)
	{
		cin>>a[i];
		cnt[a[i]]+=1;
	}
	dp[1] = cnt[1];
	myfor(i,2,100002)
	{
		dp[i] = max(dp[i-2] + 1ll*i*cnt[i], dp[i-1]);
	}
	cout<<dp[100001];
}
