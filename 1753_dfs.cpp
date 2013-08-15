#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
bool table[4][4];
int ret=100;
bool finished()
{
	int re=0;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
			re+=table[i][j];
	}
	if(re==0||re==16)
		return true;
	return false;
}
void turn(int x,int y)
{
	if((x<4)&&(x>=0)&&(y<4)&&(y>=0))
		table[x][y]=!table[x][y];
}
void flip(int m)
{
	int x=(m/4);
	int y=(m%4);
	turn(x,y);
	turn(x-1,y);
	turn(x+1,y);
	turn(x,y+1);
	turn(x,y-1);
}
void dfs(int cur,int count)
{
	if(finished())
	{
		if(count<ret)
			ret=count;
		return;
	}
	if(cur<16)
	{
		dfs(cur+1,count);
		flip(cur);
		dfs(cur+1,count+1);
		flip(cur);
	}

}
int main()
{
	char ch;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			cin>>ch;
			if(ch=='b')
				table[i][j]=1;
		}
	}
	dfs(0,0);
	if(ret>32)
		cout<<"Impossible"<<endl;
	else
		cout<<ret<<endl;
}