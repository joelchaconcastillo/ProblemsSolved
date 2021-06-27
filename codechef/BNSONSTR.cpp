#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >>t;
  while(t--)
  {
     int n;
     cin >>n;
     string b;
     cin >> b;
     int ones=0;
     for(auto &i:b)if(i=='1')ones++;
     if(ones==1){cout << 0<<endl;continue;}
     int minv=INT_MAX;
     for(int i = 1 ; i <=n; i++)
     {
	if(n%i!=0)continue;	
	int req=n/i;
        for(int k=0; k <i; k++) //start point
	{
	   int f=0;
	   for(int j=k; j<n; j+=i)
	      f += (b[j]=='1');	
	   minv=min(req-f+ones-f, minv);
	}	
     }
     cout << minv<<endl;
  }
  return 0;
}
