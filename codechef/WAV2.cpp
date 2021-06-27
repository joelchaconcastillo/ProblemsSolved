#include <bits/stdc++.h>
using namespace std;
int main()
{
   int N, Q, d[200001];
   cin >>N>>Q;
   for(int i = 0; i < N; i++)cin >> d[i];
   sort(d, d+N);
//   d[N]=d[N-1];

   for(int j = 0; j < Q; j++)
   {
      int nz=0, nne=0, x;
      cin >>x;
      int l = 0, r =N;
      while(l<r)
      {
	int m = (l+r)/2;
	if( d[m] < x) l = m+1;
	else r=m;
      }
      if(d[r]==x)cout << "0\n";
      else if(r < N && (N-r)%2) cout << "NEGATIVE\n";
      else cout << "POSITIVE\n";
   }

   return 0;
}
