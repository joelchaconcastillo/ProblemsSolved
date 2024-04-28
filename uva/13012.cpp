#include <bits/stdc++.h>
using namespace std;
int main(){
   int T;
   while(cin>>T){
	int counter = 0;
	for(int i = 0; i < 5; i++){
	   int d;
	   cin >>d;
	   counter +=(d==T);
	}
	cout << counter<<endl;
   }
   return 0;
}
