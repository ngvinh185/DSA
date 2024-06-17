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
#define maxn 10005
#define mod (int)(1e9 + 7)
using namespace std;

int a[maxn], c[maxn], n;
ll ff(int x)
{
	ll s = 0;
	f1(i, n)
	{
		s += c[i]  * abs(a[i] - x);
	}
	return s;
}
void solve()
{
	cin>>n;
	f1(i, n) cin>>a[i];
	f1(i, n) cin>>c[i];
	int l = 0, r = 1e4;
	while(r - l > 4)
	{
		int m1 = (l + r) / 2;
		int m2 = m1 + 1;
		if(ff(m1) > ff(m2)) l = m1;
		else r = m2;
	}
	ll ans = 1e18;
	f(i, l, r + 1) ans = min(ans, ff(i));
	cout<<ans; el;
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
