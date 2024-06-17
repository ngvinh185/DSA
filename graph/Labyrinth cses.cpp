#include <bits/stdc++.h>
#define vinh ios::sync_with_stdio(false);cin.tie(nullptr);
#define myfor(i,a,b) for(int i=a;i<b;i++)
#define myFor(i,a,b) for(int i=a;i>=b;i--)
#define foreach(x,a) for(auto x:a)
#define forEach(x,a) for(auto &x:a)
#define ll long long
#define ms(x,y) memset(x,y,sizeof(x))
#define first fi
#define second se

using namespace std;
int n, m;
char a[n][m];
int dx[]={-1,0,0,1};
int dy[]={0,1,-1,0};
int main()
{
	vinh
	cin>>n>>m;
	queue<pair<pair<int,int>,int>> q;
	myfor(i,0,n)
	{
		myfor(j,0,m) 
		{
			cin>>a[i][j];
			if(a[i][j]=='A') q.push({{i,j},0});
		}
	}
	while(!q.empty())
	{
		auto it=q.front();q.pop();
		if(a[it.first.first][it.first.second]=='B')
		{
			cout<<
		}
	}
}
