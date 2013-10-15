#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;

typedef struct{
	int leftpoint;
	int rightpoint;
	double fee;
	double rate;
	
} edge;

double dis[105];
bool visited[105];
edge ee [210];
int point_count;
int main()
{
	
	memset(visited,false,sizeof(visited));
	
	int currency_num, point_num, own;
	double own_amount;
	cin>>currency_num>>point_num>>own>>own_amount;
	int a,b;
	double rab,cab,rba,cba;
	for(int i=1;i<=point_num;i++)
	{
		cin>>a>>b>>rab>>cab>>rba>>cba;
		ee[point_count].leftpoint = a;
		ee[point_count].rightpoint = b;
		ee[point_count].rate = rab;
		ee[point_count].fee = cab;
		point_count++;
		ee[point_count].leftpoint = b;
		ee[point_count].rightpoint = a;
		ee[point_count].rate = rba;
		ee[point_count].fee = cba;
		point_count++;
	}
	visited[own]=true;
	dis[own]= own_amount;
	int source,dest;
	for(int i=1;i<currency_num;i++)
	{
		for(int j=0;j<point_num*2;j++)
		{
			source = ee[j].leftpoint;
			dest = ee[j].rightpoint;
			if((visited[ee[j].leftpoint]==true)&&(dis[source]>ee[j].fee))
			{
				visited[ee[j].rightpoint] = true;
				double trans = (dis[source]-ee[j].fee)*ee[j].rate;
				if(trans>dis[dest])
					dis[dest] = trans;
			}
		}
	}
	bool flag = false;
	for(int i=0;i<point_num*2;i++)
	{
		source = ee[i].leftpoint;
		dest = ee[i].rightpoint;
		if((visited[ee[i].leftpoint]==true)&&(dis[source]>ee[i].fee))
		{
			double trans = (dis[source]-ee[i].fee)*ee[i].rate;
			if(trans>dis[dest])
				flag = true;
		}

	}

	if(flag == true)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;




}