/* Algorithm-Z-7221.cpp

	29-Apr 2019 20:50
	
	Jacob Yang

	Algorithm X (Exact cover via dancing links). This algorithm visits all solutions
	to a given exact cover problem, using the data structures just described. It also
	maintains a list x_0, x_1, ..., x_T of node pointer for backtracking, where T is
	large enough to accommodate one entry for each option in a solution. 

	Algorithm C (Exact covering with colors). This algorithm visits all solutions
	to a given XCC problem, using the same conventions as Algorithm X.


	Algorithm M (Covering with multiplicities and colors). This algorithm visits
	all solutions to a given MCC problem, extending Algorithm X and C.

	Algorithm Z (Dancing with ZDDs). Given an XCC problem as in Algorithm C,
	this algorithm outputs a free ZDD for the sets of options that satisfy it. The
	ZDD instructions {I_2, ..., I_s} have the form (ō? l_j : h_j) illustrated in (122), and
	I_s is the root. (But if the problem has no solutions, the algorithm terminates
	with s = 1, and the root is 0.) The data structures of Algorithm C are extended
	by a "memo cache" consisting of signatures S[j] and ZDD pointers Z[j]. Algorithm C's
	table of choices x_0 x_1 ... is joined by two new auxiliary tables m_0 m_1 ...
	and z_0 z_1 ..., indexed by the current level l.
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



Z3:
/*	Z3. [Choose i.]	At this point items i_1, ... , i_t still need to be covered, as in
		step C3 of Algorithm C. Choose one of them, and call it i.
*/



Z4:
/*	Z4.	[Cover i.] Cover item i using (12), and set x_l <- DLINK(i).	*/



Z5:
/*	Z5.	[Try x_l.] If x_l = i, go to Z7. Otherwise set p <- x_l + 1, and do the following
		while p ≠ x_l : Set j <- TOP(p); if j ≤ 0, set p <- ULINK(p); otherwise
		commit(p,j) and set p <- p+1. Set l <- l+1 and return to Z2.
*/



Z6:
/*	Z6.	[Try again.] Sete p <- x_l - 1, and do the following while p ≠ x_l: Set j <-
		TOP(p); if j ≤ 0, set o <- 1-j and p <- DLINK(p); otherwise uncommit(p,j)
		and set p <- p-1. If ϛ ≠ 0, set s <- s+1, output I_s = (ō? z_l : ϛ), and set
		z_l <- s. Set i <- TOP(x_l), x_l <- DLINK(x_l), and return to Z5.
*/



Z7:
/*	Z7.	[Backtrack.] Uncover item i using (14). Then set Z[m_l] <- z_l and ϛ <- z_l.
*/



Z8:
/*	Z8.	[Leave level l.] Terminate if l = 0. Otherwise set l <- l-1 and go to Z6.
*/

}

