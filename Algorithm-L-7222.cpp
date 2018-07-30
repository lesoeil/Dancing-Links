/*	Algorithm-L-7222.cpp

	Most of the comments are texts copied from TAOCP F6A 7.2.2.2
	
	Jacob Yang 22-July-2018 21:25

*/

#include "Algorithm-L-7222.h"

using namespace std;

int main(int argc, char** argv)
{
	int nRet;

	if ((argc <2) || (argc>=3))
	{
		cout<<"Usage: algoL datafile"<<endl;
		cout<<"datafile is the file name of raw data including n and 3SAT (2SAT)."<<endl;
		return 0;
	}

	string clause_file(argv[1]);

	//auto_ptr<CLAUSE> 
	DPLLAD* pDP((new DPLLAD(clause_file)));
	nRet = pDP->AlgorithmL();

	//cout<<"Hello, Algorithm L (Satisfiability by DPLL with lookahead)"<<endl;

	return 0;

}


DPLLAD::DPLLAD(string& data_file)
		:fileName(data_file)
{

}

/*	Algorithm L (Satisfiability by DPLL with lookahead). Given nonempty clauses
	C_1 ⋀ ... ⋀ C_m of size <= 3, on n > 0 Boolean variables x_1 ... x_n, this algorithm 
	finds a solution if and only if the clauses are satisfiable. Its family of cooperating
	data structures is discussed in the text.

*/
int DPLLAD::AlgorithmL()
{
	

L1: /*	[Initialize.] Record all binary clauses in the BIMP array and all ternary
		clauses in the TIMP array. Let U the number of distinct variables in unit
		clauses; terminate unsuccessfully if two unit clauses contradict each other,
		otherwise record all distince unit literals in FORCE[k] for 0 <= k < U. Set
		VAR[k] <- k+1 and INX[k+1] <- k for 0 <= k < n; and d <- F <- I <-
		ISTAMP <- 0. (Thinkd = depth, F = fixed variables, I = ISTACK size.)
	*/

	/* Read clauses from dat file: Fill FORCE, BIMP and TIMP. Assign U, BSIZE and TSIZE. */
	extract();

	/* TODO: Terminate unsuccessfully if two unit clauses contradict each other. */
	for (auto x: FORCE)
	{
		if (FORCE.find(x^1) != FORCE.end())
		{
			cout<<"Conflict liberals "<<x<<" and "<<(x^1)<<" found in unit literals FORCE!"<<endl;
			cout<<"Terminate unsuccessfully!!!"<<endl;
			return -1;
		}
	}

	// VAR and INX
	INX.push_back(-1);
	for (int k=0; k<n; k++)
	{
		VAR.push_back(k+1);
		INX.push_back(k);

		BRANCH.push_back(-1);
	}


	// d, F, I, ISTAMP
	d = 0;
	F = 0;
	I = 0;
	ISTAMP = 0;


L2:	/*	[New node.] Set BRANCH[d] <- -1. If U = 0, invoke Algorithm X below
		(which looks ahead for simplifications and also gathers data about how to 
		make the next branch). Terminate happily if Algorithm X finds all clauses
		satisfied; go to L15 if Algorithm X discovers a conflict; go to L5 if U > 0.
	*/
	BRANCH[d] = -1;

	if (U==0)
	{	
		bool bFindConflict = false;
		bFindConflict = AlgorithmX();
		if (bFindConflict)
		{
			goto L15;
		}
		else
		{
			// Terminate happily since Algorithm X finds all clauses satisfied.
			cout<<"Congratulations!!! All clauses are satisfiled! ^_^"<<endl;
			return 0;
		}
	}
	else if (U > 0)
	{
		goto L5;
	}



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

bool DPLLAD::AlgorithmX()
{
	bool bConflict = true;
	int N = 0;

X1:	/* [Satisfied?] If F = n, terminate happily (no variables are free).
	*/

	if (F == n)
	{
		cout<<"F: "<<F<<" is equal to n: "<<n<<endl;
		cout<<"No variables are free. Terminate happily."<<endl;
		bConflict = true;
		return bConflict;
	}


X2:	/*	[Compile rough heuristics.] Set N = n - F and use (65) to compute a 
		rough score h(l) for each free literal l.
	*/
	N = n - F;
	//cout<<"N: "<<N<<"   n: "<<n<<"  F: "<<F<<endl;


X3:	/*	[Preselect candidates.] Let C be the current number of free variables that 
		are "participants," and put them into the CAND array. If C = 0, set
		C <- N and put all free variables into CAND; terminate happily, however, 
		if all clauses are satisfied (see exercise 152). Give each variable x in CAND 
		the rating r(x) = h(x)h(~x). Then while C > 2C_(max) (see (66)), delete all 
		elements of CAND whose rating exceeds the mean rating; but terminate this 
		loop if no element are actually deleted. Finally, if C > C_(max), reduce C to 
		C_(max) by retaining only top-ranked candidates. (See exercise 153.)
	*/


X4:	/*	[Nest the candidates.] Construct a lookahead forest, represented in LL[j] 
		and LO[j] for 0 <= j < S and by PARENt pointers (see exercise 155).
	*/


X5:	/*	[Prepare to explore.] Set U' <- j' <- BASE <- j <- 0 and CONFLICT <- X13.
	*/


X6:	/*	[Choose l for lookahead.] Set l <- LL[j] and T <- BASE + LO[j]. Set 
		H(l) <- H(PARENT(l)), where H(⋀) = 0. If l is not fixed in context T, go to 
		X8. Otherwise, if l is fixed false but not proto false, do step X12 with l <- ~l.
	*/

X7:	/*	[Move to next.] If U > U', set U' <- U and j' <- j. Then set j <- j+1. If 
		j = S, set j <- 0 and BASE <- BASE + 2S. Terminate normally if j = j', or 
		if j = 0 and BASE +  2S >= PT. Otherwise return to X6.
	*/

X8:	/*	[Compute sharper heuristic.] Perform (72). Then if w > 0, set H(l_0) <- 
		H(l_0) + w and go to X10.
	*/

X9:	/*	[Exploit an autarky.] If H(l_0) = 0, do step X12 with l <- l_0. Otherwise gen-
		erate the new binary clause l_0 ∨ ~PARENT(l_0). (Exercise 166 explains why.)
	*/

X10:	/*	[Optionally look deeper.] Perform Algorithm Y below.
		*/

X11:	/*	[Exploit necessary assignments.] Do step X12 for all literals l ∈ BIMP(~l_0) 
			that are fixed true but not proto true. Then go to X7. (See exercise 167.)
		*/


X12:	/*	[Force l.] Set FORCE[U] <- l, U <- U+1, T' <- T, and perform (72) with 
			T <- PT. Then set T <- T'. (This step is a subroutine, used by other steps.)
		*/


X13:	/*	[Recover from conflict.] If T < PT, do step X12 with l <- ~l_0 and go to X7.
			Otherwise terminate with a contradiction.
		*/


	return false;
}


/*	Algorithm Y (Double lookahead for Algorithm X). This algorithm, invoked in 
	step X10, uses the same data structures (and a few more) to look ahead more 
	deeply. Parameters β and Y are explained above. Initially DFAIL(l) = 0 for all l.

*/
int DPLLAD::AlgorithmY()
{

Y1:	/*	[Filter.] Terminate if DFAIL(l_0) = ISTAMP, or if T + 2S(Y + 1) > PT.
		Otherwise, if H(l_0) <= t, set t <- βt and terminate.
	*/


Y2:	/*	[Initialize.] Set BASE <- T - 2, LBASE <- BASE + 2S*Y, DT <- LBASE + LO[j], 
		i <- ^j' <- ^j <- 0, E <- F, and CONFLICT <- Y8. Perform (62) with l <- l_0 
		and T <- Dt.
	*/

Y3:	/*	[Choose l for double look.] Set l <- LL[j] and T <- BASE + LO[j]. If l is not 
		fixed in context T, go to Y5. Otherwise, if l is fixed false but not Dfalse, do 
		step Y7 with l <- ~l.
	*/


Y4:	/*	[Move to next.] Set ^j <- ^j + 1. If ^j = S, set ^j <- 0 and BASE <- BASE + 2S.
		Go to Y6 if ^j' = ^j, or if ^j = 0 and BASE = LBASE. Otherwise return to Y3.
	*/


Y5:	/*	[Look ahead.] Perform (73), and return to Y4 (if no conflict arises).
	*/


Y6:	/*	[Finish.] Generate new binary clauses (~l_0 ∨ W_k) for 0 <= k < i. Then set 
		BASE <- LBASE, T <- Dt, t <- H(l_0), DFAIL(l_0) <- ISTAMP, CONFLICT <- 
		X13, and terminate.
	*/


Y7:	/*	[Make ^l_0 false.] Set ^j' <- ^j, T' <- T, and perform (73) with l <- ^l_0 and 
		T <- DT. Then set T <- T', W_i <- ^l_0, i <- i+1. (This step is a subroutine.)
	*/


Y8:	/*	[Recover from conflict.] If T < DT, do step Y7 with l <- ~LL[^j] and go 
		to Y4. Otherwise set CONFLICT <- X13 and exit to X13.
*/

	return 0;
}


int DPLLAD::extract()
{
	//cout<<fileName<<endl;

	fstream fs;
	fs.open(fileName.c_str(), fstream::in);
	if ((fs.rdstate() & std::fstream::failbit) != 0)	
	{
		cout<<"Fail to open file \""<<fileName<<"\"."<<endl;
		cout<<"Please check whether file exist or not."<<endl;
		cout<<"Or whether process calling has the rights to open it or not."<<endl;
		return -2;
	}


	string line;
	
	getline(fs, line);
	//cout<<line<<endl;

	istringstream buf(line);
	istream_iterator<string> beg(buf);
	istream_iterator<string> end;

	vector<string> tokens(beg, end);

	for (auto& s: tokens)
	{
		//cout<<s<<" ";
		n = std::stoi(s);
		//cout<<"number of literals n is:"<<n<<endl;
	}
	//cout<<endl;

	for (int i=0; i<2*n+2; i++)
	{
		TIMP.push_back(list<PAIRLINK*>());
		TSIZE.push_back(0);
		BIMP.push_back(set<int>());
		BSIZE.push_back(0);
	}

	#if 0
	for (int i=0; i<2*n+2; i++)
	{
		cout<<"TIMP["<<i<<"].size(): "<<TIMP[i].size()<<endl;
		cout<<"BIMP["<<i<<"].size(): "<<BIMP[i].size()<<endl;
	}
	#endif
	

	vector<set<int, less<int>>* > raw;
	int i_index=0;

	while (getline(fs, line))
	{
		istringstream buf(line);
		istream_iterator<string> beg(buf);
		istream_iterator<string> end;

		vector<string> tokens(beg, end);
		if (tokens.size()<=0)
		{
			continue;
		}

		set<int, less<int>>* its = new set<int, less<int>>; 
		raw.push_back(its);
		
		for (auto& s: tokens)
		{
			//cout<<s<<" ";
			raw[i_index]->insert(std::stoi(s));
		}
		//cout<<endl;
		i_index++;
	}

	//cout<<"i_index: "<<i_index<<endl;
	m = i_index;

	//cout<<"raw.size(): "<<raw.size()<<endl;
	//set<int>::const_iterator it;
	for (int i=0; i<=1; i++)
	{
		
	}
	

	//int tail[2+2*n];
	for (int i=0; i<m; i++)
	{
		cout<<(*raw[i]).size()<<": ";
		for (auto x: *raw[i])
		{
			cout<<x<<" ";
		}
		cout<<endl;
		
		if (1 == (*raw[i]).size())
		{
			int u;

			for (auto x: *raw[i])
			{
				u = x;
			}

			FORCE.insert(u);
		}
		else if (2 == (*raw[i]).size())
		{
			int temp[2];
			int j = 0;

			for (auto x: *raw[i])
			{
				//cout<<"x: "<<x<<" ";
				temp[j] = x;
				//cout<<"temp["<<i<<"]: "<<temp[i]<<" ";
				j++;
			}

			int u = temp[0];
			int v = temp[1];

			BIMP[u^1].insert(v);
			BIMP[v^1].insert(u);
		}
		else if (3 == (*raw[i]).size())
		{
			int temp[3];
			int j = 0;

			for (auto x: *raw[i])
			{
				//cout<<"x: "<<x<<" ";
				temp[j] = x;
				//cout<<"temp["<<i<<"]: "<<temp[i]<<" ";
				j++;
			}

			int u = temp[0];
			int v = temp[1];
			int w = temp[2];

			//cout<<"u:"<<u<<"  v:"<<v<<"  w:"<<w<<endl;

	   		PAIRLINK* u_sharp = new PAIRLINK(v,w, NULL);
	   		PAIRLINK* v_sharp = new PAIRLINK(w,u, NULL);
	   		PAIRLINK* w_sharp = new PAIRLINK(u,v, NULL);

	   		u_sharp->LINK = v_sharp;
	   		v_sharp->LINK = w_sharp;
	   		w_sharp->LINK = u_sharp;

	   		TIMP[u^1].push_back(u_sharp);
	   		TIMP[v^1].push_back(v_sharp);
	   		TIMP[w^1].push_back(w_sharp);
		}
		else
		{

		}

	}

	for (int i=2; i<2*n+2; i++)
	{
		TSIZE[i] = TIMP[i].size();
		BSIZE[i] = BIMP[i].size();
		U = FORCE.size();
	}

	debugPrint();

	int sidx = 2+2*n;
	for(int i=0; i<raw.size(); i++)
	{
	
	}

	for (int i=raw.size()-1; i>=0; i--)
	{
		//int j = 0;

		for (auto val: *raw[i])
		{
	
			sidx++;
			//j++;cout<<j<<":";
			//cout<<val<<" ";
		}
		
		//cout<<endl;
	}

	return 0;
}


PAIRLINK::PAIRLINK(int x, int y, PAIRLINK* p):
v(x),
w(y),
LINK(p)
{

}


int DPLLAD::debugPrint()
{
	for (int i=2; i<2*n+2; i++)
	{
		cout<<"TIMP["<<i<<"].size(): "<<TIMP[i].size()<<endl;
		for (auto x: TIMP[i])
		{
			cout<<x->v<<" "<<x->w<<" "<<x->LINK<<endl;
		}
	}

	for (int i=2; i<2*n+2; i++)
	{
		cout<<"BIMP["<<i<<"].size(): "<<BIMP[i].size()<<endl;
		cout<<"Literals in BIMP["<<i<<"]: ";
		for (auto x: BIMP[i])
		{
			cout<<x<<" ";
		}
		cout<<endl;
	}

	{
		cout<<"FORCE.size(): "<<FORCE.size()<<endl;
		cout<<"Literals in FORCE: ";
		for (auto x: FORCE)
		{
			cout<<x<<" ";
		}
		cout<<endl;
	}

	return 0;
}