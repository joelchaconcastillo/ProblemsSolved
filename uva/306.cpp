#include <bits/stdc++.h>
#define MAX_N 1000
using namespace std;
int main()
{
  char line[MAX_N], line2[MAX_N];
  int cod[MAX_N], period[MAX_N], n;
  while( scanf("%d\n", &n) !=EOF)
 {
  if(n==0) break;
  for(int i = 1; i <= n; i++)
  scanf("%d%*c", cod+i);
  
  for(int i = 1; i <= n; i++)
  {
     period[i] = 0;
     if( i != cod[i])
     {
       int c = i;
       while( c != i  || !period[i]) c = cod[c], period[i] +=1;
     }
  } 
 char ll[MAX_N];
  while(fgets(ll, MAX_N,stdin))
  {
     int k = 0, i = 0;
     while(isdigit(ll[i])) k = (k*10)+(ll[i]-'0'), i++;
     i++;
     if(k == 0) break;
     int c = '\n';
     int s = strchr(ll+i, c)-ll;
     for(int j = 0 ; j < n; i++, j++)
     if(i<s) line[j]=ll[i];else line[j]=' ';
     for(int c = 0 ; c < n; c++)
     {
        int n = c+1, j = ((period[c+1])?k%period[c+1]:0);
	for(int a = 0; a < j; a++) n = cod[n];
	line2[n-1] = line[c];
     }
     line2[n] = '\0';
     printf("%s\n", line2);
  }
     printf("\n");
  }
  return 0;
}
