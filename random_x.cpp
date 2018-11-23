#include <iostream>


#include "random_x.h"

using namespace std;

int main()
{
	//regexMatch();
	//randomGen();
	
	//cout<<y<<endl;

	return 0;
}




#include <regex>

int regexMatch()
{
	regex pat (R"(\w{2}\s*\d{5}(-\d{4})?)"); // ZIP code pattern: XXddddd-dddd and variants

	int lineno = 0;
	for (string line; getline(cin, line);) { // read into line buffer
		++lineno;
		smatch matches; // matched strings go here
		if (regex_search(line, matches, pat)) // search for pat in line
			cout<<lineno<<": "<<matches[0]<<'\n';
	}

	return 0;
}


#include <random>

int randomGen()
{
	using my_engine = default_random_engine; // type of engine
	using my_distribution = uniform_int_distribution<>; // type of distribution

	my_engine re {}; // the default engine

	my_distribution one_to_six {1,6}; // distribution that maps to the ints 1..6

	auto die = bind(one_to_six, re); // make a generator

	//int x = die(); // roll the die: x becomes a value in [1..6]
	//int y = die();

	for (int i = 0; i<100; i++)
	{
		auto x = die();
		cout<<x<<endl;	
	}


	return 0;
}