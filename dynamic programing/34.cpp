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
	int n;cin>>n;
	int a[n+1];
	my_for(i,1,n+1) cin>>a[i];
	int T[n+1]={0},G[n+1]={0};
	int cnt=1;
	T[1]=1;G[n]=1;
	int res=-1e9;
	cout<<T[1]<<" ";
	my_for(i,2,n+1)
	{
		if(a[i]>a[i-1]) 
		{
			cnt+=1;
			T[i]=cnt;	
		}	
		else 
		{
			cnt=1;
			T[i]=cnt;
		}
		cout<<T[i]<<" ";
	}	
	cout<<endl;
	cnt=1;
	my_For(i,n-1,1)
	{
		if(a[i]<a[i+1]) 
		{
			cnt+=1;
			G[i]=cnt;
		}
		else 
		{
			cnt=1;
			G[i]=cnt;
		}
	}
	my_for(i,1,n+1) cout<<G[i]<<" ";
	cout<<endl;
	res=max(res,T[n]);
	my_for(i,2,n+1)
	{
		if(a[i-1] < a[i+1]) res = max(res, T[i-1] + G[i+1]);
	}
	cout<<res;
}
