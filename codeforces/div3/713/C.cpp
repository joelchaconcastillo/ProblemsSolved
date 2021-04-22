#include <bits/stdc++.h>
using namespace std;
int main()
{
  int ite;
  cin>>ite;
  while(ite--)
  {
   int a,b;
   string s;
   cin>>a>>b>>s;
   int n=s.size();
   int i=0, j=n-1;

   if( a!=0 || b != 0) cout <<"-1\n";
   else cout <<s<<endl;
  }
  return 0;
}
