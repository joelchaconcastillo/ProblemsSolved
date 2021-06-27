#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    string st;
    cin >> n>>st;
    map<int, int> cont;
    for(int i = 0; i < n; i++)cont[st[i]]++;
    int s = n;
    for(int i = 2; i < n; i++)
    {
      map<int, int> tmp = cont;
	for(int j = 0; j < n; j+=i)
	{
	    tmp[st[j]]--;
	    if(tmp[st[j]]==0)
	    {
		s -=cont[st[j]];
		s++;
		cont[st[j]]=0;
	    }
	}
    }
    cout << s<<endl;
  }
  return 0;
}
