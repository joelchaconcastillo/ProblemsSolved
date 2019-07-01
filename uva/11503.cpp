#include <bits/stdc++.h>
using namespace std;

map<string, string> parent;
map<string, int> rank;

string find(string node)
{
	if( parent[node] == node) return node;
	else
	   return find(parent[node]);
}
void unionset(string A, string B)
{
	string rootA = find(A);
	string rootB = find(B);
        if( rank[rootA] < rank[rootB] )
	{
            
	}
	else
	{
	}
}

int main()
{
 int n F;
 char nameA[21], nameB[21];
 scanf("%d\n", &n);
 for(int i = 0; i < n; i++)
    {
	    scanf("%d\n", &F);
	    for(int j = 0; j < F; j++)
            {
	       scanf("%s %s\n", nameA, nameB);
	       unionSet(nameA, nameB);
	    }
	    
    }

}
