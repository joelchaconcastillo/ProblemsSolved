#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);
  int t;
  cin >>t;
  while(t--)
  {
    int A, B, X;
    cin >> A >>B >>X;
    cout << (B-A)/X<<endl;
  }
  return 0;
}
