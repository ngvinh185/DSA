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
int dp[505][505];
int main()
{
	string s; cin>>s;
	int n = s.size();
	myfor(i,0,n)
	{
		myfor(j,0,i+1)
		{
			dp[i][j] = 1;
		}
	}
	int res = -1e9;
	myfor(d,1,n)
	{
		myfor(i,0,n-d)
		{
			int j = i + d;
			if(s[i] == s[j]) 
			{
				if(dp[i+1][j-1]) dp[i][j] = 1;  
				else dp[i][j] = 0;
			}
			else dp[i][j] = 0;
//			if (dp[i][j]) res = max(res,d+1);
		}
	}

	myfor(i,0,n)
	{
		myfor(j,i,n)
		{
			if(dp[i][j] == 1) res = max(res,j-i+1);
		}
	}
	cout<<res;
}
