#include <bits/stdc++.h>
using namespace std;
int prev[100000]={-1};
int dp[100000]={0};
int data[100000];

int DC(int L, int R, int value)
{
  if( L == R) return L;
  int m = (L+R)/2;
  if(dp[m] < value) return DC(L, m);
  else if(dp[m]> R) return DC(m+1, R);
}
int main()
{
 int i = 1, size_dp = 1;
 dp[0] = -10000;
 prev[0] = -1;
 while(scanf("%d", &data[i]) != EOF)
 {
    //looking for the index of LIS
    int idx = DC(0, i-1, data[i]);
    if( data[i] < dp[idx])
    {
	dp[idx] = data[i];
        prev[idx] = dp[idx-1];
    }
    else
    {
	prev[size_dp] = dp[size_dp];
	dp[size_dp] = data[i];
	size_dp++;
    }
    i++;
 }
 
 printf("%d\n-\n", size_dp);
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
