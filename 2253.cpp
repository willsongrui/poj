#include <iostream>
#include <queue>
#include <math.h>
#include <memory.h>
#include <iomanip>
using namespace std;
#define eps 1e-8
typedef struct
{
	int x;
	int y;
}stone;
int stoneNum;
stone stones[250];
bool vis[250];
double dis[250][250];

double findmin(double range)
{
	double curmin=9999999;
	for(int i=1;i<=stoneNum;i++)
	{
		for(int j=i+1;j<=stoneNum;j++)
			if(dis[i][j]>range&&dis[i][j]<curmin)
				curmin=dis[i][j];
	}
	return curmin;
}
queue <int> mq;
bool reached(double len)
{
	memset(vis,false,sizeof(vis));
	vis[1]=true;
	while(mq.empty()==false)
		mq.pop();
	mq.push(1);
	int top;
	while(mq.empty()==false)
	{

		top=mq.front();
		mq.pop();
		for(int i=1;i<=stoneNum;i++)
		{
			if(vis[i]==false)
			{	
				if(len-dis[top][i]>-eps)
				{
					mq.push(i);
					vis[i]=true;
					if(i==2)
						return true;
				}
			}
		}
	}
	return false;
}

int main()
{
	
	int x,y;
	int rounds=1;
	while(cin>>stoneNum)
	{
		if(stoneNum==0)
			break;
		for(int i=1;i<=stoneNum;i++)
		{
			cin>>stones[i].x>>stones[i].y;

		}
	
		for(int i=1;i<=stoneNum;i++)
		{
			for(int j=i+1;j<=stoneNum;j++)
			{
				dis[i][j]=sqrt((double)(stones[i].x-stones[j].x)*(stones[i].x-stones[j].x)+(stones[i].y-stones[j].y)*(stones[i].y-stones[j].y));
				dis[j][i]=dis[i][j];
			}
		}
		double curdis=-1;
		curdis = findmin(curdis);
		while(curdis<=dis[1][2])
		{
			if(reached(curdis)==true)
			{
				cout<<"Scenario #"<<rounds<<endl;
				cout<<"Frog Distance = ";
				cout<<fixed<<setprecision(3)<<curdis<<endl<<endl;
				break;
			}
			curdis = findmin(curdis);
		}
		rounds++;
		
	}
	return 0;
}