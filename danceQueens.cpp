/* danceQueens.cpp */

/*	Jacob 
	10 Aug 2017 

*/

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#include "danceQueens.h"

int DomainDk::nextLarger(int current)
{
	int next = -1;
	if ((current >= min) && (current <= max))
	{
		next = current+1;
	}

	return next;
}

QUEEN::QUEEN(int numberOfQueens)
{
	count = 0;
	n = numberOfQueens;
	x = new int(n+1);

	for (int i=0; i<n+1; i++)
	{
		D.push_back(new DomainDk);
	}

	for (int i=0; i<n+1; i++)
	{
		x[i] = -1;
		D[i]->min = 1;
		D[i]->max = n;
	}

	l = 0;
}

bool QUEEN::P(int k)
{
	bool bPass = true;
	//TODO: Check x[k] can exit with x[]1..k]
	for (int i=1; i<k; i++)
	{
		if ((x[k] == x[i]) || (abs(x[k]-x[i])==(k-i)))
		{
			bPass = false;
			break;
		}
	}
	return bPass;
}

void QUEEN::basicBackTrack()
{
B1:	// [Initialize.]
	// Set l <- 1, and initialize the data strcuture needed later.
	l = 1;
	memset(x, 0, n);

B2:	// [Enter level l.]
	// If l > n, visit x[1], x[2], ..., x[n] and go to B5.
	// Otherwise set x[l] <- min D[l], the smallest of D[l]. 
	if (l > n)
	{
		count++;
		#if 0
		for (int i=1; i<=n; i++)
		{
			cout<<x[i]<<"  ";
		}
		cout<<endl;
		#endif

		#if 0
		if (0 == (count % 10000))
		{
			cout<<count<<endl;
		}
		#endif

		goto B5;
	}
	else
	{
		x[l] = D[l]->min;
	}

B3:	// [Try x[l].]
	// If P(l) holds,update data structures to facilitate testing of P(l+1), set l<-l+1 and go to B2.
	if (P(l))
	{
		l = l+1;
		goto B2;
	}

B4:	// [Try again.]
	// If x[l] != max D[l], set x[l] to the next larger element of D[l] and return to B3.
	if (x[l] != D[l]->max)
	{
		x[l] = D[l]->nextLarger(x[l]);
		goto B3;
	}

B5:	// [Backtrack.]
	// Set l <- l-1. If l > 0, download the data structures by undoing the changes recently made in 
	// step B3, and return to B4. (Otherwise stop.)
	l = l-1;
	if (l > 0)
	{
		//undo changes recently made in step B3.

		//return to B4.
		goto B4;
	}
	else
	{
		return;
	}
}


void QUEEN::customizedBackTrack()
{
	bool a[n+1];
	bool b[2*n];
	bool c[2*n];
	int t = 0;

B1: // [Initialize.]
	memset(a, 0, n+1);
	memset(b, 0, 2*n);
	memset(c, 0, 2*n);
	l = 1;

B2: // [Enter level l.]
	if (l > n)
	{
		count++;
		/*
		for (int i=1; i<=n; i++)
		{
			cout<<x[i]<<" ";
		}
		cout<<endl;
		*/
		goto B5;
	}
	else
	{
		t =1;
	}

B3: // [Try t.]
	if ( (a[t] == 1) || (b[t+l-1] ==1) || (c[t-l+n]==1) )
	{
		goto B4;
	}
	else
	{
		a[t] = 1;
		b[t+l-1] = 1;
		c[t-l+n] = 1;
		x[l] = t;
		l = l+1;
		goto B2;
	}

B4: // [Try again.]
	if (t<n)
	{
		t = t+1;
		goto B3;
	}

B5: //[Backtrack.]
	l = l-1;
	if (l>0)
	{
		t = x[l];
		c[t-l+n] = 0;
		b[t+l-1] = 0;
		a[t] = 0;
		goto B4;
	}


	return;
}


/*
Walker's method.  The 1950-era programs of R.J. Walker organized back-
tracking in a somewhat different way. Instead of letting x[l] run through all
elements of D[l], he calculated and stored the set

			S[l] <-- { x in D[l] | P[l](x[1], ..., x[l-1],x) holds}		(5)

upon entry to each node at level l. This computation can often be done efficiently
all at once, instead of piecemeal, because some cutoff properties make it possible
to combine steps that would otherwise have to be repeatedly for each x in D[l].
*/

#if 0
//Correct Result but very slow.
void QUEEN::WalkersBackTrack()
{
	//long long int taxi = 0x1000000000;
	if (n>32)
	{
		cout<<"This version of Walker's method suppose n<=32."<<endl;
		cout<<"Number of Queens is "<<n<<", which is larger than 32."<<endl;
		cout<<"Function returns without run."<<endl;
		return;
	}

	unsigned long long int A;
	unsigned long long int B;
	unsigned long long int C;
	unsigned long long int S[n+1];

W1: // [Initialized.] Set l <- 1, and initialize the data structures needed later.

	l = 1;
	//A = 0;
	//B = 0;
	//C = 0;
	//S[0] = 0;  ....... S[n] = 0;

W2: // [Enter level l.] (Now (P[l-1](x[1], .... , x[l-1])) holds.) If l > n, visit x[1] x[2] ... x[n]
    //and go to W4. Otherwise determine the set S[l] as in (5).

	if (l > n)
	{
		count++;
		/*
		for (int i=1; i<=n; i++)
		{
			cout<<x[i]<<" ";
		}
		cout<<endl;
		*/
		goto W4;
	}
	else
	{
		A = 0;
		B = 0;
		C = 0;
		S[l] = 1;

		for (int j=1; j<l; j++)
		{
			A = (A | (1ULL<<x[j]));
			B = (B | (1ULL<<(x[j]+j-l)));
			C = (C | (1ULL<<(x[j]-j+l)));
		}

		for (int j=n+1; j<64; j++)
		{
			S[l] = (S[l] | (1ULL<<j));
		}

		S[l] = ~(S[l] | A | B | C);
	}


W3: // [Try to advance.] If S[l] is nonempty, set x[l] <- min S[l], update the data
	// structures to facilitate computing S[l+1], set l <- l+1, and go to W2.

	if (S[l]>0)
	{
		for (int k=1; k<=n; k++)
		{
			if (S[l] & (1ULL<<k))
			{
				x[l] = k;
				break;
			}
		}

		l = l+1;
		goto W2;
	}

W4:	// [Backtrack.] Set l <- l - 1. If l > 0, downdate the data structures by
	//	undoing changes made in step W3, set S[l] <- S[l] \ x[l], and retreat to W3. 

	l = l-1;

	if (l > 0)
	{
		//Downdate data structures by undoing changes made in step W3.

		//Remove x[l] from S[l].
		S[l] = S[l] & (~(1<<x[l]));
		goto W3;
	}
}
#endif


void QUEEN::WalkersBackTrack()
{
	//long long int taxi = 0x1000000000;
	if (n>32)
	{
		cout<<"This version of Walker's method suppose n<=32."<<endl;
		cout<<"Number of Queens is "<<n<<", which is larger than 32."<<endl;
		cout<<"Function returns without run."<<endl;
		return;
	}

	unsigned long long int A[n+2];
	unsigned long long int B[n+2];
	unsigned long long int C[n+2];
	unsigned long long int S[n+2];
	unsigned long long int filter = ~(0xFFFFFFFFFFFFFFFFULL-(unsigned int)(pow(2,n)-1));

W1: // [Initialized.] Set l <- 1, and initialize the data structures needed later.

	l = 1;
	//A = 0;
	//B = 0;
	//C = 0;
	//S[0] = 0;  ....... S[n] = 0;
	A[l] = 0;
	B[l] = 0;
	C[l] = 0;
	S[l] = 0;

W2: // [Enter level l.] (Now (P[l-1](x[1], .... , x[l-1])) holds.) If l > n, visit x[1] x[2] ... x[n]
    //and go to W4. Otherwise determine the set S[l] as in (5).

	if (l > n)
	{
		count++;
		/*
		for (int i=1; i<=n; i++)
		{
			cout<<x[i]<<" ";
		}
		cout<<endl;
		*/
		goto W4;
	}
	else
	{
		//cout<<"S[l] before W2:"<<S[l]<<endl;
		S[l] = ~(A[l] | B[l] | C[l]);
		S[l] &= filter;
		//cout<<"For level "<<l<<": "<<A[l]<<" "<<B[l]<<" "<<C[l]<<" "<<S[l]<<endl;
	}


W3: // [Try to advance.] If S[l] is nonempty, set x[l] <- min S[l], update the data
	// structures to facilitate computing S[l+1], set l <- l+1, and go to W2.
	//cout<<S[l]<<endl;

	if (S[l]>0)
	{
		/*
		for (unsigned int k=0; k<n; k++)
		{
			if (S[l] & (1ULL<<k))
			{
				x[l] = k+1;
				break;
			}
		}
		*/
		x[l] = ffsll(S[l]);

		//A[l+1] = A[l] | (1<<(x[l]-1));
		//B[l+1] = (A[l+1] >> (l-j)) | (A[l+1] << (32-l+j));
		//C[l+1] = A[l+1]
		//B[l+1] = (B[l]>>1) | (B[l]<<31) | (1<<(x[l]+l-(l+1)-1));
		//C[l+1] = (C[l]<<1) | (C[l]>>31) | (1<<(x[l]-l+(l+1)-1));
		//B[l+1] = (B[l]>>1) | (1<<(x[l]+l-(l+1)-1));
		//C[l+1] = (C[l]<<1) | (1<<(x[l]-l+(l+1)-1));
		//S[l+1] = 0xFFFFFFFF-(2^n-1);
		
		l = l+1;
		A[l] = A[l-1] | (1<<(x[l-1]-1));
		B[l] = (B[l-1] >> 1) | (B[l-1] << 63) | (1<<(x[l-1]+l-1-l-1));;
		C[l] = (C[l-1] << 1) | (C[l-1] >> 63) | (1<<(x[l-1]-(l-1)+l-1));

		goto W2;
	}

W4:	// [Backtrack.] Set l <- l - 1. If l > 0, downdate the data structures by
	//	undoing changes made in step W3, set S[l] <- S[l] \ x[l], and retreat to W3. 

	l = l-1;

	if (l > 0)
	{
		//Downdate data structures by undoing changes made in step W3.

		//Remove x[l] from S[l].
		S[l] = S[l] & (~(1ULL<<(x[l]-1)));
		goto W3;
	}
}


int main(int argc, char* argv[])
{
	if (argc >= 2)
	{
		int nQ = atoi(argv[1]); 
		QUEEN queen(nQ);
		//cout<<queen.n<<endl;
		time_t t1 = time(0);
		//queen.basicBackTrack();//Queen(14):15 seconds.  Queen(15):113 seconds.
		//queen.customizedBackTrack();//Queen(14):3 seconds. Queen(15):19 seconds.  Queen(16):128 seconds.
		queen.WalkersBackTrack();
		time_t t2 = time(0);
		cout<<"Solutions for Queen("<<nQ<<") is: "<<queen.count<<endl;
		cout<<"Time used for Queen("<<nQ<<") is: "<<t2 - t1<<" seconds."<<endl;
	}
	else
	{
		cout<<"argument missing for numberOfQueens!!!"<<endl<<endl;
		cout<<"Usage: queen n";
		cout<<"    (n is an integer for numberOfQueens to be used by program.)"<<endl<<endl;
		cout<<"For example:";
		cout<<"    ./queen 10"<<endl;
	}
	

	return 0;
}

