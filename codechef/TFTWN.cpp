#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, Q;
    cin >>N>>Q;
    vector<long long> t(N);
    for(int i = 0; i < N; i++)cin>>t[i];
    long long l = 0, r= 1e15+1;
    long long m;
    while(l<r)
    {
       long long conT = 0, m=(l+r)/2;
       for(int i = 0; i < N; i++)conT+=(m/t[i]);
       if( conT < Q)  l=m+1;
       else r = m;
    }

    if(l%3==0)cout << "BAD EXPERIENCE\n";
    else cout <<"GOOD EXPERIENCE\n";
  return 0;
}
