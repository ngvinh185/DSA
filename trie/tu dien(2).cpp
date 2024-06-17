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
#define maxn
#define mod (int)(1e9 + 7)
using namespace std;
struct node
{
	node* child[26];
	int isEnd;
	node()
	{
		ms(child, NULL);
		isEnd = 0;
	}
};

node *root = new node();

void Add(string s)
{
	node *u = root;
	foreach(x, s)
	{
		int k = x - 'a';
		if(u -> child[k] == NULL) u -> child[k] = new node();
		u = u -> child[k]; 
	}
	u -> isEnd = 1;
}

bool Querry(string s)
{
	node *u = root;
	foreach(x, s)
	{
		int k = x - 'a';
		if(u -> child[k] == NULL) return 0;
		u = u -> child[k]; 
	}
	return u -> isEnd;
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
