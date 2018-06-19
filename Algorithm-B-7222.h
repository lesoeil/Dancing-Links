/*	Algorithm-B-7222.h
	Jacob Yang	2018-Mar-13

*/

#include <vector>

using namespace std;

/*  Below is copy from taocp 7.2.2.2 to explain what fields are needed for Algorithm B.

	Let us therefore redesign Algorithm A and make it more laid-back. Our
new data structure for each cell p has only one field, L(p); the other fields F(p),
B(p), C(p) are no longer necessary, nor do we need 2n+2 special cells. As
before we will represent clauses sequentially, with the literals of C_j beginning at
START(j) for 1 <= j <= m. The watched literal will be the one in START(j); and a 
new field, LINK(j), will be the number of another clause with the same watched
literal (or 0, if C_j is the last such clause). Moreover, our new algorithm won't 
need SIZE(j). Instead, we can assume that the final literal of C_j is in location
START(j-1)-1, provided that we define START(0) appropriately.
*/


class CELL
{
public:
	int L;	// literal
};


class CLAUSE
{
public:
	CLAUSE(string& data_file);
	int algoB();

private:
	string fileName;
	vector<CELL> cell;
	vector<int> START;
	vector<int> LINK;
	vector<int> W;
	int mClauses;	// number of 3SAT clauses
	int n;	// number of literals

	int extract();
	int debugPrint();
};