#include <bits/stdc++.h>
#define ft() ios::sync_with_stdio(false);cin.tie(nullptr);
#define myfor(i,a,b) for(int i=a;i<b;i++)
#define myFor(i,a,b) for(int i=a;i>=b;i--)
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
#define maxn 5001
#define mod (int)(1e9 + 7)
using namespace std;
set<int> a[maxn];
vi ec;
int n, m;
void build(int v)
{
	stack<int> st;
	st.push(v);
	while(!st.empty())
	{
		int top = st.top();
		if(a[top].size())
		{
			auto it = a[top].begin();
			int u = *it;
			a[top].erase(it);
			auto _it = a[u].find(top);
			a[u].erase(_it);
			st.push(u);
		}
		else
		{
			ec.push_back(top);
			st.pop();
		}
	}
	foreach(x,ec) cout<<x<<" ";
}
int main()
{
	ft()
	cin>>n>>m;
	f1(i,m)
	{
		int x, y; cin>>x>>y;
		a[x].insert(y);
		a[y].insert(x);
	}
	build(1);
}
