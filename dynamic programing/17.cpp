#include <bits/stdc++.h>
#define vinh ios::sync_with_stdio(false);cin.tie(nullptr);
#define anonymous main
#define int long long
#define my_for(i,a,b) for(int i=a;i<b;i++)
#define my_For(i,a,b) for( i=a;i>=b;i--)
#define foreach(x,a) for(auto x:a)
#define forEach(x,a) for(auto &x:a)
using namespace std;
anonymous()
{
	vinh
	int n,s;cin>>n>>s;
	int a[n];
	forEach(x,a) 
	{
		cin>>x;
	}
	int dp[s+1]={0};// luu so cach tao nen so tien j khi dung cac dong coin a[i] (1 dong coin dung nhieu lan va khong xet tt)
	dp[0]=1;
	my_for(i,0,n)
	{
		my_for(j,a[i],s+1)// moi phan tu dung 1 lan thi duyet nguoc vong for nay lai
		{
			dp[j]+=dp[j-a[i]];
		}
	}
	cout<<dp[s];
}
