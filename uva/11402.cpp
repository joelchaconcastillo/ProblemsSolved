#include <bits/stdc++.h>
using namespace std;
vector<int> treedata;
string Pirates;
void buildTree(int node, int L, int R)
{
   if( L == R ) 
	treedata[node] = (Pirates[L]== '1')?1:0;
   return;
   int left =node<<1;
   int right = left+1;
    buildTree(left, L, (L+R)/2);
   //right
    buildTree(right, (L+R)/2 + 1, R);
  treedata[node] = treedata[left] + treedata[left];
}
int main()
{
   int N;
   scanf("%d\n", &N);
   for(int i = 0; i < N; i++)
   {
	//enambling data...
	int M; 
	scanf("%d\n", &M);
	Pirates = "";
	for(int j = 0; j < M; j++)
 	{
	   string data;
	   int rep;
	   scanf("%d\n", &rep);
	   cin >> data;
	   //scanf("%s\n", &data);
	   for(int k = 0; k < rep; k++) Pirates += data;
	}
	//Queries...
	int Q;
	scanf("%d\n", &Q);
	for(int j = 0; j < Q; j++)
	{
	
	}
	treedata.resize(2*Pirates.size());
	buildTree(0,0,Pirates.size());
   }
}
