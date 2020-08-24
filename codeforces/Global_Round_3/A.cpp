#include <bits/stdc++.h>
using namespace std;
int main()
{
  long long a, b, c;
  cin >> a >>b >>c;
  long long cont = 2*c;
  if( b < a) cont += 2*b+1;
  else if( a <b ) cont +=2*a+1;
  else cont+=2*a;
  cout << cont <<endl;
  return 0;
}
