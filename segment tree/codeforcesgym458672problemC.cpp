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
int a[100001], t[4*100001];// luu chi so phan tu lon nhat trong doan l-> r
int compare(int i, int j)
{
	return (a[i] > a[j]) ? i : j;
}
void build(int id, int l, int r)
{
	if(l == r) t[id] = l;
	else
	{
		int m = (l+r)/2;
		build(id * 2, l, m);
		build(id * 2 + 1, m+1, r);
		t[id] = compare(t[id*2], t[id*2+1]);
	}
}
void update(int id, int l, int r, int pos)
{
	if(l==r) 
	{
		t[id] = pos;
	}
	else
	{
		int m = (l+r)/2;
		if(pos <= m) update(id*2, l, m, pos);
		else update(id*2+1, m+1, r, pos);
		t[id] = compare(t[id*2], t[id*2+1]); 
	}
}
int get(int id, int l, int r, int u, int v)
{
//	if(l>r) return 0;
	if(l > v||u > r) return 0;
	if(l>=u && r<=v) return t[id];
	int m = (l+r)/2;
	int index1 = get(id*2,l,m,u,v);
	int index2 = get(id*2+1,m+1,r,u,v);
	return compare(index1, index2);
}
int main()
{
	int n; cin>>n;
	myfor(i,1,n+1) cin>>a[i];
	build(1,1,n);
	int q; cin>>q;
	a[0] = 1;
	while(q--)
	{
		int num; cin>>num;
		if(num)
		{
			int u, v, MOD; cin>>u>>v>>MOD;
			int p1 = get(1,1,n,u,v);
			int p2 = compare(get(1,1,n,u,p1-1), get(1,1,n,p1+1,v));
			cout<<((a[p1]%MOD)*(a[p2]%MOD)) % MOD<<endl;
		}
		else
		{
			int pos, val;
			a[pos] = val;
			update(1,1,n,pos);
		}
	}
}