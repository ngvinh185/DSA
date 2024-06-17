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
int a[maxn], n, k;
bool check (int x)
{
	ll s = 0; // chi phi tao nen so trung vi x
	f(i, (n+1)/2, n+1)
	{
		if(a[i] < x) s += x - a[i]; 
	}
	return s <= k; // xem chi phi do co tman ko
}
int main()
{
	ft()
	cin>>n>>k;
	f1(i, n) cin>>a[i];
	sort(a+1, a+n+1);
	ll l = a[(n+1)/2], r = 2e9 + 1;
	// l: la so trung vi lon nhat co the tao nen ko vuot qua k block, l luon dung; r la so trung vi ko the tao nen vs k block (r luon sai)
	while(r -l > 1)
	{
		int m = (l + r) / 2;
		if(check(m)) l = m;
		else r = m;
	}
	cout<<l;
}
