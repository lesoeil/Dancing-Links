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

SimpleParser::SimpleParser(string& fname)
:fileName(fname)
{

}

SimpleParser::~SimpleParser()
{

}

int SimpleParser::horn()
{
	int nRet = -1;

	nRet = extract();

	return nRet;
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

	//vector<set<int, greater<int>>* > raw;
	int i_index=1;

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
		cout<<i_index<<":  ";
		for (auto& s: tokens)
		{
			int temp = 0;
			int len = s.length();
			//std::stoi(s)
			
			//cout<<s<<" => "<<temp<<endl;

			//raw.push_back(make_pair(0, temp));
			cout<<s<<" ";
			//raw[i_index]->insert(std::stoi(s));
		}
		cout<<endl;
		//cout<<endl;
		i_index++;
	}

#if 0
	//cout<<"i_index: "<<i_index<<endl;
	cout<<"Bit number is: "<<n<<endl;

	auto print = [](const pair<int, int> &point) { std::cout<<point.first<<" "<<point.second<<endl;};
	
	for_each (raw.begin(), raw.end(), print);
#endif	

	return 0;
}