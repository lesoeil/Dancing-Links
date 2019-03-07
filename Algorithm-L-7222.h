/*	Algorithm-L-7222.h

	Most of the comments are texts copied from TAOCP F6A 7.2.2.2
*/

#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>


#include <iomanip>
#include <utility>

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

class PAIRLINK
{
public:
	PAIRLINK(int x, int y, PAIRLINK* p);
	int v;
	int w;
	PAIRLINK* LINK;
};


class DPLLAD
{

public:
	DPLLAD(string& data_file);

	int AlgorithmL();
	bool AlgorithmX();
	int AlgorithmY();

private:
	int getVariable(int literal);
	bool isFreeLiteral(int l);
	int refineHeuristic();
	int assignLiteral(int x_rm);
	int solveExercise145();
	int regression(vector<double> *ph, double* ph_ave, vector<double> *ph_i, double* ph_ave_i);
	int solveHeuristic();
	int getTIMP(int literal);
	int chooseLiteral();//To be called in step L3.

	int propagateBIMP(int literal);
	int takeAccount(int literal);

	int algoL_step_1();
	int algoL_step_2();
	int algoL_step_3();
	int algoL_step_4();
	int algoL_step_5();
	int algoL_step_6();
	int algoL_step_7();
	int algoL_step_8(int L, int u, int v);
	int algoL_step_9();
	int algoL_step_10();
	int algoL_step_11();
	int algoL_step_12();
	int algoL_step_13();
	int algoL_step_14();
	int algoL_step_15();

private:
	string fileName;
	int n; // number of variables 1..n
	int m; // number of clauses

	int s;

	int d; // depth
	int G; 
	
	int F; // fixed variables
	int I; // ISTACK size
	int ISTAMP;

	int T;	// context T
	int NT;	// near truth  (2^32 - 4)

	int X;
	int RT;

	/*	Algorithm L uses a sequential stack R_0, R_1, ..., to record the names of 
		literals that have received values.
	*/
	vector<int> R;
	int E;	// current stack size of sequential stack R.
	int L;


	vector<int> DEC;
	vector<int> BACKF;
	vector<int> BACKI;
	vector<int> BRANCH;

	vector<unsigned int> VAL;

	/*	There is an array VAR, which contains a permutation of {1,...,n},
		with VAR[k] = x if and only if INX[x] = k. Furthermore VAR[k] is a 
		"free variable" -- not fixed in context RT -- if and only if 
		0 <= k < N. This setup makes it convenient to keep track of the 
		variables that are currently free: A variable becomes fixed by 
		swapping it to the end of the free list and decreasing N; then 
		we can free it later by simply increasing N, without swapping.
	*/

	int N;
	vector<int> VAR;
	vector<int> INX;

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
	vector<list<PAIRLINK*>> TIMP;
	vector<int> TSIZE;


	/*	A literal l is forced true when it appears in a clause C whose other literals 
		have been false, namely when the set of currently assigned literals L has re-
		duced C to the unit clause C|L = (l). Such unit clauses arise from the reduction 
		of binary clauses. Algorithm L therefore keeps track of the binary clauses (u V v) 
		that are relevant to the current subproblem F|L. This information is kept 
		in a so-called "bimp table" BIMP(l) for every literal l, which is a list of other 
		literals l' whose truth is implied by the truth of l. Indeed, instead of simply 
		including binary clauses within the whole list of given clauses, as Algorithm A, 
		B, and D do, Algorithm L stores the relevant facts about (u V v) directly, in a 
		ready-to-use way, by listing u in BIMP(~v) and v in BIMP(~u). Each of the 2n 
		tables BIMP(l) is represented internally as sequential list of length BSIZE(l), 
		with memory allocated dynamically via the buddy system (see exercise 134).
	*/
	vector<set<int>> BIMP;
	vector<int> BSIZE;

	vector<int> IST;

	vector<int> FORCE; //record
	int U; //number of distinct variables in unit clauses

	int extract();
	int debugPrint();

	vector<double> h;
	double h_ave;

	vector<double> H;

	vector<int> LL;
	vector<int> LO;
};