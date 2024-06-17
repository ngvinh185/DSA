#include <bits/stdc++.h>
#define vinh ios::sync_with_stdio(false);cin.tie(nullptr);
#define myfor(i,a,b) for(int i=a;i<b;i++)
#define myFor(i,a,b) for(int i=a;i>=b;i--)
#define foreach(x,a) for(auto x:a)
#define forEach(x,a) for(auto &x:a)
#define ll long long
#define ms(x,y) memset(x,y,sizeof(x))
#define fi first
#define se second
#define pii pair<int,int>
#define vii vector<pair<int,int>>
#define vil vector<pair<int,ll>>
#define vll vector<pair<ll,ll>>
#define vi vector<int>
#define vl vector<ll>
using namespace std;
//dang bi sai
string max_str(string a,string b)
{
	if(a.size()!=b.size())
	{
		if(a.size()>b.size()) return a;
		else return b;
	}
	else return max(a,b);
}
string to_hex(string a)
{
	while(a.size() % 4 !=0)
	{
		a='0'+a;
	}
	map<string,char> d = {
		{"0000", '0'}, {"0001", '1'}, {"0010", '2'}, {"0011", '3'},
        {"0100", '4'}, {"0101", '5'}, {"0110", '6'}, {"0111", '7'},
        {"1000", '8'}, {"1001", '9'}, {"1010", 'A'}, {"1011", 'B'},
        {"1100", 'C'}, {"1101", 'D'}, {"1110", 'E'}, {"1111", 'F'}
	};
	int i=0;
	string res="";
	string tmp="";
	while(i<=a.size())
	{
		while(tmp.size() < 4)
		{
			tmp+=a[i];
			i+=1;
		}
		res+=d[tmp];
		tmp="";
	}
	i = 0;
	while(i < res.size() && res[i]=='0')
	{
		i+=1;
	}

	string ans=res.substr(i);
	return ans;
}
int main()
{
	vinh
	int n; cin>>n;
	char a[n][n];
	myfor(i,0,n)
	{
		myfor(j,0,n)
		{
			cin>>a[i][j];
		}
	}
	string s[n][n];
	myfor(i,0,n)
	{
		myfor(j,0,n)
		{
			if(i==0&&j==0) s[i][j]=a[i][j];
			else if(i==0) s[i][j]=s[i][j-1]+a[i][j];
			else if(j==0) s[i][j]=s[i-1][j]+a[i][j];
			else s[i][j]=max_str(s[i-1][j],s[i][j-1])+a[i][j];
		}
	}
	cout<<to_hex(s[n-1][n-1]);
}
