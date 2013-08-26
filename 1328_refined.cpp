#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
typedef struct
{
	bool exists;
	double x;
	double y;
}node;

vector<node> mv;
int num,d;
int ret;

int find_conj(int x,int y,int n)
{
	if(d<abs(y))
		return -1;
	else if(y<=0)
		return -1;
	double pianyi = sqrt((double)(d*d-y*y));
	
	node cur;
	cur.x = x-pianyi;
	cur.y = x+pianyi;
	mv.push_back(cur);
}


bool cmp(node a,node b)
{
	if(fabs(a.y-b.y)<0.0005)
		return a.x<b.x;
	else
		return a.y<b.y;
}
int find_result()
{
	int count=0;
	for(int i=0;i<num;i++)
	{
		if(mv[i].exists==true)
		{
			for(int j=i;j<num;j++)
			{
				if(mv[j].x<=mv[i].y)
				{
					mv[j].exists=false;
				}
			}
			count++;
		}
	}
	return count;
}
int main()
{
	int hah;
	int round=0;
	while(cin>>num>>d)
	{
		bool flag=true;	
		mv.clear();
		int x,y;
		if(num==0)
			break;
		else
		{
			ret=0;
			round++;
			for(int i=0;i<num;i++)
			{	
				cin>>x>>y;
				hah=find_conj(x,y,i);
				if(hah<0)
				{
					flag=false;
						
				}
				else
					mv[i].exists=true;
				
			}
			if(flag==false)
				cout<<"Case "<<round<<": "<<-1<<endl;
			else
			{	
				sort(mv.begin(),mv.end(),cmp);
				cout<<"Case "<<round<<": "<<find_result()<<endl;
			}
		}
	}
}