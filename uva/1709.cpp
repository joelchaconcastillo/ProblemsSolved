#include <bits/stdc++.h>
using namespace std;
double f(double p, double a, double b, double c, double d, double k){
   return p*(sin(a*k+b)+cos(c*k+d)+2.0);
}
int main(){
   double p,a,b,c,d,n;
   while(cin>>p>>a>>b>>c>>d>>n){
	double maxv = INT_MIN;
	double res=0;
	for(double i =1; i <= n; i++){
	    auto val = f(p,a,b,c,d,i);
	    maxv = max(maxv, val);
	    res=max(res, max(maxv-val, 0.0));
	}
	cout << fixed<<setprecision(6)<<res<<endl;
   }
   return 0;
}
