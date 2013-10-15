#include <iostream>
#include <memory.h>
using namespace std;
int costtime[600];
typedef struct {
	int source;
	int dest;
	int time;
}path;
path paths[6000];
int N;//Field Num
int M;//Path Num
int wormholes;
#define MAXTIME 0xfffffff
bool bellman_ford()
{
	for(int i=1;i<=N;i++)
		costtime[i]=MAXTIME;
	costtime[1]=0;
	bool flag;
	for(int i=1;i<=N;i++)
	{
		flag=false;
		for(int j=1;j<=2*M+wormholes;j++)
		{
			if(costtime[paths[j].source]!=MAXTIME)
			{
				if(costtime[paths[j].dest]>costtime[paths[j].source]+paths[j].time)
				{
					costtime[paths[j].dest]=costtime[paths[j].source]+paths[j].time;
					flag=true;
				}
			}
		}
		if(flag==false)
			break;
	}
	if(flag==true)
		return true;
	else
		return false;
}
int main()
{
	int rounds;
	cin>>rounds;
	while(rounds--)
	{
		memset(costtime,0,sizeof(costtime));
		memset(paths,0,sizeof(paths));
		cin>>N>>M>>wormholes;
		int source,dest,costtime;
		for(int i=1;i<=2*M;i++)
		{
			cin>>source>>dest>>costtime;
			paths[i].source=source;
			paths[i].dest=dest;
			paths[i].time=costtime;
			i++;
			paths[i].source=dest;
			paths[i].dest=source;
			paths[i].time=costtime;
		}
		for(int i=1;i<=wormholes;i++)
		{
			cin>>source>>dest>>costtime;
			paths[2*M+i].source=source;
			paths[2*M+i].dest=dest;
			paths[2*M+i].time=-costtime;
		}
		bool flag=bellman_ford();
		if(flag==true)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;

}