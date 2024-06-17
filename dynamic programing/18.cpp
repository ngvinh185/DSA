#include <bits/stdc++.h>
#define vinh ios::sync_with_stdio(false);cin.tie(nullptr);
#define anonymous main
#define int long long
#define my_for(i,a,b) for(int i=a;i<b;i++)
#define my_For(i,a,b) for(int i=a;i>=b;i--)
#define foreach(x,a) for(auto x:a)
#define forEach(x,a) for(auto &x:a)
using namespace std;

string bit(int n)
{
	if(n!=1&&n!=0)
	{
		string a=bit(n/2);
		string b=to_string(n%2);
		string c=bit(n/2);
		string res=a+b+c;
		return res;
	}
	else
	{
		if(n==1) return "1";
		else return "0";
	}
}
anonymous()
{
	vinh
	int n;cin>>n;
	cout<<bit(n);
}
