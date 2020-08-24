#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
     int s;
     char tt;
     cin >> s;
     int prev = -1;
     int maxc = 0;
     for(int i = 1; i <= s; i++)
	{
	 cin >> tt;
	  if(tt == 'A')
	  {
	    if( prev != -1) maxc = max(maxc, i-prev-1);
	    prev = i; 
	  }
	}

	if( prev != -1) maxc = max(maxc, s-prev);
	
     cout << maxc<<endl;
	
  }
  return 0;
}
