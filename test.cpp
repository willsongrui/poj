#include <iostream>
#include <memory.h>
using namespace std;
int main()
{
	char a[]="sdfdsfs";
	char b[100];
	memcpy(b,a,sizeof(a));
	cout<<b;
	cout<<sizeof(a);
}