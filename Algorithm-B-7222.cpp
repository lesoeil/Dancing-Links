/*  13-Mar-2018 Jacob Yang
COMBINATORIAL ALGORITHMS
SATISFIABILITY: BACKTRACKING ALGORITHMS

Lazy data structures.   Algorithm B.

	Here's the general idea: When we work on clauses F|L, the variables that occur in L
have known values, but the other variables do not. For example, in Algorithm A,
variable x_j is implicitly known to be either true of false when j<=d, but its value
is unknown when j>d. Such as situation is called a partial assignment. A partial
assignment is consistent with a set of clauses if no clause consists entirely of
false literals. Algorithms for SAT usually deal exclusively with consistent partial
assignments; the goal is to convert them to consistent total assignments, by 
gradually eliminating the unknown values.

	Thus every clause in a consistent partial assignment has at least one nonfalse
literal; and we can assume that such a literal appears first, when the clause is
represented in memory. Many nonfalse literals might be present, but only one of 
them is designated as the clause's "watchee." When a watched literal becomes
false, we can find another nonfalse literal to swap into its place -- unless the
clause has been reduced to a unit, a clause of size 1.



*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>

#include "Algorithm-B-7222.h"

using namespace std;


int main(int argc, char** argv)
{
	int nRet;

	if ((argc <2) || (argc>=3))
	{
		cout<<"Usage: sat datafile"<<endl;
		cout<<"datafile is the file name of raw data including n and clauses."<<endl;
		return 0;
	}

	string clause_file(argv[1]);

	//auto_ptr<CLAUSE> 
	CLAUSE* pClause((new CLAUSE(clause_file)));
	nRet = pClause->algoB();

	//cout<<"Hello Algorithm B!"<<endl;
	return nRet;
}



CLAUSE::CLAUSE(string& data_file)
		:fileName(data_file),
		cell(),
		mClauses(-1),
		n(-1)
{}

CLAUSE::~CLAUSE()
{

}


int CLAUSE::debugPrint()
{
	/*
	cout<<"Total number cells: "<<cell.size()<<endl;
	cout<<"Total number START: "<<START.size()<<endl;
	cout<<"Total number LINK: "<<LINK.size()<<endl;
	cout<<"Total number W: "<<W.size()<<endl;

	for (int s=0; s<cell.size(); s++)
	{
		cout<<s<<" L: "<<cell[s].L<<endl;
	}
	*/

	for (int s=2; s<=2*n+1; s++)
	{
		cout<<"Literal: "<<s<<"       -->                   W["<<s<<"]: "<<W[s]<<endl;
	}


	cout<<"Clause "<<0<<":        -->   START["<<0<<"]: "<<START[0]<<" LINK["<<0<<"]: "<<LINK[0]<<endl;
	for (int c=1; c<=START.size(); c++)
	{
		cout<<"Clause "<<c<<": ";
		for (int s=START[c]; s<START[c-1]; s++)
		{
			cout<<cell[s].L<<" ";
		}

		cout<<" -->   START["<<c<<"]: "<<START[c]<<" LINK["<<c<<"]: "<<LINK[c];

		cout<<endl;
	}

	/*
	for(int i=0; i<=START.size(); i++)
	{
		cout<<"Clause "<<i<<" -->   START["<<i<<"]: "<<START[i]<<" LINK["<<i<<"]: "<<LINK[i]<<endl;
	}
	*/

	return 0;
}

/*	Algorithm B (Satisfiability by watching). Given nonempty clauses C_1 ^ .... ^ C_m
	on n > 0 Boolean variables x_1 ... x_n, represented as above, this algorithm finds
	a solution if and only if the clauses are satisfiable. It records its current progress
	in an array m_1 ... m_n of "moves," whose significance was explained above.
*/

/*	Exercises
	124. [21] Spell out the low-level link field operations that are sketched in step B3.
	125. [20] Modify Algorithm B so that it finds all satisfying assignments of the clauses.
*/
int CLAUSE::algoB()
{
	int d = -1;
	int l = -1;
	vector<int> m;
	int l_inv = -1;
	int nRet = -1;
	int watchee = -1;

	int temp = -1;
	int next = -1;

//	00. To read number of literals and 3SAT clauses from file.
	nRet = extract();
	if (nRet < 0)
	{
		cout<<"Open file "<<fileName<<" failed!!!"<<endl;
		return nRet;
	}

	//debugPrint();

	//n should has already been initialized before here.
	m.insert(m.begin(), n+1, -1);

B1: /*	[Initialize.] Set d <- 1. */
	/*	d is a temporary variable/index to hold the depth (the number of liberals) 
		that the algorithm B will check. At B1, d is initialized to 1, which means 
		that at the start of this algorithm the 1st literal will be checked/covered.  
	*/
	d = 1;

B2: /*	[Rejoice or choose.] If d > n, terminate successfully. Otherwise set m_d <- 
		[W_(2d) = 0 or W_(2d+1) != 0] and l <- 2d + m_d. */

	/*	At the start of B2, d will be compared to n, the total number of variables 
		( number of literals = 2 * number of variables as we know, |l| and ~|l|),
		if (d > n), then it means that (d-1) >= n strictly different literals have 
		been covered and all the clauses have been converted to consistent total
		assignments. That is to say, all clauses hold truth when all variables have 
		been assigned solid value (either 0 or 1, false or true). 

		else if (d<=n), then it means that we need continue to do the job of finding
		consistent total assignments.
	*/

	/*	18-June-2018
		The only case that we assign m_d to 0 is that:
			both (W_(2d) != 0) and (W_(2d+1) ==0)
		which means that there are certain clause watches literal (~|l|), but there 
		is no clause watching literal |l| at this moment.

		The cases that we assign m_d to 1 is that:
			either (W_(2d)==0) or (W_(2d+1) != 0)
		which means that there is no clause watching literal (~|l|) at this moment, 
		or when there is at least one clause watching literal |l|.

		watching ~|l|	watching |l|	m_d
			0				0			 1
			0				1			 1
			1				0			 0
			1				1			 1

		The logic seems to be that Algorithm B take the priority to choose |l| first
		unless there is no clause watching |l| and there is at least clause watching ~|l|
	*/

	if (d > n)
	{
		//cout<<"successfully Finished!"<<endl;
		for (int i=1; i<d; i++)
		{
			cout<<m[i]<<" ";
		}
		cout<<endl;

		/* 	Exercise
			125. [20] Modify Algorithm B so that it finds all satisfying assignments of the clauses.
		*/
		goto B6;

		//return 0;
	}
	else
	{
		m[d] = ((W[2*d]==0) || (W[2*d+1]!=0))? 1:0;
		l = 2*d + m[d];
	}


B3: /*	[Remove ~l if possible.] For all j such that ~l is watched in C_j, watch another
		literal of C_j. But go to B5 if that can't be done. (See exercise 124.) */

	//cout<<"d: "<<d<<"  l:"<<l<<endl;
	/*	First we want to make sure that all clauses who watch (~l) 
	*/
	watchee = W[l^1];
	while (watchee)
	{
		if (cell[START[watchee]].L > cell[START[watchee-1]-1].L)
		{
			goto B5;
		}

		watchee = LINK[watchee];
	}


	for (int i=1; i<=START.size(); i++)
	{
		if ((cell[START[i]].L)>l)
		{
			for (int s=START[i]+1; s<=START[i-1]-1; s++)
			{
				if (l == cell[s].L)
				{
					//cout<<"Before swap: "<<cell[START[watchee]].L<<"  "<<cell[s].L<<endl;
					swap(cell[START[i]].L, cell[s].L);
					//cout<<"After swap: "<<cell[START[watchee]].L<<"  "<<cell[s].L<<endl;
					break;
				}
			}

			if (l == cell[START[i]].L)
			{
				int temp = LINK[i];
				LINK[i] = W[l];
				W[l] = i;	
			}
		}
	}

	watchee = W[l^1];
	while (watchee)
	{
		for (int s=START[watchee]+1; s<=START[watchee-1]-1; s++)
		{
			if (cell[START[watchee]].L < cell[s].L)
			{
				//cout<<"Before swap: "<<cell[START[watchee]].L<<"  "<<cell[s].L<<endl;
				swap(cell[START[watchee]].L, cell[s].L);
				//cout<<"After swap: "<<cell[START[watchee]].L<<"  "<<cell[s].L<<endl;
				break;
			}
		}

		int temp = LINK[watchee];
		LINK[watchee] = W[cell[START[watchee]].L];		
		W[cell[START[watchee]].L] = watchee;

		watchee = temp;
	}

/*	Above is my implementation of 7.2.2.2 Algorithm B.B3 before snooping on the answer to 124.
*/

/*	Exercises
	124. [21] Spell out the low-level link field operations that are sketched in step B3.
*/

/*	Answer to 124.
	124. Set j <- W_(~l). While j != 0, a literal other than (~l) should be watched in clause j, so
	we do the following: Set i <- START(j), i' <- START(j-1), j' <- LINK(j), k <- i + 1.
	While k < i', set l' <- L(k); if l' isn't false (that is, if |l'| > d or l' + m_(|l'|) is even,
	see (57)), set L(i) <- l', LINK(j) <- W_(l'), W_(l') <- j, j <- j', and exit the loop
	on k; otherwise set k <- k+1 and continue that loop. If k reaches i', however, we
	cannot stop watching ~l; so we set W_(~l) <- j, exit the loop on j, and go on to step B5.
*/


B4: /*	[Advance.] Set W_(~l) <- 0, d <- d+1, and return to B2. */
	temp = W[l^1];
	W[l^1] = 0;

	while (temp != 0)
	{
		next = LINK[temp];
		LINK[temp] = 0;
		temp = next;
	}

	d = d + 1;
	goto B2;

B5: /*	[Try again.] If m_d < 2, set m_d <- 3 - m_d, l <- 2d + (m_d & 1), and go to B3.*/
	if (m[d] < 2)
	{
		m[d] = 3 - m[d];
		l = 2*d + (m[d] & 1);
		goto B3;
	}

B6: /*	[Backtrack.] Terminate unsuccessfully if d = 1 (the clauses are unsatisfi-
		able). Otherwise set d <- d - 1 and to back to B5. */
	if (d==1)
	{
		//cout<<"Failed to find. The clauses seems unsatisfiable???"<<endl;
		//debugPrint();
		return -1;
	}
	else
	{
		d = d-1;
		goto B5;
	}


	return 0;
}


int CLAUSE::extract()
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
	mClauses = i_index;

	//cout<<"raw.size(): "<<raw.size()<<endl;
	//set<int>::const_iterator it;
	for (int i=0; i<=1; i++)
	{
		cell.push_back(CELL());
		cell[i].L = -1;
		W.push_back(0);
	}
	

	int tail[2+2*n];
	for (int i=2; i<2*n+2; i++)
	{
		cell.push_back(CELL());
		cell[i].L = -1;
		W.push_back(0);
	}



	int sidx = 2+2*n;
	for(int i=0; i<raw.size(); i++)
	{
		START.push_back(0);
		LINK.push_back(0);
	}

	for (int i=raw.size()-1; i>=0; i--)
	{
		//int j = 0;

		START[i+1] = sidx;		
		for (auto val: *raw[i])
		{
			cell.push_back(CELL());
			cell[sidx].L = val;
			sidx++;
			//j++;cout<<j<<":";
			//cout<<val<<" ";
		}
		LINK[i+1] = W[cell[START[i+1]].L];
		W[cell[START[i+1]].L] = i+1;
		//cout<<endl;
	}

	START[0] =  sidx;
	/*	
	cout<<"sidx: "<<sidx<<endl;
	START[0] =  sidx;
	for (int s=2; s<=2*n+1; s++)
	{
		cout<<"W["<<s<<"]: "<<W[s]<<endl;
	}

	for (int s=0; s<sidx; s++)
	{
		cout<<s<<" L: "<<cell[s].L<<endl;
	}

	for(int i=0; i<=raw.size(); i++)
	{
		cout<<"START["<<i<<"]: "<<START[i]<<" LINK["<<i<<"]: "<<LINK[i]<<endl;
	}
	*/

	/*
	while (getline(fs, line))
	{
		cout<<line<<endl;
	}
	*/

	return 0;
}