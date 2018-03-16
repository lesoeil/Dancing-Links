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
	if ((argc <2) || (argc>=3))
	{
		cout<<"Usage: sat datafile"<<endl;
		cout<<"datafile is the file name of raw data including n and clauses."<<endl;
		return 0;
	}

	string clause_file(argv[1]);

	auto_ptr<CLAUSE> pClause((new CLAUSE(clause_file)));
	pClause->algoB();

	
	cout<<"Hello Algorithm B!"<<endl;
	return 0;
}



CLAUSE::CLAUSE(string& data_file)
		:fileName(data_file),
		cell(),
		mClauses(-1),
		n(-1)
{}

/*	Algorithm B (Satisfiability by watching). Given nonempty clauses C_1 ^ .... ^ C_m
	on n > 0 Boolean variables x_1 ... x_n, represented as above, this algorithm finds
	a solution if and only if the clauses are satisfiable. It records its current progress
	in an array m_1 ... m_n of "moves," whose significance was explained above.
*/
int CLAUSE::algoB()
{
	int d = -1;
	int l = -1;
	vector<int> m;
	int l_inv = -1;
	int nRet = -1;

//	00. To read number of literals and 3SAT clauses from file.
	nRet = extract();
	if (nRet < 0)
	{
		cout<<"Open file "<<fileName<<" failed!!!"<<endl;
		return nRet;
	}

	//n should has already been initialized before here.
	m.insert(m.begin(), n+1, -1);

B1: /*	[Initialize.] Set d <- 1. */
	d = 1;

B2: /*	[Rejoice or choose.] If d > n, terminate successfully. Otherwise set m_d <- 
		[W_(2d) = 0 or W_(2d+1) != 0] and l <- 2d + m_d. */
	if (d > n)
	{
		cout<<"successfully Finished!"<<endl;
		return 0;
	}
	else
	{
		m[d] = ((W[2*d]==0) || (W[2*d+1]!=0))? 1:0;
		l = 2*d + m[d];
	}

B3: /*	[Remove ~l if possible.] For all j such that ~l is watched in C_j, watch another
		literal of C_j. But go to B5 if that can't be done. (See exercise 124.) */


B4: /*	[Advance.] Set W_(~l) <- 0, d <- d+1, and return to B2. */
	W[l^1] = 0;
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
		cout<<"Failed to find. The clauses seems unsatisfiable???"<<endl;
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
			cout<<val<<" ";
		}
		LINK[i+1] = W[cell[START[i+1]].L];
		W[cell[START[i+1]].L] = i+1;
		cout<<endl;
	}

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