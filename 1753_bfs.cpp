/*Pay attention to the bfs ,make sure all the sequent node into the queue
bfs must judge whether the node is in the queue already
*/

#include <iostream>
#include <queue>
#include <cstring>
#include <stdlib.h>
using namespace std;
char str[5][5];
bool dp[70000];
int turn[16] = {0xC800,0xE400,0x7200,0x3100,0x8C80,0x4E40,0x2720,0x1310,0x08C8,0x04E4,0x0272,0x0131,0x008C,0x004E,0x0027,0x0013};
struct node
{
    int state;
    int now_row;
};
queue <node> s;
bool cal(node &tem,int a,int b)
{
    if(tem.state==0 || tem.state == 65535)//判断退出的情况
    {
        cout<<tem.now_row<<endl;
        exit(0);
    }
    tem.state =tem.state^turn[16 -a*4 -b -1];//hash翻转
    tem.now_row++;
	if(dp[tem.state] == true)//一定要注意这句话的位置，要在翻转后判断
        return false;
	dp[tem.state] = true;//一定要注意这句话的位置，要在翻转后设置
    return true;
}
int main()
{
    int i,j,my_state=0;
    memset(dp,false,sizeof(dp));
    for(i=0;i <4; i++)
        for(j=0; j<4; j++)
        {
            cin>>str[i][j];
            if(str[i][j] == 'b')
                my_state|=1<<(i*4+j);//如果是b就当做是1存入状态中去
        }
	node tem={my_state,0};
    s.push(tem);//把初始状态压入队列
    while(!s.empty())
    {
        tem = s.front();
        s.pop();
        for(i=0; i<4;i++)
        {
            for(j=0; j<4; j++)
            {
                node tem2 = tem;
                if(cal(tem2,i,j)) //返回true加入队列
                {
                    s.push(tem2);
                }

            }
        }
    }
	cout<<"Impossible"<<endl;//如果最后没有搜索到就退出

    return 0;
}