#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
int numcoin,numstation,start;
const int N=110;
bool visited[N];
double value;
double dis[N];
struct edge{
  int leftpoint,rightpoint;
  double rate,fee;
}ee[2*N];
bool bellman_ford(){
  
  for(int i=0;i<N;++i)
	  dis[i]=0;
  int pos=start;
  dis[pos]=value;
  visited[pos]=true;
  bool flag=0;
  for(int i=1;i<=numcoin;++i){
    flag=0;
	for(int j=0;j<2*numstation;++j){
		if((visited[ee[j].leftpoint]!=false)&&(dis[ee[j].leftpoint]>ee[j].fee))
		{
		  visited[ee[j].rightpoint]=true;
		  
		  if(dis[ee[j].rightpoint]<(dis[ee[j].leftpoint]-ee[j].fee)*ee[j].rate)
		  {
		  	dis[ee[j].rightpoint]=(dis[ee[j].leftpoint]-ee[j].fee)*ee[j].rate;
		  	flag = true;
		  }
		}
	}
	if(!flag)
		break;
  }
  if(!flag)
	  return false;
  return true;
}
int main(){
	memset(visited,false,sizeof(visited));
	//freopen("1.txt","r",stdin);
	scanf("%d%d%d%lf",&numcoin,&numstation,&start,&value);
	  //totalvalue=eachvalue*numcount;
	  int x,y;
	  double rate1,fee1,rate2,fee2;
	  for(int i=0;i<numstation*2;++i){
	    scanf("%d%d%lf%lf",&x,&y,&rate1,&fee1);
		ee[i].leftpoint=x;ee[i].rightpoint=y;
		ee[i].rate=rate1;ee[i].fee=fee1;
		scanf("%lf%lf",&rate2,&fee2);
		i++;
		ee[i].leftpoint=y;ee[i].rightpoint=x;
		ee[i].rate=rate2;ee[i].fee=fee2;
	  }
	 bool flag=bellman_ford();
	 if(flag)
		 printf("YES\n");
	 else
		 printf("NO\n");
	
  return 0;
}