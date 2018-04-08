#include<iostream>

using namespace std;

bool isPrime(int n);

int main(int argc, char** argv)
{
	if (argc <2)
	{
		cout<<"Usage: ./prime n"<<endl;
		cout<<"n is the positive integer of upper bound"<<endl;
		return -1;
	}


	int k = atoi(argv[1]);

	if (k<=1)
	{
		cout<<"Usage: ./prime n"<<endl;
		cout<<"n is the positive integer of upper bound >=2"<<endl;
		return -2;
	}

	int count = 0;
	cout<<count+1<<"th: ";
	for (int i = 2; i<=k; i++)
	{
		if (isPrime(i))
		{
			count++;
			cout<<i<<"  ";
			if ((count % 10) == 0)
			{
				cout<<endl;
				cout<<count<<"th: ";
			}
		}
	}
	cout<<endl;
	cout<<"Total number of prime number <= "<<k<<" is :"<<count<<endl;

	return 0;
}


bool isPrime(int n)
{
	for (int i=2; (i*i)<=n; i++)
	{
		if ((n % i) == 0)
		{
			return false;
		}
	}

	return true;
}