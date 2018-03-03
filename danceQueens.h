/* danceQueen.h */
#ifndef DANCE_QUEENS_H
#define DANCE_QUEENS_H

class DomainDk
{
public:	
	int min;
	int max;
	int nextLarger(int current);
};

class QUEEN
{
public:
	QUEEN(int numberOfQueens);
	int n;
	int l;
	int count;
	int* x;
	vector<DomainDk*> D;

	bool P(int k);
	void basicBackTrack();
	void customizedBackTrack();
	void WalkersBackTrack();
};

#endif