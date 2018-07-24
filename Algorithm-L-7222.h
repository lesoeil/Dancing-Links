/* Algorithm-L-7222.h
*/

#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <set>
#include <fstream>
#include <sstream>

using namespace std;

class CELL
{
public:
	int k;
};

class LITERAL
{
public:
	int l;
};


class DPLLAD
{

public:
	DPLLAD(string& data_file);

	int AlgorithmL();
	int AlgorithmX();
	int AlgorithmY();

private:
	string fileName;
	int n; // number of variables 1..n
	int m; // number of clauses

	vector<unsigned int> VAL;

	/*	Every literal l has a sequential list TIMP(l) of length TSIZE(l),
		consisting of pairs p_1 = (u_1, v_1), p_2 = (u_2, v_2), ..., 
		such that the truth of l implies that each (u_i, v_i) becomes a 
		relevant binary clause. If (u V v V w) is a ternary clause, there 
		will be three pairs p = (v,w), p' = (w,u), and p" = (u,v), appearing 
		in the respective lists TIMP(~u), TIMP(~v), and TIMP(~w). Moreover, 
		the three pairs are linked together cyclically, with 
			LINK(p) = p', LINK(p') = p", LINK(p") = p.			(61)

		Memory is allocated for the timp tables once and for all, as the clauses are input,
		because Algorithm L does not generate new ternaries during its computations.
		Individual pairs p are, however, swapped around within these sequential tables,
		so that the currently active ternary clauses containing u always appear in the 
		first TSIZE(~u) positions that have been allocated to TIMP(~u).
	*/
	vector<list<pair<LITERAL, LITERAL>>> TIMP;
	vector<int> TSIZE;


	vector<list<LITERAL>> BIMP;
	vector<int> BSIZE;

	vector<int> IST;

	int ISTAMP;

	vector<LITERAL> FORCE; //record
	int U; //number of distinct variables in unit clauses

	int extract();

};