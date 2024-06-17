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
using namespace std;
int cnt[100001];
ll dp[100001];
int main()
{
	vinh
	int n; cin>>n;
	int a[n];
	myfor(i,0,n)
	{
		cin>>a[i];
		cnt[a[i]]+=1;
	}
	sort(a,a+n);
	priority_queue<pll> q;
	myfor(i,0,n)
	{
		if(a[i]==a[i-1]) continue;
		dp[a[i]] = 1ll * cnt[a[i]] * a[i];
		if(!q.empty())
		{
			auto it = q.top();
			int res = it.se;
			if(res != a[i] - 1) dp[a[i]] += dp[res];
			else 
			{
				q.pop();
				if(!q.empty())
				{
					auto it1 = q.top();
					int res1 = it1.se;
					dp[a[i]] += dp[res1];
				}
				q.push(it);
			}
		}
//		cout<<a[i]<<" "<<dp[a[i]]<<endl;
		q.push({dp[a[i]],a[i]});
	}
	cout<<*max_element(dp,dp+100001);
}
