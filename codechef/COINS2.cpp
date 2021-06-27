#include <bits/stdc++.h>
using namespace std;
long long maxostia(long long n)
{
  map<long long, long long> dp;
  priority_queue<long long> q;
  q.push(-1);
  dp[1]=1;
  dp[2]=2;
  dp[3]=3;
  dp[4]=4;
  dp[5]=5;
  dp[6]=6;
  dp[8]=8;
  dp[9]=9;
  dp[12]=13;
  dp[16]=17;
  while(!q.empty())
  {
     long long idx=-q.top();
     long long id1=2*idx, id2=3*idx, id3=4*idx;
     q.pop();
     dp[id1]=max(id1, dp[id1/2]+dp[id1/3]+dp[id1/4]);
     dp[id2]=max(id2, dp[id2/2]+dp[id2/3]+dp[id2/4]);
     dp[id3]=max(id3, dp[id3/2]+dp[id3/3]+dp[id3/4]);
     q.push(-id1);
     q.push(-id2);
     q.push(-id3);
     if(id1>n)break;
  }
  return max(n, dp[n/2]+dp[n/3]+dp[n/4]);
}
int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  while(cin>>n)
    cout << maxostia(n)<<endl;
  return 0;
}
