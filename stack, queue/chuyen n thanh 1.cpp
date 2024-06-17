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
int main()
{
	vinh
	int t; cin>>t;
	while(t--)
	{
		int n, m; cin>>n;
		m = 1;
		queue<pii> q;
		q.push({0,n});
		set<int> se; se.insert(n);
		while(!q.empty())
		{
			auto it = q.front(); q.pop();
			int cnt = it.fi, v = it.se;
//			cout<<"Thao tac thu "<<cnt<<" :x = "<<v<<endl;
			if(v == m) 
			{
				cout<<cnt<<endl;
				break;
			}
			else
			{
				if(v > 1 && se.count(v-1) == 0)
				{
					se.insert(v-1);
					q.push({cnt+1, v-1});													
				}
				myfor(i,2,sqrt(v)+1)
				{
					if(v % i == 0)
					{
						int tmp = max(v/i,i);
//						se.insert(v/i);
						q.push({cnt+1, tmp});
					}
				}
			}
		}
	}	
}
