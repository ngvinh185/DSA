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
struct node
{
	int data;
	node* left;
	node* right;
	node(int x)
	{
		data = x;
		right = NULL;
		left = NULL;
	}
};

void makeNode(node* root, int u, int v, char c)
{
	if (c=='L') root -> left = new node(v);
	else root -> right = new node(v);
}
int ok ;
void insertNode(node *root, int u, int v, char c)
{
	if (ok) return ;
	if(root == NULL) return;
	if(root -> data == u) 
	{
		ok = 1;
		makeNode(root, u, v, c);
	}
	else
	{
		insertNode(root->left, u, v, c);
		insertNode(root->right, u, v, c);
	}
}
int Dem(node *root, int cnt)
{
	if(!root -> left && !root -> right) return cnt;
	int res = -1e9;
	if(root -> right) res = max (res, Dem(root->right,cnt+1));
	if(root -> left) res = max (res,Dem(root->left,cnt + 1));
	return res; 
}
int main()
{
	vinh
	int n; cin>>n;
	node* root = NULL;
	myfor(i,0,n)
	{
		int u, v;
		char c;
		cin>>u>>v>>c;
		ok = 0;
		if(root == NULL) 
		{
			root = new node(u);
			insertNode(root, u, v, c);
		}
		else
		{
			insertNode(root, u, v, c);
		}
	}
	cout<<Dem(root,0);
}
