#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t ;
  cin >>t;
  while(t--)
  {
     int n,m;

     cin >>n>>m;
     vector<vector<bool> > g(n, vector<bool>(m, 0));
     bool r;
     for(int i = 0; i < n; i++)
     {
	for(int j = 0; j < m; j++)
	{
     	   char d;
	   cin >>d;
	   g[i][j] = d-'0';
	   if(i==0 && j==0)r=(bool)g[i][j];
	   else
	   r^=(bool)g[i][j];
	}
     }
     if(r)cout <<"YES"<<endl;
     else cout << "NO"<<endl;
  }
  return 0;
}
