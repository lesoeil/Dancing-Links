/* 
exer38-fasc-7228-taocp.cpp
*/

/*

Exercise 38. [M22] A "perfect number" 

"perfect digital invariants" are akin to "amicable digital pairs" such as 
		136 = 2*2*2 + 4*4*4 + 4*4*4   and 244 = 1*1*1 + 3*3*3 + 6*6*6
*/


#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

#include "exer38-fasc-7228-taocp.h"


int main(int argc, char** argv)
{
	/* Count digits 
	string num("2656162296193301098036764167100329792078748434854147717669387628693320478845113744801479850942958");
	vector<int> listDigit = countDigits(num);
	int n = listDigit.size();
	int count = 0;
	for (int i=0; i<n; i++)
	{
		cout<<i<<": "<<listDigit[i]<<endl;
		count += listDigit[i];
	}

	cout<<"Total number of digits ";

	return 0;
	*/

	
		int m;
		if (argc >= 2)
		{
			if ( (atoi(argv[1]) >=1) &&  (atoi(argv[1]) <=100) )
			{
			 	m = atoi(argv[1]);
			 	//cout<<m<<endl;
			}
		}

		testMulBig(m);
	

	return 0;


	/*
	int m = 3;

	if (argc >=3)
	{
		if ( (atoi(argv[2]) >=0) &&  (atoi(argv[2]) <=100) )
		{
		 	m = atoi(argv[2]);
		}
		else
		{
			cout<<"Ohh, "<<argv[2]<<" seems to be out of range [0..100] ..."<<endl;
			return 0;
		}
	}
	else
	{
		cout<<"Welcome to POTPOURRI! Since there is no number input, we take it as 3"<<endl<<endl;
	}


	string cmd("exer38");

	if (argc >=2)
	{
		cmd = argv[1];

		if ( (cmd.compare("P") == 0) || (cmd.compare("p") == 0))
		{
			calPerfect(m);
		}
		else if ( (cmd.compare("T") == 0)  || (cmd.compare("t") == 0) )
		{
		
			int t = m+1;
			int s = 9;
			int n = t+s;
			algoTtaocp7213(n, t);
		}
		else if ( (cmd.compare("L") == 0)  || (cmd.compare("l") == 0) )
		{
			int n = 9+1;
			int t = m+1;
			algoLtaocp7213(n, t);
		}
		else
		{
			exer38(m);
		}

	}
	else
	{
		cout<<"Since there is no sub-commmand input, we take it as "<<cmd<<endl;
		exer38(m);
	}


	return 0;
	*/
}


int exer38(int m)
{
	int64_t j;
	int64_t k;

	int64_t  upper = 1;
	for (int i=0; i<=m; i++)
	{
		upper *= 10;
	}
	cout<<"upper is "<<upper<<" for "<<m<<endl;

	cout<<"Now we start the journey to calculate Amicable digital pair of order "<<m<<":"<<endl;
	int64_t i = 1;

	while ( i++ < upper)
	{
		int64_t  rem;
		int64_t  quo;

		
		rem = 0;
		quo = i;
		j = 0;		
		while (quo > 0)
		{
			rem = quo % 10;
			quo = quo / 10;

			int tmp = 1;
			for (int s = 0; s<m; s++)
			{
				tmp *= rem;
			}

			j += tmp;
		}
		

		//cout<<i<<" "<<a1<<" "<<a2<<" "<<a3<<endl;

		rem = 0;
		quo = j;
		k = 0;

		while (quo > 0)
		{
			rem = quo % 10;
			quo = quo / 10;

			int tmp = 1;
			for (int s = 0; s<m; s++)
			{
				tmp *= rem;
			}

			k += tmp;
		}

		//cout<<j<<" "<<b1<<" "<<b2<<" "<<b3<<endl;
		//cout<<k<<endl;


		if ((i==k) && (i!=j) && (i<j))
		{
			cout<<i<<" and "<<j<<endl;
		}

	}

	return 0;	
}



/*
Perfect digital invariants of order m.

m = 3
153
370
371
407

m = 4
1634
8208
9474

m = 5 
4150
4151
54748
92727
93084
194979

m = 6
548834

m = 7
1741725
4210818
9800817
9926315
14459929

m = 8
24678050
24678051
88593477


m = 9
146511208
472335975
534494836
912985153

n = 10
4679307774

n = 11
9 6 6 5 4 4 3 2 1 0 0 0:32164049650
9 6 6 5 4 4 3 2 1 1 0 0:32164049651
9 8 5 4 4 3 2 2 2 0 0 0:40028394225
9 8 7 6 6 4 3 2 2 0 0 0:42678290603
9 8 7 7 6 6 5 4 4 3 0 0:44708635679
9 8 8 6 6 5 5 4 3 0 0 0:49388550606
9 9 8 8 7 6 6 5 3 2 1 0:82693916578
9 9 9 5 4 4 4 2 1 1 0 0:94204591914



*/
int calPerfect(int m)
{
	int64_t j;
	int64_t k;

	int64_t  upper = 1;
	for (int i=0; i<=m; i++)
	{
		upper *= 10;
	}
	cout<<"upper is "<<upper<<" for "<<m<<endl;

	cout<<"Now we start the journey to calculate Amicable digital pair of order "<<m<<":"<<endl;
	int64_t i = 1;

	while ( i++ < upper)
	{
		int64_t  rem;
		int64_t  quo;

		
		rem = 0;
		quo = i;
		j = 0;		
		while (quo > 0)
		{
			rem = quo % 10;
			quo = quo / 10;

			int tmp = 1;
			for (int s = 0; s<m; s++)
			{
				tmp *= rem;
			}

			j += tmp;
		}
		
		if (i==j)
		{
			cout<<i<<endl;
		}

	}

	return 0;	
}


/*
t = m+1
n = 10  0..9
*/
int algoTtaocp7213(int n, int t)
{
	int c[t+3];
	int j = 0;
	int x = -1;
	uint64_t count = 0;
	int cmb[t+1];


T1: /* [Initialize.] Set c_j <- j-1 for 1 <= j <= t; then set c_(t+1) <- n, c_(t+2) <- 0, and j <- t. */
	for (j=1; j<=t; j++)
	{
		c[j] = j-1;
	}

	c[t+1] = n;
	c[t+2] = 0;
	j = t;


T2: /* [Visit.] (At this point j is the smallest index such that c_(j+1) > j.) Visit the combinations c_t ... c_2 c_1. 
	Then, if j > 0, set x <- j and go to step T6. */

	//Visit combination c[1..t]
	{
		/*
		for (int i =t; i>=2; i--)
		{
			cout<<c[i]-i+1<<" ";
		}
		cout<<c[1];
		cout<<endl;
		*/
		for (int i=t; i>=2; i--)
		{
			cmb[i] = c[i]-i+1;
		}
		cmb[1] = c[1];

		/*
		for (int i=t; i>=1; i--)
		{
			cout<<c[i];
		}
		cout<<endl;
		*/

		if (bCheck(&cmb[0], t, t-1) == true) {
			for (int i =t; i>=2; i--)
			{
				cout<<c[i]-i+1<<" ";
			}
			cout<<c[1];
			cout<<":";

			{
				int64_t  quo;
				int64_t coffee;
				int64_t element;
				int m = t-1;

				coffee = 0;	
				for (int i=1; i<=t; i++)
				{
					quo = 1;
					element = cmb[i];
					for (int j=1; j<=m; j++)
					{
						quo *= element;
					}

					coffee += quo;
				}
				cout<<coffee;
			}
			
			cout<<endl;
		}

		count++;
	}

	if (j > 0)
	{
		x = j;
		goto T6;
	}

T3: /* [Easy case?] If c_1 + 1 < c_2, set c_1 <- c_1 + 1 and return to T2. Otherwise set j <- 2. */
	if ((c[1]+1) < c[2])
	{
		c[1] += 1;
		goto T2;
	}
	else
	{
		j = 2;
	}


T4: /* [Find j.] Set c_(j-1) <- j-2 and x <- c_j + 1. If x = c_(j+1), set j <- j+1 and repeat step T4. */
	c[j-1] = j-2;
	x = c[j] + 1;

	if (x == c[j+1])
	{
		j = j+1;
		goto T4;
	}


T5: /* [Done?] Terminate the algorithm if j > t. */
	if (j > t) // Done. Terminate.
	{
		cout<<"Completed."<<endl;
		cout<<"Total cases checked: "<<count<<endl;
		return 0;
	}


T6: /* [Increase c_j.] Set c_j <- x, j <- j-1, and return to T2.*/
	c[j] = x;
	j = j-1;
	goto T2;

}


int algoLtaocp7213(int n, int t)
{
	int c[t+3];
	int j = 0;
	uint64_t count = 0;

L1: /* [Initialize.] Set c_j <- j-1 for 1 <= j <= t; also set c_(t+1) <- n and c_(t+2) <- 0.*/
	for (j=1; j<=t; j++)
	{
		c[j] = j-1;
	}

	c[t+1] = n;
	c[t+2] = 0;


L2: /* [Visit.] Visit the combination c_t ... c_2 c_1 */
	for (int i=1; i<=t; i++)
	{
		cout<<c[i];
	}
	cout<<endl;
	count++;


L3: /* [Find j.] Set j <- 1. Then, while, (c_j) + 1 = c_(j+1), set c_j <- j-1 and j <- j+1;
	eventually the condition c_j +1 != c_(j+1) will occur. */
	j = 1;
	while ((c[j]+1) == c[j+1])
	{
		c[j] = j-1;
		j = j+1;
	}


L4: /* [Done?] Terminate the algorithm if j > t. */
	if (j>t)
	{
		cout<<"Completed with total "<<count<<" cases checked."<<endl;
		return 0;
	}

L5: /* [Increase c_j.] Set c_j <- c_j +1 and return to L2.*/
	c[j] +=1;
	goto L2;

}



bool bCheck(int* c, int t, int m)
{
	int64_t  quo;

	int64_t coffee;
	int64_t element; 

	coffee = 0;
	for (int i=1; i<=t; i++)
	{
		quo = 1;
		element = c[i];
		for (int j=1; j<=m; j++)
		{
			quo *= element;
		}

		coffee += quo;
	}


	quo = coffee;
	vector<int> latte;

	while (quo > 0)
	{
		latte.push_back(quo % 10);
		quo = quo / 10;
			
	}

	sort(latte.begin(), latte.end());

	/*
	for (int i=t; i>=1; i--)
	{
		cout<<c[i];
	}
	cout<<endl;

	cout<<coffee<<endl;
	for (auto x:latte)
	{
		cout<<x;
	}
	cout<<endl;
	*/


	int n = latte.size();
	int k = t;

	for (int i=n; i>=1; i--)
	{
		if (c[k] != latte[i-1])
		{
			return false;
		}
		k--;
	}

	if (k>0)
	{
		do
		{
			if (c[k] != 0)
			{
				return false;
			}

			k--;
		} while (k>0);
	}


	return true;
}


int addBig(vector<uint8_t>* a1, const vector<uint8_t>* a2, uint8_t base)
{
	int n1 = (*a1).size();
	int n2 = (*a2).size();

	int n = (n1 <= n2)? n1:n2;
	cout<<"n1: "<<n1<<"; n2:"<<n2<<";  n: "<<n<<endl;

	uint8_t tmp;
	uint8_t buf=0;
	for (int i=0; i<n; i++)
	{
		tmp = (*a1)[i]+(*a2)[i]+buf;
		if (tmp >= base)
		{
			buf = tmp / base;
			(*a1)[i] = tmp % base;
		}
		else
		{
			buf = 0;
			(*a1)[i] = tmp % base;
		}
	}

	if (n1 > n)
	{
		for (int i=n; i<n1; i++)
		{
			tmp = (*a1)[i]+buf;
			if (tmp >= base)
			{
				buf = tmp / base;
				(*a1)[i] = tmp % base;
			}
			else
			{
				buf = 0;
				(*a1)[i] = tmp % base;
			}
		}

		if (buf > 0)
		{
			(*a1).push_back(buf);
		}
	}
	else if (n2 == n)
	{
		if (buf > 0)
		{
			(*a1).push_back(buf);
		}
	}
	else
	{
		for (int i=n; i<n2; i++)
		{
			tmp = (*a2)[i] + buf;
			if (tmp >= base)
			{
				buf = tmp / base;
				(*a1).push_back(tmp % base);
			}
			else
			{
				buf = 0;
				(*a1).push_back(tmp % base);
			}
		}

		if (buf > 0)
		{
			(*a1).push_back(buf);
		}
	}

	return 0;
}


template<T> int mul(const vector<T>& mp1, const vector<T>& mp2, vector<T>* product)
{

}


template<T> int mulDigit(const vector<T>& mp1, const T& mp2, vector<T>* product)
{

}


template<T>



/*
pCoffee will be vector of single digit, each element of vector<uint8_t> will hold one digit of non-negative 
integer (which can be very big, the only limitation will be size limitation of vector and maybe also memory size.

mulBig() function has been implemented to multiply an non-negative integer (any-size-quantity non-negative integer, 
as long as C++ std::vector can hold it) by a single digit non-negative integer (the definition/value of single-digit 
non-negative integer will depend on value of number base. For example, if the number system is decimal number, then 
we can pass the value of base with 10, which will be used during carry on cacculation. )

*/
int mulBig(vector<uint8_t>* pCoffee, uint8_t p, uint8_t base)
{
	
	int n = (*pCoffee).size();
	vector<uint8_t> buffer(n+1);

	if (n<=0)
	{
		cout<<"input vecor is empty."<<endl;
		return 0;	
	}

	uint8_t tmp = 0;

	int i = 0;
	while (1)
	{
		//cout<<i<<":"<<(int)((*pCoffee)[i])<<endl;

		tmp = (*pCoffee)[i]*p;
		tmp += buffer[i];

		if (tmp >= base)
		{
			(*pCoffee)[i] = tmp % base;

			int s = i+1;
			uint8_t rem = tmp / base;
			buffer[s] = rem;
		}
		else
		{
			(*pCoffee)[i] = tmp % base;
		}

		i++;

		if (i >= n)
		{
			break;
		}
	}

	if (buffer[n]>0)
	{
		(*pCoffee).push_back(buffer[n]);
	}

	return 0;
}

/*
		int m = 100;

		if (argc >= 2)
		{
			if ( (atoi(argv[1]) >=1) &&  (atoi(argv[1]) <=100) )
			{
			 	m = atoi(argv[1]);
			 	//cout<<m<<endl;
			}
		}
*/
void testMulBig(int m)
{
		vector<uint8_t> coffee;
		uint8_t p = 9;
		uint8_t base = 10;
		

		coffee.push_back(p);

		int n;

		for (int i = 0; i<m; i++)
		{
			mulBig(&coffee, p, base);
		}

		//cout<<(int)base<<endl;

		n = coffee.size();
		for (int i=n; i>=1; i--)
		{
			cout<<(int)(coffee[i-1]);
		}
		cout<<endl;
		cout<<"digits: "<<n<<endl;


		vector<uint8_t> seven;
		p = 7;
		base = 10;
		seven.push_back(1);

		for (int i = 0; i<m; i++)
		{
			mulBig(&seven, p, base);
		}

		n = seven.size();
		for (int i=n; i>=1; i--)
		{
			cout<<(int)(seven[i-1]);
		}
		cout<<endl;
		cout<<"seven digits: "<<n<<endl;


		n = seven.size();
		//vector<uint8_t> seven1(seven);
		vector<uint8_t> seven1;
		for (int i=0; i<n; i++)
		{
			seven1.push_back(seven[i]);// x 10
		}
		mulBig(&seven1, 2, base);

		n = seven1.size();
		for (int i=n; i>=1; i--)
		{
			cout<<(int)(seven1[i-1]);
		}
		cout<<endl;
		cout<<"seven1 digits: "<<n<<endl;

		vector<uint8_t> seven2;
		seven2.push_back(0);
		n = seven.size();
		for (int i=0; i<n; i++)
		{
			seven2.push_back(seven[i]);// x 10
		}

		mulBig(&seven2, 9, base);
		n = seven2.size();
		for (int i=n; i>=1; i--)
		{
			cout<<(int)(seven2[i-1]);
		}
		cout<<endl;
		cout<<"seven2 digits: "<<n<<endl;


		addBig(&seven1, &seven2, base);

		addBig(&seven1, &coffee, base);

		n = seven1.size();
		for (int i=n; i>=1; i--)
		{
			cout<<(int)(seven1[i-1]);
		}
		cout<<endl;
		cout<<"digits: "<<n<<endl;
	}


/*
x = 26 56162 29619 33010 98036 76416 71003 29792 07874 84348 54147 71766 93876 28693 32047 88451 13744 80147 98509 42958 = PI_100(x)

2656162296193301098036764167100329792078748434854147717669387628693320478845113744801479850942958
2656162296193301098036764167100329792078748434854147717669387628693320478845113744801479850942958
*/
vector<int> countDigits(string& num)
{
	const char* ch = num.c_str();
	vector<int> digit(10, 0);

	int n = num.size();

	for (int i=0; i<n; i++)
	{
		switch (ch[i])
		{
			case '0':
				digit[0]++;
				break;
			case '1':
				digit[1]++;
				break;
			case '2':
				digit[2]++;
				break;
			case '3':
				digit[3]++;
				break;
			case '4':
				digit[4]++;
				break;
			case '5':
				digit[5]++;
				break;
			case '6':
				digit[6]++;
				break;
			case '7':
				digit[7]++;
				break;
			case '8':
				digit[8]++;
				break;
			case '9':
				digit[9]++;
				break;
			default:
				break;
		}
	}

	return digit;
}




			/*
			while (1)
			{
				if ((s) < ((*pCoffee).size()))
				{
					buffer[s] += rem;

					if (((*pCoffee)[s]) >=base)
					{
						rem = (*pCoffee)[s] / base;
						(*pCoffee)[s] = (*pCoffee)[s] % base;
						s++;
					}
					else
					{
						break;
					}
				}
				else
				{
					(*pCoffee).push_back(rem);
					break;
				}	
			}
			*/	