/*  Jacob 2017-06-18 

DancingLinks.h


*/

#include <iostream>

using namespace std;

typedef struct
{
	union
	{
		int LEN;
		int TOP;
	};
	int LLINK;
	int RLINK;
	int ULINK;
	int DLINK;
	//string name;
} DanceNode;


class DanceLink
{
public:
	DanceLink(string& dataFile);
	~DanceLink() {};

	int algorithmD();
	int exact();
	int cover(int i);
	int hide(int p);
	int uncover(int i);
	int unhide(int p);

private:
	string danceFile;
	vector<DanceNode*> dance;
	map<int, string> item_name;
	int N;	//number of items
	int P;	//number of options
	int Z;	//last spacer address
	int l;	//level
	vector<int> x;
};



/*
class DanceLinkNode;
class DanceItem;

class DanceName
{
private:
	string key;
	DanceItem* LLINK;
	DanceItem* RLINK;
};


class DanceItem
{
public:

private:
	int LEN;
	DanceLinkNode* ULINK;
	DanceLinkNode* DLINK;
};


class DanceLinkNode
{
public:
	//int remove(DanceLinkNode* X);

private:
	DanceItem* TOP;
	DanceLinkNode* ULINK;
	DanceLinkNode* DLINK;
};
*/