#include <bits/stdc++.h>
#define vinh ios::sync_with_stdio(false);cin.tie(nullptr);
#define anonymous main
//#define int long long
#define my_for(i,a,b) for(int i=a;i<b;i++)
#define my_For(i,a,b) for(int i=a;i>=b;i--)
#define foreach(x,a) for(auto x:a)
#define forEach(x,a) for(auto &x:a)
using namespace std;
anonymous()
{
	vinh
	int n,k;cin>>n>>k;
	int a[n+1];//luu so cach di len bac thu i
	a[0]=1;
	my_for(i,1,n+1)
	{
		a[i]=0;
		my_For(j,i-1,max(i-k,0))
		{
			a[i]+=a[j];
		}
	}
	cout<<a[n];
}
