#include <bits/stdc++.h>
using namespace std;
int r[]={0, -1, 0, 1}, c[]={-1, 0, 1, 0};
int main()
{
  int t;
  cin >>t;
  while(t--)
  {
     int M, N;
     cin >> M>>N;
     vector<vector<int> > g(M, vector<int>(N)), d(M, vector<int>(N, INT_MAX));
     for(int i = 0; i < M; i++)
	for(int j = 0; j < N; j++) cin >> g[i][j];
     pair<int,int> s,e;
     cin>>s.first>>s.second>>e.first>>e.second;
     queue<pair<int, int>>q;
     q.push(s);
     d[s.first][s.second]=0;
     bool found=0;
     while(!q.empty())
     {
	pair<int,int> current = q.front();
	q.pop();
	if(current == e){found=1; break;}
	for(int i = 0; i < 4; i++)
	{
	   pair<int,int>next(current.first+r[i], current.second+c[i]);
	   if(next.first<0 || next.first >=M || next.second <0 || next.second>=N)continue;
	   if(g[next.first][next.second] != g[s.first][s.second]) continue;
	   if( d[next.first][next.second] > d[current.first][current.second]+1)
	   {
	    q.push(next);
	    d[next.first][next.second] = d[current.first][current.second]+1;
	   }
	}
     }
     if(found)cout << d[e.first][e.second]<<endl;
     else cout <<-1<<endl;
  }
  return 0;
}
