#include <bits/stdc++.h>
#define vinh ios::sync_with_stdio(false);cin.tie(nullptr);
#define my_for(i,a,b) for(int i=a;i<b;i++)
#define my_For(i,a,b) for(int i=a;i>=b;i--)
#define foreach(x,a) for(auto x:a)
#define forEach(x,a) for(auto &x:a)
#define ll long long
using namespace std;
int visited[101];
stack<int> topo;
vector<int> a[101];
string s[101];
void printImpos()
{
	cout<<"Impossible";
	exit(0);
}
void dfs(int v)
{
	visited[v]=1;
	foreach(x,a[v])
	{
		if(visited[x]==1) printImpos();
		if(!visited[x]) dfs(x);
	}
	visited[v]=2;
	topo.push(v);
}
void compare(string x,string y)
{
	my_for(i,0,min(x.size(),y.size()))
	{
		if(x[i]!=y[i])
		{
			a[y[i]-'a'].push_back(x[i]-'a');
			return ;
		}
	}
	if(x.size()<y.size()) printImpos();
}
int main()
{
	vinh
	int n;cin>>n;
	vector<string> tmp;
	my_for(i,0,n)
	{
		cin>>s[i];
		if(i) compare(s[i],s[i-1]);
	}
	my_for(i,0,26)
	{
		if(!visited[i]) dfs(i);
	}
	while(!topo.empty())
	{
		cout<<char(topo.top()+'a');
		topo.pop();
	}
}
