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

bool check(string s)
{
	stack<char> st;
	foreach(x, s)
	{
		if(x == '(') st.push(x);
		else 
		{
			if(st.empty()) return 0;
			char top = st.top();
			if(top != '(') return 0;
			st.pop();	
		} 
	}
	return st.empty();
}
int main()
{
	ft()
	int n; cin>>n;
	n*=2;
	vector<string> ans;
	f(mask, 1, (1<<n))
	{
		string s = "";
		F(i, n-1, 0)
		{
			int x = ((mask >> i) & 1);
			if(x == 1) s += ')';
			else s += '(';
		}
		ans.pb(s);
	}
	vector<string> res;
	foreach(x, ans)
	{
		if(check(x)) res.pb(x);
//		cout<<x<<" ";
	}
	cout<<res.size()<<endl;
	foreach(x, res) {cout<<x; el;}
}
