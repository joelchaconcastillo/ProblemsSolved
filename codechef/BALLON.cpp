#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >>t;
  while(t--)
  {
     int N, maxi=0;
     cin >>N;
     bool s[8];
     memset(s, false, sizeof s);
     for(int i = 0;i < N; i++)
     {
       int d;
       cin >>d;
       if( d <= 7 && !s[d])
	   s[d]=1, maxi=i+1;
     }
     cout << maxi<<endl;

  }
  return 0;
}

