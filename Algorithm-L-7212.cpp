/*	Algorithm-L-7212.cpp 
	15-Jan-2019

	Algorithm L (Lexicographic permutation generation). Given a sequence of n
	elements a_1 a_2 ... a_n, initially sorted so that
							a_1 <= a_2 <= ... <= a_n,						(1)
	this algorithm generates all permutations of {a_1, a_2, ... , a_n}, visiting them in 
	lexicographic order. (For example, the permutations of {1, 2, 2, 3} are
		1223, 1232, 1322, 2123, 2132, 2213, 2231, 2312, 2321, 3122, 3212, 3221
	ordered lexicographically.) An auxiliary element a_0 is assumed to be present for 
	convenience; a_0 must be strictly less than the largest element a_n.
	)


*/

#include <iostream>
#include <set>
#include "Algorithm-L-7212.h"

using namespace std;

int main()
{
	//cout<<"This is the generating all permutations."<<endl;

	int n = 10;
	int a[] = {-1, 0, 1 , 2, 3, 4, 5, 6, 7, 8, 9};

	int nRet = -1;

	nRet = algoL(a, n);

	return 0;

}


int algoL(int a[], int n)
{

	int L[10][10] = {	{0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
						{1, 8, 3, 2, 5, 4, 7, 6, 9, 0},
						{2, 9, 5, 6, 3, 0, 8, 4, 7, 1},
						{3, 7, 0, 9, 8, 6, 1, 5, 2, 4},
						{4, 6, 7, 5, 2, 9, 0, 8, 1, 3},
						{5, 0, 9, 4, 7, 8, 3, 1, 6, 2},
						{6, 5, 4, 7, 1, 3, 2, 9, 0, 8},
						{7, 4, 1, 8, 0, 2, 9, 3, 5, 6},
						{8, 3, 6, 0, 9, 1, 5, 2, 4, 7},
						{9, 2, 8, 1, 6, 7, 4, 0, 3, 5}
	};

	int RL[10][10];

	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			RL[L[i][j]][j] = i;
		}
	}

	int t[n];
	memset(t, 0, n*sizeof(int));

	for (int k=0; k<n; k++)
	{
		cout<<t[k]<<" ";
	}
	cout<<endl<<endl;;

	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			cout<<L[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			cout<<RL[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

#if 0
	for (int i=1; i<=n; i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
#endif


	int r =0;
	int m=0;

	int j = 0;
	int l = 0;
	int k = 0;

	int count = 0;

/*	VOL 4A Page 319 */

	set<int> row;
	

/* L1.	[Visit.] Visit the permutation a_1 a_2 ... a_n. */
L1: 
	r = a[1];

	row.clear();
	for (m=0; m<n; m++)
	{
		row.insert(RL[a[m+1]][m]);
	}

	if (row.size() == n)
	{
		t[a[1]]++;
	}

	count++;

#if 0
	for (int s=1; s<=n; s++)
	{
		cout<<a[s]<<" ";
	}
	cout<<endl;
#endif



/* L2.	[Find j.] Set j <- n -1. If a_j >= a_(j+1), decrease j by 1 repeatedly until 
		a_j < a_(j+1). Terminate the algorithm if j = 0. (At this point j is the smallest
		subscript such that we've already visited all permutations beginning with
		a_1 ... a_j. So the lexicographically next permutation will make a_j larger.)
*/	
L2:
	j = n-1;
	if (j==0) 
	{
		int sum = 0;
		for (int i=0; i<n; i++)
		{
			cout<<t[i]<<" ";

			sum += t[i];
		}
		cout<<"Total transversals: "<<sum<<endl;
		cout<<endl<<endl;

		cout<<"count: "<<count<<endl<<endl;

		return 0;
	}

	while (a[j] >= a[j+1])
	{
		j--;

		if (j==0)
		{
			int sum = 0;
			for (int i=0; i<n; i++)
			{
				cout<<t[i]<<" ";

				sum += t[i];
			}
			
			cout<<endl<<endl;

			cout<<"Total transversals: "<<sum<<endl;

			cout<<endl<<endl;
			
			cout<<"count: "<<count<<endl<<endl;

			return 0;
		}
	}
	

/* L3.	[Increase a_j.] Set l <- n. If a_j >= a_l, decrease l by 1 repeatedly until a_j < a_l.
		Then interchange a_j <-> a_l. (Since a_(j+1) >= ... >= a_n, element a_l is the 
		smallest element greater than a_j that can legitimately follow a_1 ... a_(j-1) in a 
		permutation. Before the interchange we had a_(j+1) >= ... >= a_(l-1) >= a_l > a_j >=
		a_(l+1) >= ... >= a_n; after the interchange, we have a_(j+1) >= ... >= a_(l-1) >= a_j >
		a_l >= a_(l+1) >= ... >= a_n.)
*/
L3:
	l = n;
	while (a[j] >= a[l])
	{
		l--;
	}

	int temp = a[j];
	a[j] = a[l];
	a[l] = temp;


/* L4.	[Reverse a_(j+1) ... a_n.] Set k <- j+1 and l <- n. Then, while k < l, interchange
		a_k <-> a_l and set k <- k+1, l <- l-1. Return to L1.

*/
L4:
	k = j+1;
	l = n;
	while (k<l)
	{
		int temp = a[k];
		a[k] = a[l];
		a[l] = temp;
		k++;
		l--;
	}

	goto L1;

}

