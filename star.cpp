#include<iostream>
#include<set>

#include <fstream>
#include <sstream>
#include <iterator>
#include <string>

using namespace std;

void genSharpAlpha()
{
	for (char a='A'; a<='Z'; a++)
	{
		cout<<"#"<<a<<" ";
	}
	cout<<endl;
}

void genAlpha()
{
	for (char a='A'; a<='Z'; a++)
	{
		cout<<a<<" ";
	}
	cout<<endl;	
}


void genMatrixElem(int row, int col)
{
	for (int i=0; i<row; i++)
	{
		for (int j=0; j<col; j++)
		{
			cout<<i<<j<<" ";
		}
	}
	cout<<endl;	
}


void genShortOptions()
{
	for (char a='A'; a<='Z'; a++)
	{
		cout<<"#"<<a<<" "<<a<<":0"<<endl;
		cout<<"#"<<a<<" "<<a<<":1 #"<<endl;
	}
}


/*
void genLetterOptions(char* pWord, int numOfLetters, int choice)

For example:

L A B E L
A B I D E
S L A I N
T E S T S

For, L A B E L

pWord: point to  char label[5]= {L,A,B,E,L}
numOfLetters: 5
choice: 4

For, L
     A
     S
     T

pWord: point to  char last[5]= {L,A,S,T}
numOfLetters: 4
choice: 5

*/
void genLetterOptions(const char* pWord, int numOfLetters, int choice, bool bRow)
{
	char up[numOfLetters];
	set<char> lset;
	set<char>::iterator it;

	for (int t=0; t<numOfLetters; t++)
	{
		up[t] = toupper(pWord[t]);
		lset.insert(up[t]);
	}

	if (bRow)
	{
		for (int i=0; i<choice; i++)
		{
			cout<<"A"<<i;

			for (int j=0; j<numOfLetters; j++)
			{
				cout<<" "<<i<<j<<":"<<up[j];
			}
			
			
			for (it=lset.begin(); it != lset.end(); it++)
			{
				cout<<" "<<*it<<":1";
			}

			cout<<endl;
		}
	}
	else
	{
		for (int j=0; j<choice; j++)
		{
			cout<<"D"<<j;

			for (int i=0; i<numOfLetters; i++)
			{
				cout<<" "<<i<<j<<":"<<up[i];
			}
			
			
			for (it=lset.begin(); it != lset.end(); it++)
			{
				cout<<" "<<*it<<":1";
			}

			cout<<endl;
		}
	}
}


int main(int argc, char* argv[])
{

	//char tri[5] = {'l', 'a' , 'b', 'e', 'l'};
	//genLetterOptions(tri, 5, 4, true);

	//char las[4] = {'l', 'a', 's', 't'};
	//genLetterOptions(las, 4, 5, false);

	//genShortOptions();
	//genSharpAlpha();
	//genAlpha();
	//genMatrixElem(4,5);
	int count = 0;
	fstream fs;
	fs.open("word5-2000.dat", fstream::in);
	string line;
	int numOfLetters=5;
	int choice = 4;
	bool bRow = true;

	while (getline(fs, line))
	{
		genLetterOptions(line.c_str(), numOfLetters, choice, bRow);
		//cout<<line<<endl;
		//count++;
	}

	fs.close();


	fs.open("word4-1000.dat", fstream::in);
	numOfLetters=4;
	choice = 5;
	bRow = false;

	while (getline(fs, line))
	{
		genLetterOptions(line.c_str(), numOfLetters, choice, bRow);
		//cout<<line<<endl;
		//count++;
	}

	fs.close();	

	//cout<<"Total lines/words handled: "<<count<<endl;
	

	int l = 101;
	cout<<"l: "<<l<<"   l_inv: "<<(l^1)<<endl;

	return 0;
}