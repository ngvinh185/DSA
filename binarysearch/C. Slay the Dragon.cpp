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
ll a[maxn], n, x, y, tong = 0;
void ktao()
{
	f1(i, n)
	{
		tong += a[i];
	}
} 

bool check(ll s)
{
	int it = lower_bound(a + 1, a + n + 1, x) - a;
	if(it != n + 1)
	{
		ll sum = tong - a[it];
		if(sum + s >= y) 
		{
			return true;
		}
		it -= 1;
		s -= (x - a[it]);
		if (s >= 0 && it != 0)
		{
			sum = tong - a[it];
			if(sum + s >= y) 
			{
				return true;
			}
		}
	}
	else
	{
		s -= (x - a[n]);
		if(s >= 0)
		{
			ll sum = tong - a[n];
			if(sum + s >= y) 
			{
				return true;
			}
		}
	}
	return false;
}
void solve()
{
	cin>>x>>y;
	ll l = -1, r = 1e18 + 5;
	while(r - l > 1)
	{
		ll m = (l + r) / 2;
		if(check(m)) r = m;
		else l = m;
//		cout<<endl;
	}
	cout<<r<<endl;
}
int main()
{
	ft()
	cin>>n;
	f1(i, n) cin>>a[i];
	sort(a + 1, a + n + 1);
	ktao();
	int t; cin>>t;
	while(t--)
	{
		solve();
	}
}
