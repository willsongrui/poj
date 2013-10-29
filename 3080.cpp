#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
string DNA[15];
int D[80];
bool kmp(string text,string pattern)
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
			return true;
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


	return false;






}
bool cmp(string a,string b)
{
	int k=a.size();
	for(int i=0;i<k;i++)
	{
		if(a[i]<b[i])
			return true;
		else if(a[i]>b[i])
			return false;
	}
	return false;
}
int main()
{
	int rounds;
	cin>>rounds;
	string seg;
	vector<string>result;
	while(rounds--)
	{
		result.clear();
		int num;
		cin>>num;
		for(int i=1;i<=num;i++)
		{
			cin>>DNA[i];
		}
		bool has_result=false;
		for(int j=60;j>=3;j--)
		{
			if(has_result==true)
				break;
			for(int i=0;i<=60-j;i++)
			{
				seg = DNA[1].substr(i,j);
				//cout<<"examine seg"<<seg<<endl;
				bool flag=true;
				for(int k=2;k<=num;k++)
				{
					if(kmp(DNA[k],seg)==false)
					{
						flag=false;
						break;
					}
				}
				if(flag == true)
				{
					
					has_result=true;
					result.push_back(seg);
					
				}
			}
		}
		if(has_result==false)
			cout<<"no significant commonalities"<<endl;
		else
		{
			
			sort(result.begin(),result.end(),cmp);
			
			
				cout<<result[0]<<endl;
		}
	}
	return 0;
}