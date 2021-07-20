#include <bits/stdc++.h>
using namespace std;
int n;
vector<long long>items;
long long M = 998244353LL;
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   cin>>n;
   cin.ignore();
   items.assign(n,0);
   for(auto &i:items)
   {
	   string st;
	   getline(cin, st);
	   if(st[0]=='-')i=-1;
	   else i=stol(st.substr(2));
   }
   queue<pair<priority_queue<long long, vector<long long>, greater<long long> >, pair<long long, int> > > q; //queue, current sum, id
   long long sum = 0;
   for(int i = 0; i < n; i++)
   {
       pair<priority_queue<long long, vector<long long>, greater<long long> >, pair<long long, int> > tmp;
       if(items[i]!=-1)
       {
         tmp.first.push(items[i]);
         tmp.second.first=0;
       }
       else tmp.second.first=items[i];
       tmp.second.second=i;
       q.push(tmp);
   }
   while(!q.empty())
   {
       pair<priority_queue<long long, vector<long long>, greater<long long> >, pair<long long, int> > c = q.front();q.pop();
       cout << c.second.second<<endl;
       sum += c.second.first;
       if(c.first.size()==n)continue;
       for(int i = c.second.second+1; i < items.size(); i++)
       {
	    priority_queue<long long, vector<long long>, greater<long long> > c2 = c.first;
	    long long cf=c.second.first;
	    if(!c2.empty() && items[i]==-1)
	    {
		 cf -= c2.top();
		 c2.pop();
	    }
	    else
	    {
		  cf += items[i];
		  c2.push(items[i]);
	    }
	    q.push(make_pair(c2, make_pair(cf, i)));
       }
   }
   cout <<sum%M<<endl;
   return 0;
}
