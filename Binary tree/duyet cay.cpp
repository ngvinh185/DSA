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
int ok = 0;
struct node 
{
	int data;
	node *left;
	node *right;
	node(int x)
	{
		data = x;
		left = NULL;
		right = NULL;
	}
};
void makeRoot(node* root, int u, int v, char c)
{
	if(c=='L') root->left = new node(v);
	else root -> right = new node(v);
}
void insertNode(node* root, int u, int v, char c)
{
	if(root == NULL || ok) return ;
	else if(root->data == u) 
	{
		makeRoot(root, u, v, c);
		ok = 1;
	}
	else
	{
		insertNode(root->left, u, v, c);
		insertNode(root->right, u, v, c);
	}
}
void inorder(node *root)
{
	if(root==NULL) return;
	inorder(root->left);
	cout<<root -> data<<" ";
	inorder(root->right);
}
void preorder(node *root)
{
	if(root==NULL) return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
void postorder(node *root)
{
	if(root==NULL) return;
	inorder(root->left);
	inorder(root->right);
	cout<<root -> data<<" ";
}
int main()
{
	vinh

}
