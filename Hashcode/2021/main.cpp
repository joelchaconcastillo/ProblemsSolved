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
	//sol[i].push_back(make_pair(j, rand()%min(D,2)+1));
	sol[i].push_back(make_pair(j, rand()%D+1));
      }
      random_shuffle(sol[i].begin(), sol[i].end());
    }
}
/**
 *Improvement: pre-process and save the states in a matrix time vs light (just improves to the incremental evaluation)
 * */
void updateLights(vector<pair<int, int> > &stateLight, vvp &sol)
{
   for(int i = 0; i < I; i++)
   {
	stateLight[i].second++;
	if( stateLight[i].second >= sol[i][stateLight[i].first].second)
          stateLight[i].second=0, stateLight[i].first++, stateLight[i].first %= (int)sol[i].size();
   }
}
/**
 * Improvements: just check lights with waiting cars
 * */
int moveCars(vector<pair<int, int> > &stateLight, vector<queue<pair<int, int> > > &stateStreet, vector<int> &cStreet, vvp &sol, int t)
{
   int score = 0;
   for(int i = 0; i < I; i++)
   {
       int greenStreet = inStreet[i][sol[i][stateLight[i].first].first];
       if(stateStreet[greenStreet].empty() || stateStreet[greenStreet].front().first > t) continue;
       int car = stateStreet[greenStreet].front().second;
       stateStreet[greenStreet].pop();
       int nextStreet = carPath[car][cStreet[car]+1];
       if( cStreet[car] == carPath[car].size()-2 && t+stlen[nextStreet] <= D)
	score += (F+(D-t-stlen[nextStreet])); 
       else
	stateStreet[nextStreet].push(make_pair(t+stlen[nextStreet], car));
	cStreet[car]++;
   }
   return score;
}
int eval(vvp &sol)
{
   vector<pair<int, int> > stateLight(I, pair<int, int>(0, 0));
   //cars variables..
   vector<queue<pair<int, int> > > stateStreet(S);
   vector<int> cStreet(V, 0);
   int score = 0;
   for(int i = 0; i < V; i++)
   {
	   stateStreet[carPath[i][0]].push(make_pair(0, i));//init waiting cars
   }
   for(int t = 0; t <= D; t++)
   { 
       score += moveCars(stateLight, stateStreet, cStreet, sol, t);
       updateLights(stateLight, sol);
   }
 return score;
}
int main()
{
  srand(1);
  read();
  vvp sol;
  randominit(sol);
  cout <<"score... "<< eval(sol)<<endl;
 // write(sol);
  return 0;
}
