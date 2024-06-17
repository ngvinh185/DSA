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
#define vii vector<pair<int,int>>
#define vil vector<pair<int,ll>>
#define vll vector<pair<ll,ll>>
#define vi vector<int>
#define vl vector<ll>
using namespace std;
// sai
int n, m;
int ok = 0;
int dfs(int n, int cnt)
{
	cout<<n<<" "<<cnt<<endl;
	if(ok) return cnt;
	if(n <= 0 ) return -1;
	else if(n == m) 
	{
		ok = 1;
		return cnt;
	}
	else if(n > 0)
	{
		int l = -1;
		if(n*2 <= m) l = dfs(n*2, cnt+1);
		int r = dfs(n-1, cnt+1);
		if(ok)
		{
			ok = 0;
			return cnt+1;
		}
		if (l==-1) return r;
		else if(r==-1) return l;
		else return min(l,r);
	}
	return -1;
}
int main()
{
	vinh
	cin>>n>>m;
	cout<<dfs(n, 0);
}
