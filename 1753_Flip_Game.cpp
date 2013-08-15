#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
bool table[4][4];
bool temp[4][4];
int moves;
void change(int x, int y)
{
	temp[x][y] = !temp[x][y];
	if(x > 0)
		temp[x-1][y] = !temp[x-1][y];
	if(y > 0)
		temp[x][y-1] = !temp[x][y-1];
	if(x < 3)
		temp[x+1][y] = !temp[x+1][y];
	if(y < 3)
		temp[x][y+1] = !temp[x][y+1];

}
int main()
{
	char ch;
	for(int i=0 ; i <= 3; i++)
	{
		for(int j=0; j <= 3; j++)
		{
			cin >> ch;
			if(ch == 'b')
				table[i][j] = false;
			else
				table[i][j] = true;
 		}
	}
	
	
	bool can = false;
	
	int least = 100;
	int color = 0;
	for( ; color != 2; color++)
	{
		for(int i = 0; i < 16 ; i++)
		{
			moves = 0;
			memcpy(temp, table, sizeof(table));

			int c = 3;
			for(int j = 1; j < 16; j = j * 2)
			{
				if((i & j) != 0)
				{
					change(0 , c);
					moves++;
				}
				c--;
			}
			for(int j = 1; j < 4; j++)
			{
				for(int k = 0; k < 4; k++)
				{
					if(temp[j-1][k] != color)
					{	
						moves++;
						change(j , k);
					}
				}
			}
			bool flag = true;
			for(int j = 0; j < 4; j++)
			{
				if(temp[3][j] != color)
				{	
					flag = false;
					break;
				}
			}
			if(flag == true)
			{
				//cout <<color<<"  "<<moves <<"  "<<i<<endl;
				if(moves < least)
					least = moves;
				can = true;
			}
		}
	}
	if(can == false)
		cout<<"Impossible"<<endl;
	else
		cout<<least<<endl;
	return 0;


}