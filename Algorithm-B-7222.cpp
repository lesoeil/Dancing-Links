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
		m(-1),
		n(-1)
{}

int CLAUSE::algoB()
{
	return 0;
}