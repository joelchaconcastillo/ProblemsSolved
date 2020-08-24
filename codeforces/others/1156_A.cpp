#include<bits/stdc++.h>
using namespace std;
bool checksort(vector<int> &nv)
{
 for(int i = 0; i < nv.size()-1; i++) if( nv[i+1] < nv[i]) return false;
 return true; 
}
int Thanos_sort(vector<int> nv)
{
   int maxsize = -1;
   if(checksort(nv)) return nv.size();
   if(nv.size() == 2)
	return (checksort(nv))?2:1;
   int middle = nv.size()/2;  
   int left = Thanos_sort(vector<int>(nv.begin(), nv.begin() + middle ));
   maxsize = max(maxsize, left);
   int right = Thanos_sort(vector<int>(nv.begin()+middle, nv.end()));
   maxsize = max(maxsize, right);
   return maxsize;
}
int main()
{
 int n;
 scanf("%d\n", &n);
 vector<int> nv(n);
 for(int i = 0; i < n; i++) scanf("%d ",&(nv[i]));
 ///check sorted...
 cout << Thanos_sort(nv) <<endl;
  
}
