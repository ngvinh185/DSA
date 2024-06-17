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
int s1, s2;
int t1, t2;
int ok = 0;
void dfs(int i, int j, int cnt, int dir)
{
//	cout<<i<<" "<<j<<endl;
	if(cnt > 3) return ;
	if(i==t1 && j==t2) 
	{
		ok=1;
		return ;
	}
	if(ok) return ;
	a[i][j]='*';
	myfor(k,0,4)
	{
		int i1 = i + dx[k], j1 = j + dy[k];
		if(i1>=0 && i1<n && j1>=0 && j1<m && a[i1][j1] == '.')
		{
			if(k == dir) dfs(i1, j1, cnt, k);
			else dfs(i1, j1, cnt+1, k);
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
				s1=i; s2=j;
			}
			else if(a[i][j]=='T')
			{
				t1=i; t2=j;
			}
		}
	}	
	dfs(s1,s2,0,-1);
	if(!ok) cout<<"NO";
	else cout<<"YES";
}
