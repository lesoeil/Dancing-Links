/*  DanceColor.cpp

Jacob 2017-Sep-17

DanceColor.cpp is code for Algorithm C (Exact covering with colors).

7.2.2.1 DANCING LINKS: COLOR-CONTROLLED COVERING

Color-controlled covering. Take a break! Before reading any further, please 
spend a minute or two solving the "word search" puzzle in Fig. 71. Compar-
atively mindless puzzles like this one provide a low-stress way to sharpen your 
word-recognition skills. It can be solved easily -- for instance, by making eight 
passes over the arrary -- and the solution appears in Fig. 72.

Fig. 71. Find the mathematicians*:
Put ovals around the following names where they appear in the 15 x 15 array shown 
here, reading either forward or backward or upward or downward, or diagonally in 
any direction. After you've finished, the leftover letters will form a hidden 
message.

	ABEL		HENSEL		MELLIN
	BERTRAND	HERMITE		MINKOWSKI
	BOREL		HILBERT		NETTO
	CANTOR		HURWITZ		PERRON
	CATALAN		JENSEN		RUNGE
	FROBENIUS	KIRCHHOFF	STERN
	GLAISHER	KNOPP		STIELTJES
	GRAM		LANDAU		SYLVESTER
	HADAMARD	MARKOFF		WEIERSTRASS

Our goal in this section is not to discuss how to solve such puzzles; instead, we 
shall consider how to create them. It's by no means easy to pack those 27 names 
into the box in such a way that their 184 characters occupy only 135 cells, with 
eight directions well mixed. How can that be done with reasonable efficiency?
	For this purpose we shall extend the idea of exact covering by introducing 
color codes. Let's image that each cell ij of array is to be "colored" with 
one of the letters {A,...,Z}. Then the task of creating such a puzzle is essentially 
to choose from among a vast set of options

	'ABEL 00:A 01:B 02:E 03:L'
	'ABEL 00:A 10:B 20:E 30:L'
	'ABEL 00:A 11:B 22:E 33:L'
	'ABEL 01:L 02:E 03:B 04:A'
			......
	'WEIERSTRASS e4:W e5:E e6:I e7:E e8:R e9:S ea:T eb:R ec:A ed:S ee:S'		(48)

in such a way that the following conditions are satisfied:
  i) Exactly one option must be chosed for each of the 27 mathematicians' names.
 ii) The chosen options must give consistent colors to each of the 15x15 cells ij.

There also are informal constraints: It's desirable to have many shared letters 
between names, and to intermix the various directions, so that the puzzle has 
plenty of variety and perhaps a few surprises. But conditions (i) and (ii) are 
the important criteria for a computer to consider; the auxiliary informalities are 
best handled interactively, with human guidance.
	Notice that the color constraints (ii) are significantly different from the name 
constraints (i). Several distinct options are allowed to specify the color of the 
same cell, as long as those specifications don't conflict with each other.
	Let us therefore define a new problem, exact covering with colors, or XCC for 
short. As before, we're given a set of items, of which N_1 are primary and N - N_1 
are secondary. We're also given a family of M options, each of which includes at 
least one primary item. The new rule is that a color is assigned to the secondary 
items of each option. The new task is to find all choices of options such that 
	  i) every primary item occurs exactly once; and
	 ii) every secondary item has been assigned at most one color.
The primary items are required; the secondary items are elective.
	Color assignments are denoted by a colon; for example, '00:A' in (48) means 
that color A is assigned to the secondary item 00. When a secondary item of an 
option is not followed by a colon, it is implicitly assigned a unique color, which 
doesn't match the color of any other option. Therefore the ordinary exact cover 
problems that we've been studying so far, in which secondary items don't explic-
itly receive colors but cannot be chosen in more than one option, are just special 
cases of the XCC problem, even though nothing about color was mentioned.
	A tremendous variety of combinatorial problems can be expressed readily in 
the XCC framework. And there's good news: The dancing links technique works 
beautifully with such problems! Indeed, we will see that this considerably more 
general problem can be solved with only a few small extensions to Algorithm D.
	The nodes of Algorithm D have just three fields: TOP, ULINK, and DLINK.
We now add a fourth field, COLOR; this field is set to the positive value c when 
the node represents an item that has explicitly been assigned color c. Consider, 
for example, the following toy problem with three primary items {p,q,r} and 
two secondary items {x,y}, where the options are
							'p q x y:A';
							'p r x:A y';
							'p x:B';
							'q x:A';
							'r y:B'.									(49)

Table 2 shows how it would be represented in memory, extending the conventions
of Table 1. Notice that COLOR = 0 when no color has been specified. The COLOR 
fields of header nodes (nodes 1-5 in this example) need not be initialized 
because they're never examined. The COLOR fields of the spacer nodes (nodes 6, 
11, 16, 19, 22, 25) are unimportant, except that they must be nonnegative.

	It's easy to see how these COLOR fields can be used to get the desired effect:
When an option is chosen, we "purify" any secondary items that it names, by 
effectively removing all options that have conflicting colors. One slightly subtle 
point arises, because we don't want to waste time purifying a list that has already 
been culled. The trick is to set COLOR(x) <- -1 in every node x that's already 
known to have the correct color, except in nodes that have already been hidden.

	Thus we want to upgrade the original operations cover(i) and hide(p) in (12)
and (13), as well as their counterparts uncover(i) and unhide(p) in (14) and (15),
in order to incorporate color controls. The changes are simple:

 cover'(i) is like cover(i), but it calls hide'(p) instead of hide(p);			(50)
 hide'(p) is like hide(p), but it ignores node q when COLOR(q)<0;				(51)
 uncover'(i) is like uncover(i), but it call unhide'(p) instead of unhide(p);	(52)
 unhide'(p) is like unhide(p), but it ignores node q when COLOR(q)<0.			(53)

Our colorful algorithm also introduces two new operations and their inverses:

			  
commit(p,j) = 	{	
					If COLOR(p) == 0, cover'(j);
			  		if COLOR(p) > 0, purify(p).										
			  	}																(54)

purify(p) = 	{	
					Set c <- COLOR(p), i <- TOP(p), q <- DLINK(i).
					While q ≠ i, do the following and set q <- DLINK(q):
						if COLOR(q) ≠ c, hide'(q);
						otherwise COLOR(q) <- -1.
				}																(55)

uncommit(p,j) = {
					If COLOR(p) == 0, uncover'(j);
					if COLOR(p) > 0, unpurify(p).
				}																(56)

unpurify(p) = 	{
					Set c <- COLOR(p), i <- TOP(p), q <- ULINK(i).
					While q ≠ i, do the following and set q <- ULINK(q):
						if COLOR(q) < 0, COLOR(q) <- c;
						otherwise unhide'(q).
				}																(57)
Otherwise Algorithm C is almost word-for-word identical to Algorithm X.

Algorithm C (Exact covering with colors).	This algorithm visits all solutions
to a given XCC problem, using the same conventions as Algorithm X.

C1.[Initialize.] Set the problem up in memory, as in Table 2. (See exercise 8.)
	Also set N to the number of items, Z to the last spacer address, and l <- 0.

C2.[Enter level l.] If RLINK(0) = 0 (hence all items have been covered), visit the 
	solution that is specified by x_0 x_1 ... x_(l-1) and go to C8. (See exercise 13.)

C3.[Choose i.] At this point the items i_1, ..., i_t still need to be covered, where 
	i_1 = RLINK(0), i_(j+1) = RLINK(i_j), RLINK(i_t) = 0. Choose one of them, and 
	call it i. (The MRV heuristic of exercise 9 often works well in practice.)

C4.[Cover i.] Cover item i using (50), and set x_l <- DLINK(i).

C5.[Try x_l.] If x_l = i, go to C7 (we've tried all options for i). Otherwise set
	p <- x_l + 1, and do the following while p ≠ x_l: Set j <- TOP(p); if j ≤ 0, set 
	p <- ULINK(p); otherwise commit(p,j) and set p <- p+1. (This covers the 
	items ≠ i in the option that contains x_l.) Set l <- l+1 and return to C2.

C6.[Try again.] Set p <- x_l - 1, and do the following while p != x_l: Set j <- 
	TOP(p); if j ≤ 0, set p <- DLINK(p); otherwise uncommit(p,j) and set 
	p <- p-1. (This uncovers the items ≠ i in the option that contains x_l, using 
	the reverse order.) Set i <- TOP(x_l), x_l <- DLINK(x_l), and return to C5.

C7.[Backtrack.] Uncover item i using (52).

C8.[Leave level l.] Terminate if l = 0. Otherwise set l <- l - 1 and go to C6.

	Algorithm C applies directly to several problems that we've already dis-
cussed in previous sections. For example, it readily generates word rectangles, 
as well as intriguing patterns of words that have more intricate structure (see 
exercise 164-171). We can use it to find all de Bruijn cycles, and their two-
dimensional counterparts (see exercies 155-158). The extra generality of exact 
covering options also invites us to impose additional constraints for special 
applications. Furthermore, Algorithm C facilitates experiments with the tetrad 
tiles that we studied in Section 2.3.4.3 (see exercises 220 and 221).
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
#include <stdlib.h>

#include "DanceColor.h"

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

	if ((argc <2) || (argc>3))
	{
		cout<<"Usage: dance ***.dat [nnn]"<<endl;
		cout<<"***.dat is the file name of raw data."<<endl;
		cout<<"nnn is the number of primary items. If no, then default all are primary items."<<endl;
		return 0;
	}

	string options(argv[1]);
	int n = 0;
	if (argc > 2)
	{
		n = atoi(argv[2]);
	}

	DanceLink queen(options, n);
	queen.algorithmC();

	return 0;
}

/* 18-Sep-2017 20:32
Algorithm C (Exact covering with colors). This algorithm visits all solutions 
to a given XCC problem, using the same conventions as Algorithm D.
*/
#undef DEBUGPRINT
#define DEBUGPRINT

int DanceLink::algorithmC()
{
	int i = -1;
	int j = -1;
	int p = -1;

	int cut_512 = 0;//count for exercise 251
	int cut_610a = 0; //count for exercise 255 a)
	int bc[13] = {0};//To count the number of pentimoes touching boundary in each solution.
	int touchX = 0;
	vector<int> index;

#if 0  //Standard step D1 of Algorithm D (Exact cover via dancing links)
D1://[Initialize.]
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

// Modify step C1 so that only the primary items appear in the active list.
C1:/*[Initialize.] Set the problem up in memory, as in Table 2 (see exercise 8).
	 Also set N to the number of items, Z to the last spacer address, and l <- 0.  */
	
	//exer8();
	//return 0;


	N = exact();//Set the problem up in memory
	Z = dance.size()-1;
	l = 0;
	cout<<"N  : "<<N<<"  (number of items)"<<endl;
	cout<<"np : "<<np<<"  (number of primary items)"<<endl;
	cout<<"P  : "<<P<<"  (number of options)"<<endl;
	cout<<"Z  : "<<Z<<"  (last spacer address)"<<endl;
	cout<<"l  : "<<l<<"  (start level at D1)"<<endl;
	cout<<endl;

	for (int s=0; s<P+1; s++)
	{
		x.push_back(s);
	}

	cout<<"Record.size: "<<record.size()<<endl;

	//cout<<"record.size(): "<<record.size()<<endl;
	
	//if (np > (record.size()-1))
	if ( (np > N) || (np<=0))
	{
		cout<<"Number of Primary Items np: "<<np<<" is out of range 1.."<<N<<"(total number of items)"<<endl;
		np = N;
		cout<<"To make sense, now set num Of primary items to total number of items."<<endl<<endl;

		cout<<"N  (total number of items)  : "<<N<<endl;
		cout<<"np (number of primary items): "<<np<<endl<<endl;
	}
	//r_1, r_2, r_3, r_4, c_1, c_2, c_3, c_4//unsigned int numberOfPrimary = 8;//r_1, r_2, r_3, r_4, c_1, c_2, c_3, c_4
	record[0]->LLINK = np;
	record[np]->RLINK = 0;

	if (np<N)
	{
		record[np+1]->LLINK = N+1;
		record[N+1]->RLINK = np+1;
	}


#if	defined(DEBUGPRINT)
	for (int i=0; i<record.size(); i++)
	{
		cout<<"Item: "<<i<<"  NAME:"<<record[i]->NAME<<"  LLINK:"<<record[i]->LLINK<<"  RLINK:"<<record[i]->RLINK<<endl;
	}
#endif

#if defined(DEBUGPRINT)
	for (int i=np+1; i<=N; i++)//record.size(); i++)
	{
		cout<<i<<"th item which is "<<i-np<<"th secondary item "<<record[i]->NAME<<" with LEN: "<<dance[i]->LEN<<endl;
	}
	cout<<endl;
#endif
	/*
	for (int s=0; s<P+1; s++)
	{
		cout<<x[s]<<" ";
	}
	*/

C2:/*[Enter level l.] If RLINK(0) = 0 (hence all items have been covered), visit the 
	 solution that is specified by x_0 x_1 ... x_l-1 and go to C8. (See exercise 12.)
	*/
	//cout<<"dance[0]->RLINK: "<<dance[0]->RLINK<<endl;
	if (record[0]->RLINK == 0)
	{
/*  Update 2017-09-22 For DanceColor.cpp changes for Exercise 18 will be removed since 
			there is no such requirement for exact cover with color.   And, what's more,
			at this moment, I have not get correct result for exercise 18 yet! So there 
			must be bugs in touch() function.....

18. [21] Modify Algorithm D so that it doesn't require the presence of any primary
items in the options. A valid solution should not contain any purely secondary options;
but it must intersect every such option. (For example, if only items a and b of (6) were
primary, the only valid solution would be to choose options 'a d g' and 'b c f'.)

*/
		//bool bTouch = touch();
		//if (bTouch)
		{
			cout<<"Total level: "<<l<<endl;
			count++;
			cout<<"This is the "<<count<<"th solution."<<endl;
			//Visit solution specified by x[0..l-1]
			for (int s=0; s<l; s++)
			{
				//cout<<x[s]<<" (option: "<<(-((dance[x[s]-1])->TOP))+1<<") ";
				cout<<x[s]<<" ";
			}
			cout<<endl;

			#if 0 //Original output for dance linking color 27-Nov-2017 Jacob

			for  (int s=0; s<l; s++)
			{
				int next = x[s];
				while (((DanceNode*)dance[next-1])->TOP >0)
				{
					next = next -1;
				}

				while (((DanceNode*)dance[next])->TOP >0)
				{
					cout<<item_name[dance[next]->TOP]<<" ";
					next = next+1;
				}
				//cout<<x[s]<<" (option: "<<(-((dance[x[s]-1])->TOP))+1<<") ";
				cout<<endl;
			}
			cout<<endl;
			#endif

			#if 0 // 27-Nov-2017 Jacob Below is the version for 5x12 5*k+(12-5)*k
			int idx[12] = {0};
			for  (int s=0; s<l; s++)
			{
				int next = x[s];
				while (((DanceNode*)dance[next-1])->TOP >0)
				{
					next = next -1;
				}

				int cord = 0;
				int start = 100;
				while (((DanceNode*)dance[next])->TOP >0)
				{
					cout<<item_name[dance[next]->TOP]<<" ";
					
					int pos;
					if (cord>0)
					{
						//cout<<((item_name[dance[next]->TOP]).c_str())[1]<<endl;
						switch (((item_name[dance[next]->TOP]).c_str())[1])
						{
							case '0': pos = 0; break;
							case '1': pos = 1; break;
							case '2': pos = 2; break;
							case '3': pos = 3; break;
							case '4': pos = 4; break;
							case '5': pos = 5; break;
							case '6': pos = 6; break;
							case '7': pos = 7; break;
							case '8': pos = 8; break;
							case '9': pos = 9; break;
							case 'a': pos = 10; break;
							case 'b': pos = 11; break;
						}
						if (start>pos) start = pos;
					}

					cord++;
					next = next+1;
				}
				idx[start]++;
				//cout<<x[s]<<" (option: "<<(-((dance[x[s]-1])->TOP))+1<<") ";
				cout<<endl;
			}

			int check_cut=0;
			for (int i=0; i<11; i++)
			{
				check_cut += idx[i];
				if (check_cut == (i+1))
				{
					cut_512++;
				}
			}

			cout<<endl;
			#endif

			#if 0 // 03-Dec-2017 Jacob Below is the version to count Exer 255 a)
			/* TAOCP 7.2.2.1 Exercises
				254. [20] There are 2339 ways to pack the twelve pentominoes into a 6 x 10 box, not
				counting reflections. What's a good way to find them all, using Algorithm D?
				255. [23] Continuing exercise 254, explain how to find special kinds of packings:
					a) Those that decomose into 6 x k and 6 x (10-k).

			*/
			int idx[10] = {0};
			for  (int s=0; s<l; s++)
			{
				int next = x[s];
				while (((DanceNode*)dance[next-1])->TOP >0)
				{
					next = next -1;
				}

				int cord = 0;
				int start = 100;
				while (((DanceNode*)dance[next])->TOP >0)
				{
					cout<<item_name[dance[next]->TOP]<<" ";
					
					int pos;
					if (cord>0)
					{
						//cout<<((item_name[dance[next]->TOP]).c_str())[1]<<endl;
						switch (((item_name[dance[next]->TOP]).c_str())[1])
						{
							case '0': pos = 0; break;
							case '1': pos = 1; break;
							case '2': pos = 2; break;
							case '3': pos = 3; break;
							case '4': pos = 4; break;
							case '5': pos = 5; break;
							case '6': pos = 6; break;
							case '7': pos = 7; break;
							case '8': pos = 8; break;
							case '9': pos = 9; break;
						}
						if (start>pos) start = pos;
					}

					cord++;
					next = next+1;
				}
				idx[start]++;
				//cout<<x[s]<<" (option: "<<(-((dance[x[s]-1])->TOP))+1<<") ";
				cout<<endl;
			}

			int check_cut=0;

			for (int i=0; i<=4; i++)
			{
				check_cut += idx[i];				
			}
			if (check_cut == 6)
			{
					cut_610a++;
			}

			cout<<endl;
			#endif

			#if 0 // 04-Dec-2017 Jacob Below is the version to count Exer 255 e)
			/* TAOCP 7.2.2.1 Exercises
				254. [20] There are 2339 ways to pack the twelve pentominoes into a 6 x 10 box, not
				counting reflections. What's a good way to find them all, using Algorithm D?
				255. [23] Continuing exercise 254, explain how to find special kinds of packings:
					e) Those with the minimum number of pentominoes touching the outer boundary.
				To be started tomorrow 5-Dec-2017. ^_^
			*/
			
			int countBond = 0;
			for  (int s=0; s<l; s++)
			{
				int next = x[s];
				while (((DanceNode*)dance[next-1])->TOP >0)
				{
					next = next -1;
				}

				int cord = 0;
				bool bBond = false;
				while (((DanceNode*)dance[next])->TOP >0)
				{
					cout<<item_name[dance[next]->TOP]<<" ";
					
					int pos;
					if (cord>0)
					{
						//cout<<((item_name[dance[next]->TOP]).c_str())[1]<<endl;
						if ( ((((item_name[dance[next]->TOP]).c_str())[0])=='0') ||
							 ((((item_name[dance[next]->TOP]).c_str())[0])=='5') ||//row == 6
							 ((((item_name[dance[next]->TOP]).c_str())[1])=='0') ||
							 ((((item_name[dance[next]->TOP]).c_str())[1])=='9'))//col == 10
						{
							bBond = true;
						}
						
					}

					cord++;
					next = next+1;
				}
				
				if (bBond)
				{
					countBond++;
				}
				//cout<<x[s]<<" (option: "<<(-((dance[x[s]-1])->TOP))+1<<") ";
				cout<<endl;
			}

			bc[countBond]++;
			
			cout<<endl;
			#endif

			#if 1 // 06-Dec-2017 Jacob Below is the version to count Exer 255 f)
			/* TAOCP 7.2.2.1 Exercises
				254. [20] There are 2339 ways to pack the twelve pentominoes into a 6 x 10 box, not
				counting reflections. What's a good way to find them all, using Algorithm D?
				255. [23] Continuing exercise 254, explain how to find special kinds of packings:
					f) X pentomino should touch only the R, S, U and V -- no others.

			*/
			vector<pair<int, int>> rsuv;
			vector<pair<int, int>> xb;
			int Xxsum=0;
			int Xysum=0;
			for  (int s=0; s<l; s++)
			{
				int next = x[s];
				while (((DanceNode*)dance[next-1])->TOP >0)
				{
					next = next -1;
				}

				int cord = 0;
				char head;
				while (((DanceNode*)dance[next])->TOP >0)
				{
					cout<<item_name[dance[next]->TOP]<<" ";
					
					if (cord==0)
					{
						head = ((item_name[dance[next]->TOP]).c_str())[0];
					}

					

					if (cord>0)
					{
						if ((head=='X') || (head=='R') || (head=='S') || (head=='U') || (head=='V'))
						{
							int x;
							int y;
							char xchar = ((item_name[dance[next]->TOP]).c_str())[0];
							char ychar = ((item_name[dance[next]->TOP]).c_str())[1];
							//cout<<head<<"  "<<xchar<<"  "<<ychar<<endl;
							x = xchar-'0';
							y = ychar-'0';
							//cout<<head<<" "<<x<<" "<<y<<endl;
							//cout<<((item_name[dance[next]->TOP]).c_str())[1]<<endl;
							if (head=='X')
							{
								Xxsum +=x;
								Xysum +=y;
								//cout<<head<<" "<<Xxsum<<" "<<Xysum<<endl;
							}
							else
							{
								rsuv.push_back(std::make_pair(x,y));
							}

							#if 0
							if (head=='R')
							{
								xb.push_back(make_pair(x,y));
							}
							#endif
						}
					}

					cord++;
					next = next+1;
				}
				
				
				cout<<endl;
			}
			
			int xc = Xxsum / 5;
			int yc = Xysum / 5;
			/*
				   #
				  ###
				   #
			   
			    	         (xc-2,yc)

				(xc-1,yc-1)      #      (xc-1, yc+1)

	(xc, yc-2)		 #	  	  (xc,yc)		 #			(xc, yc+2)

				(xc+1, yc-1)	 #		(xc+1, yc+1)

							(xc+2, yc)
			*/

			if (((xc-2)>=0) && (yc>=0))
			{
				xb.push_back(make_pair(xc-2,yc));
			}

			if (((xc-1)>=0) && (yc-1))
			{
				xb.push_back(make_pair(xc-1,yc-1));	
			}
			

			if (((xc-1)>=0) && ((yc+1)>=0))
			{
				xb.push_back(make_pair(xc-1,yc+1));
			}
			
			if ((xc>=0) && ((yc-2)>=0))
			{
				xb.push_back(make_pair(xc,yc-2));
			}

			if ((xc>=0) && ((yc+2)>=0))
			{
				xb.push_back(make_pair(xc,yc+2));
			}

			if (((xc+1)>=0) && ((yc-1)>=0))
			{
				xb.push_back(make_pair(xc+1,yc-1));	
			}
			
			if (((xc+1)>=0) && ((yc+1)>=0))
			{
				xb.push_back(make_pair(xc+1,yc+1));
			}
			
			if (((xc+2)>=0) && (yc>=0))
			{
				xb.push_back(make_pair(xc+2,yc));
			}
			

#if 0
			cout<<"("<<xc-2<<","<<yc<<")"<<"("<<xc-1<<","<<yc-1<<")"<<"("<<xc-1<<","<<yc+1<<")"<<endl;
			cout<<"("<<xc<<","<<yc-2<<")"<<"("<<xc<<","<<yc+2<<")"<<"("<<xc+1<<","<<yc-1<<")"<<endl;
			cout<<"("<<xc+1<<","<<yc+1<<")"<<"("<<xc+2<<","<<yc<<")"<<endl;
#endif
			/* For each element in xb, see if belongs to rsuv or not.
				If yes, then it meets the requirement of Exercise 255. f)
				If no, then X touchs other pentomino.

			*/
			bool bT = true;
			vector<pair<int, int>>::iterator it;
			for (it=xb.begin(); it!=xb.end(); it++)
			{
				//if (find(rsuv.begin(), rsuv.end(),make_pair(it->first,it->second))==rsuv.end())
				if (find(rsuv.begin(), rsuv.end(), *it)==rsuv.end())
				{
					bT = false;
					break;
				}
			}

			if (bT)
			{
				touchX++;
				index.push_back(count);
			}

			cout<<endl;
			#endif
		}

		goto C8;
	}

C3:/*[Choose i.] At this point the items i_1, ..., i_t still need to be covered, where 
	 i_1 = RLINK(0), i_(j+1) = RLINK(i_j), RLINK(i_t) = 0. Choose one of them, and 
	 call it i. (The MRV heuristic of exercise 9 often works well in practice.)
	*/
	//TODO: To replace with MRV in exercise 9
	//i = record[0]->RLINK;

	/* 7.2.2.1 COMBINATORIAL SEARCHING (F5C: 11 Oct 2017@2319)  Exercise
	  9. [18] Explain how to branch in step D3 on an item i for which LEN(i) is minimum.
	If several items have that minimum length, i itself should also be minimum. (This
	choice is often called the "minimum remaining values" (MRV) heuristic.)
	*/
	/* Jacob 2017-10-31 20:37 This is a very simple routine to implement MRV heuristic, 
		which is used to choose the item to be covered with the minimum length and minimum index.
		MRV heuristic makes fundanmental changes to processing speed of Algorithm D and Algorithm C.
		Without MRV heuristic, Algorithm C just can not get first output after several hours.
		By using MRV heuristic, Algorithm C get the output almost immediately.
	 */
	{
	int start = 0;

	int min_len = 0;
	int min_addr = 0;
	int i_addr = 0;
	int i_len = 0;

	i_addr = record[0]->RLINK;
	i_len = dance[i_addr]->LEN;
	min_addr = i_addr;
	min_len = i_len;

	while ((record[i_addr]->RLINK) != start)
	{
		i_addr = record[i_addr]->RLINK;
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

C4:/*[Cover i.] Cover item i using (50), and set x_l = DLINK(i). */
	cover(i);
	//x.push_back(dance[i]->DLINK);
	x[l] = dance[i]->DLINK;
C5:/*[Try x_l] If x_l = i, go to C7 (we've tried all options for i). Otherwise set
	 p <- (x_l)+1, and do the following while p != x_l: Set j <- TOP(p); if j<=0, set 
	 p <- ULINK(p); otherwise commit(p,j) and set p <- p+1. (This covers the 
	 items != i in the option that contains p.) Set l <- l+1 and return to C2.
	*/
	if ( x[l] == i)
	{
		goto C7;
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
				commit(p,j);
				p = p+1;
			}
		}

		l = l+1;
		goto C2;
	}

C6:/*[Try again.] Set p <- (x_l) - 1, and do the following while p != x_l: Set 
	 j <- TOP(p); if j <= 0, set p <- DLINK(p); otherwise uncommit(p,j) and set 
	 p <- p-1. (This uncovers the items != i in the option that contains p, using 
	 the reverse order.) Seet i <- TOP(x_l), x_l <- DLINK(x_l), and return to C5.
	*/
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
			uncommit(p,j);
			p = p-1;
		}
	}

	i = dance[x[l]]->TOP;
	x[l] = dance[x[l]]->DLINK;
	goto C5;

C7://[Backtrack.]
	uncover(i);

C8://[Leave level l.]
	if (l == 0)
	{
		cout<<"Processing Completed."<<endl<<"Total number of solutions is "<<count<<endl;
		//cout<<"cut_610a is :"<<cut_610a<<endl;
		/*
		for (int i=0; i<13; i++)
		{
			cout<<"For "<<i<<"pentominoes touch boundary, Number of solutions: "<<bc[i]<<endl;
		}
		*/
		cout<<"touchX: "<<touchX<<endl;
		for (int i=0; i<touchX; i++)
		{
			cout<<index[i]<<" ";			
		}
		cout<<endl;
		return 0;
	}
	else
	{
		l = l-1;
		goto C6;
	}
}

DanceLink::DanceLink(string& fileName)
{
	danceFile = fileName;
	record.clear();
	dance.clear();
	N = -1;
	np = -1;
	P = -1;
	Z = -1;
	l = -1;
	count = 0;
	x.clear();
}

DanceLink::DanceLink(string& fileName, int numOfPrimaryItems)
{
	danceFile = fileName;
	record.clear();
	dance.clear();
	N = -1;
	np = numOfPrimaryItems;
	P = -1;
	Z = -1;
	l = -1;
	count = 0;
	x.clear();	
}


int DanceLink::cover(int i)
{
	int p = dance[i]->DLINK;
	while (p!=i)
	{
		hide(p);
		p = dance[p]->DLINK;
	}

	int l = record[i]->LLINK;
	int r = record[i]->RLINK;
	record[l]->RLINK = r;
	record[r]->LLINK = l;

	return 0;
}


int DanceLink::hide(int p)//this is actually hide'(p), while function name not allow '
{
	int x = -1;
	int u = -1;
	int d = 0;

	int q = p+1;
	while (q != p)
	{
		/*
		if (dance[q]->COLOR < 0)
		{
			//ignores node q when COLOR(q)<0
			q = q+1;
		}
		else
		*/
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
				if (dance[q]->COLOR < 0)
				{
					//ignores node q when COLOR(q)<0
					q = q+1;
				}
				else
				{
					dance[u]->DLINK = d;
					dance[d]->ULINK = u;
					dance[x]->LEN = dance[x]->LEN - 1;
					q = q+1;
				}
			}
		}
	}	

	return 0;
}

int DanceLink::uncover(int i)
{
	int l = record[i]->LLINK;
	int r = record[i]->RLINK;
	
	record[l]->RLINK = i;
	record[r]->LLINK = i;

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
		/*
		if (dance[q]->COLOR < 0)
		{
			//ignores node q when COLOR(q)<0
			q = q+1;
		}
		else
		*/
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
				if (dance[q]->COLOR < 0)
				{
					//ignores node q when COLOR(q)<0
					q = q-1;
				}
				else
				{
					dance[u]->DLINK = q;
					dance[d]->ULINK = q;
					dance[x]->LEN = dance[x]->LEN + 1;
					q = q-1;
				}
			}
		}
	}

	return 0;
}


int DanceLink::commit(int p, int j)
{
	if (dance[p]->COLOR == 0)
	{
		cover(j);
	}

	if (dance[p]->COLOR > 0)
	{
		purify(p);
	}

	return 0;
}

int DanceLink::purify(int p)
{
	char c = dance[p]->COLOR;
	int  i = dance[p]->TOP;
	int  q = dance[i]->DLINK;

	while (q != i)
	{
		if (dance[q]->COLOR != c)
		{
			hide(q);
		}
		else
		{
			if (q != p)
			{
				dance[q]->COLOR = -1;
			}
		}

		q = dance[q]->DLINK;
	}

	return 0;
}


int DanceLink::uncommit(int p, int j)
{
	if (dance[p]->COLOR == 0)
	{
		uncover(j);
	}

	if (dance[p]->COLOR > 0)
	{
		unpurify(p);
	}

	return 0;
}

int DanceLink::unpurify(int p)
{
	char c = dance[p]->COLOR;
	int  i = dance[p]->TOP;
	int  q = dance[i]->ULINK;

	while (q != i)
	{
		if (dance[q]->COLOR < 0)
		{
			dance[q]->COLOR = c;
		}
		else
		{
			if (q != p)
			{
				unhide(q);
			}
		}

		q = dance[q]->ULINK;
	}

	return 0;
}

/*
bool DanceLink::touch()
{
	for (int i=np+1; i<record.size(); i++)
	{
		cout<<i<<":dance["<<i<<"]->LEN: "<<dance[i]->LEN<<endl;
		#if 0
		if (dance[i]->LEN > 0)
		{
			int p = dance[i]->DLINK;
			while (p != i)
			{
				if (dance[p-1]->TOP <= 0)
				{
					cout<<p-1<<" "<<dance[p-1]->TOP<<" which is <= 0"<<endl; 
					return false;
				}

				p = dance[p]->DLINK;
			}
		}
		#endif
	}

	return true;
}
*/

/* 7.2.2.1 DANCING LINKS: EXERCISES  -- First Set
 8. [22] Design an algorithm to set up the initial memory contents of an exact cover
problem, as needed by Algorithm D and illustrated in Table 1.  The input to your
algorithm should consist of a sequence of lines with the following format:
   The very first line lists the names of all items.
   Each remaining line specifies the items of a particular option, one option per line.
*/

/* 7.2.2.1 Color-controlled covering.


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
	
	DanceRecord* pHead = new DanceRecord;
	pHead->NAME = string("-");
	pHead->LLINK = -1;
	pHead->RLINK = 1;
	record.push_back(pHead);

	DanceNode* pNode = new DanceNode;
	pNode->LEN = 0;
	pNode->ULINK = -1;
	pNode->DLINK = -1;	
	
	dance.push_back(pNode);


	int node_addr = 0;
	
	for (auto& s: tokens)
	{
		//cout<<'"'<<s<<'"'<<endl;
		item[s] = 0;
		node_addr++;
		item_count++;

		DanceRecord* pRecord = new DanceRecord;
		pRecord->NAME = s;
		pRecord->LLINK = node_addr-1;
		pRecord->RLINK = node_addr+1;
		record.push_back(pRecord);

		DanceNode* pNode = new DanceNode;
		pNode->LEN = 0;
		pNode->ULINK = node_addr;
		pNode->DLINK = node_addr;
		dance.push_back(pNode);

		item_addr[s] = node_addr;
		item_name[node_addr] = s;
	}

	//record[node_addr]->RLINK = 0;
	//record[0]->LLINK = node_addr; 


	node_addr++;

	DanceRecord* pTail = new DanceRecord;
	pTail->NAME = "-";
	pTail->LLINK = node_addr-1;
	pTail->RLINK = 0;
	record.push_back(pTail);
	record[0]->LLINK = node_addr; 


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
		for (auto& sc: options)
		{	
			//To check whether s is composed of single item or item:color
			auto pos = sc.find(':');
			string s;
			char c;
			//TODO: To trim leading and tailing spaces later on.
			if (pos != string::npos)
			{
				s = sc.substr(0,pos);
				//c = sc.substr(pos+1, sc.size()-pos);
				size_t n = (sc.substr(pos+1, sc.size()-pos)).find_first_not_of(' ');
				if (n != string::npos)
				{
					c = (sc.substr(pos+1, sc.size()-pos)).at(n);
				}
				else
				{
					c = 0;
				}
				//cout<<"sc:|"<<sc<<"|     s:|"<<s<<"|     c:|"<<c<<"|"<<endl;
			}
			else
			{
				s = sc;
				c = 0;
			}

			item[s]++;

			//cout<<s<<endl;

			DanceNode* pNode = new DanceNode;
			pNode->TOP = item_addr[s];
			pNode->COLOR = c;

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
			dance[item_addr[s]]->LEN++;

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
		pNode->COLOR = '-';
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

#if 0
int ck = 0;
for (auto& s: dance)
{
	cout<<ck<<"->TOP: "<<s->TOP<<"    "<<ck<<"->LEN: "<<s->LEN<<endl;
	ck++;
}
#endif

#if defined(DEBUGPRINT)
	int k = 0;
	int round=0;
	cout<<endl;
	cout<<"THE INITIAL CONTENTS OF MEMORY CORRESPONDING TO ["<<danceFile<<"]*********"<<endl;
	cout<<"*****************************        START      ************************"<<endl<<endl;
	for (auto& s: dance)
	{
		if (k<0)
		{
			//N/A
		}
		
		if (k==0)
		{
			cout<<"Below are list of "<<item_count<<" items: "<<endl;
			cout<<"- "<<k<<" "<<s->LEN<<" "<<s->ULINK<<" "<<s->DLINK<<" "<<s->COLOR<<endl;
		}
		
		if ((k>0) && (k<=item_count))
		{
			cout<<item_name[k]<<" "<<k<<" "<<s->LEN<<" "<<s->ULINK<<" "<<s->DLINK<<endl;
				//cout<<tokens[k-1]<<": "<<s->LEN<<" ";
		}

		if (k==item_count+1)
		{
			cout<<"- "<<k<<" "<<s->TOP<<" "<<s->ULINK<<" "<<s->DLINK<<" "<<endl<<endl;
			cout<<"Below are list of "<<P<<" options:"<<endl;
			cout<<endl;
		}
		
		if (k>item_count)
		{
			if (s->TOP>0)
			{
				cout<<item_name[s->TOP]<<" "<<k<<" "<<s->TOP<<" "<<s->ULINK<<" "<<s->DLINK<<" "<<\
				(((s->COLOR)==0)? '0':s->COLOR)<<" "<<endl;
			}

			if (s->TOP<0)
			{
				cout<<"  "<<k<<" "<<s->TOP<<" "<<s->ULINK<<" "<<s->DLINK<<" "<<s->COLOR<<" "<<endl;
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

		k++;
	}

	cout<<"THE INITIAL CONTENTS OF MEMORY CORRESPONDING TO ["<<danceFile<<"]*********"<<endl;
	cout<<"*****************************     END    **********************************"<<endl<<endl;
#endif	

	return item_count;
}



int DanceLink::exer8()
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

I1:/*[Read the first line.] Set i <- N_1 <- 0. Then, for each item name a on the first 
	 line, set i <- i+1, NAME(i) <- a, LLINK(i) < i-1, RLINK(i-1) <- i. If a names 
	 the first secondary item, also set N_1 <- i-1. (In practice a is limited to at most 8 
	 characters, say. One should report an error if a = NAME(j) for some j < i.)
	*/
	int i = 0;
	int N_1 = 0;	
	
	DanceRecord* pHead = new DanceRecord;
	pHead->NAME = string("-");
	pHead->LLINK = -1;
	pHead->RLINK = 1;
	record.push_back(pHead);

	vector<string> tokens(beg, end);
	for (auto& s: tokens)
	{
		if (s.compare("SECOND")==0)
		{
			N_1 = i;
			continue;
		}

		//cout<<'"'<<s<<'"'<<endl;
		i = i+1;
		DanceRecord* pRecord = new DanceRecord;
		record.push_back(pRecord);
		record[i]->NAME = s;
		record[i]->LLINK = i-1;
		record[i-1]->RLINK = i;
	}

I2:/*[Finish the horizontal list.] Set N <- i. If N_1 = 0 (there were no secondary items),
	 set N_1 <- N. Then set LLINK(N+1) <- N, RLINK(N) <- N+1, LLINK((N_1)+1) <- 
	 N+1, RLINK(N+1) <- (N_1)+1, LLINK(0) <- N_1, RLINK(N_1) <- 0. (The active 
	 secondary items, if any, are accessible from record N+1.)
	*/
	N = i;
	if (N_1 == 0)
	{
		N_1 = N;
	}


	DanceRecord* pTail = new DanceRecord;
	pTail->NAME = "-";
	record.push_back(pTail);

	record[N+1]->LLINK = N;
	record[N]->RLINK = N+1;
	record[N_1+1]->LLINK = N+1;
	record[N+1]->RLINK = N_1+1;
	record[0]->LLINK = N_1;
	record[N_1]->RLINK = 0;

I3:/*[Prepare for options.] Set LEN(i) <- 0 and ULINK(i) <- DLINK(i) <- i for 1 <= i <= N.
	 (These are the header nodes for the N item lists, which are intially empty.) Then
	 set M <- 0, p <- N+1, TOP(p) <- 0. (Node p is the first spacer.)
	*/
	


I4:/*[Read an option.] Terminate with Z <- p if no input remains. Otherwise let the next 
	 line of input contain the item names a_1 ... a_k, and do the following for 1 <= j <= k:
	 Use an algorithm from Chapter 6 to find the index i_j for which NAME(i_j) = a_j.
	 (Report an error if unsuccessful. Complain also if an item name appears more 
	 than once in the same option, because a duplicate might make Algorithm D fail
	 spectacularly.) Set LEN(x_j) <- LEN(i_j) + 1, q <- ULINK(i_j), ULINK(p+j) <- q,
	 DLINK(q) <- p+j, DLINK(p+j) <- i_j, ULINK(i_j) <- p+j, TOP(p+j) <- i_j.
	*/

I5:/*[Finish an option.] Set M <- M+1, DLINK(p) <- p+k, p<- P+k+1, TOP(q) <- -M,
	 ULINK(p) <- p-k, and return to step I4. (Node p is the next space.)
	*/


	for (int i=0; i<record.size(); i++)
	{
		cout<<"Item: "<<i<<"  NAME:"<<record[i]->NAME<<"  LLINK:"<<record[i]->LLINK<<"  RLINK:"<<record[i]->RLINK<<endl;
	}

	return 0;//TODO: "return 0;" added 2017-Oct-19 20:56 to suppress the warning of control reaches  		
}