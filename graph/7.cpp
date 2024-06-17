#include <bits/stdc++.h>
#define vinh ios::sync_with_stdio(false);cin.tie(nullptr);
#define anonymous main
#define int long long
#define my_for(i,a,b) for(int i=a;i<b;i++)
#define my_For(i,a,b) for(int i=a;i>=b;i--)
#define foreach(x,a) for(auto x:a)
#define forEach(x,a) for(auto &x:a)
//Cho do thi vo huong G duoc bieu dien duoi dang danh sach canh Hay chuyen
//doi do thi duoi dang danh sach canh nay sang ma tran ke tuong ung 
//Input Format
//Dong dau tien la 2 so n va m tuong ung voi so luong dinh va canh cua do thi Cac
//dinh cua do thi duoc danh so tu 1 toi n m dong tiep theo moi dong chua dinh u v
//tuong ung voi mot canh cua do thi 
//Constraints
//1<=n<=1000; 1<=m<=n*(n - 1)/2;
//Output Format
//In ra ma tran ke theo mau 
//Sample Input 0
//5 4
//4 3
//3 1
//4 2
//5 4
//Sample Output 0
//0 0 1 0 0
//0 0 0 1 0
//1 0 0 1 0
//0 1 1 0 1
//0 0 0 1 0
using namespace std;
int F[100][100];
anonymous()
{
	vinh
	int n,m;cin>>n>>m;
	my_for(i,0,m) 
	{
		int x,y;cin>>x>>y;
		F[x][y]=1;
		F[y][x]=1;
	}
	my_for(i,1,n+1)
	{
		my_for(j,1,n+1)
		{
			cout<<F[i][j]<<" ";
		}
		cout<<endl;
	}
}
