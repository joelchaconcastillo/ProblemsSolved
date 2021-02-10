#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b){  return (b==0)?a:gcd(b, a%b);}
int main()
{
  int t;
  cin >>t;
  while(t--)
  {
     long long n;
     cin>> n;
     cout << gcd(2020, 2021)<<endl;
//     if( (n%)==0) cout <<"YES\n";
//     else cout << "NO\n";
  }
}
