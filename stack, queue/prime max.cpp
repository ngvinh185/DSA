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
#define maxn
#define bit(i, s) ((s>>i) & 1)
#define mod (int)(1e9 + 7)
using namespace std;
bool nt(int n)
{
	f(i, 2, sqrt(n)+1) 
	{
		if(n % i == 0) return false;
	}
	return n > 2;
}
int main()
{
	ft()
	int n; cin>>n;
	ll res = -1e18;
	int a[n];
	forEach(x, a) cin>>x;
	f0(mask, (1<<n))
	{
		ll s = 0;
		f0(i, n) 
		{
			if(bit(i, mask)) s += a[i];
		}
		if(nt(s)) res = max(res, s);
	}
	cout<<res;
}
