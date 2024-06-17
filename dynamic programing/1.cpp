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
	string s1,s2;cin>>s1>>s2;
	int n=s1.size();
	int m=s2.size();
	s1="@"+s1,s2="@"+s2;
	int F[n+1][m+1];// luu day con chung dai nhat ket thuc i (s1) va j (s2)
	my_for(i,0,n+1)
	{
		my_for(j,0,m+1) 
		{
			if(i==0||j==0) F[i][j]=0;
			else if(s1[i]==s2[j]) F[i][j]=F[i-1][j-1]+1;
			else F[i][j]=max(F[i-1][j],F[i][j-1]);
		}
	} 
	cout<<F[n][m];
}
