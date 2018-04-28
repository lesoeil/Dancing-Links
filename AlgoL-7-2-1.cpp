/*	TAOCP 7.1.2 Algorithm L (Find normal lengths)
	Jacob 2018-04-28 20:51

*/

#include<iostream>

using namespace std;

int main(int argc, char** argv)
{

	//cout<<"This is my first program for Volume 4A!"<<endl;

}


int algoL()
{

/*	Algorithm L (Find normal lengths). This algorithm determines L(f) for all
	normal truth tables 0 <= f < 2^((2^n)-1), by building lists of all nonzero normal 
	functions of length r for r >= 0.
*/


/*	L1. [Initialize.] Let L(0) <- 0 and L(f) <- MAX for 1 <= f < 2^((2^n)-1). Then, for
		1 <= k <= n, set L(x_k) <- 0 and put x_k into list 0, where
								x_k = ((2^(2^n))-1)/((2^(2^(n-k)))+1)				(11)
		is the truth table for x_k. (See exercise 8.) Finally, set c <- (2^((2^n)-1))-n-1;
		c is the number of places where L(f) = MAX.
*/


/*	L2. [Loop on r.] Do step L3 for r = 1, 2, ...; eventually the algorithm will
		terminate when c becomes 0.
*/


/*	L3. [Loop on j and k.] Do step L4 for j = 0, 1, ..., and k = r - 1 -j, while
		j<=k.
*/


/*	L4. [Loop on g and h.] Do step L5 for all g in list j and all h in list k. (If j = k,
		it suffices to restrict h to functions that follow g in list k.)
*/


/*	L5. [Loop on f.] Do step L6 for f = g & h, f = ~g & h, f = g & ~h, f = g | h, and 
		f = g XOR h. (Here g & h denotes the bitwise AND of the integers g and h; we
		are representing truth tables by integers in binary notation.)
*/


/*	L6. [Is f new?] If L(f) = MAX, set L(f) <- r, c <- c-1, and put f in list r.
		Terminate the algorithm if c = 0.

*/

}
