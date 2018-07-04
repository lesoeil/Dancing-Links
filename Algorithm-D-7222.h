/*	

*/

#include <vector>

using namespace std;

class CELL
{
public:
	int L;	// literal	
};


class DPLL
{

public:
	DPLL(string& data_file);
	int algoD();
	bool isUnit(int l);
	bool isLiteralFalse(int literal);

private:
	string fileName;
	vector<CELL> cell;
	vector<int> START;
	vector<int> LINK;
	vector<int> W;
	int mClauses;	// number of 3SAT clauses
	int n;	// size of variables

	//vector<int> NEXT;	//active ring.
	int h; //head
	int t; //tail

	vector<int> x;  // value of variables: -1: unset; 0 or 1: set

	int extract();
	int debugPrint();
};
