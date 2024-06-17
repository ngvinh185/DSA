#include <bits/stdc++.h>
#define vinh ios::sync_with_stdio(false);cin.tie(nullptr);
#define myfor(i,a,b) for(int i=a;i<b;i++)
#define myFor(i,a,b) for(int i=a;i>=b;i--)
#define foreach(x,a) for(auto x:a)
#define forEach(x,a) for(auto &x:a)
#define ll long long
#define ms(x,y) memset(x,y,sizeof(x))
//#define first fi
//#define second se

using namespace std;
int n, m;
int a[1001][1001];
int dx[]={-1,0,0,1};
int dy[]={0,1,-1,0};
void dijkstra(int i,int j)
{
	vector<vector<int>> d;
	myfor(i,0,n)
	{
		vector<int> tmp(m,1e9);
		d.push_back(tmp);
	}
	d[i][j]=a[i][j];
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
	q.push({d[i][j],{i,j}});
	while(!q.empty())
	{
		auto it=q.top(); q.pop();
		auto index=it.second; int kc=it.first ;
		int i=index.first, j=index.second;
		if(kc > d[i][j]) continue ;
		myfor(k,0,4)
		{
			int i1=i+dx[k], j1=j+dy[k];
			if(i1>=0 && i1<n && j1>=0 && j1<m) 
			{
				if(d[i1][j1] > d[i][j] + a[i1][j1])
				{
					d[i1][j1] = d[i][j] + a[i1][j1] ;
//					cout<<i1<<" "<<j1<<" "<<d[i1][j1]<<endl;
					q.push({d[i1][j1], {i1,j1}});
				}
				
			}
		}
	}
	cout<<d[n-1][m-1];
}
int main()
{
	vinh
	cin>>n>>m;
	myfor(i,0,n)
	{
		myfor(j,0,m) cin>>a[i][j];
	}
	dijkstra(0,0);
}
