#include <bits/stdc++.h>
#define N 100000
using namespace std;
int D, I, S, V, F;
typedef vector<vector<pair<int,int> > > vvp;
unordered_map<string, int> stId;
vector<string> idSt;
vector<int> stlen, remlenCar;
vector<vector<int> > inStreet, carPath;

void read()
{
   cin >> D >> I >> S >> V >> F;
   idSt.resize(S);
   stlen.resize(S, 0);
   inStreet.resize(I);
   remlenCar.resize(V,0); 
   carPath.resize(V); 
   for(int i = 0; i < S; i++)
   {
    int a,b, l;
    cin >> a >> b >> idSt[i]>>l; 
    inStreet[b].push_back(i);
    stlen[i] = l;
    stId[idSt[i]]=i;
   }
   for(int i = 0; i < V; i++)
   {
      int s;
      cin >> s;
      for(int j = 0; j < s; j++)
      {
        string street;
	cin >> street;
        carPath[i].push_back(stId[street]);
	remlenCar[i] += stlen[stId[street]];
      }
   }
}
void write(vvp &sol)
{
   cout << I<<endl;
   for(int i = 0; i < I; i++)
   {
      cout << i << endl;
      cout << sol[i].size()<<endl;
      for(int j = 0; j < sol[i].size(); j++)
      cout << idSt[inStreet[i][sol[i][j].first]]<< " " << sol[i][j].second<<endl;
   }
}
void randominit(vvp &sol)
{
    sol.resize(I);
    for(int i = 0; i < I; i++)
    {
      for(int j = 0; j < (int)inStreet[i].size(); j++)
      {
	sol[i].push_back(make_pair(j, rand()%D+1));
      }
      random_shuffle(sol[i].begin(), sol[i].end());
    }
}
int eval(vvp &sol)
{

}
int main()
{
  read();
  vvp sol;
  randominit(sol);
  write(sol);
  return 0;
}
