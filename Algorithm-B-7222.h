/*	Algorithm-B-7222.h
	Jacob Yang	2018-Mar-13

*/

#include <vector>

using namespace std;

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