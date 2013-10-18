#include <iostream>
using namespace std;
int L;
int N;
int result[101];
int jieguo[101];
void dfs(int level)
{
	if(level>L)
		return;
	for(int i=1;i<level;i++)
	{
		result[level]=result[level-1]+result[i];
		if(result[level]==N)
		{
			if(level<L)
			{
				L=level;
				for(int j=1;j<=L;j++)
					jieguo[j]=result[j];
			}
		}
		else if(result[level]<N)
			dfs(level+1);
	}
}
int main()
{
	while(cin>>N&&N!=0)
	{
		result[1]=1;
		L=100;
		if(N==1)
			cout<<1<<endl;
		else
		{
			dfs(2);
			for(int i=1;i<=L;i++)
			{
				cout<<jieguo[i];
				if(i==L)
					cout<<endl;
				else
					cout<<" ";
			}

		}
	}
	return 0;
}