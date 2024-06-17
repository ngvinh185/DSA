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

bool check(string s)
{
    stack<char> st;
    foreach(x,s)
    {
        if(x == '(' || x == '[' || x == '{') st.push(x);
        else
        {
            if (st.empty()) return false;
            if(x == ')') 
            {
            	if (st.top() != '(') return false;
			}
            else if(x == '}') 
            {
            	if (st.top() != '{') return false;
			}
            else{
                if (st.top() != '[') return false;
            } 
            st.pop(); 
        } 
    }
    return st.empty();
}
int main()
{
    vinh
    string s; cin>>s;
    cout<<check(s);
}
