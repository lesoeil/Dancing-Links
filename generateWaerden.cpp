/* try.cpp

	05-mai-2018
	Jacob
*/

#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	if (argc != 4)
	{
		cout<<"Command Usage: "<<argv[0]<<" j k n"<<endl;
		cout<<"j k n are positive integers."<<endl;
		cout<<"This command is to find binary sequence x_1 ... x_n that has no j \
equally spaced 0s and k equally spaced 1s."<<endl;

		return -1;
	}

	int j = std::stoi(argv[1]);
	int k = std::stoi(argv[2]);
	int n = std::stoi(argv[3]);; //total number of bits


	for (int gap=1; gap<=((n-1)/(j-1)); gap++)
	{
		for (int base=1; base<= (n-((j-1)*gap)); base++)
		{
			for (int index=0; index<j; index++)
			{
				cout<<2*(base+index*gap)+1<<" ";
			}
			cout<<endl;
		}
	}


	for (int gap=1; gap<=((n-1)/(k-1)); gap++)
	{
		for (int base=1; base<= (n-((k-1)*gap)); base++)
		{
			for (int index=0; index<k; index++)
			{
				cout<<2*(base+index*gap)<<" ";
			}
			cout<<endl;
		}
	}


/*	
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
*/

	/*
	cout<<"1<<10 = "<<(1<<10)<<endl;
	cout<<"1>>10 = "<<(1>>10)<<endl;
	*/

	return 0;
}