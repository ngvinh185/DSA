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
#define pll pair<ll,ll>
#define vii vector<pair<int,int>>
#define vil vector<pair<int,ll>>
#define vll vector<pair<ll,ll>>
#define vi vector<int>
#define vl vector<ll>
using namespace std;

void change(string s)
{
	stack<string> st;
	myFor(i,s.size()-1,0)
	{
		if(isalpha(s[i])) 
		{
			st.push(string(1,s[i]));
		}
		else 
		{
			string a = st.top(); st.pop();
			string b = st.top(); st.pop();
			string res = "(" + a + s[i] + b + ")";
			st.push(res);
		}
	}
	cout<<st.top();
}
int main()
{
	vinh
	string s; cin>>s;
	change(s);
}
