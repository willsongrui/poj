#include <iostream>
#include <string>
#include <memory.h>
using namespace std;
int N;
string trucks[2020];
bool in_set[2020];
int dist[2020][2020];
int md[2020];
int find_min()
{
	int id;
	int cur=0xfffffff;
	for(int i=1;i<=N;i++)
	{
		if(in_set[i]==false&&md[i]<cur)
		{	
			cur=md[i];
			id=i;
		}
	}
	return id;
}
int prim()
{

	for(int i=1;i<=N;i++)
	{
		md[i]=dist[1][i];
	}
	for(int count=1;count<N-1;count++)
	{
		int k=find_min();
		in_set[k]=true;
		for(int i=1;i<=N;i++)
		{
			if(in_set[i]==false)
			{
				if(md[i]>dist[i][k])
					md[i]=dist[i][k];
			}
		}
	}
	int result=0;
	for(int i=1;i<=N;i++)
		result+=md[i];
	return result;
}
int cal(int i,int j)
{
	int diff=0;
	for(int m=0;m<7;m++)
	{
		if(trucks[i][m]!=trucks[j][m])
			diff++;
	}
	return diff;
}
int main()
{	
	while(cin>>N&&N!=0)
	{
		
		memset(in_set,false,sizeof(in_set));
		for(int i=1;i<=N;i++)
		{
			cin>>trucks[i];
		}
		
		for(int i=1;i<=N;i++)
		{
			dist[i][i]=0;
			for(int j=i+1;j<=N;j++)
			{
				dist[i][j]=dist[j][i]=cal(i,j);
			}
		}
		in_set[1]=true;
		int result=prim();
		cout<<"The highest possible quality is 1/"<<result<<"."<<endl;
		

	}
	return 0;

}