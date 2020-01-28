#include <bits/stdc++.h>

using namespace std;
vector<vector<int> > gr;
int col[300];
bool Bi(int node, int color)
{
  if(col[node] == color) return true;
  if(col[node] == 1-color) return false;
  col[node] == color;
  for(int i = 0 ; i < gr[node].size(); i++)
     if(col[gr[node][i]] == -1)
     if(!Bi(gr[node][i], 1-color)) return false;
   return true;
}
int main()
{
  int n,l;
  while(scanf("%d\n", &n), n)
  {
    gr.resize(n);
    for(int i = 0; i < n; i++) col[i] = -1;
    //fill_n(col, sizeof col ,-1);
    scanf("%d", &l);
    for(int a  = 0; a < l; a++)
    {
      int i, j;
      scanf("%d %d", &i, &j);
      gr[i].push_back(j);
      gr[j].push_back(i);
    }
    if(Bi(0, 1))
	printf("NOT BICOLORABLE.\n");
    else
	printf("BICOLORABLE\n");
  }
  return 0;
}
