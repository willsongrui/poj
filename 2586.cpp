#include <iostream>
using namespace std;
int main()
{
	int s,d;
	bool flag;
	while(cin>>s>>d)
	{
		int result=0;
		flag=false;
		double k=(double)d/s;
		if(k>4.0)
			result=10*s-2*d;
		else if(k>1.5)
			result=8*s-4*d;
		else if(k>(2.0/3))
			result=6*s-6*d;
		else if(k>0.25)
			result=3*s-9*d;
		else
			result=-1;
		if(result>0)
			cout<<result<<endl;
		else
			cout<<"Deficit"<<endl;


	}
}