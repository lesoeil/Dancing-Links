/* try.cpp

	05-mai-2018
	Jacob
*/

#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	int n = 9; //total number of bits
	int r = 3; 

	for (int gap=1; gap<=((n-1)/(r-1)); gap++)
	{
		for (int i=1; i<= (n-((r-1)*gap)); i++)
		{
			for (int j=0; j<r; j++)
			{
				cout<<2*(i+j*gap)<<" ";
			}
			cout<<endl;
			
			for (int j=0; j<r; j++)
			{
				cout<<2*(i+j*gap)+1<<" ";
			}
			cout<<endl;
			
		}
	}


	/*
	cout<<"1<<10 = "<<(1<<10)<<endl;
	cout<<"1>>10 = "<<(1>>10)<<endl;
	*/

	return 0;
}