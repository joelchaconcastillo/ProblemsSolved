#include <bits/stdc++.h>
using namespace std;
int main()
{
   int A,C;
   vector<int> data(100005, 0);
   while( cin >>A >> C, A > 0)
   {
      int minb=INT_MAX , maxb=INT_MIN;
      int totalsum = 0, prev=-1, prevprev;
      for(int i = 0; i  < C; i++)
      {
	cin >> data[i];
      }
	minb = min(data[0], minb);
	maxb = max(data[0], maxb);
	for(int i = 1; i  < C-1; i++)
	{
	   maxb = max(maxb, data[i]);
	   minb = min(minb, data[i]);
	   if( (data[i-1] < data[i] && data[i] > data[i+1]) )
	   {
	      totalsum += maxb-minb;
//	      cout << minb << "-"<<maxb<<endl;
	      maxb = minb = data[i];
	   }
       }
	totalsum +=  A-minb;
      
      cout << totalsum <<endl;
   }
}
