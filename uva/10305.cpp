#include <bits/stdc++.h>
#define MAXSIZE 300
using namespace std;
vector<vector<int> >adj;
bool check[MAXSIZE][MAXSIZE];
int degree[MAXSIZE], order_in[MAXSIZE];
int main()
{
 int n,m;
   while(scanf("%d %d", &n, &m), n!=0 && m!=0)
  {
    adj.clear(); 
    adj.resize(n); 
    memset(degree, 0, MAXSIZE);
    memset(order_in, 0, MAXSIZE);
    memset(check, false, sizeof check);
   
    for(int a =0 ; a < m; a++)
    {
      int i, j;
      scanf("%d %d", &i, &j);
      if(check[i-1][j-1]) continue;
      if(i==j) continue;
      if(order_in[i-1] == 0)
      order_in[i-1] = a+1;
      adj[i-1].push_back(j-1);
      check[i-1][j-1] = true;
      degree[j-1]++;
    }
    for(int a =0 ; a < m; a++) 
      if(order_in[a] == 0) order_in[a]=2;
    priority_queue<pair<int, int> > pq;
    //insert zero-deree in queue
    
   for(int i = 0; i < n; i++)
    {
     if(degree[i] == 0)
     {
     // degree[i]--;
      pq.push(make_pair(-order_in[i], i)); 
     }
    }
    queue<int> q;
    while(!pq.empty())
    {
     if(q.empty())
     {
       while(!pq.empty())
       {
    	  q.push(pq.top().second);
	 cout << pq.top().second<< " " << pq.top().first<<endl;
	  pq.pop();
       }
     }
     int node = q.front(); q.pop();
      printf("%d", node+1);
      //update degree...
       for(int i =0; i < adj[node].size(); i++)
       {
	  degree[adj[node][i]]--;
          if(degree[adj[node][i]] == 0)
          {
           pq.push(make_pair(-order_in[adj[node][i]], adj[node][i])); 
	  }
       }
	if(!q.empty()) printf(" ");
    }
    printf("\n"); 
	break;
  }
}
