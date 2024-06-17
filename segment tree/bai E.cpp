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
#define maxn 1000001
using namespace std;
struct node
{
	int open, close, sum;
	friend node operator + (node &a, node &b)
	{
		node x;
		int mi = min(a.open, b.close);
		x.sum = a.sum + b.sum + 2 * mi;
		x.close = a.close + b.close - mi;
		x.open = a.open + b.open - mi;
		return x;
	}
};
node t[4*maxn]; string s;
void build(int id, int l, int r)
{
	if(l == r)
	{
		node x;
		if(s[l] == ')') x.close = 1;
		else if(s[l] == '(') x.open = 1;
		x.sum = 0;
		t[id] = x;
		return;
	}
	int m = (l+r)/2;
	build(id*2, l, m);
	build(id*2+1, m+1, r);
	t[id] = t[id*2] + t[id*2+1];
}
node get(int id, int l, int r, int u, int v)
{
	if(u>r || l>v) return {0,0,0};
	if(l>=u && r<=v) return t[id];
	int m = (l+r)/2;
	node t1 = get(id*2, l, m, u, v);
	node t2 = get(id*2+1, m+1, r, u, v);
	return t1 + t2;
}
int main()
{
	vinh
	cin>>s;
	s = " " + s;
	build(1,1,s.size());
	int q; cin>>q;
	while(q--)
	{
		int l, r; cin>>l>>r;
		node x = get(1, 1, s.size(), l, r);
		cout<<x.sum<<endl;
	}
}
