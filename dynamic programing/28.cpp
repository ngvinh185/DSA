#include <bits/stdc++.h>
#define vinh ios::sync_with_stdio(false);cin.tie(nullptr);
#define anonymous main
#define int long long
#define my_for(i,a,b) for(int i=a;i<b;i++)
#define my_For(i,a,b) for(int i=a;i>=b;i--)
#define foreach(x,a) for(auto x:a)
#define forEach(x,a) for(auto &x:a)
using namespace std;
int F[10001][10001];	//luu so cach tao ra j<m tai vi tri i tm dk
anonymous()
{
	vinh
	int n,m;cin>>n>>m;
	int a[n+1];
	my_for(i,1,n+1) cin>>a[i];

	if(a[1]!=0) F[1][a[1]]=1;
	else
	{
		my_for(i,1,m+1) F[1][i]=1;
	}
	my_for(i,2,n+1)
	{
		if(a[i]==0)
		{
			my_for(j,1,m+1)
			{
				F[i][j]=F[i-1][j-1]+F[i-1][j]+F[i-1][j+1];
			}
		}
		else
		{
			F[i][a[i]]=F[i-1][a[i]-1]+F[i-1][a[i]]+F[i-1][a[i]+1];		
		}				
	}
	int cnt=0;
	my_for(i,1,m+1)
	{
		cnt+=F[n][i];
	}
	cout<<cnt;
}
