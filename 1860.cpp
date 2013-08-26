#include <queue>
#include <iostream>
#include <vector>
using namespace std;
int cur_num;
int ex_num;
int start_num;
double amount;
typedef struct
{
	int to;
	double rate;
	double cost;
}_ex;
vector<_ex> exchange[105];
queue<int> mq;
int times[105];
double amounts[105];
bool inqueue[105];
int main()
{
	for(int i=0;i<105;i++)
	{
		inqueue[i]=false;
		amounts[i]=-1.0;
		times[i]=0;
	}
	cin>>cur_num>>ex_num>>start_num>>amount;
	int a,b;
	_ex _excur;
	for(int i=0;i<ex_num;i++)
	{
		cin>>a>>b;
		cin>>_excur.rate>>_excur.cost;
		_excur.to=b;
		exchange[a].push_back(_excur);
		_excur.to=a;
		cin>>_excur.rate>>_excur.cost;
		exchange[b].push_back(_excur);
	}
	amounts[start_num]=amount;
	mq.push(start_num);
	times[start_num]++;
	int cur;
	bool flag=false;
	vector<_ex>::iterator iter;
	inqueue[start_num]=true;
	while(mq.empty()==false)
	{

		cur=mq.front();
		mq.pop();
		if(times[cur]>1000)
		{
			flag=true;
			break;
		}
		inqueue[cur]=false;
		
		if((cur==start_num)&&amounts[cur]>amount)
		{
			flag=true;
			break;
		}
		for(iter=exchange[cur].begin();iter!=exchange[cur].end();iter++)
		{
			double money=(amounts[cur]-iter->cost)*(iter->rate);
			if(money>amounts[iter->to])
			{
				amounts[iter->to]=money;
				if(inqueue[iter->to]==false)
				{
					inqueue[iter->to]=true;
					times[iter->to]++;
					mq.push(iter->to);
				}
			}
			
		}

		
	}
	if(flag==true)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}