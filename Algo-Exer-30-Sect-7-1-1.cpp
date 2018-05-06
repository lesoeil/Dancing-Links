/* TAOCP 7.1.1 BOOLEAN BASICS Exercise 30

	30. [27] The text points out that an implicant of a Boolean function can be regarded
	as a subcube such as 01*0*, contained in the set V of all points for which the function is
	true. Every subcube can be represented as a pair of binary numbers a = (a_(n-1)...a_0)_2
	and b = (b_(n-1)...b_0)_2, where a records the positions of the asterisks and b records the
	bits in non-* positions. For example, the numbers a = (00101)_2 and b = (01000)_2
	represent the subcube c = 01*0*. We always have a & b = 0.
		The "j-buddy" of a subcube is defined whenever a_j = 0, by changing b to (b XOR 2^j).
	For example, 01*1* has three buddies, namely its 4-buddy 11*0*, its 3-buddy 00*0*,
	and its 1-buddy 01*1*. Every subcube c (belongs to) V can be assigned a tag value (t_(n-1)...t_0)_2,
	where t_j = 1 if and only if the j-buddy of c is defined and contained in V. With this
	definition, c represents a maximal subcube (hence a prime implicant) if and only if its
	tag is zero.
		Use these concepts to design an algorithm that finds all maximal subcubes (a,b)
	of a given set V, where V is represented by the n-bit numbers v_0 < v_1 < ... < v_(m-1).


	Jacob 	04-May-2018 21:24
*/

#include <iostream>
#include <fstream>
#include <sstream>

#include "Algo-Exer-30-Sect-7-1-1.h"

using namespace std;

#define CUBE_DEBUG
#undef  CUBE_DEBUG

int main(int argc, char** argv)
{
	if (argc<2)
	{
		cout<<"fileName for data input is needed."<<endl;
		cout<<"Usage: "<<argv[0]<<" dataFile"<<endl;
		return -1;
	}

	string fname(argv[1]);

	CUBE raw(fname);
	raw.algoCube();
	//cout<<"Hello CUBE"<<endl;

	return 0;

}


CUBE::CUBE(string& fname)
:fileName(fname),
 n(0)
{

}

CUBE::~CUBE()
{

}

int CUBE::algoCube()
{
	int nRet = -1;

C0: /* Read raw data from data file and transform it into pair (a,b) 
		as mentioned in 7.1.1 Exercise 30.
	*/
	nRet = extract();

C1: 
	//cout<<raw[0].first<<"  "<<raw[0].second<<endl;
	//cout<<"size of data elements: "<<raw.size()<<endl;
	
	std::vector<pair<int, int>> baseCube(raw);
	std::vector<pair<int, int>> nextCube;

	//auto cloneCube = [](const pair<int, int> &point) { baseCube.push_back(make_pair(point.first, point.second)); };
	/*
	for_each (raw.begin(), raw.end(), [](pair<int, int>& e)
	{
		baseCube.push_back(e.first, e.second);
	});
	*/

	//auto printCube = [](const pair<int, int> &point) { std::cout<<point.first<<" "<<point.second<<endl;};
	//for_each (baseCube.begin(), baseCube.end(), printCube);

	while (baseCube.size() >0)
	{
		vector<int> t(baseCube.size(), 0);
		//cout<<"size of t: "<<t.size()<<endl;
		//std::vector<pair<int, int>>::iterator it;

		/* Jacob 5-MAI-2018


			The logic is that:
			for each round, for all elements in the vector, 
			choose each element, compute all its j-buddy,
			and compare each j-buddy to each elements located after the element, 
			if equal, then:
			1. tag j as 1 for both source element and destination element,
				which means that both elements will not marked as maximal.
			2. compute next generation of subcube (a|2^j, b & ~(2^j)) and insert it
				into next generation vector to store the elements for next round of try.


		*/
		for (int i = 0; i < baseCube.size(); i++)
		{
			int a = baseCube[i].first;
			int b = baseCube[i].second;

			for (int j=0; j<n; j++)
			{
				if ((a & (1<<j))==0)
				{
					//int a_next = a | (1<<j);
					//int b_next = b ^ (1<<j);
					int b_temp = b^(1<<j);
					for (int k=i+1; k<baseCube.size(); k++)
					{
						if ((baseCube[k].first == a) && (baseCube[k].second == b_temp))
						{
							int a_new = a | (1<<j);
							int b_new = b & ~(1<<j);
							nextCube.push_back(make_pair(a_new, b_new));
							t[i] |= (1<<j);
							t[k] |= (1<<j);
						}
					}
				}
				else
				{
					continue;
				}
			}
		}

		for (int i = 0; i < baseCube.size(); i++)
		{
			if (t[i]==0)
			{
				maxSet.insert(make_pair(baseCube[i].first, baseCube[i].second));
			}
		}

		baseCube = nextCube;
		nextCube.clear();
	}

	std::set<pair<int, int>>::iterator it;
	for (it = maxSet.begin(); it !=maxSet.end(); it++)
	{
		for (int j=0; j<n; j++)
		{
			if (it->first & (1<<(n-j-1)))
			{
				cout<<"*";
			}
			else
			{
				if (it->second & (1<<(n-j-1)))
				{
					cout<<"1";
				}
				else
				{
					cout<<"0";
				}
			}
		}
		cout<<endl;
	};
	


	return nRet;
}

int CUBE::extract()
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

	//vector<set<int, greater<int>>* > raw;
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

		//set<int, greater<int>>* its = new set<int, greater<int>>; 
		//raw.push_back(its);
		
		for (auto& s: tokens)
		{
			int temp = 0;
			int len = s.length();
			//std::stoi(s)
			for (int i=0; i<len; i++)
			{
				if (s[i] == '1')
				{
					temp |= 1<<(len-i-1);
				}
				else if (s[i] == '0')
				{
					continue;
				}
				else
				{
					break;
				}
			}
			//cout<<s<<" => "<<temp<<endl;

			raw.push_back(make_pair(0, temp));
			//cout<<s<<" ";
			//raw[i_index]->insert(std::stoi(s));
		}
		//cout<<endl;
		i_index++;
	}

#ifdef CUBE_DEBUG
	//cout<<"i_index: "<<i_index<<endl;
	cout<<"Bit number is: "<<n<<endl;

	auto print = [](const pair<int, int> &point) { std::cout<<point.first<<" "<<point.second<<endl;};
	
	for_each (raw.begin(), raw.end(), print);
#endif	

	return 0;
}