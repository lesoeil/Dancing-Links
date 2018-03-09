/*  03-Mar-2018
COMBINATORIAL ALGORITHMS
SATISFIABILITY: BACKTRACKING ALGORITHMS

	Any instance of SAT that involves at least one variable can be solved sys-
tematically by choosing a variable and setting it to 0 or 1. Either of those choices
gives us a smaller instance of SAT; so we can continue until reaching either an 
empty instance -- which is trivially satisfiable, because no clauses need to be 
satisfied -- or an instance that contains an empty clause. In the latter case we
must back up and reconsider one of our earlier choices, proceeding in the same 
fashion until we either succeed or exhaust all the possibilities.

	In general if F is any set of clauses and if l is any literal, then F|l (read
"F given l" or "F conditioned on l") is the set of clauses obtained from F by
	removing every clause that contains l; and
	removing l-reverse from every clause that contains l-reverse.


*/


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>

#include "Algorithm-A-7222.h"

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
	pClause->algoA();

	
	//cout<<"Hello Satisfiability!"<<endl;
	return 0;
}


int CLAUSE::algoA()
{
/*	Algorithm A (Satisfiability by backtracking). Giving nonempty clauses C_1 & ... & 
	C_m on n > 0 Boolean variables x_1 ... x_n, represented as above, this algorithm 
	finds a solution if and only if the clauses are satisfiable. It records its current
	progress in an array m_1 ... m_n of "moves," whose significance is explained below.
*/
	int nRet = -1;

//	00. To read number of literals and 3SAT clauses from file.
	nRet = extract();
	if (nRet < 0)
	{
		cout<<"Open file "<<fileName<<" failed!!!"<<endl;
		return nRet;
	}


A1:
/*	A1. [Initialize.] Set a <- m and d <- 1. (Here a represents the number of active
		clauses, and d represents the depth-plus-one in an implicit search tree.)		*/


A2:
/*	A2. [Choose.] Set l <- 2d. If C(l) <= C(l+1), set l <- l+1. Then sete m_d <-
		(l & 1) + 4[C(l XOR 1)=0]. (See below.) Terminate successfully if C(l) =a.		*/


A3:
/*	A3. [Remove ~l.] Delete ~l from all active clause; but goto A5 if that would make
		a clause empty. (We want to ignore ~l, because we're making l true.)			*/


A4:
/*	A4. [Deactivate l's clauses.] Suppress all clauses that contain l. (Those clauses
		are now satisfied.) Them set a <- a - C(l), d <- d+1, and return A2.			*/


A5:
/*	A5. [Try again.] If m_d < 2, set m_d <- 3 - m_d, l <- 2d + (m_d & 1), and go to A3. */


A6:
/*	A6. [Backtrack.] Terminate unsuccessfully if d = 1 (the clauses are unsatisfi-
		able). Otherwise set d <- d - 1 and l <- 2d + (m_d & 1).						*/


A7:
/*	A7. [Reactivate l's clauses.] Set a <- a + C(l), and unsuppress all clauses that
		contain l. (Those clauses are now unsatisfied, because l is no longer true.)	*/


A8:
/*	A8. [Unremove ~l.] Reinstate ~l in all the active clauses that contain it. Then go
		back to A5.
*/


	return 0;
}



CLAUSE::CLAUSE(string& data_file)
		:fileName(data_file),
		cell(),
		m(-1),
		n(-1)
{}

int CLAUSE::extract()
{
	//cout<<fileName<<endl;

	fstream fs;
	fs.open(fileName.c_str(), fstream::in);
	string line;
	
	getline(fs, line);
	//cout<<line<<endl;

	istringstream buf(line);
	istream_iterator<string> beg(buf);
	istream_iterator<string> end;

	vector<string> tokens(beg, end);

	for (auto& s: tokens)
	{
		//cout<<s<<" ";
		n = std::stoi(s);
		//cout<<"number of literals n is:"<<n<<endl;
	}
	//cout<<endl;

	vector<set<int, greater<int>>* > raw;
	int i_index=0;

	while (getline(fs, line))
	{
		istringstream buf(line);
		istream_iterator<string> beg(buf);
		istream_iterator<string> end;

		vector<string> tokens(beg, end);
		if (tokens.size()<=0)
		{
			continue;
		}

		set<int, greater<int>>* its = new set<int, greater<int>>; 
		raw.push_back(its);
		
		for (auto& s: tokens)
		{
			//cout<<s<<" ";
			raw[i_index]->insert(std::stoi(s));
		}
		//cout<<endl;
		i_index++;
	}

	//cout<<"i_index: "<<i_index<<endl;
	m = i_index;

	//cout<<"raw.size(): "<<raw.size()<<endl;
	//set<int>::const_iterator it;
	for (int i=0; i<=1; i++)
	{
		cell.push_back(CELL());
		cell[i].L = -1;
		cell[i].F = -1;
		cell[i].B = -1;
		cell[i].C = -1;
	}
	

	int tail[2+2*n];
	for (int i=2; i<2*n+2; i++)
	{
		cell.push_back(CELL());
		cell[i].L = -1;
		tail[i] = i;
		cell[i].F = tail[i];
		cell[i].B = tail[i];
		cell[i].C = 0;
	}



	int sidx = 2+2*n;
	for(int i=0; i<raw.size(); i++)
	{
		START.push_back(0);
		SIZE.push_back(0);
	}

	for (int i=raw.size()-1; i>=0; i--)
	{
		//int j = 0;

		START[i+1] = sidx;
		SIZE[i+1] = 0;
		for (auto val: *raw[i])
		{
			cell.push_back(CELL());
			cell[sidx].L = val;
			cell[sidx].C = i+1;

			cell[sidx].B = val;
			cell[sidx].F = tail[val];
			cell[tail[val]].B = sidx;
			cell[val].F = sidx;
			tail[val] = sidx;
			cell[val].C +=1;

			SIZE[i+1]++;

			sidx++;
			//j++;cout<<j<<":";
			//cout<<val<<" ";
		}
		//cout<<endl;
	}
	
	/*
	for (int s=0; s<sidx; s++)
	{
		cout<<s<<" L: "<<cell[s].L<<"  F:"<<cell[s].F<<"  B:"<<cell[s].B<<"  C:"<<cell[s].C<<endl;
	}

	for(int i=0; i<=raw.size(); i++)
	{
		cout<<"START["<<i<<"]: "<<START[i]<<" SIZE["<<i<<"]: "<<SIZE[i]<<endl;
	}
	*/

	/*
	while (getline(fs, line))
	{
		cout<<line<<endl;
	}
	*/

	
	

	return 0;
}