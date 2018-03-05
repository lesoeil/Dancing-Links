/*  03-Mar-2018
COMBINATORIAL ALGORITHMS
SATISFIABILITY: BACKTRACKING ALGORITHMS

	Any instance of SAT that involves at least one variable can be solved sys-
tematically by choosing a variable and setting it to 0 or 1. Either of those choices
gives us a smaller instance of SAT; so we can continue until reaching either an 
empty instance -- which is trivially satisfiable, because no clauses need to be 
satisfied -- or an instance that contains an empty clause. In the latter case we
must back up and reconsider one of our earlier choices, proceeding in the same 
fashion until we either succeed or exhaust all the possibilities.

	In general if F is any set of clauses and if l is any literal, then F|l (read
"F given l" or "F conditioned on l") is the set of clauses obtained from F by
	removing every clause that contains l; and
	removing l-reverse from every clause that contains l-reverse.


*/


#include<iostream>

using namespace std;


int main(int argc, char** argv)
{

	cout<<"Hello Satisfiability!"<<endl;
	return 0;
}



int algoA()
{
/*	Algorithm A (Satisfiability by backtracking). Giving nonempty clauses C_1 & ... & 
	C_m on n > 0 Boolean variables x_1 ... x_n, represented as above, this algorithm 
	finds a solution if and only if the clauses are satisfiable. It records its current
	progress in an array m_1 ... m_n of "moves," whose significance is explained below.
*/


A1:
/*	A1. [Initialize.] Set a <- m and d <- 1. (Here a represents the number of active
		clauses, and d represents the depth-plus-one in an implicit search tree.)		*/


A2:
/*	A2. [Choose.] Set l <- 2d. If C(l) <= C(l+1), set l <- l+1. Then sete m_d <-
		(l & 1) + 4[C(l XOR 1)=0]. (See below.) Terminate successfully if C(l) =a.		*/


A3:
/*	A3. [Remove ~l.] Delete ~l from all active clause; but goto A5 if that would make
		a clause empty. (We want to ignore ~l, because we're making l true.)			*/


A4:
/*	A4. [Deactivate l's clauses.] Suppress all clauses that contain l. (Those clauses
		are now satisfied.) Them set a <- a - C(l), d <- d+1, and return A2.			*/


A5:
/*	A5. [Try again.] If m_d < 2, set m_d <- 3 - m_d, l <- 2d + (m_d & 1), and go to A3. */


A6:
/*	A6. [Backtrack.] Terminate unsuccessfully if d = 1 (the clauses are unsatisfi-
		able). Otherwise set d <- d - 1 and l <- 2d + (m_d & 1).						*/


A7:
/*	A7. [Reactivate l's clauses.] Set a <- a + C(l), and unsuppress all clauses that
		contain l. (Those clauses are now unsatisfied, because l is no longer true.)	*/


A8:
/*	A8. [Unremove ~l.] Reinstate ~l in all the active clauses that contain it. Then go
		back to A5.
*/


	return 0;
}


