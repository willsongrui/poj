#include <iostream>
using namespace std;
int dis[150][150];
int edge[150][150];
int stocknum;
#define INF 0xfffffff
int find_max(int line)
{
	int max=0;
	for(int i=1;i<=stocknum;i++)
	{
		if(max<dis[line][i])
			max=dis[line][i];
	}
	return max;
}
void floyd()
{
	for(int i=1;i<=stocknum;i++)
		for(int j=1;j<=stocknum;j++)
			dis[i][j]=edge[i][j];
	for(int m=1;m<=stocknum;m++)
	{
		for(int i=1;i<=stocknum;i++)
		{
			for(int j=1;j<=stocknum;j++)
			{
				if(dis[i][m]!=INF&&dis[m][j]!=INF)
				{
					if(dis[i][j]>dis[i][m]+dis[m][j])
						dis[i][j]=dis[i][m]+dis[m][j];
				}
			}
		}
	}
}
int main()
{
	while(cin>>stocknum)
	{
		if(stocknum==0)
			break;
		int relation;
		int partner;
		for(int i=1;i<=stocknum;i++)
			for(int j=1;j<=stocknum;j++)
			{
				if(i!=j)
					edge[i][j]=INF;
				else edge[i][j]=0;
			}
		for(int i=1;i<=stocknum;i++)
		{
			cin>>relation;
			for(int j=1;j<=relation;j++)
			{
				cin>>partner;
				cin>>edge[i][partner];
			}

		}
		floyd();
		int result_amount=0xfffffff;
		int result_id;
		int cur;
		bool flag=false;
		for(int i=1;i<=stocknum;i++)
		{
			cur=find_max(i);
			if(cur==0xfffffff)
			{
				
				continue;
			}
			if(cur<result_amount)
			{
				result_amount=cur;
				result_id=i;
				flag=true;
			}
		}
		if(flag==false)
			cout<<"disjoint"<<endl;
		else
			cout<<result_id<<" "<<result_amount<<endl;
	}
	return 0;
}