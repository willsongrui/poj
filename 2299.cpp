#include <iostream>
using namespace std;
int num;
int seq[500001];
int temp[500001];
void swap(int i,int j)
{
	int temp=seq[i];
	seq[i]=seq[j];
	seq[j]=temp;
}
long long guibin(int s,int t)
{
	if((s==t)||(s==t-1))
	{
		if(seq[s]>seq[t])
		{	
			swap(s,t);
			return 1;
		}
		else
			return 0;
	}
	long long result = 0;
	int mid = (s+t)/2;
	result = guibin(s,mid);
	result += guibin(mid+1,t);
	int i,j;
	int count = s;
	for(i=s,j=mid+1;(i<=mid)&&(j<=t);)
	{
		if(seq[i]<seq[j])
		{
			temp[count]=seq[i];
			i++;
			count++;
		}
		else
		{
			temp[count]=seq[j];
			j++;
			count++;
			result+=(mid-i+1);
		}
	}
	if(i>mid)
	{
		for(int k=j;k<=t;k++)
			temp[count++]=seq[k];
	}
	else if(j>t)
	{
		for(int k=i;k<=mid;k++)
		{	
			temp[count++]=seq[k];
			
		}
	}
	for(int k=s;k<=t;k++)
		seq[k]=temp[k];
	return result;
}
int main()
{
	while(cin>>num)
	{
		if(num==0)
			break;
		for(int i=1;i<=num;i++)
			cin>>seq[i];
		cout<<guibin(1,num)<<endl;
	}
	return 0;
}