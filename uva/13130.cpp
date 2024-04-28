#include <bits/stdc++.h>
using namespace std;
int main(){
   int T;
   cin>>T;
   while(T--){
      vector<int> d(5,0);
      for(auto &i:d)cin>>i;
      int diff = d[1]-d[0];
      bool has=true;
      for(int i = 1;i < 5 && has; i++){
	  if(d[i]-d[i-1] != diff) has=false;
      }
      if(has) cout << "Y"<<endl;
      else cout << "N"<<endl;
   }
   return 0;
}
