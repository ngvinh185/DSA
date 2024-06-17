#include <bits/stdc++.h>
#define vinh ios::sync_with_stdio(false);cin.tie(nullptr);
#define anonymous main
#define int long long
#define my_for(i,a,b) for(int i=a;i<b;i++)
#define my_For(i,a,b) for(int i=a;i>=b;i--)
#define foreach(x,a) for(auto x:a)
#define forEach(x,a) for(auto &x:a)
using namespace std;
//k lay hay co lay
struct job{
	int begin,end,profit;
};
bool myFunc(job x,job y)
{
	return x.end<y.end;
}
int bs(job a[],int l,int r,int x)
{
	int res=0;
	while(l<=r)
	{
		int m=(l+r)/2;
		if(a[m].end<=x)
		{
			res=m;
			l=m+1;
		}
		else r=m-1;
	}
	return res;
}
anonymous()
{
	vinh
	int n;cin>>n;
	job a[n+1]={0};
	my_for(i,1,n+1)
	{
		cin>>a[i].begin>>a[i].end>>a[i].profit;
	}	
	sort(a,a+n+1,myFunc);
	int F[n+1]={0};//luu profit max khi lam den ngay a[i].end
	my_for(i,1,n+1)
	{
		F[i]=max(F[i-1],a[i].profit+F[bs(a,1,i-1,a[i].begin-1)]);
	}
	cout<<F[n];
}
