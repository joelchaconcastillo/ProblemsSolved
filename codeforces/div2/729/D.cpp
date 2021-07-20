#include <bits/stdc++.h>
using namespace std;
int n;
vector<long long>items;
long long M = 998244353LL;
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   cin>>n;
   cin.ignore();
   items.assign(n,0);
   for(auto &i:items)
   {
	   string st;
	   getline(cin, st);
	   if(st[0]=='-')i=-1;
	   else i=stol(st.substr(2));
   }
   long long sum = 0;
   for(int t = 0; t < n;t++)
   {
      if(items[t]==-1)continue;
      vector<vector<long long> > f(n+1, vector<long long> (n+1,0));
      f[0][0]=1;
      for(int i =1; i < n; i++)
      {
         for(int j = 0; j <= i; j++)
	{
	  if(t!=i) f[i][j] = f[i-1][j];
	  if( items[i] == -1)
	     if( i <=t || j > 0 ) f[i][max(j-1,0)] = (f[i][max(j-1,0)]+f[i-1][j])%M;
	  else
	  {
	   if( items[i] < items[t])
	     f[i][j+1] = (f[i][j+1]+f[i-1][j])%M;
	   else 
	     f[i][j] = (f[i][j]+f[i-1][j])%M;
	  }
      }
     }
      for(int i = 0; i < n; i++) sum += (items[t]*f[n][i])%M;
   }
   cout << sum%M<<endl;
   return 0;
}
