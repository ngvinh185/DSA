#include <bits/stdc++.h>
#define vinh ios::sync_with_stdio(false);cin.tie(nullptr);
#define anonymous main
#define int long long
#define my_for(i,a,b) for(int i=a;i<b;i++)
#define my_For(i,a,b) for(int i=a;i>=b;i--)
#define foreach(x,a) for(auto x:a)
#define forEach(x,a) for(auto &x:a)
using namespace std;
anonymous()
{
	vinh
	int t;cin>>t;
	while(t--)
	{
		int n,w;cin>>n>>w;
		int wt[n+1],p[n+1];
		my_for(i,1,n+1) cin>>wt[i];
		my_for(i,1,n+1) cin>>p[i];
		wt[0]=0,p[0]=0;
		int k[n+1][w+1];
		my_for(i,0,n+1)
		{
			my_for(j,0,w+1)
			{
				if(i==0||j==0) k[i][j]=0;
				else if(wt[i]<=j)
				{
					k[i][j]=max(k[i-1][j],k[i-1][j-wt[i]]+p[i]);		
				}
				else k[i][j]=k[i-1][j];
			}
		}
		cout<<k[n][w]<<endl;
	}
}
