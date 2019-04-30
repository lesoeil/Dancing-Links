/*

Algorithm-X-7221.cpp

Jacob Yang

30-Apr-2019 Tue 09:52 PM Revise based on previous DancingLinks.cpp

To compile under Mac:

g++ -std=c++11 -g Algorithm-X-7221.cpp -o algoX

"algoX" can be any valid name for the executable application.
*/

/*
Suppose we have a doubly linked list, in which each node X has a 

predecessor and successor denoted respectively by LLINK(X) and 

RLINK(X).

Then we know that it's easy to delete X from the list:

RLINK(LLINK(X)) <- RLILNK(X),  LLINK(RLINK(X)) <- LLINK(X).		(1)

In a backtrack application, we're better off leaving LLINK(X) and 

RLINK(X) unchanged. Then we can undo operation (1) by simply setting

RLINK(LLINK(X)) <- X,  LLINK(RLINK(X)) <- X.					(2)

*/

/*

int A[6][7] = 
{
{0, 0, 1, 0, 1, 0, 0},
{1, 0, 0, 1 ,0, 0, 1},
{0 ,1, 1, 0, 0, 1, 0},
{1, 0, 0, 1, 0, 1, 0},
{0, 1, 0, 0, 0, 0, 1},
{0, 0, 0, 1, 1, 0, 1},
};

*/

/*
    Furthermore, we won't even talk about rows and columns!
Some of the exact cover problems we deal with already involve 
concepts that are called "rows" and "columns" in their own 
areas of application. Instead we will speak of options and 
items: Each option is a set of items; and the goal of an exact 
cover problem is to find disjoint options that cove all the items.

For example, we shall regard (5) as the specification of six 
options involving seven items. Let's name the items a, b, c, 
d, e, f, g; then the options are
	'c e';	'a d g';	'b c f';	'a d f';	'b g';	'd e g'	(6)

The first, fourth, and fifth options give us each item exactly once.

To cove item i, we delete all of the options that involve i, 
from our database of currently active options, and we also 
delete i from the list of items that need to be covered. The 
algorithm is simply this:
 Select an item i that needs to be covered; but terminate 
     successfully if none are left (we've found a solution).
 If no active options involves i, terminate unsuccessfully 
     (there's no solution). Otherwise cover item i.
 For each just-deleted option O that involves i, cover each 
     item j != i in O, and solve the residual problem. 
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <map>

#include "Algorithm-X-7221.h"

using namespace std;

int main(int argc, char* argv[])
{
	//DanceLinkNode x;
	
	/*
	cout<<"This is the start of dancing link."<<time(NULL)<<endl;
	for (int i=0; i<6; i++)
	{
		for (int j=0; j<7; j++)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}	
	*/
	//vector<DanceNode*> dance;
	//item_count = exact(&dance);

	//string exer8("exer8.dat");

	//DanceLink echo(exer8);
	//echo.algorithmD();	

	string options(argv[1]);
	DanceLink queen(options);
	queen.algoX();

	return 0;
}


/*	Algorithm X (Exact cover via dancing links). This algorithm visits all solutions
	to a given exact cover problem, using the data structures just described. It also
	maintains a list x_0, x_1, ..., x_T of node pointers for backtracking, where T is
	large enough to accommodate one entry for each option in a solution.*/
int DanceLink::algoX()
{
	int i = -1;
	int j = -1;
	int p = -1;

//Standard step D1 of Algorithm D (Exact cover via dancing links)
X1:
/*	[Initialize.] Set the problem up in memory, as in Table 1. (See exercise 8.)
	Also set N to the number of items, Z to the last spacer address, and l <- 0.
*/
	N = exact();//Set the problem up in memory
	Z = dance.size()-1;
	l = 0;
	cout<<"N: "<<N<<" Z: "<<Z<<" l:"<<l<<endl;
	for (int s=0; s<P+1; s++)
	{
		x.push_back(s);
	}

	/*
	for (int s=0; s<P+1; s++)
	{
		cout<<x[s]<<" ";
	}
	*/
#endif

#if 0
// Modify step X1 so that only the primary items appear in the active list.
X1://[Initialize.] [Modified version which only work for specified version of 4 queens problem.]
	N = exact();//Set the problem up in memory
	unsigned int numberOfPrimary = 8;//r_1, r_2, r_3, r_4, c_1, c_2, c_3, c_4
	cout<<"dance[0]->LLINK: "<<dance[0]->LLINK<<endl;
	cout<<"dance[8]->RLINK: "<<dance[8]->RLINK<<endl;
	Z = dance.size()-1;
	l = 0;
	cout<<"N: "<<N<<"  (number of items)"<<endl;
	cout<<"P: "<<P<<"  (number of options)"<<endl;
	cout<<"Z: "<<Z<<"  (last spacer address)"<<endl;
	cout<<"l: "<<l<<"  (start level at D1)"<<endl;
	cout<<endl;

	//dance[0]->LLINK = 8;
	//dance[8]->RLINK = 0;
	cout<<"dance[0]->LLINK: "<<dance[0]->LLINK<<endl;
	cout<<"dance[0]->RLINK: "<<dance[0]->RLINK<<endl;
	cout<<"dance[8]->LLINK: "<<dance[8]->LLINK<<endl;
	cout<<"dance[8]->RLINK: "<<dance[8]->RLINK<<endl;
	cout<<endl;	 

	for (int s=0; s<P+1; s++)
	{
		x.push_back(s);
	}

	/*
	for (int s=0; s<P+1; s++)
	{
		cout<<x[s]<<" ";
	}
	*/
#endif

X2:
/*	[Enter level l.] If RLINK(0) = 0 (hence all items have been covered), visit the
	solution that is specified by x_0 x_1 ... x_(l-1) and go to X8. (See exercise 13.)
*/
	//cout<<"dance[0]->RLINK: "<<dance[0]->RLINK<<endl;
	if (dance[0]->RLINK == 0)
	{
		cout<<"Total level: "<<l<<endl;
		//Visit solution specified by x[0..l-1]
		for (int s=0; s<l; s++)
		{
			//cout<<x[s]<<" (option: "<<(-((dance[x[s]-1])->TOP))+1<<") ";
			cout<<x[s]<<" ";
		}
		cout<<endl;

		for  (int s=0; s<l; s++)
		{
			int next = x[s];
			while (((DanceNode*)dance[next])->TOP >0)
			{
				cout<<item_name[dance[next]->TOP]<<" ";
				next = next+1;
			}
			//cout<<x[s]<<" (option: "<<(-((dance[x[s]-1])->TOP))+1<<") ";
			cout<<endl;
		}
		cout<<endl;

		goto D8;
	}

D3://[Choose i.]
	//TODO: To replace with MRV in exercise 9
	//i = dance[0]->RLINK;

	{
	int start = 0;

	int min_len = 0;
	int min_addr = 0;
	int i_addr = 0;
	int i_len = 0;

	i_addr = dance[0]->RLINK;
	i_len = dance[i_addr]->LEN;
	min_addr = i_addr;
	min_len = i_len;

	while ((dance[i_addr]->RLINK) != start)
	{
		i_addr = dance[i_addr]->RLINK;
		i_len = dance[i_addr]->LEN;

		if (min_len > i_len)
		{
			min_addr = i_addr;
			min_len = i_len;
		}
	}


	i = min_addr;
	//cout<<"C3: choose node "<<i<<endl;
	}

D4://[Cover i.]
	cover(i);
	//x.push_back(dance[i]->DLINK);
	x[l] = dance[i]->DLINK;
D5://[Try x[l] ]
	if ( x[l] == i)
	{
		goto D7;
	}
	else
	{
		p = x[l] + 1;
		while (p != x[l])
		{
			j = dance[p]->TOP;
			if (j<=0)
			{
				p = dance[p]->ULINK;
			}
			else
			{
				cover(j);
				p = p+1;
			}
		}

		l = l+1;
		goto D2;
	}

D6://[Try again.]
	p = x[l]-1;
	while (p != x[l])
	{
		j = dance[p]->TOP;
		if (j<=0)
		{
			p = dance[p]->DLINK;
		}
		else
		{
			uncover(j);
			p = p-1;
		}
	}

	i = dance[x[l]]->TOP;
	x[l] = dance[x[l]]->DLINK;
	goto D5;

D7://[Backtrack.]
	uncover(i);

D8://[Leave level l.]
	if (l == 0)
	{
		return 0;
	}
	else
	{
		l = l-1;
		goto D6;
	}

}

DanceLink::DanceLink(string& file)
{
	danceFile = file;
	dance.clear();
	N = -1;
	Z = -1;
	l = -1;
}


int DanceLink::cover(int i)
{
	int p = dance[i]->DLINK;
	while (p!=i)
	{
		hide(p);
		p = dance[p]->DLINK;
	}

	int l = dance[i]->LLINK;
	int r = dance[i]->RLINK;
	dance[l]->RLINK = r;
	dance[r]->LLINK = l;

	return 0;
}

int DanceLink::hide(int p)
{
	int x = -1;
	int u = -1;
	int d = 0;

	int q = p+1;
	while (q != p)
	{
		x = dance[q]->TOP;
		u = dance[q]->ULINK;
		d = dance[q]->DLINK;

		if (x <= 0)
		{
			q = u;
		}
		else
		{
			dance[u]->DLINK = d;
			dance[d]->ULINK = u;
			dance[x]->LEN = dance[x]->LEN - 1;
			q = q+1;
		}
	}	

	return 0;
}

int DanceLink::uncover(int i)
{
	int l = dance[i]->LLINK;
	int r = dance[i]->RLINK;
	
	dance[l]->RLINK = i;
	dance[r]->LLINK = i;

	int p = dance[i]->ULINK;

	while (p != i)
	{
		unhide(p);
		p = dance[p]->ULINK;
	}

	return 0;
}

int DanceLink::unhide(int p)
{
	int q = p-1;
	int x = -1;
	int u = -1;
	int d = -1;

	while (q != p)
	{
		x = dance[q]->TOP;//segment fault: x = dance[p]->TOP;
		u = dance[q]->ULINK;
		d = dance[q]->DLINK;

		if (x <= 0)
		{
			q = d;
		}
		else
		{
			dance[u]->DLINK = q;
			dance[d]->ULINK = q;
			dance[x]->LEN = dance[x]->LEN + 1;
			q = q-1;
		}
	}

	return 0;
}

/* 7.2.2.1 DANCING LINKS: EXERCISES  -- First Set
 8. [22] Design an algorithm to set up the initial memory contents of an exact cover
problem, as needed by Algorithm D and illustrated in Table 1.  The input to your
algorithm should consist of a sequence of lines with the following format:
   The very first line lists the names of all items.
   Each remaining line specifies the items of a particular option, one option per line.

*/
int DanceLink::exact()
{
	vector<string> name;

	fstream fs;
	//fs.open("exer8.dat", fstream::in);
	fs.open(danceFile.c_str(), fstream::in);
	string line;
	
	getline(fs, line);
	//cout<<line<<endl;
	istringstream buf(line);
	istream_iterator<string> beg(buf);
	istream_iterator<string> end;

	vector<string> tokens(beg, end);
	map<string, int> item;
	map<string, int> item_addr;
	//map<int, string> item_name;
	//vector<DanceNode*> dance;
	int item_count = 0;
	
	DanceNode* pNode = new DanceNode;
	pNode->LEN = 0;
	pNode->ULINK = -1;
	pNode->DLINK = -1;	
	pNode->LLINK = -1;
	pNode->RLINK = 1;
	dance.push_back(pNode);


	int node_addr = 0;
	
	for (auto& s: tokens)
	{
		//cout<<'"'<<s<<'"'<<endl;
		item[s] = 0;
		node_addr++;
		item_count++;
		DanceNode* pNode = new DanceNode;
		pNode->LEN = 0;
		pNode->ULINK = node_addr;
		pNode->DLINK = node_addr;
		pNode->LLINK = node_addr-1;
		pNode->RLINK = node_addr+1;
		dance.push_back(pNode);

		item_addr[s] = node_addr;
		item_name[node_addr] = s;
	}

	dance[node_addr]->RLINK = 0;
	dance[0]->LLINK = node_addr; 


	node_addr++;
	pNode = new DanceNode;
	pNode->TOP = 0;
	pNode->ULINK = -1;
	pNode->DLINK = -1;
	dance.push_back(pNode);
	int prevSpacer = node_addr;	


	int i=0;
	while (getline(fs, line))
	{
		i++;
		//cout<<"Option "<<i<<": "<<line<<endl;

		istringstream buf(line);
		istream_iterator<string> beg(buf);
		istream_iterator<string> end;

		vector<string> options(beg, end);

		int firstNode = node_addr+1;
		for (auto& s: options)
		{	
			item[s]++;

			//cout<<s<<endl;

			DanceNode* pNode = new DanceNode;
			pNode->TOP = item_addr[s];

			node_addr++;
			int addr = dance[item_addr[s]]->DLINK;
			int dNode = item_addr[s];
			while (addr != item_addr[s])
			{
				dNode = addr;
				addr = dance[dNode]->DLINK;
			}

			pNode->ULINK = dNode;
			dance[dNode]->DLINK = node_addr;
			pNode->DLINK = item_addr[s];
			dance[item_addr[s]]->ULINK = node_addr;

			dance.push_back(pNode);	

			//cout<<s<<" TOP:"<<pNode->TOP<<"  ULINK:"<<pNode->ULINK;
			//cout<<"  DLINK:"<<pNode->DLINK<<endl;
		}
		//cout<<endl;
		int lastNode = node_addr;
		dance[prevSpacer]->DLINK = lastNode;

		node_addr++;
		DanceNode* pNode = new DanceNode;
		pNode->TOP = -i;
		pNode->ULINK = firstNode;
		pNode->DLINK = -1;
		dance.push_back(pNode);
		prevSpacer = node_addr;
	}

	fs.close();

	//N = item_count;
	//Z = node_addr;
	//l = 0;
	P = i;

	map<string, int>::iterator it;

	//cout<<"item : len"<<endl;
	//for (it=item.begin(); it != item.end(); it++)
	//{
	//	cout<<it->first<<":"<<it->second<<endl;
	//}


	/*
	int n=0;
	cout<<n++<<" ";
	for (auto& s: tokens)
	{
		cout<<n++<<" ";
	}
	cout<<endl;

	cout<<"  ";
	for (auto& s: tokens)
	{
		cout<<s<<" ";
	}
	cout<<endl;
	*/

	/*
	int k = 0;
	int round=0;
	for (auto& s: dance)
	{
		if (s->TOP!=0)
		{
			if (s->TOP>0)
			{
				cout<<item_name[s->TOP]<<" "<<k<<" "<<s->TOP<<" "<<s->ULINK<<" "<<s->DLINK<<" "<<endl;
			}

			if (s->TOP<0)
			{
				cout<<"  "<<k<<" "<<s->TOP<<" "<<s->ULINK<<" "<<s->DLINK<<" "<<endl;
			}
			//cout<<s<<" TOP:"<<pNode->TOP<<"  ULINK:"<<pNode->ULINK;
			//cout<<"  DLINK:"<<pNode->DLINK<<endl;
			if (s->TOP<0)
			{
				round++;
				cout<<"End of Option "<<round<<endl;
				cout<<endl;
			}
		}
		else
		{
			if (k==0)
			{
				cout<<k<<" "<<s->TOP<<" "<<s->ULINK<<" "<<s->DLINK<<" "<<endl;
			}
			else if ((k>0) && (k<=item_count))
			{
				s->LEN = item[tokens[k-1]];
				cout<<k<<" "<<s->LEN<<" "<<s->ULINK<<" "<<s->DLINK<<endl;
				//cout<<tokens[k-1]<<": "<<s->LEN<<" ";
			}
			else
			{
				cout<<endl;
				cout<<k<<" "<<s->TOP<<" "<<s->ULINK<<" "<<s->DLINK<<" "<<endl<<endl;
				cout<<"Start of Option.......";
				cout<<endl;
				cout<<endl;
			}
		}

		k++;
	}
	*/

	return item_count;
}