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
#define pb push_back
#define maxn 10001
#define mod (int)(1e9 + 7)
using namespace std;

int child[50 * maxn][27], isEnd[50 * maxn], cnt = 0;

void Add(string s)
{
	int u = 0;
	foreach(x, s)
	{
		if(!child[u][x - 'a']) child[u][x - 'a'] = ++cnt;
		u = child[u][x - 'a'];
	}
	isEnd[u] = 1;
}

bool Querry(string s)
{
	int u = 0;
	foreach(x, s)
	{
		if(!child[u][x - 'a']) return false;
		u = child[u][x - 'a'];
	}
	return isEnd[u];
}
int main()
{
	ft()
	string s;
	int n, q; cin>>n;
	while(n--)
	{
		cin>>s;
		Add(s);
	}
	cin>>q;
	while(q--)
	{
		cin>>s;
		cout<<Querry(s)<<endl;
	}
}
