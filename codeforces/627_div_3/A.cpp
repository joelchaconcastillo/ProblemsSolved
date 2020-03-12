#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t, n;
  int data[100];
  scanf("%d\n", &n);
  for(int i = 0; i < n; i++)
  {
     scanf("%d\n", &t);
     bool f=true;
     int minv = INT_MAX, maxv = INT_MIN;
     for(int j = 0; j < t; j++)
     {
	int a;
 	scanf("%d ", &data[j]);
	maxv = max(maxv, data[j]);
     }	
     while( true)
     {
        for(int j = 0; j < t; j++)
	{
	 if(data[j] < maxv) data[j] +=2;
	}
        minv = INT_MAX, maxv = INT_MIN;
	for(int j = 0; j < t; j++)
	{
	  if(data[j] > 0) data[j]--;
	  maxv = max(maxv, data[j]);
	  minv = min(minv, data[j]);
	}
	int diff = maxv-minv;
	if( maxv <= 2) break;
     }
	int sum = 0;	
	for(int j = 0; j < t; j++) sum+=data[j];//cout << data[j]<< " ";cout <<endl;
      if(t == 1 || sum == 2*t) printf("YES\n");
	else printf("NO\n");
  }
  return 0;
}
