/*  Jacob 2017-Sep-17 

DanceMCC.h


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

	int ULINK;
	int DLINK;

	char COLOR;
} DanceNode;

typedef struct
{
	string NAME;
	int LLINK;
	int RLINK;	
	int SLACK;
	int BOUND;
} DanceRecord;

class DanceLink
{
public:
	DanceLink(string& fileName);
	DanceLink(string& fileName, int numOfPrimaryItems);
	~DanceLink() {};

	int algorithmM();

private:
	string danceFile;
	vector<DanceRecord*> record;
	vector<DanceNode*> dance;
	map<int, string> item_name;
	int N;	//number of items
	int np;	//number of primary items
	int P;	//number of options
	int Z;	//last spacer address
	int l;	//level
	int count;
	vector<int> x;
	vector<int> FT;

	int exact();
	int exer8();
	int cover_HI(int i);
	int uncover_HI(int i);
	int hide_HI(int p);
	int unhide_HI(int p);
	int tweak(int x, int p);
	int untweak(int l);
	int tweak_HI(int x, int p);
	int untweak_HI(int l);
	int commit(int p, int j);
	int uncommit(int p, int j);
	int purify(int p);
	int unpurify(int p);
	int sharpHeur();
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