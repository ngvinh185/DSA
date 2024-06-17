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
ll t[800001];
int a[200001];
void build(int i, int l, int r)
{
	if (l == r)
	{
		t[i] = a[l];
	}
	else
	{
		int m = (l + r) / 2;
		build(i*2, l, m);
		build(i*2+1, m+1, r);
		t[i] = t[i*2] + t[i*2+1]; // merge
	}
}
void update(int i, int l, int r, int pos, int val)
{
	if (l == r) 
	{
		t[i] = val;
	}
	else
	{
		int m = (l+r) / 2;
		if(pos <= m) update(i*2, l, m, pos, val);
		else update(i*2+1, m+1, r, pos, val);
		t[i] = t[i*2] + t[i*2+1]; // merge
	}
}
ll get(int i, int l, int r, int u, int v)
{
	if(r < u || v < l) return 0;
	if(l >= u && r <= v) return t[i];
	int m = (l+r) / 2;
	ll s1 = get(i*2, l, m, u ,v);
	ll s2 = get(i*2+1, m+1, r, u, v);
	return s1 + s2;
}
int main()
{
	vinh
	int n, q; cin>>n>>q;
	myfor(i,1,n+1) cin>>a[i];
	build(1,1,n);
	while(q--)
	{
		int num; cin>>num;
		if(num == 1)
		{
			int y, x; cin>>y>>x;
			update(1, 1, n, y, x);
		}
		else 
		{
			int l, r; cin>>l>>r;
			cout<<get(1, 1, n, l, r)<<endl;
		}
	}
}
