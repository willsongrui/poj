#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;
int array[10001];
void exchange(int a,int b)
{
	int temp=array[a];
	array[a]=array[b];
	array[b]=temp;
}
int randomized_partition(int beg,int end)
{
	int pos = rand()%(end-beg+1);
	exchange(pos+beg,end);
	int a=beg-1;
	int b=beg;
	for(;b<end;b++)
	{
		
		if(array[b]<array[end])
		{
			if(b>a+1)
				exchange(a+1,b);
			a++;
		}
	}
	exchange(a+1,end);
	return a+1;

}
int mid_sort(int beg,int end,int mid)
{
	
	int pos=randomized_partition(beg,end);
	if(pos==mid)
		return array[pos];
	else
	{
		if(pos<mid)
			return mid_sort(pos+1,end,mid);
		else
			return mid_sort(beg,pos-1,mid);

	}
}
int main()
{
	srand((unsigned)time(0));
	int num;
	cin>>num;
	for(int i=1;i<=num;i++)
	{
		cin>>array[i];
	}
	cout<<mid_sort(1,num,(1+num)/2)<<endl;
	return 0;
}
