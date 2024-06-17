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
bool check(int a[], int b[], int n)
{
	myfor(i,0,n)
	{
		if(a[i] != b[i] || a[i] != b[n-i-1])
			return false;
	}
	return true;
}
int main()
{
	vinh
	int n; cin>>n;
	int a[n], b[n]; 
	myfor(i,0,n)
	{
		cin>>a[i];
		b[i] = a[i];
	}
	sort(b,b+n);
	if (check(a,b,n)) cout<<"NO";
	else cout<<"YES";
}
