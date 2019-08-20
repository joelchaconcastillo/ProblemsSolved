#include <bits/stdc++.h>
using namespace std;
int main()
{
   int n, l, w;
   while(scanf("%d %d %d\n", &n, &l, &w)!= EOF)
   {
	int cont = 1;
	priority_queue< pair< double, double> > pq;
	for(int i = 0; i < n; i++)
	{
		int c, r;
		scanf("%d %d\n", &c, &r);
		if( r*r  - ( (w*w)/4.0 ) < 0) continue;
		double half =  sqrt(r*r  - ( (w*w)/4.0  ));
		double start = max(0.0, c-half);
		double end = c+half;
		pq.push(make_pair(  -start,  end));
	}
	if(pq.empty())
	{
           printf("-1\n");
	   continue;
	}
	double Start1 = -pq.top().first;
	double End1 = pq.top().second;
	pq.pop();
	if(Start1 > 0) 
	{
	   printf("-1\n");
	   continue;
	}
	while(!pq.empty() && End1 < l)
	{
           double currentStart = -pq.top().first;
	   double currentEnd = pq.top().second;
	   double bestEnd = End1;
	   while(!pq.empty() && currentStart <= End1)
	   {
	      if( currentEnd > bestEnd )
	      {
		bestEnd = currentEnd;
	      }
	      pq.pop();
	      currentStart = -pq.top().first;
	      currentEnd = pq.top().second;
	   } 
	   if( bestEnd > End1 )
	   {
	      End1 = bestEnd;
	      cont++;	
	   }
	   else if( bestEnd == End1) 
	   {
	           cont=-1;
	           break;
	   }
	}
	if(End1 < l) cont=-1;
	printf("%d\n", cont);
   }
}
