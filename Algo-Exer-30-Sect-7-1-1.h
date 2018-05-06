/*	Algo-Exer-30-Sect-7-1-1.h

*/
#ifndef AlgoExer30Sect711
#define AlgoExer30Sect711

#include <vector>
#include <map>
#include <set>

using namespace std;

class CUBE
{
public:
	CUBE(string& fname);
	~CUBE();

	int algoCube();
	int extract();

private:
	string fileName;
	int n;
	std::vector<pair<int, int>> raw;
	std::set<pair<int, int>> maxSet;
};


#endif//AlgoExer30Sect711
