/*	Algorithm-H-7215.cpp */


#include <iostream>

#include "Algorithm-H-7215.h"

using namespace std;

int main() {

	cout<<"Back to C++! ^_^"<<endl;

	int n = 4;

	cout<<"Before call function algoH(n):"<<endl<<endl;
	algoH(n);
	cout<<"After call function algoH(n)."<<endl;

	return 0;
}

/*	Algorithm H (Restricted growth strings in lexicographic order.) Given n ≥ 2, 
	this algorithm generates all partitions of { 1,2,...,n } by visiting all strings
	a_1 a_2 ... a_n that satisfy the restricted growth codition (4). We maintain an 
	auxiliary array b_1 b_2 ... b_n, where b_(j+1) = 1 + max(a_1, ..., a_j); the value of b_n is
	actually kept in a separate variable, m, for efficiency.
*/
int algoH(int n) {
	cout<<"Entry of Algorithm-H-7215."<<endl<<endl;

	int a[n+1];
	int b[n+1];
	int m;

H1:
/*	H1. [Initialize.] Set a_1 ... a_n <-- 0 ... 0, b_1 ... b_(n-1) <-- 1 ... 1, and m <-- 1. */
	
	memset(a, 0, (n+1)*sizeof(int));
	memset(b, 1, (n+1)*sizeof(int));
	m = 1;

H2:
/*	H2. [Visit.] Visit the restricted growth string a_1 ... a_n, which represents a 
		partition into m+[a_n = m] blocks. Then go to H4 if a_n = m.	*/
	cout<<"Block: "<<m+(a[n]==m)<<endl;
	for (const auto& e : a) {
		cout<<e<<" ";
	}
	cout<<endl;


H3:
/*	H3. [Increase a_n.] Set a_n <-- a_n + 1 and return to H2. */



H4:
/*	H4. [Find j.] Set j = n-1; then, while a_j = b_j, set j <-- j-1. */



H5:
/*	H5. [Increase a_j.] Terminate if j = 1. Otherwise set a_j <-- a_j + 1. */



H6:
/*	H6. [Zero out a_(j+1) ... a_n.] Set m <-- b_j + [a_j = b_j] and j <-- j+1. Then, while 
		j < n, set a_j <-- 0, b_j <-- m, and j <-- j+1. Finally set a_n <-- 0 and to back
		to H2.	*/

	cout<<"Exit of Algorithm-H-7215."<<endl<<endl;
	return 0;
}