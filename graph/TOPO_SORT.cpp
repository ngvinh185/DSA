#include <bits/stdc++.h>
#define vinh ios::sync_with_stdio(false);cin.tie(nullptr);
#define anonymous main
#define int long long
#define my_for(i,a,b) for(int i=a;i<b;i++)
#define my_For(i,a,b) for(int i=a;i>=b;i--)
#define foreach(x,a) for(auto x:a)
#define forEach(x,a) for(auto &x:a)
using namespace std;
vector<int> a[10001];
stack<int> st;
int visited[1001];
void DFS(int v)
{
	visited[v]=1;
	foreach(x,a[v])
	{
		if(visited[x]==1) 
		{
			cout<<"Do thi co chu trinh~";
			exit(0);
		}
		if(!visited[x])
		{
			DFS(x);
		}
	}
	visited[v]=2;// da duyet het tat ca duong di tu dinh v sang dinh khac
	st.push(v);
}
anonymous()
{
	vinh
	int n,m;cin>>n>>m;
	my_for(i,0,m)
	{
		int x,y;cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	my_for(i,1,n+1)
	{
		if(!visited[i]) DFS(i);
	}
	while(!st.empty())
	{
		cout<<st.top()<<" ";
		st.pop();
	}
}
