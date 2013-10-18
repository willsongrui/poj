#include <iostream>
#include <memory.h>
#include <stdio.h>
using namespace std;
typedef struct {
	int x;
	int y;
}node;
typedef struct{
	int x;
	int y;
	int len;
}qnode;
qnode que[2600];
int count;
int lie,hang;
node nodes[110];
int dir[][2]={{-1,0},{1,0},{0,-1},{0,1}};
bool vis[110][110];
int maze[110][110];
int dis[110][110];
int md[110];
bool in_set[110];

bool qualified(int x,int y)
{
	if(x<1||y<1||x>hang||y>lie)
		return false;
	if(maze[x][y]==-1||vis[x][y]==true)
		return false;
	return true;
}
int find_node(int x,int y)
{
	for(int i=1;i<count;i++)
	{
		if(nodes[i].x==x&&nodes[i].y==y)
			return i;
	}
}

void find_dis(int cur)
{
	memset(vis,0,sizeof(vis));
	memset(que,0,sizeof(que));
	que[1].x=nodes[cur].x;
	que[1].y=nodes[cur].y;
	que[1].len=0;
	int tail=2;
	int head=1;
	vis[nodes[cur].x][nodes[cur].y]=true;
	qnode curNode;
	while(head<tail)
	{
		curNode = que[head];
		head++;
		if(maze[curNode.x][curNode.y]!=-1)
		{
			int id=find_node(curNode.x,curNode.y);
			if(dis[id][cur]>curNode.len)
				dis[cur][id]=dis[id][cur]=curNode.len;
		}
		int curx,cury;
		for(int i=0;i<4;i++)
		{
			curx=curNode.x+dir[i][0];
			cury=curNode.y+dir[i][1];
			qnode tempnode;
			if(qualified(curx,cury))
			{
				que[tail].x=curx;
				que[tail].y=cury;
				que[tail].len=curNode.len+1;
				tail++;
				vis[curx][cury]=true;
			}
		}

	}
}
int find_min()
{
	int id;
	int cur=0xfffffff;
	for(int i=1;i<count;i++)
	{
		if(in_set[i]==false&&md[i]<cur)
		{	
			cur=md[i];
			id=i;
		}
	}
	return id;
}
int prim()
{
	memset(in_set,false,sizeof(in_set));
	for(int i=1;i<count;i++)
	{
		md[i]=dis[1][i];
	}
	for(int i=1;i<count;i++)
	{
		int k=find_min();
		in_set[k]=true;
		for(int j=1;j<count;j++)
		{
			if(in_set[j]==false)
			{
				if(md[j]>dis[j][k])
					md[j]=dis[j][k];
			}
		}
	}
	int result=0;
	for(int i=1;i<count;i++)
		result+=md[i];
	return result;
	
}
int main()
{
	int rounds;
	cin>>rounds;
	
	while(rounds--)
	{

		count=1;
		cin>>lie>>hang;
		char sentence[10];
		char temp;
		gets(sentence);
		for(int i=1;i<=hang;i++)
		{
			gets(sentence);

			for(int j=1;j<=lie;j++)
			{
				temp=sentence[j-1];
				if(temp=='#')
					maze[i][j]=-1;
				else if(temp=='A'||temp=='S')
				{
					maze[i][j]=1;
					nodes[count].x=i;
					nodes[count].y=j;
					count++;
				}
				else
					maze[i][j]=0;
			}
		}
		for(int i=1;i<count;i++)
		{
			dis[i][i]=0;
			for(int j=i+1;j<count;j++)
				dis[j][i]=dis[i][j]=0xffffff;
		}
		for(int i=1;i<count;i++)
		{
			find_dis(i);
		}
		int result=prim();
		cout<<result<<endl;
	}
	return 0;
}