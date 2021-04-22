#include <bits/stdc++.h>
const int MAX_N = 1e5+5;
using namespace std;
int p[MAX_N];
vector<int> tree[MAX_N];
vector<tuple<int, int, long long> > adj[MAX_N]; //id, Limit, charge
vector<tuple<int, int, int> >queries; //node, weight, day
void build_tree(int current, int prev)
{
  p[current]=prev;
  for(auto i:adj[current])
  {
     if(get<0>(i)==prev)continue;
     tree[current].push_back(get<0>(i));
     build_tree(get<0>(i), current);
  } 
}
int main()
{
  int ite;
  cin>>ite;
  for(int t = 1; t <= ite;t++)
  {
    int N, Q;
    cin>>N >>Q;
//    p.assign(N, 0);
//    Li.assign(N, 0);
//    Ai.assign(N, 0);
//    adj.assign(N, vector<int>());
//    tree.assign(N, vector<int>());
    for(int i = 0; i < N-1; i++)
    {
	int X, Y, L, A;
	cin>>X>>Y>>L>>A;
	X--, Y--;
	adj[X].push_back({Y, L, A});
	adj[Y].push_back({X, L, A});
    }
    build_tree(0, 0);
    queries.clear();
    for(int i = 0; i < Q; i++)
    {
	int node, W;
	cin>>node>>W;
	node--;
	queries.push_back({node, W, i});
    }
    sort(edges, edges+N-1);
    sort(queries.begin(), queries.end());
    for(auto i:adj) cout << get<0>  
   exit(0);
  }
  return 0;
}
