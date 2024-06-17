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
	s="@"+s;
	int sum=0;
	my_for(i,1,n+1)
	{
		my_for(j,i,n+1)
		{
			sum+=stoll(s.substr(i,j-i+1));
		}
	}
	cout<<sum;
}
