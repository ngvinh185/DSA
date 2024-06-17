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
	string s;cin>>s;
	int n=s.size();
	s="0"+s;
	int sum=0;
	int dp[n+1]={0};//dp[j] :luu tong cac ptu lien tuc tu i:1,2..-> j vd:dp[2] cua 345=34+4
	my_for(i,1,n+1)
	{
		dp[i]=dp[i-1]*10+i*(s[i]-'0');	
//		cout<<i<<" "<<dp[i]<<endl;
		sum+=dp[i];
	}
	cout<<sum;
}
