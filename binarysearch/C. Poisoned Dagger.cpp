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
#define maxn 105
#define mod (int)(1e9 + 7)
using namespace std;
int a[maxn], n; ll k;
bool check(ll x)
{
	ll s = 0;
	f(i, 2, n+1)
	{
		s += fmin(a[i] - a[i-1], x);
	}
	s += x;
	return s >= k;
}

void solve()
{
	cin>>n>>k;
	f1(i, n) cin>>a[i];
	ll l = 0, r = 1e18 + 5;
	while(r - l > 1)
	{
		ll m = (l + r) / 2;
		if(check(m)) r = m;
		else l = m;
	}
	cout<<r<<endl;
}

int main()
{
	ft();
	int t; cin>>t;
	while(t --)
	{
		solve();
	}
}
