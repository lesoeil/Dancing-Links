/*	Jacob 24-Jun-2018
	
	The purpose of this file is to try to implement TAOCP 7.2.2.2 Algorithm D.

	Most of the contents in the comments are copied from taocp 7.2.2.2 related sections.
	The purpose is for easy checking with coding.

*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>

#include "Algorithm-D-7222.h"

using namespace std;

int main(int argc, char** argv)
{
	int nRet;

	if ((argc <2) || (argc>=3))
	{
		cout<<"Usage: dpll datafile"<<endl;
		cout<<"datafile is the file name of raw data including n and clauses."<<endl;
		return 0;
	}

	string clause_file(argv[1]);

	//auto_ptr<CLAUSE> 
	DPLL* pDPLL((new DPLL(clause_file)));
	nRet = pDPLL->algoD();

	cout<<"Hello Algorithm D !"<<endl;

	return 0;
}


DPLL::DPLL(string& data_file)
		:fileName(data_file)
{

}

int DPLL::debugPrint()
{
	/*
	cout<<"Total number cells: "<<cell.size()<<endl;
	cout<<"Total number START: "<<START.size()<<endl;
	cout<<"Total number LINK: "<<LINK.size()<<endl;
	cout<<"Total number W: "<<W.size()<<endl;

	for (int s=0; s<cell.size(); s++)
	{
		cout<<s<<" L: "<<cell[s].L<<endl;
	}
	*/

	for (int s=2; s<=2*n+1; s++)
	{
		cout<<"Literal: "<<s<<"       -->                   W["<<s<<"]: "<<W[s]<<endl;
	}
	
	for (int c=START.size(); c>=1; c--)
	{
		cout<<"Clause "<<c<<": ";
		for (int s=START[c]; s<START[c-1]; s++)
		{
			cout<<cell[s].L<<" ";
		}

		cout<<" -->   START["<<c<<"]: "<<START[c]<<" LINK["<<c<<"]: "<<LINK[c];

		cout<<endl;
	}

	cout<<"Clause "<<0<<":        -->   START["<<0<<"]: "<<START[0]<<" LINK["<<0<<"]: "<<LINK[0]<<endl;

	/*
	for(int i=0; i<=START.size(); i++)
	{
		cout<<"Clause "<<i<<" -->   START["<<i<<"]: "<<START[i]<<" LINK["<<i<<"]: "<<LINK[i]<<endl;
	}
	*/

	return 0;
}

int DPLL::algoD()
{
	int nRet;

	nRet = extract();
	if (nRet < 0)
	{
		cout<<"Open file "<<fileName<<" failed!!!"<<endl;
		return nRet;
	}

	debugPrint();

	int b;
	int d;
	int f;
	int k;

	int hP[n+1]; // records current progress
	int m[n+1];  // moves
	int x[n+1];  // value of variables: -1: unset; 0 or 1: set
	int NEXT[n+1];	//active ring.
	
	memset(NEXT, 0, (n+1)*sizeof(int));  // Be careful: memset count in unit of bytes !!!!

/*
	TAOCP 7.2.2.2 Algorithm D (Satisfiability by cyclic DPLL). Given nonempty clauses C_1 ⋀ ... ⋀
	C_m on n > 0 Boolean variables x_1 ... x_n, represented with lazy data structures
	and an active ring as explained above, this algorithm finds a solution if and only
	if the clauses are satisfiable. It records its current progress in an array h_1 ... h_n of
	indices and an array m_0 ... m_n of "moves," whose significance is explained below.
*/

D1:	/*	[Initialize.] Set m_0 <- d <- h <- t <- 0, and do the following for k = n, n-1,
		..., 1: Set x_k <- -1 (denoting an unset value); if W_(2k) ≠ 0 or W_(2k+1) ≠ 0,
		set NEXT(k) <- h, h <- k, and if t = 0 also set t <- k. Finally, if t ≠ 0,
		complete the active ring by setting NEXT(t) <- h.
	*/

	m[0] = 0;
	d = 0;
	h = 0;
	t = 0;

	for (k = n; k >= 1; k--)
	{
		x[k] = -1;

		if ((W[2*k] != 0) || (W[2*k+1] != 0))
		{
			NEXT[k] = h;
			h = k;
			if (t == 0)
			{
				t = k;
			}
		}	
	}

	//TODO: Will this be here?
	if (t != 0)
	{
		NEXT[t] = h;
	}

	//Debug Print active ring at the beginning.
	for (k = 1; k<=n; k++)
	{
		cout<<"NEXT["<<k<<"]: "<<NEXT[k]<<endl;
	}

	//return 0;


D2:	/*	[Success?] Terminate if t = 0 (all clauses are satisfied). Otherwise set k <- t.
	*/

	if (t == 0)
	{
		cout<<"Success! All clauses are satisfied"<<endl;

		for (int i=1; i<=n; i++)
		{
			cout<<x[i]<<" ";
		}
		cout<<endl;

		return 0;
	}
	else
	{
		k = t;
	}

D3:	/*	[Look for unit clauses.] Set h <- NEXT(k) and use the subroutine in exer-
		cise 129 to compute f <- [2h is a unit] + 2[2h+1 is a unit]. If f = 3, go
		to D7. If f = 1 or 2, set m_(d+1) <- f+3, t <- k, and go to D5. Otherwise, if
		h ≠ t, set k <- h and repeat this step.
	*/
	h = NEXT[k];

	f = 0;
	if (isUnit(2*h))
	{
		f = f+1;
	}

	if (isUnit(2*h+1))
	{
		f = f+2;
	}

	if (3 == f)
	{
		goto D7;
	}
	else if ( (1==f) || (2==f))
	{
		m[d+1] = f+3;
		t = k;
		goto D5;
	}
	else
	{
		if (h != t)
		{
			k = h;
			goto D3;
		}
	}

D4:	/*	[Two-way branch.] Set h <- NEXT(t) and m_(d+1) <- [W_(2h) = 0 or W_(2h+1) ≠ 0]
	*/
	h = NEXT[t];
	if ((0==W[2*h]) || (0!=W[2*h+1]))
	{
		m[d+1] = 1;
	}
	else
	{
		m[d+1] = 0;	
	}

D5:	/*	[Move on.] Set d <- d+1, h_d <- k <- h. If t = k, set t <- 0; otherwise delete
		variable k from the ring by setting NEXT(t) <- h <- NEXT(k).
	*/
	d = d+1;
	k = h;
	hP[d] = k;

	if (t == k)
	{
		t = 0;
	}
	else
	{
		h = NEXT[k];
		NEXT[t] = h;
	}

D6:	/*	[Update watches.] Set b <- (m_d + 1) mod 2, x_k <- b, and clear the watch list
		for ~(x_k) (see exercise 130). Return to D2.
	*/
	b = (m[d] + 1) % 2;
	x[k] = b;

	/*	7.2.2.2 Exercise
		130. [22] What low-level list processing operations are needed to "clear the watch list
		for ~(x_k)" in step D6?

	*/
	//TODO: Clear the watch list for ~(x_k)


	goto D2;

D7:	/*	[Backtrack.] Set t <- k. While m_d ≥ 2, set k <- h_d, x_k <- -1; if W_(2k) ≠ 0 or
		W_(2k+1) ≠ 0, set NEXT(k) <- h, h <- k, NEXT(t) <- h; and set d <- d-1.
	*/

	t = k;

	while (m[d] >= 2)
	{
		k = hP[d];
		x[k] = -1;

		if ((0 != W[2*k]) || (0 != W[2*k+1]))
		{
			NEXT[k] = h;
			h = k;
			NEXT[t] = h;
			d = d-1;
		}
	}

D8:	/*	[Failure?] If d > 0, set m_d <- 3 - m_d, k <- h_d, and return to D6. Otherwise
		terminate the algorithm (because the clause aren't satisfiable.)
	*/
	if (d>0)
	{
		m[d] = 3 - m[d];
		k = hP[d];
		goto D6;
	}
	else
	{
		cout<<"The clauses aren't satisfiable."<<endl;
	}


	return 0;

}


/*	7.2.2.2 Exercise
	129. [20] In the context of Algorithm D, design a subroutine that, given a literal l,
	returns 1 or 0 according as l is or is not being watched in some clause whose other
	literals are entirely false.
*/
/*	A unit clause (l) forces l to be true; therefore two-way branching is unnecessary
	whenever a unit clause is present.
*/

bool DPLL::isUnit(int literal)
{
	int temp = W[literal];

	bool bUnit = false;

	if (0 != temp)
	{
		while (0 != temp)
		{
			if (START[temp] > START[temp-1])
			{
				bUnit = true;
				break;
			}

			temp = LINK[temp];
		}	
	}

	return bUnit;
}



int DPLL::extract()
{
	//cout<<fileName<<endl;

	fstream fs;
	fs.open(fileName.c_str(), fstream::in);
	if ((fs.rdstate() & std::fstream::failbit) != 0)	
	{
		cout<<"Fail to open file \""<<fileName<<"\"."<<endl;
		cout<<"Please check whether file exist or not."<<endl;
		cout<<"Or whether process calling has the rights to open it or not."<<endl;
		return -2;
	}


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

	vector<set<int, less<int>>* > raw;
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

		set<int, less<int>>* its = new set<int, less<int>>; 
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
	mClauses = i_index;

	//cout<<"raw.size(): "<<raw.size()<<endl;
	//set<int>::const_iterator it;
	for (int i=0; i<=1; i++)
	{
		cell.push_back(CELL());
		cell[i].L = -1;
		W.push_back(0);
	}
	

	int tail[2+2*n];
	for (int i=2; i<2*n+2; i++)
	{
		cell.push_back(CELL());
		cell[i].L = -1;
		W.push_back(0);
	}



	int sidx = 2+2*n;
	for(int i=0; i<raw.size(); i++)
	{
		START.push_back(0);
		LINK.push_back(0);
	}

	for (int i=raw.size()-1; i>=0; i--)
	{
		//int j = 0;

		START[i+1] = sidx;		
		for (auto val: *raw[i])
		{
			cell.push_back(CELL());
			cell[sidx].L = val;
			sidx++;
			//j++;cout<<j<<":";
			//cout<<val<<" ";
		}
		LINK[i+1] = W[cell[START[i+1]].L];
		W[cell[START[i+1]].L] = i+1;
		//cout<<endl;
	}

	START[0] =  sidx;
	/*	
	cout<<"sidx: "<<sidx<<endl;
	START[0] =  sidx;
	for (int s=2; s<=2*n+1; s++)
	{
		cout<<"W["<<s<<"]: "<<W[s]<<endl;
	}

	for (int s=0; s<sidx; s++)
	{
		cout<<s<<" L: "<<cell[s].L<<endl;
	}

	for(int i=0; i<=raw.size(); i++)
	{
		cout<<"START["<<i<<"]: "<<START[i]<<" LINK["<<i<<"]: "<<LINK[i]<<endl;
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