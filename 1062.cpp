#include <iostream>
#include <memory.h>
using namespace std;
int M,N;
typedef struct{
	int Price;
	int minPrice;
	int standing;
}good;
good goods[200];
int edges[200][200];
bool vis[200];
int disjkstra(int lstanding)
{
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=N;i++)
	{
		goods[i].minPrice=goods[i].Price;
	}
	int curMin,mingoods=0;
	for(int j=1;j<=N;j++)
	{
		curMin = 0xfffffff;
		for(int i=1;i<=N;i++)
		{
			if((vis[i]==false)&&(goods[i].minPrice<curMin)&&(goods[i].standing<=lstanding+M)&&(goods[i].standing>=lstanding))
			{
				curMin = goods[i].minPrice;
				mingoods = i;
			}
		}
		if((curMin==0xfffffff)||(mingoods==1))
			return goods[1].minPrice;

		vis[mingoods]=true;
		for(int i=1;i<=N;i++)
		{
			if((edges[mingoods][i]!=-1)&&(vis[i]==false)&&(goods[i].standing<=lstanding+M)&&(goods[i].standing>=lstanding))
			{
				if(goods[i].minPrice>goods[mingoods].minPrice+edges[mingoods][i])
				{
					goods[i].minPrice=goods[mingoods].minPrice+edges[mingoods][i];	
				}
			}
		}
	}
}
int main()
{
	cin>>M>>N;
	int sub,goodsID,offPrice;
	for(int i=0;i<200;i++)
	{
		for(int j=0;j<200;j++)
		{
			edges[i][j]=-1;
		}
	}
	for(int i=1;i<=N;i++)
	{
		cin>>goods[i].Price>>goods[i].standing>>sub;
		for(int j=1;j<=sub;j++)
		{
			cin>>goodsID>>offPrice;
			edges[goodsID][i]=offPrice;
		}
	}
	int cur;
	int result = 0xffffff;
	for(int i=1;i<=N;i++)
	{
		cur = disjkstra(goods[i].standing);
		//cout<<result<<endl;
		if(cur<result)
			result=cur;
	}
	cout<<result<<endl;
	return 0;
}