/*	Algorithm-H-7215.cpp */


#include <iostream>
#include <sstream>

#include "Algorithm-H-7215.h"

using namespace std;

int main(int argc, char* argv[]) {

	//cout<<"Back to C++! ^_^"<<endl;

	int n = 4;

	if (argc >= 2) {	
		istringstream ss(argv[1]);
		int x;
		if (!(ss>>x)) {
			cerr<<"Invalid input for number: "<<argv[1]<<endl;
		} else if (!ss.eof()) {
			cerr<<"Character appending to number digits: "<<argv[1]<<endl;
		}

		n = x;
	} else {
		cout<<"No number input so take default value of number: "<<n<<endl;
	}

	//cout<<"Before call function algoH(n):"<<endl<<endl;
	algoH(n);
	//cout<<"After call function algoH(n)."<<endl;

	return 0;
}

/*	Algorithm H (Restricted growth strings in lexicographic order.) Given n ≥ 2, 
	this algorithm generates all partitions of { 1,2,...,n } by visiting all strings
	a_1 a_2 ... a_n that satisfy the restricted growth codition (4). We maintain an 
	auxiliary array b_1 b_2 ... b_n, where b_(j+1) = 1 + max(a_1, ..., a_j); the value of b_n is
	actually kept in a separate variable, m, for efficiency.
*/
int algoH(int n) {
	//cout<<"Entry of Algorithm-H-7215."<<endl<<endl;

	int a[n+1];
	int b[n+1];
	int m = -1;
	int j = -1;
	int count = 0;

H1:
/*	H1. [Initialize.] Set a_1 ... a_n <-- 0 ... 0, b_1 ... b_(n-1) <-- 1 ... 1, and m <-- 1. */
	
	//memset(a, 0, (n+1)*sizeof(int));
	//memset(b, 1, (n+1)*sizeof(int));

	for (int i=0; i<=n; i++) {
		a[i] = 0;
		b[i] = 1;
	}

	m = 1;

H2:
/*	H2. [Visit.] Visit the restricted growth string a_1 ... a_n, which represents a 
		partition into m+[a_n = m] blocks. Then go to H4 if a_n = m.	*/
	count++;
	//cout<<"Partition "<<count<<" with Block: "<<m+(a[n]==m)<<endl;
	
	/*
	for (const auto& e : a) {
		cout<<e<<" ";
	}*/

	for (int i=1; i<=n; i++) {
		cout<<a[i]<<" ";
	}

	cout<<endl;

	if (a[n] == m) {
		goto H4;
	}


H3:
/*	H3. [Increase a_n.] Set a_n <-- a_n + 1 and return to H2. */
	a[n] +=1;
	goto H2;


H4:
/*	H4. [Find j.] Set j = n-1; then, while a_j = b_j, set j <-- j-1. */
	j = n-1;

	while (a[j] == b[j]) {
		j = j-1;
	}


H5:
/*	H5. [Increase a_j.] Terminate if j = 1. Otherwise set a_j <-- a_j + 1. */
	if (j==1) {
		cout<<"Terminate successfully as j == 1."<<endl;
		cout<<"Total number of partitions is "<<count<<endl;
		return 0;
	}
	else {
		a[j] = a[j] + 1;
	}


H6:
/*	H6. [Zero out a_(j+1) ... a_n.] Set m <-- b_j + [a_j = b_j] and j <-- j+1. Then, while 
		j < n, set a_j <-- 0, b_j <-- m, and j <-- j+1. Finally set a_n <-- 0 and to back
		to H2.	*/
	m = b[j] + (a[j]==b[j]);
	j = j+1;

	while (j<n) {
		a[j] = 0;
		b[j] = m;
		j = j+1;
	}

	a[n] = 0;
	goto H2;


	cout<<"Unexpected Exit of Algorithm-H-7215 with m = "<<m<<" and j = "<<j<<endl;
	cout<<"Number of partitions before unexpected exit is "<<count<<endl;
	return 0;
}