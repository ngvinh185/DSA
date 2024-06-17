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
int preOrd[100001], inOrd[100001];
int n;
int Find(int a[],int x)
{
	myfor(i,0,n) 
	{
		if(a[i]==x) return i;
	}
	return 0;
}
void buildTree(node* root, int in_l, int in_r)
{
	int pre_pos = Find(preOrd,root -> data);
	int in_pos = Find(inOrd,root -> data);
	if (in_pos > in_l)
	{
		root -> left = new node(preOrd[pre_pos+1]);
		buildTree(root -> left, in_l, in_pos - 1);
	}
	if (in_pos < in_r)
	{
		int soLuongTapTrai = in_pos - in_l + 1;
		root -> right = new node(preOrd[pre_pos + soLuongTapTrai]);
		buildTree(root -> right, in_pos +1, in_r);
	}
}
void postOrder(node *root)
{
	if(root == NULL) return ; 
	postOrder(root -> left);
	postOrder(root -> right);
	cout<<root->data<<" ";
}
int main()
{
	vinh
	cin>>n;
	myfor(i,0,n) cin>>inOrd[i];
	myfor(i,0,n) cin>>preOrd[i];
	node* root = new node(preOrd[0]);
	buildTree(root,0,n-1);
	postOrder(root);
}
