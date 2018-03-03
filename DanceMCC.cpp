/*  DanceMultiColor.cpp

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

Notice that COLOR = 0 when no color has been specified. The COLOR 
fields of header nodes (nodes 1-5 in this example) and spacer nodes (nodes 6, 
11, 16, 19, 22, 25) need not be initialized because they're never examined.

	It's easy to see how these COLOR fields can be used to get the desired effect:
When an option is chosen, we "purify" any secondary items that it names, 
by effectively removing all options that have conflicting colors. One slightly 
subtle point arises, because we don't want to waste time purifying a list that 
has already been culled. The trick is to set COLOR(x) <- -1 in every node x 
that's already known to have the correct color, except in nodes that originally 
triggered purification.

cover'(i) is like cover(i), but it calls hide'(p) instead of hide(p);			(50)
hide'(p) is hide(p), but it ignores node q when COLOR(q)<0;						(51)
uncover'(i) is like uncover(i), but it call unhide'(p) instead of unhide(p);	(52)
unhide'(p) is like unhide(p), but it ignores node q when COLOR(q)<0.			(53)

Our colorful algorithm also introduces two new operations and their inverses:

commit(p,j) = {
	If COLOR(p) == 0, cover'(j);	
	if COLOR(p) > 0, purify(p).		}											(54)

purify(p) = {
	Set c <- COLOR(p), i <- TOP(p), q <- DLINK(i).
	While q != i, do the following and set q <- DLINK(q):
		if COLOR(q) != c, hide'(q);
		otherwise if q != p, COLOR(q) <- -1.	}								(55)

uncommit(p,j) = {
	If COLOR(p) == 0, uncover'(j);
	if COLOR(p) > 0, unpurify(p).	}											(56)

unpurify(p) = {
	Set c <- COLOR(p), i <- TOP(p), q <- ULINK(i).
	While q != i, do the following and set q <- ULINK(q):
		if COLOR(q) < 0, COLOR(q) <- c;
		otherwise if q != p, unhide'(q).	}									(57)
Otherwise Algorithm C is almost word-for-word identical to Algorithm D.

Algorithm C (Exact covering with colors).	This algorithm visits all solutions
to a given XCC problem, using the same conventions as Algorithm D.

C1.[Initialize.] Set the problem up in memory, as in Table 2 (see exercise 8).
	Also set N to the number of items, Z to the last spacer address, and l <- 0.

C2.[Enter level l.] If RLINK(0) = 0 (hence all items have been covered), visit the 
	solution that is specified by x_0 x_1 ... x_(l-1) and go to C8. (See exercise 12.)

C3.[Choose i.] At this point the items i_1, ..., i_t still need to be covered, where 
	i_1 = RLINK(0), i_(j+1) = RLINK(i_j), RLINK(i_t) = 0. Choose one of them, and 
	call it i. (The MRV heuristic of exercise 9 often works well in practice.)

C4.[Cover i.] Cover item i using (50), and set x_l <- DLINK(i).

C5.[Try x_l.] If x_l = i, go to C7 (we've tried all options for i). Otherwise set
	p <- x_l + 1, and do the following while p != x_l: Set j <- TOP(p); if j <= 0, set 
	p <- ULINK(p); otherwise commit(p,j) and sete p <- p+1. (This covers the 
	items != i in the option that contains p.) Set l <- l+1 and return to C2.

C6.[Try again.] Set p <- x_l - 1, and do the following while p != x_l: Set 
	j <- TOP(p); if j <= 0, set p <- DLINK(p); otherwise uncommit(p,j) and set 
	p <- p - 1. (This uncovers the items != i in the option that contains p, using 
	the reverse order.) Set i <- TOP(x_l), x_l <- DLINK(x_l), and return to C5.

C7.[Backtrack.] Uncover item i using (52).

C8.[Leave level l.] Terminate if l = 0. Otherwise set l <- l - 1 and go to C6.

	Algorithm C applies directly to several problems that we've already dis-
cussed in previous sections. For example, it readily generates word rectangles, 
as well as intriguing patterns of words that have more intricate structure (see 
exercise 164-171). We can use it to find all de Bruijn cycles, and their two-
dimensional counterparts (see exercies ???-???); the extra generality of exact 
covering options also makes it easy to impose additional constraints for special 
applications. Furthermore, Algorithm C facilitates experiments with the tetrad 
tilese that we studied in Section 2.3.4.3 (see exercises 190 and 191).
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

#include "DanceMCC.h"

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
		cout<<"Usage: mcc datafile [nnn]"<<endl;
		cout<<"datafile is the file name of raw data including primary items, secondary items \
		 and options."<<endl;
		cout<<"nnn is the number of primary items. If no, then by default all items are primary items."<<endl;
		return 0;
	}

	string options(argv[1]);
	int n = 0;
	if (argc > 2)
	{
		n = atoi(argv[2]);
	}

	DanceLink queen(options, n);
	queen.algorithmM();

	return 0;
}

/* 18-Sep-2017 20:32
Algorithm M (Covering with multiplicities and colors). This algorithm visits 
all solutions to a given MCC problem, extending Algorithms D and C.
*/
#undef DEBUGPRINT
//#define DEBUGPRINT

int DanceLink::algorithmM()
{
	int i = -1;
	int j = -1;
	int p = -1;
	int q = -1;

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

/* Algorithm M (Covering with multiplicities and colors). This algorithm visits
	all solutions to a given MCC problem, extending Algorithm D and C.
*/
M1:/*[Initialize.] Set the problem up in memory as in step C1 of Algorithm C,
		with the addition of multiplicity specifications (72). Also set N to the 
		number of items, N_1 to the number of primary items, Z to the last spacer
		address, and l <- 0. */

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
		FT.push_back(0);
	}

	cout<<"Record.size: "<<record.size()<<endl;
	
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

	/* We're ready now to write Algorithm M, except that we need a way to represent
		multiplicities in the data structures. For this purpose every primary 
		item has two new fields, SLACK and BOUND. Suppose the desired multiplicity of p
		is in the interval [u..v], where 0 <= u <= v and v != 0; Algorithm D and C
		correspond to the case u = v = 1. Then we set SLACK(p) <- v-u, BOUND(p) <- v */	
	
	int u[np+1];
	int v[np+1];

	#if 1//for 4-5-Letter-word
	for (int i=1; i<=np; i++)
	{
		u[i] = 1;
		v[i] = 1;
	}
	u[np] = 8;//primary item 36: #
	v[np] = 8;
	#endif

	#if 0 //for 5-queens
	for (int i=1; i<=np; i++)
	{
		u[i] = 1;
		v[i] = 5;//5 queens
	}
	u[1] = 5;
	v[1] = 5;
	#endif

	/* Setup multiplicity for items generated for 5 queens problem:
			We can solve it, MCC-wise, by introducing n^2 + 1 primary items, namely
		the pairs ij for 0<= i,j <n and the special item #, together with n^2 options:
					'# ij (i_1)(j_1) (i_2)(j_2) ... (i_t)(j_t)' for 0<=i,j<n,		(64)
		where (i_1)(j_1), (i_2)(j_2), ..., (i_t)(j_t) are the cells attacked by a queen on ij.
		Each cell ij is assigned the multiplicy [1..m]; item # gets multiplicity m.

	*/

	record[0]->SLACK = 0;
	record[0]->BOUND = 0;

	for (int i =1; i<=np; i++)
	{
		record[i]->SLACK = v[i]-u[i];//To be filled with actual v-u
		record[i]->BOUND = v[i];//To be filled with v
	}

	for (int i=np+1; i<record.size(); i++)
	{
		record[i]->SLACK = 0;
		record[i]->BOUND = 0;
	}

#if	defined(DEBUGPRINT)
	for (int i=0; i<record.size(); i++)
	{
		cout<<"Item: "<<i<<"  NAME:"<<record[i]->NAME<<"  LLINK:"<<record[i]->LLINK<<"  RLINK:" \
			<<record[i]->RLINK<<"  SLACK:"<<record[i]->SLACK<<" BOUND:"<<record[i]->BOUND<<endl;
	}
#endif

	for (int i=0; i<record.size(); i++)
	{
		cout<<"Item: "<<i<<"  NAME:"<<record[i]->NAME<<"  LLINK:"<<record[i]->LLINK<<"  RLINK:" \
			<<record[i]->RLINK<<"  SLACK:"<<record[i]->SLACK<<" BOUND:"<<record[i]->BOUND<<endl;
	}

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

	/*
	for (int st = N+1; st<Z; st++)
	{
		cout<<item_name[dance[st]->TOP]<<":"<<dance[st]->COLOR<<" "<<endl;;
	}
	*/
	

M2:/*[Enter level l.] If RLINK(0) = 0 (hence all items have been covered), visit the 
	 solution that is specified by x_0 x_1 ... x_l-1 and go to M9. (See exercise 238.)
	*/
#if	defined(DEBUGPRINT)	
	cout<<"Enter M2: record[0]->RLINK: "<<record[0]->RLINK<<" and l:"<<l<<endl;
#endif



	for  (int k=1; k<=np; k++)
	{
		if ((record[k]->BOUND) > (record[k]->SLACK))
		{
			if (record[0]->RLINK == 0)
			{
				goto M9;
			}
			else
			{
				goto M3;
			}
		}
	}
			
	count++;

	if ((count % 300) == 0)
	{
		cout<<count<<"th solutions so far."<<endl;
	}

#if 1
			cout<<"This is the "<<count<<"th solution."<<endl;
			//Visit solution specified by x[0..l-1]
			for (int s=0; s<l; s++)
			{
				//cout<<x[s]<<" (option: "<<(-((dance[x[s]-1])->TOP))+1<<") ";
				cout<<x[s]<<" ";
			}
			cout<<endl;

			//Original output for dance linking color 27-Nov-2017 Jacob

			for  (int s=0; s<l; s++)
			{
				int next = x[s];
				while (((DanceNode*)dance[next-1])->TOP >0)
				{
					next = next -1;
				}

				while (((DanceNode*)dance[next])->TOP >0)
				{
					cout<<item_name[dance[next]->TOP]<<":"<<dance[next]->COLOR<<" ";
					next = next+1;
				}
				//cout<<x[s]<<" (option: "<<(-((dance[x[s]-1])->TOP))+1<<") ";
				cout<<endl;
			}
			cout<<endl;

#endif

	goto M9;


#if 0
	if (record[0]->RLINK == 0)
	{
		{
			for  (int k=1; k<=np; k++)
			{
				if ((record[k]->BOUND) > (record[k]->SLACK))
				{
					goto M9;
				}
			}
			
			count++;

			if ((count % 300) == 0)
			{
				cout<<count<<"th solutions so far."<<endl;
			}
			goto M9;//Jacob 2018-02-14 10:29 pm To skip print solutions of options.
			cout<<"Total level: "<<l<<endl;

			
			cout<<"This is the "<<count<<"th solution."<<endl;
			//Visit solution specified by x[0..l-1]
			for (int s=0; s<l; s++)
			{
				//cout<<x[s]<<" (option: "<<(-((dance[x[s]-1])->TOP))+1<<") ";
				cout<<x[s]<<" ";
			}
			cout<<endl;

			//Original output for dance linking color 27-Nov-2017 Jacob

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
		}

		#if	defined(DEBUGPRINT)	
		cout<<"M2: Before goto M9."<<endl;
		#endif

		#if 0
		//Test code
		for (int i=0; i<=np+1; i++)
		{
			cout<<"i:"<<i<<"    LLINK: "<<record[i]->LLINK<<"    RLINK: "<<record[i]->RLINK<< \
			"    SLACK:"<<record[i]->SLACK<<"    BOUND:"<<record[i]->BOUND<<endl;
		}
		#endif
		

		goto M9;
	}
#endif	

M3:/*[Choose i.] At this point the items i_1, ..., i_t still need to be covered, where 
	 i_1 = RLINK(0), i_(j+1) = RLINK(i_j), RLINK(i_t) = 0. Choose one of them, and 
	 call it i. (The MRV heuristic of exercise 240 often works well in practice.)
	 If the branching degree θ_i is zero (see exercise 240), go to M9.
	*/
	/* 7.2.2.1 COMBINATORIAL SEARCHING (F5C: 25 Dec 2017@1312)  Exercise 240.
		240. [21] Extend answer 9 to the more general situation that arises in Algorithm M:
		a) Let θ_p be the number of different choices that will be explored at the current 
		   position of the search tree if primary item p is selected for branching. Express θ_p
		   as a function of LEN(p), SLACK(p), and BOUND(p).
		b) Suppose θ_p = θ_p' and SLACK(p)=SLACK(p')=0, but LEN(p)<LEN(p'). Should 
		   we prefer to branch on p or on p', based on exercise 239?
	*/
	#if	defined(DEBUGPRINT)	
	cout<<"Enter M3"<<endl;
	#endif

	#if 0 // This is for most simple case
	i = record[0]->RLINK;
	//cout<<"M3 level: "<<l<<"  Choose i: "<<i<<endl;
	#else // Sharp preference heuristic is used for 4-5-Letter-word issue.
	i = sharpHeur();
	#endif

	#if	defined(DEBUGPRINT)	
	cout<<"M3: record[0]->RLINK: "<<record[0]->RLINK<<" and i: "<<i<<endl;
	#endif

	//If the branching degree θ_i is zero (see exercise 240), go to M9.
	//if ((dance[i]->LEN) < (record[i]->BOUND - record[i]->SLACK))
	{
		int ax = 0;
		int bx = 0;
		ax = (record[i]->BOUND >record[i]->SLACK)? record[i]->BOUND - record[i]->SLACK:0;
		bx = ((dance[i]->LEN + 1) > ax)? (dance[i]->LEN + 1 - ax):0;
		
		if (bx==0)
		{
			goto M9;
		}
	}

M4:/*[Prepare to branch on i.] Set x_l <- DLINK(i) and BOUND(i) <- BOUND(i)-1.
	  If BOUND(i) is now zero, cover item i using (50). If BOUND(i) != 0 or
	  SLACK(i) != 0, set FT[i] <- x_l.
	*/
	//cout<<"M4 with i: "<<i<<endl;
	#if	defined(DEBUGPRINT)
	cout<<"Enter M4:"<<endl;
	#endif

	x[l] = dance[i]->DLINK;
	record[i]->BOUND -=1;
	//cout<<"M4  x_l: "<<x[l]<<"  i: "<<i<<"  bound:"<<record[i]->BOUND<<endl;
	if (0 == record[i]->BOUND)
	{
		#if	defined(DEBUGPRINT)
		cout<<"M4: record["<<i<<"]->BOUND is 0. Before call cover_HI("<<i<<")"<<endl;
		#endif
		cover_HI(i);
		//cout<<"M4: record["<<i<<"]->BOUND is 0. Call cover_HI("<<i<<")"<<endl;
		//return 0;
		#if	defined(DEBUGPRINT)
		cout<<"M4: record["<<i<<"]->BOUND is 0. After call cover_HI("<<i<<")"<<endl;
		#endif
	}	
	else
	{
	if ((0 != record[i]->BOUND) || (0 != record[i]->SLACK))
	{
		#if	defined(DEBUGPRINT)
		cout<<"M4: otherwise. To set FT["<<i<<"] to "<<x[l]<<endl;
		#endif
		//cout<<"M4: otherwise. To set FT["<<i<<"] to "<<x[l]<<endl;
		//FT[i] = x[l];
		//cout<<"M4: i:"<<i<<"  BOUND: "<<record[i]->BOUND<<"  SLACK:"<<record[i]->SLACK \
			<<" FT["<<l<<"] to "<<x[l]<<endl;
		FT[l] = x[l];
	}
	}
	
M5:/*[Possibly tweak x_l.] If BOUND(i) = SLACK(i) = 0, go to M6 if x_l != i, to M8
	  if x_l = i. (That case is like Algorithm C.) Otherwise if LEN(i) <= BOUND(i)-
	  SLACK(i), go to M8 (list i is too short). Otherwise if x_l != i, call tweak(x_l,i)
	  (see (69)), or tweak'(x_l,i) if BOUND(i) = 0. Otherwise if BOUND(i) != 0, set
	  p <- LLINK(i), q <- RLINK(i), RLINK(p) <- q, LLINK(q) <- p.
	*/
	#if	defined(DEBUGPRINT)
	cout<<"Enter M5:"<<endl;
	#endif
	
	if ((0==record[i]->BOUND) && (0==record[i]->SLACK))
	{
		if (i != x[l])
		{
			//cout<<"M5: i!=x[l] ==> goto M6  with i:"<<i<<" and l:"<<l<<" x["<<l<<"]:"<<x[l]<<endl;
			#if	defined(DEBUGPRINT)
			cout<<"M5: i!=x[l] ==> goto M6  with i:"<<i<<" and l:"<<l<<" x["<<l<<"]:"<<x[l]<<endl;
			#endif

			goto M6;
		}
		else
		{
			//cout<<"M5: i==x[l] ==> goto M8  with i:"<<i<<" and l:"<<l<<" x["<<l<<"]:"<<x[l]<<endl;
			#if	defined(DEBUGPRINT)
			cout<<"M5: i==x[l] ==> goto M8  with i:"<<i<<" and l:"<<l<<" x["<<l<<"]:"<<x[l]<<endl;
			#endif

			goto M8;
		}
	}
	else 
	{
		if ((dance[i]->LEN) <= (record[i]->BOUND - record[i]->SLACK))// list i is too short
		{
			//cout<<"M5: LEN <= BOUND-SLACK ==> goto M8 with dance["<<i<<"]->LEN: "<<dance[i]->LEN \
				<<"  BOUND-SLACK:"<<record[i]->BOUND - record[i]->SLACK<<endl;
			#if	defined(DEBUGPRINT)
			cout<<"M5: LEN <= BOUND-SLACK ==> goto M8 with dance["<<i<<"]->LEN: "<<dance[i]->LEN \
				<<"  BOUND-SLACK:"<<record[i]->BOUND - record[i]->SLACK<<endl;
			#endif
			goto M8;
		}
		else
		{
			if (i != x[l])
			{
				//FT[l] = x[l];//Jacob 2018-02-10
				if (0 != record[i]->BOUND)
				{
					//cout<<"M5: before tweak("<<x[l]<<","<<i<<"), with l:"<<l<<" BOUND: "<<record[i]->BOUND<<endl;
					#if	defined(DEBUGPRINT)
					cout<<"M5: before tweak("<<x[l]<<","<<i<<"), with l:"<<l<<endl;
					#endif
					tweak(x[l], i);
					#if	defined(DEBUGPRINT)
					cout<<"M5: after tweak("<<x[l]<<","<<i<<"), with l:"<<l<<endl;
					#endif
				}				
				else
				{
					//cout<<"M5: before tweak_HI("<<x[l]<<","<<i<<"), with l:"<<l<<" BOUND: "<<record[i]->BOUND<<endl;
					#if	defined(DEBUGPRINT)
					cout<<"M5: before tweak_HI("<<x[l]<<","<<i<<"), with l:"<<l<<endl;
					#endif
					tweak_HI(x[l], i);
					#if	defined(DEBUGPRINT)
					cout<<"M5: after tweak_HI("<<x[l]<<","<<i<<"), with l:"<<l<<endl;
					#endif
				}
			}
			else
			{
				if (0 != record[i]->BOUND)
				//if ((record[i]->BOUND) < (record[i]->SLACK)) 
				{
					//cout<<"l:"<<l<<" i:"<<i<<" BOUND:"<<record[i]->BOUND<<" SLACK:"<<record[i]->SLACK<<endl;
					#if	defined(DEBUGPRINT)
					#endif
					p = record[i]->LLINK;
					q = record[i]->RLINK;
					record[p]->RLINK = q;
					record[q]->LLINK = p;
				}
			}
		}
	}
	

M6:/*[Try x_l.] If x_l != i, set p <- x_l + 1, and do the following while p != x_l: Set j <-
	  TOP(p); if j <= 0, set p <- ULINK(p); otherwise if j <= N_1, set BOUND(j) <-
	  BOUND(j) - 1, p <- p+1, and cover'(j) if BOUND(j) is now 0; otherwise
	  commit(p,j) and set p <- p+1. (This loop covers or partially covers the
	  items != i in the option that contains x_l.) Set l <- l+1 and return to M2. 
	*/
	#if	defined(DEBUGPRINT)
	cout<<"Enter M6: with i:"<<i<<" l:"<<l<<" x["<<l<<"]:"<<x[l]<<endl;
	#endif

	if (i != x[l])
	{
		p = x[l]+1;

		while (p != x[l])
		{
			#if	defined(DEBUGPRINT)
			cout<<"M6: Enter while loop with p: "<<p<<" and x["<<l<<"]:"<<x[l]<<endl;
			#endif
			j = dance[p]->TOP;
			if (j <= 0)
			{
				p = dance[p]->ULINK;
			}
			else
			{
				if (j <= np)
				{
					record[j]->BOUND -=1;
					p +=1;
					if (0 == record[j]->BOUND)
					{
						#if	defined(DEBUGPRINT)
						cout<<"M6: before cover_HI("<<j<<")"<<endl;
						#endif
						cover_HI(j);
						#if	defined(DEBUGPRINT)
						cout<<"M6: after cover_HI("<<j<<")"<<endl;
						#endif
					}
				}
				else
				{
					#if	defined(DEBUGPRINT)
					cout<<"M6: before commit("<<p<<","<<j<<")"<<endl;
					#endif
					commit(p,j);
					#if	defined(DEBUGPRINT)
					cout<<"M6: after commit("<<p<<","<<j<<")"<<endl;
					#endif
					p +=1;
				}
			}	
		}

		l +=1;
		goto M2;
	}

M7:/*[Try again.] If x_l != i, set p <- x_l - 1, and do the following while p != x_l:
	  Set j <- TOP(p); if j <= 0, set p <- DLINK(p); otherwise if j <= N_1, set
	  BOUND(j) <- BOUND(j) + 1, p <- p-1, and uncover'(j) if BOUND(j) is
	  now 1; otherwise uncommit(p,j) and set p <- p-1. (This loop uncovers
	  the items != i in the option that contains x_l, using the reverse order.) Set
	  x_l <- DLINK(x_l) and return to M5.
	*/
	#if	defined(DEBUGPRINT)
	cout<<"Enter M7: with i:"<<i<<" l:"<<l<<" x["<<l<<"]:"<<x[l]<<endl;
	#endif

	if (i != x[l])
	{
		p = x[l]-1;
		while (p != x[l])
		{
			#if	defined(DEBUGPRINT)
			cout<<"M7: Enter while loop with p: "<<p<<" and x["<<l<<"]:"<<x[l]<<endl;
			#endif
			j = dance[p]->TOP;

			if (j <= 0)
			{
				p = dance[p]->DLINK;
			}
			else
			{
				if (j <= np)
				{
					record[j]->BOUND +=1;
					p -=1;

					if (1 == record[j]->BOUND)
					{
						#if	defined(DEBUGPRINT)
						cout<<"M7: before uncover_HI("<<j<<")"<<endl;
						#endif
						uncover_HI(j);
						#if	defined(DEBUGPRINT)
						cout<<"M7: after uncover_HI("<<j<<")"<<endl;
						#endif
					}
				}
				else
				{
					#if	defined(DEBUGPRINT)
					cout<<"M7: before uncommit("<<p<<","<<j<<")"<<endl;
					#endif
					uncommit(p,j);
					#if	defined(DEBUGPRINT)
					cout<<"M7: after uncommit("<<p<<","<<j<<")"<<endl;
					#endif
					p -=1;
				}
			}
		}

		x[l] = dance[x[l]]->DLINK;
		goto M5;
	}

M8:/*[Restore i.] If BOUND(i) = SLACK(i) = 0, uncover item i using (52).
	  Otherwise call untweak(l) (see (71)), or untweak'(l) if BOUND(i) = 0. Set
	  BOUND(i) <- BOUND(i) + 1.
	*/
	#if	defined(DEBUGPRINT)
	cout<<"Enter M8: with i:"<<i<<" record["<<i<<"]->SLACK:"<<record[i]->SLACK<< \
		" record["<<i<<"]->BOUND:"<<record[i]->BOUND<<endl;
	#endif

	if ((0 == (record[i]->BOUND)) && (0 == (record[i]->SLACK)))
	{
		#if	defined(DEBUGPRINT)
		cout<<"M8: before uncover_HI("<<i<<")"<<endl;
		#endif
		uncover_HI(i);
		#if	defined(DEBUGPRINT)
		cout<<"M8: after uncover_HI("<<i<<")"<<endl;
		#endif
	}
	else
	{
		if (0 != record[i]->BOUND)
		{
			#if	defined(DEBUGPRINT)
			cout<<"M8: before untweak("<<l<<")"<<endl;
			#endif
			untweak(l);
			//untweak(i);
			#if	defined(DEBUGPRINT)
			cout<<"M8: after untweak("<<l<<")"<<endl;
			#endif
		}
		else
		{
			#if	defined(DEBUGPRINT)
			cout<<"M8: before untweak_HI("<<l<<")"<<endl;
			#endif
			untweak_HI(l);
			//untweak_HI(i);
			#if	defined(DEBUGPRINT)
			cout<<"M8: after untweak_HI("<<l<<")"<<endl;
			#endif
		}
	}

	record[i]->BOUND +=1;

M9:/*[Leave level l.] Terminate if l = 0. Otherwise set l <- l-1. If x_l <= N, set
	  i <- x_l, p <- LLINK(i), q <- RLINK(i), RLINK(p) <- LLINK(q) <- i, and go
	  to M8. Otherwise set i <- TOP(x_l) and go to M7.
	*/
	#if	defined(DEBUGPRINT)
	cout<<"Enter M9:"<<endl;
	#endif

	if (0 == l)
	{
		cout<<"Calculation Completed with number of solutions: "<<count<<endl;
		return 0;	
	}
	else
	{
		l -=1;
		if (x[l] <= N)
		{
			i = x[l];
			p = record[i]->LLINK;
			q = record[i]->RLINK;
			record[p]->RLINK = i;
			record[q]->LLINK = i;
			goto M8;
		}
		else
		{
			i = dance[x[l]]->TOP;
			goto M7;
		}
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

/* cover(i) = { Set p <- DLINK(i). (Here p,l, and r are local variables.)
				While p != i, hide(p), then set p <- DLINK(p) and repeat.
				Set l <- LLINK(i), r <- RLINK(i),
					RLINK(l) <- r, LLINK(r) <- l.	}							(12) */

/* cover'(i) is like cover(i), but it calls hide'(p) instead of hide(p);		(50) */

/* Jacob 2018-Jan-21 The input i of cover(i)/cover'(i) can only be the index of items.
	The reason is that i has been used to retrieve LLINK item l and RLINK item r of 
	item i, and remove i from the doule linklist by modifying RLINK of l and LLINK of r.
	in the row of:
	"the records for individual items; those records have NAME, LLINK and RLINK 
	fields, where NAME is used in printouts."

	What cover(i) did is to:
		(1) Hide all options in which item i appears;
		(2) Remove i from LLINK/RLINK system of "records for individual items";
*/

int DanceLink::cover_HI(int i)
{
	int p = dance[i]->DLINK;
	while (p!=i)
	{
		hide_HI(p);
		//cout<<"hide p:"<<p<<endl;
		p = dance[p]->DLINK;
	}

	int l = record[i]->LLINK;
	int r = record[i]->RLINK;
	record[l]->RLINK = r;
	record[r]->LLINK = l;

	return 0;
}


/* uncover(i) = { Set l <- LLINK(i), r <- RLINK(i),
						RLINK(l) <- i, LLINK(r) <- i.
				  Set p <- ULINK(i).
				  While p != i, unhide(p), then set p <- ULINK(p) and repeat. } (14) */

/* uncover'(i) is like uncover(i), but it call unhide'(p) instead of unhide(p);	(52) */

int DanceLink::uncover_HI(int i)
{
	int l = record[i]->LLINK;
	int r = record[i]->RLINK;
	
	record[l]->RLINK = i;
	record[r]->LLINK = i;

	int p = dance[i]->ULINK;

	while (p != i)
	{
		unhide_HI(p);
		p = dance[p]->ULINK;
	}

	return 0;
}

/* hide(p) = { Set q <- p+1, and repeat the following while q != p:
				 Set x <- TOP(q), u <- ULINK(q), d <- DLINK(q);
				 if x<=0, set q <- u (q was a spacer);
				 otherwise set DLINK(u) <- d, ULINK(d) <- u,
				 	LEN(x) <- LEN(x) - 1, q <- q+1. 					}		(13) */

/* hide'(p) is hide(p), but it ignores node q when COLOR(q)<0;					(51) */

int DanceLink::hide_HI(int p)//hide'(p)
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

/* unhide'(p) is like unhide(p), but it ignores node q when COLOR(q)<0.			(53) */

int DanceLink::unhide_HI(int p)//this is actually unhide'(p), as function name does not allow '
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

/*
tweak(x,p) = { hide'(x) and set d <- DLINK(x), DLINK(p) <- d,
               ULINK(d) <- p, LEN(p) <- LEN(p) -1.           }				(69)
*/
int DanceLink::tweak(int x, int p)
{
	//cout<<"tweak("<<x<<","<<p<<")"<<endl;
	hide_HI(x);

	int d = dance[x]->DLINK;
	dance[p]->DLINK = d;
	dance[d]->ULINK = p;
	dance[p]->LEN -=1;

	return 0;
}

/*
untweak(l) = {	Set a <- FT[l], p <- (a<=N? a:TOP(a)), x <- a, y <- p;
				set z <- DLINK(p), DLINK(p) <- x, k <- 0;
				while x != z, set ULINK(x) <- y and k <- k+1,
					unhide'(x), and set y <- x, x <- DLINK(x);
				finally set ULINK(z) <- y and LEN(p) <- LEN(p)+k.		}	(71)
*/

int DanceLink::untweak(int l)
{
	int a = FT[l];
	//cout<<"untweak("<<l<<"): a: "<<a<<"is set FT["<<l<<"] to "<<FT[l]<<endl;
	int p = -1;
	int x = -1;
	int y = -1;
	int z = -1;
	int k = -1;

	p = (a<=N)? a:dance[a]->TOP;
	x = a;
	y = p;
	z = dance[p]->DLINK;
	dance[p]->DLINK = x;
	k = 0;

	while (x != z)
	{
		dance[x]->ULINK = y;
		k = k+1;
		unhide_HI(x);
		y = x;
		x = dance[x]->DLINK;
	}

	dance[z]->ULINK = y;
	dance[p]->LEN += k;

	return 0;
}

/*      A special case arises, however, when p's multiplicity has been specified to be 
   either 0 or 1. In such cases we're not allowed to choose options b,c,d, or e after 
   option a has been chosen. Therefore it's important to invoke cover'(p), as in 
   Algorithm C, instead of hiding one option at a time. (See (50).) The individual 
   options of p are then tweaked, to remove them one by one from the active list; this 
   tweaking uses the special operation tweak'(x,p), which is like tweak(x,p) in (69)
   except that it omits the operation hide'(x), because hiding was already done 
   when p was covered. Finally, the case of 0-or-1 multiplicity eventually concludes
   by invoking the routine untweak'(l), which is like untweak(l) in (71) except that 
   (i) it omits unhide'(x), and (ii) it calls uncover'(p) after restoring LEN(p). 
*/

/* the special operation tweak'(x,p), which is like tweak(x,p) in (69)
   except that it omits the operation hide'(x), because hiding was already done 
   when p was covered.
*/
int DanceLink::tweak_HI(int x, int p)
{
	//cout<<"tweak_HI  x:"<<x<<"  p:"<<p<<endl;

	//cout<<"tweak_HI  x:"<<x<<"  p:"<<p<<endl;
	int d = dance[x]->DLINK;
	while (d !=p)
	{
		dance[p]->DLINK = d;
		dance[d]->ULINK = p;
		dance[p]->LEN -=1;
		d = dance[d]->DLINK;
	}
	

	return 0;
}

/* the routine untweak'(l), which is like untweak(l) in (71) except that 
   (i) it omits unhide'(x), and (ii) it calls uncover'(p) after restoring LEN(p).
*/
int DanceLink::untweak_HI(int l)
{
	//cout<<"untweak_HI  l:"<<l<<"  FT["<<l<<"]:"<<FT[l]<<endl;
	int a = FT[l];
	//cout<<"untweak_HI("<<l<<"): a: "<<a<<"is set FT["<<l<<"] to "<<FT[l]<<endl;
	int p = -1;
	int x = -1;
	int y = -1;
	int z = -1;
	int k = -1;

	p = (a<=N)? a:dance[a]->TOP;
	x = a;
	y = p;
	z = dance[p]->DLINK;
	dance[p]->DLINK = x;
	k = 0;

	while (x != z)
	{
		dance[x]->ULINK = y;
		k = k+1;
		//unhide_HI(x);
		y = x;
		x = dance[x]->DLINK;
	}

	dance[z]->ULINK = y;
	dance[p]->LEN += k;
	
	//(ii) it calls uncover'(p) after restoring LEN(p)
	uncover_HI(p);

	return 0;
}

/*
commit(p,j) = {
	If COLOR(p) == 0, cover'(j);	
	if COLOR(p) > 0, purify(p).		}										(54)
*/

int DanceLink::commit(int p, int j)
{
	if (dance[p]->COLOR == 0)
	{
		cover_HI(j);
	}

	if (dance[p]->COLOR > 0)
	{
		purify(p);
	}

	return 0;
}

/*
uncommit(p,j) = {
	If COLOR(p) == 0, uncover'(j);
	if COLOR(p) > 0, unpurify(p).	}										(56)
*/

int DanceLink::uncommit(int p, int j)
{
	if (dance[p]->COLOR == 0)
	{
		uncover_HI(j);
	}

	if (dance[p]->COLOR > 0)
	{
		unpurify(p);
	}

	return 0;
}


/*
purify(p) = {
	Set c <- COLOR(p), i <- TOP(p), q <- DLINK(i).
	While q != i, do the following and set q <- DLINK(q):
		if COLOR(q) != c, hide'(q);
		otherwise if q != p, COLOR(q) <- -1.	}							(55)
*/

int DanceLink::purify(int p)
{
	char c = dance[p]->COLOR;
	int  i = dance[p]->TOP;
	int  q = dance[i]->DLINK;

	while (q != i)
	{
		if (dance[q]->COLOR != c)
		{
			hide_HI(q);
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


/*
unpurify(p) = {
	Set c <- COLOR(p), i <- TOP(p), q <- ULINK(i).
	While q != i, do the following and set q <- ULINK(q):
		if COLOR(q) < 0, COLOR(q) <- c;
		otherwise if q != p, unhide'(q).	}									(57)
*/

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
				unhide_HI(q);
			}
		}

		q = dance[q]->ULINK;
	}

	return 0;
}


/* Exercise 9. [18] Explain how to branch in step D3 on an item i for which LEN(i) is minimum.
			If several items have that minimum length, i itself should also be minimum. (This
			choice is often called the "minimum remaining values" (MRV) heuristic.) 

*/

/* Exercise 10. [20] In some applications the MRV heuristic of exercise 9 leads the search astray,
			because certain primary items have short lists yet convey little information about
			desirable choices. Modify answer 9 so that an item p whose name does not begin
			with the character '#' will be chosen only if LEN(p) <= 1 or no other choices exist.
			(This tactic is called the "sharp preference" heuristic.)
*/
int DanceLink::sharpHeur()
{
	int next =-1;
	int sharp = 0x7FFFFFFF;
	int nonsharp = 0x7FFFFFFF;

	for (int i = record[0]->RLINK; i !=0; i = record[i]->RLINK)
	{
		if ('#' ==(record[i]->NAME.c_str())[0])
		{
			if (dance[i]->LEN < sharp)
			{
				sharp = i;
			}
		}
		else
		{
			if (dance[i]->LEN < nonsharp)
			{
				nonsharp = i;
			}	
		}
	}

	if (0 == record[0]->RLINK)
	{
		next = 0;
	}
	else
	{
		if (sharp < 0x7FFFFFFF)
		{
			next = sharp;
		}
		else
		{
			next = nonsharp;
		}
	}
	
	return next;
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