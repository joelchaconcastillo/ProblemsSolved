#include <bits/stdc++.h>
using namespace std;
int rd[]={1, 0, -1, 0}, cd[]={0, -1, 0, 1}, ri[]={0,0,0,0}, ci[]={0,0,0,0}, ti[]={0,0,0,0};
int n, m, cont;
bool marked[8*8];
int points[8*8];
void bk(int r, int c, int d, int s)
{
   if(points[r*8+c]!=0 && points[r*8+c]!=d)return;
   if(s<4 && (ti[s]-d) < (abs(ri[s]-r)+abs(ci[s]-c)) )return; 
   if(points[r*8+c]!=0 && points[r*8+c]==d)s++;
   if(d==m*n && r==0 && c==1){
     cont++; 
     return;
   }
   for(int i = 0; i < 4; i++)
   {
     int nr=r+rd[i], nc=c+cd[i]; 
     if(nr<0 || nc<0||nr>=n || nc>=m)continue;
     if(marked[nr*m+nc])continue;
     marked[nr*m+nc]=true;
     bk(nr, nc, d+1, s);
     marked[nr*m+nc]=false;
   }
}
int main()
{
   int TC=1;
   while(cin>>n>>m)
   {
      if(n==0 && m == 0) break;
      memset(points, 0, sizeof points);
      memset(marked, false, sizeof marked);
      for(int i = 0; i< 3; i++){
        cin>>ri[i]>>ci[i];
        ti[i] = floor(((i+1.0)/4.0)*(n*m));
	points[ri[i]*8+ci[i]]=ti[i];
      }
      points[1]=n*m;
      ti[3] = n*m;
      ri[3] = n-1;
      ci[3] = m-1;
      cont = 0;
      marked[0]=true;
      bk(0,0,1,0);
      cout <<"Case "<<TC++<<": "<<cont<<endl;
  }
   return 0;
}
