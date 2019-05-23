/*  Jacob 2017-Sep-17 

DanceColor.h


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
} ColorNode;

typedef struct
{
	string NAME;
	int LLINK;
	int RLINK;	
} ColorItem;

class ColorDancing
{
public:
	ColorDancing(string& fileName);
	ColorDancing(string& fileName, int numOfPrimaryItems);
	~ColorDancing() {};

	int algorithmC();

private:
	string danceFile;
	vector<ColorItem*> record;
	vector<ColorNode*> dance;
	map<int, string> item_name;
	int N;	//number of items
	int np;	//number of primary items
	int P;	//number of options
	int Z;	//last spacer address
	int l;	//level
	int count;
	vector<int> x;

	int exact();
	int exer8();
	int cover(int i);
	int hide(int p);
	int uncover(int i);
	int unhide(int p);
	int commit(int p, int j);
	int purify(int p);
	int uncommit(int p, int j);
	int unpurify(int p);

	int c1_init();
};



/*
class DanceLinkNode;
class ColorItem;

class DanceName
{
private:
	string key;
	ColorItem* LLINK;
	ColorItem* RLINK;
};


class ColorItem
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
	ColorItem* TOP;
	DanceLinkNode* ULINK;
	DanceLinkNode* DLINK;
};
*/