#include <bits/stdc++.h>
#define ft() ios::sync_with_stdio(false);cin.tie(nullptr);
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
#define maxn 20
#define mod (int)(1e9 + 7)
using namespace std;
int dp[maxn];// luu 3^i
int bit(int i, int mask)
{
	return (mask / (int)pow((int)3, i)) % 3;
}
int main()
{
	ft()
	int n; cin>>n; // do dai day tam phan
	dp[0] = 1;
	f1(i,n) dp[i] = dp[i-1] * 3;
	for(int mask = 0; mask < dp[n]; mask += 1)
	{
		for(int i = n - 1; i >= 0; i--)
		{
			cout<<bit(i, mask);
		}
		cout<<endl;
	}
}
