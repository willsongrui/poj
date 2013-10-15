#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
typedef struct{
	string str;
	int rank;
}node; 
vector<node> seq;

int length,number;
int cal(string str)
{
	int result = 0;
	for(int i=0;i<length;i++)
	{
		for(int j=i+1;j<length;j++)
		{
			if(str[i]>str[j])
				result++;
		}
	}
	return result;
}
bool cmp(_node a,_node b)
{
	return a.rank<b.rank;
}
int main()
{
	cin>>length>>number;
	string temp;
	node _node;
	for(int i=0;i<number;i++)
	{
		cin>>temp;
		_node.str = temp;
		_node.rank = cal(temp);
		seq.push_back(_node);
		
	}
	sort(str.begin(),str.end(),cmp);
	for(int i=0;i<number;i++)
	{
		cout<<seq[flag[i]]<<endl;
	}
	return 0;
}