/*	Algorithm-A-7222.h
	Jacob	2018-Mar-07

*/

#include <vector>

using namespace std;

class CELL
{
public:
	int L;	// literal
	int F;	// forward link of double link list
	int B;	// backward link of double link list
	int C;	// for 2<= cell i <=2*n+1, number of clauses which contains literal i
			// for 2*n+2 <= cell i <= 2+2*n+3*m, id of clause in which this cell belongs.
};


class CLAUSE
{
public:
	CLAUSE(string& data_file);
	int algoA();

private:
	string fileName;
	vector<CELL> cell;
	vector<int> START;
	vector<int> SIZE;
	int m;	// number of 3SAT clauses
	int n;	// number of literals

	int extract();	
};