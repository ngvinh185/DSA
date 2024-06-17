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
int dx[8] = {-2, -2, -1, -1, +1, +1, +2, +2};
int dy[8] = {-1, +1, -2, +2, -2, +2, -1, +1};
int solve()
{
	string s, e; cin>>s>>e;
	int s1 = s.substr(0,1)[0] - 'a' + 1;
	int s2 = s.substr(1)[0] - '0';
	int e1 = e.substr(0,1)[0] - 'a' +1;
	int e2 = e.substr(1)[0] - '0';
	queue<pair<pii,int>> q;
	q.push({{s1,s2},0});
	while(!q.empty())
	{
		auto it = q.front();q.pop();
		int i = it.fi.fi, j = it.fi.se, dis = it.se;
		if(i == e1 && j == e2)
		{
			return dis;
		}
		myfor(k,0,8)
		{
			int i1 = i + dx[k], j1 = j + dy[k];
			if(i1 >=1 && i1 <=8 && j1 >=1 && j1 <= 8)
			{
				q.push({{i1,j1},dis+1});
			}
		}
	}
	return 0;
}
int main()
{
	vinh
	int t; cin>>t;
	while(t--)
	{
		cout<<solve()<<endl;
	}
}
