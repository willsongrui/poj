#include <iostream>
#include <memory.h>
#include <string>
using namespace std;
string dict[10005];
bool find_same(string a,string b)
{
	if(a==b)
		return true;
	return false;
}
bool find_similar(string a,string b)
{
	if(a.length()<b.length()-1)
		return false;
	if(a.length()-1>b.length())
		return false;
	int diff_count=0;
	if(a.length()==b.length())
	{
		
		for(int i=0;i<a.length();i++)
		{
			if(a[i]!=b[i])
				diff_count++;
			if(diff_count>1)
				break;
		}
		if(diff_count>1)
			return false;
		else
			return true;
	}
	bool flag=false;
	if(a.length()==b.length()-1)
	{

		for(int ai=0,bi=0;bi<b.length();ai++,bi++)
		{
			if(ai==a.length())
				return true;
			if((a[ai]!=b[bi])&&(flag==false))
			{
				ai--;
				flag=true;
			}
			else if(a[ai]!=b[bi])
				return false;
		}
		return true;
	}
	flag=false;
	if(a.length()==b.length()+1)
	{

		for(int ai=0,bi=0;ai<a.length();ai++,bi++)
		{
			if(bi==b.length())
				return true;
			if((a[ai]!=b[bi])&&(flag==false))
			{
				bi--;
				flag=true;
			}
			else if(a[ai]!=b[bi])
				return false;
		}
		return true;
	}
	return false;


}
int main()
{
	string str;
	int dict_count=1;
	while(cin>>str)
	{
		if(str=="#")
			break;
		dict[dict_count++]=str;
	}
	dict_count--;
	bool result;
	while(cin>>str)
	{
		if(str=="#")
			break;
		cout<<str;
		for(int i=1;i<=dict_count;i++)
		{
			result=find_same(str,dict[i]);
			if(result==true)
			{	
				cout<<" is correct"<<endl;
				break;
			}

		}

		if(result!=true)
		{
			cout<<":";
			for(int i=1;i<=dict_count;i++)
			{
				result=find_similar(str,dict[i]);
				if(result==true)
					cout<<" "<<dict[i];
			}
			cout<<endl;

		}
	}
	return 0;
}