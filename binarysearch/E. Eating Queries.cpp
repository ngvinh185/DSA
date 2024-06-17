#include <bits/stdc++.h>
#define ft() ios::sync_with_stdio(false);cin.tie(nullptr);
#define el cout<<"\n"
#define f(i,a,b) for(int i=a;i<b;i++)
#define F(i,a,b) for(int i=a;i>=b;i--)
#define foreach(x,a) for(auto x:a)
#define forEach(x,a) for(auto &x:a)
#define f1(i,n) for(int i=1;i<=n;i++)
#define f0(i,n) for(int i=0;i<n;i++)
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
#define pb push_back
#define maxn 200005
#define mod (int)(1e9 + 7)
using namespace std;
int a[maxn], n, k, dp[maxn];
void ktao()
{
	f1(i,n) dp[i] = dp[i-1] + a[i];
}
void solve()
{
	int q;
	cin>>n>>q;
	f1(i, n) cin>>a[i];
	sort(a + 1, a + n + 1);
	ktao();
//	f1(i, n) cout<<dp[i]<<" ";
//	cout<<endl;
	while(q --)
	{
		cin>>k;
		int l = -1, r = n + 1;
		while(r - l > 1)
		{
			int m = (l + r) / 2;
			if(dp[n] - dp[n - m] >= k) r = m;
			else l = m;
//			cout<<l<<" "<<m<<" "<<r<<endl;
		}
		if(r != n + 1) cout<<r<<endl;
		else cout<<-1<<endl;
	}
}
int main()
{
	ft()
	int t; cin>>t;
	while(t--)
	{
		solve();
	}
}
