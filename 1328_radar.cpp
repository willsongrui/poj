#include <iostream>
#include <math.h>
using namespace std;
typedef struct
{
	bool exists;
	double x;
	double y;
}node;
node nodes[1005];
int num,d;
int ret;
int find_count(double x)
{
	int count=0;
	for(int i=1;i<=num;i++)
	{
		if(nodes[i].exists==false)
				continue;
			if((nodes[i].x-x)*(nodes[i].y-x)<=0)
			{	
				count++;
				
			}
	}
	return count;
}
void find_result()
{
	int count=0;
	int k;
	double maxdot;
	int maxcount;
	while(count<num)
	{
		maxcount=0;
		for(int i=1;i<=num;i++)
		{
			if(nodes[i].exists==false)
				continue;
			k=find_count(nodes[i].x);
			if(maxcount<k)
			{
				maxcount=k;
				maxdot=nodes[i].x;
			}
			k=find_count(nodes[i].y);
			if(maxcount<k)
			{
			maxcount=k;
			maxdot=nodes[i].y;
			}
		}
		for(int i=1;i<=num;i++)
		{
			if(nodes[i].exists==false)
				continue;
			if((nodes[i].x-maxdot)*(nodes[i].y-maxdot)<=0)
			{	
				count++;
				nodes[i].exists=false;
			}				
		}
		ret++;
	}
}
void find_conj(int x,int y,int n)
{
	double pianyi = sqrt((double)(d*d-y*y));
	nodes[n].x = x-pianyi;
	nodes[n].y = x+pianyi;


}
int main()
{
	int round=0;
	while(cin>>num>>d)
	{

		int x,y;
		if(num==0)
			break;
		else
		{
			ret=0;
			round++;
			for(int i=1;i<=num;i++)
			{	
				cin>>x>>y;
				find_conj(x,y,i);
				
				nodes[i].exists=true;
				
			}
			find_result();
				cout<<"Case "<<round<<": "<<ret<<endl;
		}
	}
}