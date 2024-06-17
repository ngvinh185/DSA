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
int n, m;
char a[1001][1001];
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
int id1, id2;
void dfs(int i, int j, int cnt, char dir)
{
	if(cnt > 2) return ;
	if(a[i][j] == 'T') 
	{
		cout<<"YES";
		exit(0);
	}
	a[i][j]='*';
	myfor(k,0,4)
	{
		int i1 = i + dx[k], j1 = j + dy[k];
		if(i1>=0 && i1<n && j1>=0 && j1<n && a[i1][j1] == '.')
		{
			char tmp;
			if(i1==0 && j1==-1) tmp = 'l';
			else if (i1==0 && j1==1) tmp = 'r';
			else if (i1==1 && j1==0) tmp = 'b';
			else tmp = 't';
			if(tmp == dir) dfs(i1, j1, cnt, tmp);
			else dfs(i1, j1, cnt+1, tmp);
		}
	}
	a[i][j]='.';
}
int main()
{
	vinh
	cin>>n>>m;
	myfor(i,0,n)
	{
		myfor(j,0,m) 
		{
			cin>>a[i][j];
			if(a[i][j]=='S') 
			{
				id1=i; id2=j;
			}
		}
	}
	myfor(k,0,4)
	{
		int i1 = id1 + dx[k], j1 = id2 + dy[k];
		if(i1>=0 && i1<n && j1>=0 && j1<n && a[i1][j1] == '.')
		{
			char tmp;
			if(i1==0 && j1==-1) tmp = 'l';
			else if (i1==0 && j1==1) tmp = 'r';
			else if (i1==1 && j1==0) tmp = 'b';
			else tmp = 't';
			dfs(i1, j1, 0, tmp)
		}
	}
	cout<<"NO";
}
