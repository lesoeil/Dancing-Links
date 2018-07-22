/*	Algorithm-L-7222.cpp
	
	Jacob Yang 22-July-2018 21:25

*/

#include <iostream>


using namespace std;

int main(int argc, char** argv)
{

	cout<<"Hello, Algorithm L (Satisfiability by DPLL with lookahead)"<<endl;

	return 0;

}


/*	Algorithm L (Satisfiability by DPLL with lookahead). Given nonempty clauses
	C_1 ⋀ ... ⋀ C_m of size <= 3, on n > 0 Boolean variables x_1 ... x_n, this algorithm 
	finds a solution if and only if the clauses are satisfiable. Its family of cooperating
	data structures is discussed in the text.

*/
int AlgorithmL()
{


L1: /*	[Initialize.] Record all binary clauses in the BIMP array and all ternary
		clauses in the TIMP array. Let U the number of distinct variables in unit
		clauses; terminate unsuccessfully if two unit clauses contradict each other,
		otherwise record all distince unit literals in FORCE[k] for 0 <= k < U. Set
		VAR[k] <- k+1 and INX[k+1] <- k for 0 <= k < n; and d <- F <- I <-
		ISTAMP <- 0. (Thinkd = depth, F = fixed variables, I = ISTACK size.)
	*/


L2:	/*	[New node.] Set BRANCH[d] <- -1. If U = 0, invoke Algorithm X below
		(which looks ahead for simplifications and also gathers data about how to 
		make the next branch). Terminate happily if Algorithm X finds all clauses
		satisfied; go to L15 if Algorithm X discovers a conflict; go to L5 if U > 0.
	*/



L3:	/*	[Choose l.] Select a literal l that's desirable for branching (see exercise
		168). If l = 0, set d <- d+1 and return L2. Otherwise set DEC[d] <- l,
		BACKF[d] <- F, BACKI[d] <- I, and BRANCH[d] <- 0.
	*/


L4:	/*	[Try l.] Set U <- 1, FORCE[0] <- l.
	*/

L5:	/*	[Accept near truths.] Set T <- NT, G <- E <- F, ISTAMP <- ISTAMP + 1,
		and CONFLICT <- L11. Perform the binary propagation routine (62) for
		l <- FORCE[0], ..., l <- FORCE[U - 1]; then set U <- 0.
	*/



L6:	/*	[Choose a nearby true L.] (At this point the stacked literals R_k are "really 
		true" for 0 <= k < G, and "nearby true" for G <= k < E. We want them all 
		to be really true.) If G = E, goto L10. Otherwise set L <- R_G, G <- G+1.
	*/


L7:	/*	[Promote L to real truth.] Set X <- |L| and VAR[X] <- RT + L & 1. Remove
		variable X from the free list and from all TIMP pairs (see exercise 137). Do
		step L8 for all pairs (u,v) in TIMP(L), then return to L6.
	*/


L8:	/*	[Consider u ∨ v.] (We have deduced that u or v must be true; five cases
		arise.) If either u or v is fixed true (in context T, which equals NT), do
		nothing. If both u and v are fixed false, goto CONFLICT. If u is fixed false 
		but v isn't fixed, perform (62) with l <- v. If v is fixed false but u isn't 
		fixed, perform (62) with l <- u. If neither u nor v is fixed, do step L9.
	*/


L9:	/*	[Exploit u ∨ v.] If ~v ∈ BIMP(~u), perform (62) with l <- u (because ~u 
		implies both v and ~v). Otherwise if v ∈ BIMP(~u), do nothing (because we 
		already have the clause u∨v). Otherwise if ~u ∈ BIMP(~v), perform (62) with 
		l <- v. Otherwise append v to BIMP(~u) and u to BIMP(~v). (Each change 
		to BIMIP means that (63) might be invoked. Exercise 139 explains how to 
		improve this step by deducing further implications called "compensation 
		resolvents.")
	*/



L10:	/* [Accept real truths.] Set F <- E. If BRANCH[d] >= 0, set d <- d+1 and go 
			to L2. Otherwise go to L3 if d > 0, to L2 if d = 0.
		*/


L11:	/* [Unfix near truths.] While E > G, set E <- E-1 and VAL[|R_E|] <- 0.
		*/


L12:	/* [Unfix real truths.] While E > F, do the following: Set E <- E - 1 and 
			X <- |R_E|; reactivate the TIMP pairs that involve X and restore X to the 
			free list (see exercise 137); set VAL[X] <- 0.
		*/


L13:	/*	[Downdate BIMPs.] If BRANCH[d] >= 0, do the following while I > BACKI[d]:
			Set I <- I - 1 and BSIZE(l) <- s, where ISTACK[I] = (l,s).
		*/


L14:	/* [Try again?] (We've discovered that DEC[d] doesn't work.) If BRANCH[d] = 
			0, set l <- DEC[d], DEC[d] <- l <- ~l, BRANCH[d] <- 1, and go back to L4.
		*/


L15:	/* [Backtrack.] Terminate unsuccessfully if d = 0. Otherwise set d <- d - 1,
			E <- F, F <- BACKF[d], and return to L12.
		*/


	return 0;
}


/*	Algorithm X (Lookahead for Algorithm L). This algorithm, which is invoked
	in step L2 of Algorithm L, uses the data structures of that algorithm together 
	with additional arrays of its own to explore properties of the current subproblem.
	It discovers U >= 0 literals whose values are forced, and puts them in the FORCE 
	array. It terminates either by (i) satisfying all clauses; (ii) finding a contradition;
	or (iii) computing heuristic scores H(l) that will allow step L3 to choose a good 
	literal for branching. In case (iii) it might also discover new binary clause.
*/

int AlgorithmX()
{
	return 0;
}


/*	Algorithm Y (Double lookahead for Algorithm X). This algorithm, invoked in 
	step X10, uses the same data structures (and a few more) to look ahead more 
	deeply. Parameters β and Y are explained above. Initially DFAIL(l) = 0 for all l.

*/
int AlgorithmY()
{
	return 0;
}
