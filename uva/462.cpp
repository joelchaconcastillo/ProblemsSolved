#include <bits/stdc++.h>
using namespace std;

int main()
{
   string input;
   while( getline(cin, input) && !cin.eof())
   {
 	int totalScore = 0;
	int counting[500] = {0};
	bool stopped[500] = {false};

	//cases points...
	for(int i = 0; i < input.length(); i+=3)
	{
	   //checking score..
	   if(input[i] == 'A' ) totalScore +=4;
	   if(input[i] == 'K' ) totalScore +=3;
	   if(input[i] == 'Q' ) totalScore +=2;
	   if(input[i] == 'J' ) totalScore +=1;
	   counting[ input[i+1] ]++;
	}
	for(int i = 0; i < input.length(); i+=3)
	{
	   //checking score..
	   if(input[i] == 'K' && counting[input[i+1]]==1 ) totalScore -=1;
	   if(input[i] == 'Q' && (counting[input[i+1]]==1  || counting[input[i+1]]==2) ) totalScore -=1;
	   if(input[i] == 'J' && (counting[input[i+1]]>=1  && counting[input[i+1]] <=3) ) totalScore -=1;
	   if(input[i] == 'A') stopped[input[i+1]] = true;
	   if(input[i] == 'K' && counting[input[i+1]] >=2 ) stopped[input[i+1]] = true;
	   if(input[i] == 'Q' && counting[input[i+1]] >=3 ) stopped[input[i+1]] = true;
	   


	}
	int trumpscore = totalScore;
        ///non-trump-checking...
	if( counting['S'] == 2 ) totalScore+=1;
	if( counting['H'] == 2 ) totalScore+=1;
	if( counting['D'] == 2 ) totalScore+=1;
	if( counting['C'] == 2 ) totalScore+=1;
	if( counting['S'] < 2 ) totalScore+=2;
	if( counting['H'] < 2 ) totalScore+=2;
	if( counting['D'] < 2 ) totalScore+=2;
	if( counting['C'] < 2 ) totalScore+=2;

	//checking stopped..

	if( trumpscore >=16 && stopped['S'] && stopped['H'] && stopped['D'] && stopped['C']) cout << "BID NO-TRUMP" <<endl;
	else if(totalScore >=14)
	{

	  int sizelongestsuit = -1;
	  sizelongestsuit = max(sizelongestsuit, counting['S']);
	  sizelongestsuit = max(sizelongestsuit, counting['H']);
	  sizelongestsuit = max(sizelongestsuit, counting['D']);
	  sizelongestsuit = max(sizelongestsuit, counting['C']);

	  if( stopped['S'] && sizelongestsuit == counting['S'] )cout << "BID S"<<endl;
	  else if( stopped['H'] && sizelongestsuit == counting['H'])cout << "BID H"<<endl;
	  else if( stopped['D'] && sizelongestsuit == counting['D'])cout << "BID D"<<endl;
	  else if( stopped['C'] && sizelongestsuit == counting['C'])cout << "BID C"<<endl;
	}
	else if (totalScore < 14 ) cout <<"PASS"<<endl;


   }
}
