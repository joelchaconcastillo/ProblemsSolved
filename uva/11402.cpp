#include <bits/stdc++.h>
using namespace std;
vector<int> treedata;
string Pirates;
void buildTree(int node, int L, int R)
{
   if( L == R ) 
   {
	treedata[node] = (Pirates[L]== '1')?1:0;
         return;
   }
   int left = node<<1;
   int right = left+1;
    buildTree(left, L, (L+R)/2);
   //right
    buildTree(right, (L+R)/2 + 1, R);
    treedata[node] = treedata[left] + treedata[right];
}
int Query(int node, int L, int R, int i, int j)
{
  if( R < i || L>j  ) return 0;
  if( L>=i && R<=j ) return treedata[node];

  int s1 = Query(node << 1, L, (L+R)/2, i, j);
  int s2 = Query( (node << 1) + 1, (L+R)/2 + 1, R, i, j);
  return s1+s2;
}
int main()
{
   int N;
   scanf("%d\n", &N);
   for(int i = 0; i < N; i++)
   {
	//ensambling data...
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
	cout << Pirates <<endl;
	
        treedata.resize(4*Pirates.size(), 0);
	buildTree(1,0,Pirates.size()-1);
     	cout << Query(1,0, Pirates.size()-1, 0, 10); 	 
	exit(0);
	//Queries...
	int Q;
	scanf("%d\n", &Q);
	for(int j = 0; j < Q; j++)
	{
	
	}

   }
}
