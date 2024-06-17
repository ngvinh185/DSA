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
	int a[n];
	forEach(x,a) cin>>x;
	int cnt=0;
	int t=0;
	map<int,int> d;
	d[0]=1;
	my_for(i,0,n)
	{
		if(a[i]%2==0) t+=1;
		else t-=1;
		cnt+=d[t];
		d[t]+=1;
	}
	cout<<cnt;
}
