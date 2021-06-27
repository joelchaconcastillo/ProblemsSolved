#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);
  int t;
  cin >>t;
  while(t--)
  {
    string st, st2="";
    cin >>st;
    if(st[0]!='1') st = "1"+st;
    else st.insert(1, "0");
    cout << st<<endl;
  }
  return 0;
}
