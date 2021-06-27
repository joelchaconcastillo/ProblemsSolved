#include <bits/stdc++.h>
using namespace std;
map<long long, long long> mem;
long long maxostia(long long n)
{
   if(n<1) return 0;
   if( mem[n]!= 0) return mem[n];
   long long s=0;
   for(int i = 2; i<=4; i++)
	s+=maxostia(n/i);
   return mem[n] = max(s,n);
}
int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  while(cin>>n)
    cout << maxostia(n)<<endl;
  return 0;
}
