#include <bits/stdc++.h>
using namespace std;
int main(){
   int T;
   cin >>T;
   for(int t = 1; t<=T; t++){
      bool hasZero=false;
      for(int i = 0; i < 13; i++){
	      int d;
	      cin >>d;
	      if(d<=0) hasZero=true;
      }
       cout << "Set #"<<t<<": ";
      if(!hasZero)cout << "Yes"<<endl;
      else cout <<"No"<<endl;
   }
   return 0;
}
