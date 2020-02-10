#include <bits/stdc++.h>
using namespace std;

int main()
{
 int dp[100000]={0};
 int prev[100000]={-1};
 int data[100000];
 int i = 0, maxidx=0;
 dp[0] = 1;
 scanf("%d", &data[i++]);
 while(scanf("%d", &data[i]) != EOF)
 {
    int maxdp = -1; 
    for(int j = i-1; j >= 0; j--)
	if( data[j] < data[i] && dp[j] > dp[maxdp]) 
	       maxdp = j;
    if( maxdp == -1)
    {
	dp[i] = 1;
	prev[i] = -1;
    }
    else
    { 
     dp[i] = dp[maxdp]+1;
     prev[i] = maxdp;
    }

    if( dp[i] >= dp[maxidx]) 
       maxidx = i;
    i++;
 }
 printf("%d\n-\n", dp[maxidx]);
 stack<int> st;
 st.push(data[maxidx]);
 int p = prev[maxidx];
 while( p != -1)
 {
   st.push(data[p]);
  p = prev[p];
 }
 while(!st.empty())
 {
	printf("%d\n", st.top());
	st.pop();
 }
 return 0;
}
