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
int a[10] = {0, 10, 9, 8, 7, 5, 5, 6, 7, 10};
int main()
{
	ft()
	int l = 1, r = 9;
	while(r - l > 4)
	{
//		int m1 = l + (r - l) / 3;
//		int m2 = r - (r - l) / 3;
		int m1 = (l + r) / 2;
		int m2 = m1 + 1;
		cout<<m1<<" "<<m2<<endl;
		if(a[m1] > a[m2]) l = m1;
		else r = m2;
	}
	int p = -1, mi = 20;
	f(i, l, r + 1) if(a[i] < mi) mi = a[i], p = i;
	cout<<p;
}
