#include <iostream>
#include <memory.h>
using namespace std;
bool table[4][4];
typedef struct
{
	int x;
	int y;
}seq;
seq step[17];
seq finalstep[17];
int minstep;
void change(int cur)
{
	int x=cur/4;
	int y=cur%4;
	for(int i=0;i<4;i++)
	{
		table[x][i]=!table[x][i];
	}
	for(int i=0;i<4;i++)
	{
		table[i][y]=!table[i][y];
	}
	table[x][y]=!table[x][y];

}
bool isopen()
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
			if(table[i][j]!=false)
				return false;
	}
	return true;
}


void find_result(int cur,int steps)
{
	
	if(isopen()==true)
	{
		if(minstep>steps)
		{
			
			memcpy(finalstep,step,sizeof(step));
			minstep=steps;
		}
		
		return;
	}
	if(cur>15)
		return;
	find_result(cur+1,steps);
	change(cur);
	step[steps].x=cur/4;
	step[steps].y=cur%4;
	find_result(cur+1,steps+1);
	change(cur);
}
void print()
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			cout<<table[i][j];
		}
		cout<<endl;
	}
}
void _change(int x,int y)
{
	change((x-1)*4+y-1);
}
int main()
{	
	minstep=20;
	char tmp;
	for(int hang=0;hang<4;hang++)
	{
		for(int lie=0;lie<4;lie++)
		{
			cin>>tmp;
			if(tmp=='-')
				table[hang][lie]=false;
			else
				table[hang][lie]=true;
			
		}
	}
	/*int x,y;
	while(cin>>x>>y)
	{
		_change(x,y);
		print();
		if(isopen())
			cout<<"yes";
	}*/
	find_result(0,0);
	cout<<minstep<<endl;
	for(int i=0;i<minstep;i++)
	{
		cout<<finalstep[i].x+1<<" "<<finalstep[i].y+1<<endl;
	}
	return 0;
}