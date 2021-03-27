#include<bits/stdc++.h>
using namespace std;
int d[100], N, C;
int main()
{
  int T;
  cin >>T;
  for(int ite = 1; ite <=T; ite++)
  {
     cin >>N >>C;
     bool found=false;
     for(int i = 1 ; i <=N; i++) d[i-1]=i;

    int rem = C-N+1;
    int i=0, j;
    while(rem > 0 && i<j)
    {
       j = min(i+rem, N-i-1);
       reverse(d+i, d+j+1);
       rem -= (j-i);
//       cout << i<<","<<j<<endl;
       i++; 
  //   for(int a = 0; a <N;a++)cout << d[a]<<" ";
   //  cout <<endl;

    }
     cout <<"Case #"<<ite<<": ";
     if(rem != 0)cout<<"IMPOSSIBLE";
     else
     for(int i = 0; i <N;i++)cout << d[i]<<" ";
     cout <<endl;
  }
  return 0;
}
