/* Algorithm-Z-7221.cpp

	29-Apr 2019 20:50
	
	Jacob Yang
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main()
{
	cout<<"Hello Dancing with ZDDs."<<endl;

	return 0;
}


/*	Algorithm Z (Dancing with ZDDs). Given an XCC problem as in Algorithm C,
	this algorithm outputs a free ZDD for the sets of options that satisfy it. The
	ZDD instructions {I_2, ... , I_s} have the form (~o_j ? l_j : h_j) illustrated in (122), and
	I_s is the root. (But if the problem has no solutions, the algorithm terminates
	with s = 1, and the root is 0.) The data structures of Algorithm C are extended
	by a "memo cache" consisting of signatures S[j] and ZDD pointers Z[j]. Algorithm C's
	table of choices x_0 x_1 ... is joined by two new auxiliary tables m_0 m_1 ...
	and z_0 z_1 ..., indexed by the current level l.
*/
int algoZ()
{


Z1:
/*	Z1. [Initialize.] Set the problem up in memory, as in step C1 of Algorithm C.
		Also set N to the number of items, Z to the last spacer address, l <- 0,
		S[0] <- 0, Z[0] <- 1, m <- 1, s <- 1.
 */



Z2:
/*	Z2. [Enter level l.] Form a "signature" σ that characterizes the current subprob-
		lem (see below). If σ = S[t] for some t (this is a "cache hit"), set ϛ <- Z[t]
		and go to Z8. Otherwise set S[m] <- σ, m_l <- m, z_l <- 0, and m <- m+1.
*/




}

/*
*/