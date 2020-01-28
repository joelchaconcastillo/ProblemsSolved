#include <bits/stdc++.h>

using namespace std;
vector<vector<int> > gr;
int col[300];
bool visited[300];
bool flag = true;
void Bi(int node, int c)
{
  visited[node]=true;
  col[node] = c;
//  if( col[node] == c-1) return false;
  for(int i = 0 ; i < gr[node].size(); i++)
  {
     if( visited[gr[node][i]] && gr[node][i]!= node && col[gr[node][i]]==1-c)
	flag = false;
     if(!visited[node])
	Bi(gr[node][i], 1-c);
     if(!flag) return;
   }
//   return flag;
}
int main()
{
  int n,l;
  while(scanf("%d\n", &n), n)
  {
    gr.resize(n);
    for(int i = 0; i < n; i++){ col[i] = -1; visited[i]=false;}
    //fill_n(col, sizeof col ,-1);
    scanf("%d", &l);
    for(int a  = 0; a < l; a++)
    {
      int i, j;
      scanf("%d %d", &i, &j);
      gr[i].push_back(j);
      gr[j].push_back(i);
    }
Bi(0, 1);
    if(flag)
	printf("NOT BICOLORABLE.\n");
    else
	printf("BICOLORABLE\n");
  }
  return 0;
}
