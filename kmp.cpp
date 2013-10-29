#include <iostream>
#include <string>
using namespace std;
int D[1000];
int find_pattern(string text,string pattern)
{
	text = string("0") + text;
	pattern = string("0") + pattern;
	D[1] = 0;
	int k = 0;//biaoshi shangci pipei de jieguo
	for(int i=2;i<pattern.size();i++)
	{
		while((k!=0)&&(pattern[k+1]!=pattern[i]))
			k = D[k];
		if(pattern[k+1]==pattern[i])
		{	
			D[i] = k+1;
			k = k+1;
		}
		else
			D[i] = 0;
	}
	k=0;
	int i=1;
	while(i<=text.size()-pattern.size()+1)
	{
		while((text[i+k]==pattern[k+1])&&(k<=pattern.size()-2))
			k++;
		if(k==pattern.size()-1)
			return i;
		else if(k!=0)
		{
			i = i+k-D[k];
			k=D[k];
		}
		else 
		{
			i = i+1;
		}
	}


	return -1;
}
int main()
{
	string text;
	string pattern;
	while(cin>>text>>pattern)
		cout<<find_pattern(text,pattern)<<endl;
	return 0;
}