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
#define maxn 200005
using namespace std;
struct node 
{
	ll Max, pre, suf;
	ll sum;
}; 
node t[4*maxn]; int a[maxn];
void merge(int id)
{
	t[id].Max = max({t[id*2].Max,t[id*2+1].Max,t[id*2].suf+t[id*2+1].pre});
	t[id].pre = max(t[id*2].pre, t[id*2].sum + t[id*2+1].pre);
	t[id].suf = max(t[id*2+1].suf, t[id*2+1].sum + t[id*2].suf);
	t[id].sum = t[id*2].sum + t[id*2+1].sum;
}
void update(int id, int l, int r, int pos, int val)
{
	if(pos < l || r < pos) return ;
	if(l==r)
	{
		t[id] = {max(0,a[pos]), max(0, a[pos]), max(0,a[pos]), val};
	}
	else
	{
		int m = (l+r)/2;
		update(id*2, l, m, pos, val);
		update(id*2+1, m+1, r, pos, val);
		merge(id);
	}
}
int main()
{
	vinh
	int n, q; cin>>n>>q;
	myfor(i,1,n+1) 
	{
		cin>>a[i];
		update(1,1,n,i,a[i]);
	}
	while(q--)
	{
		int pos, val; cin>>pos>>val;
		a[pos] = val;
		update(1,1,n,pos,val);
		cout<<t[1].Max<<endl;
	}
}
