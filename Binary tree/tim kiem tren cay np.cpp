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

int ok ;
void insertNode(node *root, int v)
{
	if (ok) return ;
	if (root -> data < v && root -> right == NULL) 
	{
		ok = 1;
		root -> right = new node(v);
	} 
	else if(root -> data < v && root -> right != NULL) insertNode(root -> right, v);
	if (root -> data > v && root -> left == NULL) 
	{
		ok = 1;
		root -> left = new node(v);
	} 
	else if(root -> data > v && root -> left != NULL) insertNode(root -> left, v);
}
int Find(node *root, int x)
{
	if (root == NULL) return 0;
	if(x == root -> data) return 1;
	if(x<root->data) return Find(root->left,x);
	return Find(root->right,x);
}
void inOrder(node *root)
{
	if(root == NULL) return ; 
	inOrder(root -> left);
	cout<<root->data<<" ";
	inOrder(root -> right);
}
int main()
{
	vinh
	int n; cin>>n;
	int a[n];
	node *root = NULL;
	myfor(i,0,n)
	{
		cin>>a[i];
		ok =0 ;
		if (root == NULL) root = new node(a[i]);
		else insertNode(root,a[i]);
	}
	ok = 0;
	int x; cin>>x;
	if (Find(root, x)) cout<<"YES";
	else cout<<"NO";
}
