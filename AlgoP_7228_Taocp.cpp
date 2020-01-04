/*
AlgoP_7228_Taocp.cpp

Algorithm P

*/


#include<iostream>
#include<string>
#include<map>
#include<vector>


using namespace std;


int main(int argc, char** argv)
{

}


/*
Algorithm P (Perfect digital invariants.) Given m >= 3, this algorithm generate all (m+1)-digit integers x such that 
PI_m (x) = x, by finding all of the appropriate multicombinations x_1 ... x_(m+1) that satisfy (22). Its state variables
for 1 <= l <= m+2 are q_l, r_l, t_l, and the (m+1)-digit numbers Z_l, a_l, b_l, as well as the digit counts d_l and e_l.
The (m+1)-digit constants j*k^m should also be precomputed for 0 <= j <= m+1 and 0 <= k <= 10.
*/
int AlgoP_7228_Taocp(unsigned int m)
{
	uint64_t l, q, r, t, a, b;
	uint64_t x[m+3];
	uint64_t q[m+3], r[m+3], t[m+3];
	uint64_t Z[m+2], a[m+2], b[m+2];
	uint64_t d[m+2], e[m+2];

	uint64_t pm[m+2][10];// j * k^m  for 0 <= j <= m+1,  and 0 <= k < 10.

	
	{
		for (int k=0; k<10; k++)
		{
			uint64_t km = 1;
			for (int s =1; s<=m; s++)
			{
				km *= k;
			}

			for (int j = 0; j<=m+1; j++)
			{
				pm[j][k] = j * km;
			}
		}
	}


P1:/* [Initialize.] Set l <- 1, q <- 0, r <- m+1, t <- m, a <- 0, b <- c<- 9, d_1 <- e_1 <- Z_1 <- 0, and go to P3. */
	l = 1;
	q = 0;
	t = m;
	a = 0;
	b = 9;
	c = 9;
	d[1] = 0;
	e[1] = 0;
	Z[1] = 0;
	goto P3;

P2:/* [Enter level l.] (We've just set x_(l-1) <- c.) Set d_(lk) <- d_((l-1)k) +[k=c] and e_(lk) <- e_((l-1)k) for 0 <= k < 10.
	If q > 0, set Z_l <- Z_(l-1) and q <- q-1; then go immediately to P5 if q is still positive. Otherwise if r > 0, set 
	Z_l <- Z_(l-1) + c^m and r < - r-1. Otherwise go to P7.
*/
	for (int k =0; k<10; k++)
	{
		d[l*k] = d[(l-1)*k] + (k==c);
		e[l*k] = e[(l-1)*k];
	}

	if (q > 0)
	{
		Z[l] = Z[l-1];
		q = q-1;
		if (q > 0)
		{
			goto P5;
		}
	}
	else
	{
		if (r > 0)
		{
			Z[l] = Z[l-1] + pm[1][c]; // pm[1][c] = 1 * c^m, for 0 <= c <= 9
		}
		else
		{
			goto P7;
		}
	}
	


P3:/* [Done?] If l = m+2, visit the solution Z_l and go to P7.*/
	if (l == (m+2)) {
		//Visit solution Z_l
		cout<<Z[l]<<endl;
		goto P7;
	}


P4:/* [Test feasibility of c.] If there's an easy way to prove that x_l can't be <= c, using the current state variables as 
	discussed in exercise 33, go to P7. (This test might update all of the state variables except d_l.*/
	//TODO

P5:/* [Try c.] Set x_l <- c, q_l <- q, r_l <- r, t_l <- t, l <- l+1, and go to P2.*/
	x[l] = c;
	q[l] = q;
	r[l] = r;
	t[l] = t;
	l = l+1;
	goto P2;


P6:/* [Try again.] If c > 0, set c <- c-1, q <- e_(lc), and go to P5. (Now d_(lc) = 0.) */
	if (c > 0)
	{
		c = c-1;
		q = e[l*c];
		goto P5;
	}


P7:/* [Backtrack.] Terminate if l = 1. Otherwise set l <- l-1, q < q_l, and repeat this step if q > 0. Otherwise set r <- r_l, 
	a <- (t >= 0? a_(lt) : 9), b <- (t >= 0? b_(lt) : 9), c <- x_l, and go back to P6.*/
	if (1 == l)
	{
		return 0; // Terminate if l == 1.
	}
	else
	{
		do
		{
			l = l-1;
			q  = q[l];	
		} while (q>0)

		r = r[l];
		a = (t >= 0)? a[l*t] : 9;
		b = (t >= 0)? b[l*t] : 9;
		c = x[l];
		goto P6;
	}
}