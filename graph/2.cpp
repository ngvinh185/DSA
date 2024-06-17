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
	int n;cin>>n;cin.ignore();
	vector<pair<int,int>> a;
	my_for(i,1,n+1)
	{
		string s;getline(cin,s);
		stringstream ss(s);
		string tmp;
		while(ss>>tmp)
		{
			int res=stoll(tmp);
			if(res>i) a.push_back({i,res});
		}
	}
	foreach(x,a) 
	{
		cout<<x.first<<" "<<x.second<<"\n";
	}
}
