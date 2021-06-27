#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >>t;
  cin.ignore();
  while(t--)
  {
     string st;
    // getline(cin, st);
     cin >>st;
     int n =st.size();
     if(st[0]=='<' && st[1]=='/' && st[n-1]=='>')
     {
	bool f=1;
	for(int i = 2; i < n-1; i++)
	{
		if(isalnum(st[i])==0){f=0; break;}
		if(isalpha(st[i])!=0 && islower(st[i])==0){f=0; break;}
	}
	if(f && st.size()>3)cout << "Success"<<endl;
	else cout << "Error"<<endl;
     }
     else cout <<"Error"<<endl;

  }
  return 0;
}
