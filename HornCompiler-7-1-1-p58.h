/* HornCompiler-7-1-1-p58.h

	Jacob Yang 8-MAI-2018

*/

#ifndef HORN_COMPILER_711P58H
#define HORN_COMPILER_711P58H


class SimpleParser
{
public:
	SimpleParser(std::string& fname);
	~SimpleParser();

	int extract();
	int horn();


private:
	std::string fileName;

};


#endif//HORN_COMPILER_711P58H