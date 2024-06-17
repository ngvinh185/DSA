#include <bits/stdc++.h>
#define vinh ios::sync_with_stdio(false);cin.tie(nullptr);
#define anonymous main
#define int long long
#define my_for(i,a,b) for(int i=a;i<b;i++)
#define my_For(i,a,b) for(int i=a;i>=b;i--)
#define foreach(x,a) for(auto x:a)
#define forEach(x,a) for(auto &x:a)
using namespace std;
int F[1000];//luu so buoc it nhat xoa i ve 0
int dele(int n)
{
	if(n==0) return 0;
	if(F[n]!=0) return F[n];
	int m=n;
	int res=1e9;
	while(m)
	{
		int k=m%10;
		if(k!=0)
			res=min(res,dele(n-k)+1);
		m/=10;
	}
	F[n]=res;
	return res;
}
anonymous()
{
	vinh
	int n;cin>>n;
	cout<<dele(n);
}
