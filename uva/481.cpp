#include <bits/stdc++.h>
using namespace std;
int dp[100000];
int data[100000];

int i = 0, size_dp = 1;
int DC(int L, int R, int value) //like segment tree fashion..
{
  if( L > R)return 0;
  if( L == R)
  {
   if( dp[L] > value)
     dp[L] = value;
   else if( dp[L] < value)
     dp[size_dp++] = value;
   return L;
  }
  int m = (L+R)/2;
  if(dp[m] < value) return DC(m+1, R, value);
  else if(dp[m] > value) return DC(L, m-1, value);
  else return m;
}
int main()
{
 dp[0]=10000000; 
 while(scanf("%d", &data[i]) != EOF)
 {
   DC(0, size_dp-1, data[i]);
   i++;
 }
  printf("%d\n-\n", size_dp);
  for(int i = 0; i < size_dp; i++) printf("%d\n", dp[i]);
  return 0;
}
