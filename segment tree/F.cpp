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
#define maxn 100001
using namespace std;
int a[maxn], t[maxn];
void build(int id, int l, int r)
{
	if(l == r) 
	{
		if(a[l] == 1) t[id] = 1;
		else t[id] = 0;
	}
	else
	{
		int m =(l+r)/2;
		build(id*2, l, m);
		build(id*2+1, m+1, r);
		t[id] = t[id*2] + t[id*2+1];
	}
}
void update(int id, int l, int r, int pos)
{
	if (l == r) 
	{
		if(a[l] == 1) t[id] = 0;
		else t[id] = 1;	
	}	
	else 
	{
		int m = (l+r)/2;
		if(pos <= m) update(id*2, l, m, pos);
		else update(id*2+1, m+1, r, pos);
		t[id] = t[id*2] + t[id*2+1];
	}
}
int get(int id, int l, int r, int k)
{
	if(l == r) return l;
	else
	{
		int m = (l+r)/2;
		if(t[id*2] >= k) return get(id*2, l, m, k);
		else return get(id*2+1, m+1, r, k - t[id*2]);
	}
}
int main()
{
	vinh
	int n, q; cin>>n>>q;
	myfor(i,1,n+1) cin>>a[i];
	build(1,1,n);
	while(q--)
	{
		int num ; cin>>num;
		if(num == 1) 
		{
			int pos; cin>>pos;
			update(1,1,n,pos);
		}
		else
		{
			int k; cin>>k; cout<<get(1, 1, n, k)<<endl;
		}
	}
}
