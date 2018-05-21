/* HornCompiler-7-1-1-p58.h

	Jacob Yang 8-MAI-2018

*/

#ifndef HORN_COMPILER_711P58H
#define HORN_COMPILER_711P58H

#include <string>
#include <set>


class CLAUSE
{
	std::string conclusion;			// CONCLUSION(c) is the proposition on the right of clause c;
	int count;						// COUNT(c) is the number of hypothesis of c not yet asserted;
	const CLAUSE* prev;				// PREV(c) is the previous clause that awaits the same hypothesis as c;
	std::vector<std::string> start; // START(c) tells where the hypotheses of c appear in MEM.
};

class PROPOSITION
{
public:
	PROPOSITION(std::string& var);

	bool operator< (const PROPOSITION& right) const
	{
		return (pro < right.pro);
	}


	std::string pro;	// content of the proposition, for example, in "Vc ⋀ 1L => c1",
						// each of {"Vc", "1L", "c1"} is one PROPOSITION.
	bool truth;			// TRUTH(p) is 1 if known to be true, otherwise 0;
	const CLAUSE* last; // LAST(p) is the last clause in which p is waiting to be asserted;

};

class SimpleParser
{
public:
	SimpleParser(std::string& fname);
	~SimpleParser();

	int extract();
	int horn();


private:
	std::string fileName;
	std::set<PROPOSITION> P;
	std::set<CLAUSE> C;

};


#endif//HORN_COMPILER_711P58H