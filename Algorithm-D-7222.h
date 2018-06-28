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
	bool isUnit(int literal);
	int debugPrint();

private:
	string fileName;
	vector<CELL> cell;
	vector<int> START;
	vector<int> LINK;
	vector<int> W;
	int mClauses;	// number of 3SAT clauses
	int n;	// size of variables

	vector<int> NEXT;	//active ring.
	int h; //head
	int t; //tail



	int extract();
};
