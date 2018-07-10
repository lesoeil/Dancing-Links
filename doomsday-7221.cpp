/* To calculate doomsday function D(n)

*/


#include <iostream>

using namespace std;


int main(int argc, char** argv)
{
	int D[100];

	D[0] = 1;
	D[1] = 1;


	for (int n=2; n<=21; n++)
	{
		D[n] = -1;
		for (int t=1; t<n; t++)
		{
			for (int tt=0; tt<=t; tt++)
			{
				int dntt = 0;

				if (tt==0)
				{
					dntt = 1+t*D[n-t-1];
				}
				else
				{
					if (((n-t-tt+1)<0) || ((n-t-tt-1)<0))
					{
						continue;
					}

					dntt = tt + tt*D[n-t-tt+1] + (t-tt)*D[n-t-tt-1];
				}

				if (dntt > D[n])
				{
					D[n] = dntt;
				}

			}
		}
	}


	for (int n=0; n<=21; n++)
	{
		cout<<"n="<<n<<"  D("<<n<<") ="<<D[n]<<endl;	
	}

	cout<<"Hello, doomsday!"<<endl;
}


/*
	D(0) = D(1) = 1;								(76)
	D(n) = max {d(n,t,t') | 1<=t<n and 0<=t'<=t},	(77)
	d(n,t,0) = 1 + t*D(n-t-1),						(78)
	d(n,t,t') = t' + t'*D(n-t-t'+1) + (t-t')*D(n-t-t'-1), if 1<=t'<=t.		(80)

*/