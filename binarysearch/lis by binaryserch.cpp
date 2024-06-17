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
#define mod (int)(1e9 + 7)
using namespace std;
int a[maxn], n, b[maxn], ans;
int main()
{
	ft()
	cin>>n;
	f1(i, n) cin>>a[i];
	f1(i, n)
	{
//		int x = lower_bound(b + 1, b + ans + 1, a[i]) - b; // b[i+1] > b[i]
		int x = upper_bound(b + 1, b + ans + 1, a[i]) - b; // b[i+1] >= b[i]
		ans = max(ans, x);
		b[x] = a[i];
	}
	cout<<ans;
}
