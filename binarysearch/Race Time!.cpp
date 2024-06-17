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
#define maxn 100005
#define mod (int)(1e9 + 7)
using namespace std;
struct car 
{
	int v, d;
};
car a[maxn];
int n; 
double g(double t)
{
	double ma = -1e9, mi = 1e9;
	f1(i, n)
	{
		ma = max(ma, (double)a[i].v * t + a[i].d);
		mi = min(mi, (double)a[i].v * t + a[i].d);
	}
	return ma - mi;
}

int main()
{
	ft()
	cin>>n;
	double r; cin>>r;
	f1(i, n) cin>>a[i].v>>a[i].d;
	double l = 0;
	while(r - l > 4)
	{
		double m1 = (r + l) / 2;
		double m2 = m1 + 1;
		if(g(m1) > g(m2)) l = m1;
		else r = m2;
//		cout<<m1<<" "<<m2<<" "<<g(m1)<<" "<<g(m2)<<endl;
	}
	double mi = 1e9;
	f(i, l, r + 1) mi = min(mi, g(i));
	cout<<fixed<<setprecision(6)<<mi;
}
