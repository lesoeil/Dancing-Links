/*	TAOCP 7.1.1 Page 58~59 To compute Horn functions for compiler. 

	Jacob Yang	7-MAI-2018 22:38

	<expression> -> <term> | <expression> + <term> | <expression> - <term>
	<term> -> <factor> | - <factor> | <term> * <factor> | <term> / <factor>
	<factor> -> <variable> | <constant> | (<expression>)
	<variable> -> <letter> | <variable> <letter> | <variable> <digit>
	<letter> -> a | b | c
	<constant> -> <digit> | <constant> <digit>
	<digit> -> 0 | 1

	xT => xE	   => -T 	xC => xF	Vx ⋀ yL => xy	   		=> Lc
	Tx => Ex 	xF => -x 	Cx => Fx	Vx ⋀ yD => xy		 xD => xC
	Ex => x+	Tx => x*	   => (F 	     Dx => Vx		 Dx => Cx
	xT => +x 	xF => *x 	xE => (x 		    => aL	Cx ⋀ yD => xy
	Ex => x-	Tx => x/	Ex => x)			=> La			=> 0D
	xT => -x 	xF => /x 	   => F)			   bL			=> D0
	xF => xT	xV => xF	xL => xV			=> Lb			=> 1D
	Fx => Tx	Vx => Fx	Lx => Vx			=> cL 			=> D1

	compile:
	g++ -std=c++11 HornCompiler-7-1-1-p58.cpp -o horn
*/


#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

#include "HornCompiler-7-1-1-p58.h"

using namespace std;

int main(int argc, char** argv)
{
	if (argc<2)
	{
		cout<<"fileName for data input is needed."<<endl;
		cout<<"Usage: "<<argv[0]<<" dataFile"<<endl;
		return -1;
	}

	string fname(argv[1]);

	SimpleParser myParser(fname);
	myParser.horn();
	//cout<<"Hello CUBE"<<endl;

	return 0;
}

int generateALL()
{
	return 0;
}

PROPOSITION::PROPOSITION(std::string& var)
	:pro(var),
	 truth(0),
	 last(NULL)
{
	//Empty
}

CLAUSE::CLAUSE(std::string& var)
	:wholeClause(var),
	 count(0),
	 prev(NULL),
	 start(0)
{

}


SimpleParser::SimpleParser(string& fname)
	:fileName(fname),
	 l(0),
	 s(0)
{
	//std::set<PROPOSITION>::const_iterator it=P.begin();
	//MEM.insert(P.begin());
}

SimpleParser::~SimpleParser()
{

}


/*	Algorithm C (Core computation for definite Horn clauses). Given a set P of
	propositional variables and a set C of clauses, each having the form
	
	  u_1 ⋀ ... ⋀ u_k => v 	where k >= 0 and { u_1, ... , u_k, v} ⊆ P, 	  (36)
	
	this algorithm finds the set Q ⊆ P of all propositional variables that are neces-
	sarily true whenever all of the clauses are true.

		We use the following data structures for clauses c and proposition p:
		CONCLUSION(c) is the proposition on the right of clause c;
		COUNT(c) is the number of hypotheses of c not yet asserted;
		TRUTH(p) is 1 if p is known to be true, otherwise 0;
		LAST(p) is the last clause in which p is waiting to be asserted;
		PREV(c) is the previous clause that awaits the same hypothesis as c;
		START(c) tells where the hypotheses of c appear in MEM.

	An array called MEM holds all the left-hand sides of the clauses; if START(c) = l
	and COUNT(c) = k, the not-yet-asserted hypotheses of clause are MEM[l+1],
	..., MEM[l+k]. We also maintain a stack S_0, S_1, ... , S_(s-1) of all propositions
	that are known to be true but not yet asserted.
*/

int SimpleParser::horn()
{
	int nRet = -1;
	std::set<PROPOSITION>::const_iterator p;
	CLAUSE* c;
	int k = 0;
	int l = 0;
	CLAUSE* c_proceed;

C1: /*	[Initialize.] Set LAST(p) <- ⋀ and TRUTH(p) <- 0 for each proposition p.
		Also set l <- s <- 0, so that MEM and the stack are initially empty. Then
		for each clause c, having the form (36), set CONCLUSION(c) <- v. If k = 0
		and TRUTH(v) = 0, simply set TRUTH(v) <- 1, S_s <- v, and s <- s+1. But
		if k > 0, set MEM[l+j] <- u_j for 1 ≤ j ≤ k, COUNT(c) <- k, l <- l + k,
		PREV(c) <- LAST(u_k), and LAST(u_k) <- c.
	*/
	nRet = extract();

	for (auto cs: C)
	{
		if (cs.count == 0)
		{
			auto v = P.find(cs.conclusion);
			if (v->truth == 0)
			{
				//cout<<v->pro<<endl;
				const_cast<int&> (v->truth) = 1;
				SS.push_back(*v);
				s++;
			}
			//cout<<s.wholeClause<<endl;
		}
		else
		{
			auto uk = MEM[cs.start + cs.count];
			//cout<<uk->pro<<endl;
			cs.prev = uk->last;
			(const_cast<CLAUSE*&> (uk->last)) = &cs;
		}
	}

	//cout<<C.size()<<endl;
	//cout<<P.size()<<endl;

	//cout<<"l:"<<l<<"  s:"<<s<<endl;

	//cout<<"Number of clauses: "<<C.size()<<endl;
	//auto print = [](const PROPOSITION& med) { std::cout<<med.pro<<endl;};
	//for_each (P.begin(), P.end(), print);
	//cout<<"Size of P:"<<P.size()<<endl;
	
	//auto print = [](const std::set<PROPOSITION>::const_iterator& it) { std::cout<<it->pro<<endl;};
	//for_each (++MEM.begin(), MEM.end(), print);
	/*
	for (int i=1; i<MEM.size(); i++)
	{
		cout<<MEM[i]->pro<<endl;
	}
	*/

C2:	/*	[Prepare to loop.] Terminate the algorithm if s = 0; the desired core now
		consists of all propositions whose TRUTH has been set to 1. Otherwise set
		s <- s-1, p <- S_s, and c <- LAST(p). (We'll update the clauses that await p.)
	*/
	//cout<<s<<endl;
	if (0==s)
	{
		cout<<s<<" == 0. Terminate"<<endl;
		return 0;
	}
	else
	{
		s--;
		p = P.find(SS[s].pro);
		c = p->last;
	}


C3:	/*	[Done with loop?] If c = ⋀, return to C2. Otherwise set k <- COUNT(c) - 1,
		l <- START(c), and c' <- PREV(c).
	*/
	if (NULL == c)
	{
		goto C2;
	}
	else
	{
		k = c->count-1;
		l = c->start;
		c_proceed = c->prev;
	}


C4:	/*	[Done with c?] If k = 0, go to C5. Otherwise set p <- MEM[l+k].
		If TRUTH(p) = 1, set k <- k-1 and repeat this step. Otherwise set
		COUNT(c) <- k, PREV(c) <- LAST(p), LAST(p) <- c, and go to C6.
	*/
	if (0==k)
	{
		goto C5;
	}
	else
	{
		p = MEM[l+k];		
		while (k>0) 
		{
			if (1==p->truth)
			{
				k = k-1;
				p = MEM[l+k];
			}
			else
			{
		 		c->count = k;
		 		c->prev = p->last;
		 		const_cast<CLAUSE*&> (p->last) = c;
		 		goto C6;
			}
		}

		//c->count = k;
	}


C5:	/*	[Deduce CONCLUSION(c).] Set p <- CONCLUSION(c). If TRUTH(p) = 0, set
		TRUTH(p) <- 1, S_s <- p, s <- s+1.
	*/
	p = P.find(c->conclusion);
	if (0==p->truth)
	{
		const_cast<int&>(p->truth) = 1;
		SS.push_back(*p);
		s++;	
	}


C6:	/*	[Loop on c.] Set c <- c' and return to C3.
	*/
	c = c_proceed;
	goto C3;
	
}

int SimpleParser::extract()
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
	
	#if 0
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
	#endif

	vector<char> symb = {'+', '-', '*', '/', '(', ')', 'a', 'b', 'c', '0', '1'};
	/*
	{
		vector<char>::const_iterator it;
		for (it=symb.begin(); it!=symb.end(); it++)
		{
			cout<<*it<<endl;
		}
	}
	*/

	MEM.push_back(P.begin());
	//MEM.push_back((std::set<PROPOSITION>::const_iterator)(empty()));

	//vector<set<int, greater<int>>* > raw;
	int i_index=1;
	int count=0;

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

		//set<int, greater<int>>* its = new set<int, greater<int>>; 
		//raw.push_back(its);
		//cout<<i_index<<":  ";
		//cout<<"\""<<line<<"\" ==> size: "<<tokens.size()<<endl;

		vector<char>::const_iterator it;
		switch (tokens.size())
		{
		case 2:
			for (auto& ch: symb)
			{
				int index = 0;
				set<string> conditions;
				string target;
				int k = 0;
				string* final = new string("");
				CLAUSE* pClause = new CLAUSE(*final);
				pClause->start = l;
				for (auto& cs: tokens)
				{
					auto temp = cs;
					std::replace(temp.begin(), temp.end(), 'x', ch);
					//cout<<temp<<" ";
					//P.insert((std::string&)(*temp));
					auto checkp = P.find(temp);
					if (checkp == P.end())
					{
						PROPOSITION* pEle = new PROPOSITION(temp);
						P.insert(*pEle);
					}
					
					index++;
					if (index == tokens.size())
					{
						target = *(new string(temp));
						pClause->conclusion = temp;						
					}
					else
					{
						conditions.insert(*(new string(temp)));
						pClause->count++;
						k = pClause->count;
						//pClause->
						//MEM.push_back(P.begin());
						//MEM[l+k] = P.find(temp);
						MEM.insert(MEM.begin()+l+k, P.find(temp));
					}
				}


				for (auto& ts : conditions)
				{
					*final += ts+" ";
				}

				*final += target;
				//string temp_s = *final+target;

				//cout<<*final<<endl;
				auto lookfor = C.find(*final);
				if (lookfor == C.end())
				{
					//cout<<*final<<": Not Find Yet"<<endl;
					l = l+k;
					pClause->wholeClause = *final;
					C.insert(*pClause);
				}
				else
				{
					//cout<<"Duplicate clause!"<<*final<<" No need to insert."<<endl;
					delete pClause;
				}

				//cout<<endl;
				count++;
			}
			
		break;

		case 1:
		{
			int index = 0;
			set<string> conditions;
			string target;
			int k = 0;
			string* final = new string("");
			CLAUSE* pClause = new CLAUSE(*final);
			pClause->start = l;

			for (auto& cs: tokens)
			{
				auto temp = cs;
				//std::replace(temp.begin(), temp.end(), 'x', ch);
				//cout<<cs;

				auto checkp = P.find(temp);
				if (checkp == P.end())
				{
					PROPOSITION* pEle = new PROPOSITION(temp);
					P.insert(*pEle);
				}

				index++;
				if (index == tokens.size())
				{
					target = *(new string(temp));
					pClause->conclusion = temp;
				}
				else
				{
					conditions.insert(*(new string(temp)));
					pClause->count++;
					k = pClause->count;
					//pClause->
					//MEM.push_back(P.begin());
					//MEM[l+k] = P.find(temp);
					MEM.insert(MEM.begin()+l+k, P.find(temp));
				}			
			}
			//cout<<endl;

			for (auto& ts : conditions)
			{
				*final += ts+" ";
			}

			*final += target;
			//string temp_s = *final+target;

			//cout<<*final<<endl;
			auto lookfor = C.find(*final);
			if (lookfor == C.end())
			{
				//cout<<*final<<": Not Find Yet"<<endl;
				l = l+k;
				pClause->wholeClause = *final;
				C.insert(*pClause);
			}
			else
			{
				//cout<<"Duplicate clause!"<<*final<<" No need to insert."<<endl;
				delete pClause;
			}
			count++;

		break;
		}

		case 3:
			for (auto& chx: symb)
			{
				for (auto& chy: symb)
				{
					int index = 0;
					set<string> conditions;
					string target;
					int k = 0;
					string* final = new string("");
					CLAUSE* pClause = new CLAUSE(*final);
					pClause->start = l;
					for (auto& cs: tokens)
					{
						auto temp = cs;
						std::replace(temp.begin(), temp.end(), 'x', chx);
						std::replace(temp.begin(), temp.end(), 'y', chy);
						//cout<<temp<<" ";

						auto checkp = P.find(temp);
						if (checkp == P.end())
						{
							PROPOSITION* pEle = new PROPOSITION(temp);
							P.insert(*pEle);
						}
						
						index++;
						if (index == tokens.size())
						{
							target = *(new string(temp));
							pClause->conclusion = temp;
						}
						else
						{
							conditions.insert(*(new string(temp)));
							pClause->count++;
							k = pClause->count;
							//pClause->
							//MEM.push_back(P.begin());
							//MEM[l+k] = P.find(temp);
							MEM.insert(MEM.begin()+l+k, P.find(temp));
						}
					}
					//cout<<endl;

					for (auto& ts : conditions)
					{
						*final += ts+" ";
					}

					*final += target;
					//string temp_s = *final+target;

					//cout<<*final<<endl;
					auto lookfor = C.find(*final);
					if (lookfor == C.end())
					{
						//cout<<*final<<": Not Find Yet"<<endl;
						l = l+k;
						pClause->wholeClause = *final;
						C.insert(*pClause);
					}
					else
					{
						cout<<"Duplicate clause!"<<*final<<" No need to insert."<<endl;
						delete pClause;
					}

					count++;
				}
			}

		break;

		default:
		break;
		}

		//for (auto& cs: tokens)
		//{
		//	int temp = 0;
		//	int len = cs.length();
			//std::stoi(cs)
			
			//cout<<cs<<" => "<<temp<<endl;

			//raw.push_back(make_pair(0, temp));
			//cout<<cs<<" ";
			//raw[i_index]->insert(std::stoi(cs));
		//}
		//cout<<endl;
		//cout<<endl;
		//i_index++;
	}

	//cout<<"Total number of clauses: "<<count<<endl;

#if 0
	//cout<<"i_index: "<<i_index<<endl;
	cout<<"Bit number is: "<<n<<endl;

	auto print = [](const pair<int, int> &point) { std::cout<<point.first<<" "<<point.second<<endl;};
	
	for_each (raw.begin(), raw.end(), print);
#endif	

	return 0;
}