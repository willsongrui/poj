#include <iostream>
#include <string>
#include <memory.h>
using namespace std;
bool edge[30][30];
typedef struct
{
	int d;
	int f;
	int color;
}node;
int alpha_num, condition_num;
int seq_count;
node nodes[30];
int cur_time;
int seq[30];
bool dfs(int cur)
{
	nodes[cur].d = cur_time;
	nodes[cur].color = 1;
	cur_time++;
	for(int i=1;i<=alpha_num;i++)
	{
		if(edge[cur][i]==true)
		{
			if(nodes[i].color==1)
				return false;
			if(nodes[i].color==0)
			{
				bool result = dfs(i);
				if(result==false)
					return false;
			}
		}
	}
	nodes[cur].color=2;
	nodes[cur].f=cur_time;
	cur_time++;
	seq[seq_count++] = cur;
	return true;
}
int topology(int count)
{

	int flag=0;
	for(int i=1;i<=alpha_num;i++)
	{
		seq_count=1;
		memset(seq,0,sizeof(seq));
		memset(nodes,0,sizeof(nodes));
		cur_time=0;
		int result=dfs(i);

		if(result==false)
			return -1;
		flag = 1;
		for(int j=1;j<=alpha_num;j++)
		{
			if(nodes[j].color!=2)
			{	
				flag = 0;
				break;
			}
		}
		if(flag==1)
			break;
	}
	return flag;
}
int main()
{
	
	string sentence;
	int m,n;
	int found;
	while(cin>>alpha_num>>condition_num)
	{
		memset(edge,0,sizeof(edge));

		int flag=0;
		if(alpha_num==0&&condition_num==0)
			break;
		for(int i=1;i<=condition_num;i++)
		{
			cin>>sentence;
			m=sentence[0]-'A'+1;
			n=sentence[2]-'A'+1;
			edge[m][n]=true;
			if(flag==0)
			{
				int result=topology(i);
				if(result==1)
				{
					flag=1;
					found =i ;
				}
				else if(result==-1)
				{	
					flag=-1;
					found = i;
				}
			}
		}
		if(flag==1)
		{
			cout<<"Sorted sequence determined after "<<found<<" relations: ";
			for(int i=1;i<=alpha_num;i++)
			{
				cout<<(char)('A'+i-1);
			}
			cout<<'.'<<endl;

		}
		else if(flag==0)
		{
			cout<<"Sorted sequence cannot be determined."<<endl;
		}
		else
		{
			cout<<"Inconsistency found after "<<found<<" relations."<<endl;
		}
	}
	return 0;
}