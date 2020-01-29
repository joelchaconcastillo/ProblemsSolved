#include <bits/stdc++.h>
#define MAXSIZE 300
using namespace std;
vector<vector<int> >adj;
bool check[MAXSIZE][MAXSIZE];
int cc[MAXSIZE];
int main()
{
 int n,m;
   while(scanf("%d %d", &n, &m), n!=0 && m!=0)
  {
    adj.clear(); 
    adj.resize(n); 
    memset(cc, 0, MAXSIZE);
    memset(check, false, sizeof check);
    for(int a =0 ; a < m; a++)
    {
      int i, j;
      scanf("%d %d", &i, &j);
	if(check[i-1][j-1]) continue;
      adj[i-1].push_back(j-1);
      check[i-1][j-1] = true;
      cc[j-1]++;
    }
    list<int> zerod;
   bool flag = true;
    while(flag)
    {
	flag = false;
       for(int a = 0; a < n; a++)
           if( cc[a] == 0){
	 zerod.push_front(a);
	 flag=true;
	}	

       while(!zerod.empty())
       {
         int node = zerod.back(); zerod.pop_back();
         cc[node]--;
         printf("%d ", node+1);
         for(int b = 0; b < adj[node].size(); b++)
         {
           cc[adj[node][b]]--;
         }
       }
    }
    printf("\n"); 
  }
}
