/*	Code practice for 7.2.2.2 COMBINATORIAL ALGORITHMS
	Fault testing. 

	Jacob Yang 4-June-2018

*/

#include <iostream>

using namespace std;


class MULT
{
public:
	int get_z_1();
	int get_z_2();
	int get_z_3();
	int get_z_4();
	int get_z_5();

public:
	int set_x_1(bool fault, int value, int x1);	// input
	int set_x_1_1(bool fault, int value);	// = x_1
	int set_x_2_1(bool fault, int value);	// = x_1
	int set_x_3_1(bool fault, int value);	// = x_1_1
	int set_x_4_1(bool fault, int value);	// = x_1_1
	int set_x_2(bool fault, int value, int x2);	// input
	int set_x_1_2(bool fault, int value);	// = x_2
	int set_x_2_2(bool fault, int value);	// = x_2
	int set_x_3_2(bool fault, int value);	// = x_1_2
	int set_x_4_2(bool fault, int value);	// = x_1_2
	int set_y_1(bool fault, int value, int y1);	// input
	int set_y_1_1(bool fault, int value);	// = y_1
	int set_y_2_1(bool fault, int value);	// = y_1
	int set_y_2(bool fault, int value, int y2);	// input
	int set_y_1_2(bool fault, int value);	// = y_2
	int set_y_2_2(bool fault, int value);	// = y_2
	int set_y_3(bool fault, int value, int y3);	// input
	int set_y_1_3(bool fault, int value);	// = y_3
	int set_y_2_3(bool fault, int value);	// = y_3
	int set_z_1(bool fault, int value);	// = x_2_1 ⋀ y_1_1
	int set_a_2(bool fault, int value);	// = x_3_1 ⋀ y_1_2
	int set_a_1_2(bool fault, int value);	// = a_2
	int set_a_2_2(bool fault, int value);	// = a_2
	int set_a_3(bool fault, int value);	// = x_4_1 ⋀ y_1_3
	int set_a_1_3(bool fault, int value);	// = a_3
	int set_a_2_3(bool fault, int value);	// = a_3
	int set_b_1(bool fault, int value);	// = x_2_2 ⋀ y_2_1
	int set_b_1_1(bool fault, int value);	// = b_1
	int set_b_2_1(bool fault, int value);	// = b_1
	int set_b_2(bool fault, int value);	// = x_3_2 ⋀ y_2_2
	int set_b_1_2(bool fault, int value);	// = b_2
	int set_b_2_2(bool fault, int value);	// = b_2
	int set_b_3(bool fault, int value);	// = x_4_2 ⋀ y_2_3
	int set_b_1_3(bool fault, int value);	// = b_3
	int set_b_2_3(bool fault, int value);	// = b_3
	int set_z_2(bool fault, int value);	// = a_1_2 ⊕ b_1_1
	int set_c_1(bool fault, int value);	// = a_2_2 ⋀ b_2_1
	int set_c_1_1(bool fault, int value);	// = c_1
	int set_c_2_1(bool fault, int value);	// = c_1
	int set_s(bool fault, int value);		// = a_1_3 ⊕ b_1_2
	int set_s_1(bool fault, int value);	// = s
	int set_s_2(bool fault, int value);	// = s
	int set_p(bool fault, int value);		// = a_2_3 ⋀ b_2_2
	int set_z_3(bool fault, int value);	// = s_1 ⊕ c_1_1
	int set_q(bool fault, int value);		// = s_2 ⋀ c_2_1
	int set_c_2(bool fault, int value);	// = p ∨ q
	int set_c_1_2(bool fault, int value);	// = c_2
	int set_c_2_2(bool fault, int value);	// = c_2
	int set_z_4(bool fault, int value);	// = b_1_3 ⊕ c_1_2
	int set_z_5(bool fault, int value);	// = b_2_3 ⋀ c_2_2

private:
	int x_1;	// input
	int x_1_1;	// = x_1
	int x_2_1;	// = x_1
	int x_3_1;	// = x_1_1
	int x_4_1;	// = x_1_1
	int x_2;	// input
	int x_1_2;	// = x_2
	int x_2_2;	// = x_2
	int x_3_2;	// = x_1_2
	int x_4_2;	// = x_1_2
	int y_1;	// input
	int y_1_1;	// = y_1
	int y_2_1;	// = y_1
	int y_2;	// input
	int y_1_2;	// = y_2
	int y_2_2;	// = y_2
	int y_3;	// input
	int y_1_3;	// = y_3
	int y_2_3;	// = y_3
	int z_1;	// = x_2_1 ⋀ y_1_1
	int a_2;	// = x_3_1 ⋀ y_1_2
	int a_1_2;	// = a_2
	int a_2_2;	// = a_2
	int a_3;	// = x_4_1 ⋀ y_1_3
	int a_1_3;	// = a_3
	int a_2_3;	// = a_3
	int b_1;	// = x_2_2 ⋀ y_2_1
	int b_1_1;	// = b_1
	int b_2_1;	// = b_1
	int b_2;	// = x_3_2 ⋀ y_2_2
	int b_1_2;	// = b_2
	int b_2_2;	// = b_2
	int b_3;	// = x_4_2 ⋀ y_2_3
	int b_1_3;	// = b_3
	int b_2_3;	// = b_3
	int z_2;	// = a_1_2 ⊕ b_1_1
	int c_1;	// = a_2_2 ⋀ b_2_1
	int c_1_1;	// = c_1
	int c_2_1;	// = c_1
	int s;		// = a_1_3 ⊕ b_1_2
	int s_1;	// = s
	int s_2;	// = s
	int p;		// = a_2_3 ⊕ b_2_2
	int z_3;	// = s_1 ⊕ c_1_1
	int q;		// = s_2 ⋀ c_2_1
	int c_2;	// = p ∨ q
	int c_1_2;	// = c_2
	int c_2_2;	// = c_2
	int z_4;	// = b_1_3 ⊕ b_1_2
	int z_5;	// = b_2_3 ⋀ c_2_2
};

int MULT::get_z_1()
{
	return z_1;
}

int MULT::get_z_2()
{
	return z_2;
}

int MULT::get_z_3()
{
	return z_3;
}

int MULT::get_z_4()
{
	return z_4;
}

int MULT::get_z_5()
{
	return z_5;
}


int MULT::set_x_1(bool fault, int value, int x1)	// input
{
	if (fault)
	{
		x_1 = value;
	}
	x_1 = x1;

	return 0;
}

int MULT::set_x_1_1(bool fault, int value)	// = x_1
{
	if (fault)
	{
		x_1_1 = value;
	}
	else
	{
		x_1_1 = x_1;
	}

	return 0;
}
	
int MULT::set_x_2_1(bool fault, int value)	// = x_1
{
	if (fault)
	{
		x_2_1 = value;
	}
	else
	{
		x_2_1 = x_1;
	}

	return 0;
}

int MULT::set_x_3_1(bool fault, int value)	// = x_1_1
{
	if (fault)
	{
		x_3_1 = value;
	}
	else
	{
		x_3_1 = x_1_1;
	}

	return 0;
}

int MULT::set_x_4_1(bool fault, int value)	// = x_1_1
{
	if (fault)
	{
		x_4_1 = value;
	}
	else
	{
		x_4_1 = x_1_1;
	}

	return 0;
}

int MULT::set_x_2(bool fault, int value, int x2)	// input
{
	if (fault)
	{
		x_2 = value;
	}
	else
	{
		x_2 = x2;	
	}
	

	return 0;
}

int MULT::set_x_1_2(bool fault, int value)	// = x_2
{
	if (fault)
	{
		x_1_2 = value;
	}
	else
	{
		x_1_2 = x_2;
	}

	return 0;
}

int MULT::set_x_2_2(bool fault, int value)	// = x_2
{
	if (fault)
	{
		x_2_2 = value;
	}
	else
	{
		x_2_2 = x_2;
	}

	return 0;
}

int MULT::set_x_3_2(bool fault, int value)	// = x_1_2
{
	if (fault)
	{
		x_3_2 = value;
	}
	else
	{
		x_3_2 = x_1_2;
	}

	return 0;
}

int MULT::set_x_4_2(bool fault, int value)	// = x_1_2
{
	if (fault)
	{
		x_4_2 = value;
	}
	else
	{
		x_4_2 = x_1_2;
	}

	return 0;
}

int MULT::set_y_1(bool fault, int value, int y1)	// input
{
	if (fault)
	{
		y_1 = value;
	}
	else
	{
		y_1 = y1;	
	}
	

	return 0;
}

int MULT::set_y_1_1(bool fault, int value)	// = y_1
{
	if (fault)
	{
		y_1_1 = value;
	}
	else
	{
		y_1_1 = y_1;
	}

	return 0;
}

int MULT::set_y_2_1(bool fault, int value)	// = y_1
{
	if (fault)
	{
		y_2_1 = value;
	}
	else
	{
		y_2_1 = y_1;
	}

	return 0;
}

int MULT::set_y_2(bool fault, int value, int y2)	// input
{
	if (fault)
	{
		y_2 = value;
	}
	else
	{
		y_2 = y2;	
	}
	

	return 0;
}

int MULT::set_y_1_2(bool fault, int value)	// = y_2
{
	if (fault)
	{
		y_1_2 = value;
	}
	else
	{
		y_1_2 = y_2;
	}

	return 0;
}
	
int MULT::set_y_2_2(bool fault, int value)	// = y_2
{
	if (fault)
	{
		y_2_2 = value;
	}
	else
	{
		y_2_2 = y_2;
	}

	return 0;
}

int MULT::set_y_3(bool fault, int value, int y3)	// input
{
	if (fault)
	{
		y_3 = value;
	}
	else
	{
		y_3 = y3;	
	}
	

	return 0;
}

int MULT::set_y_1_3(bool fault, int value)	// = y_3
{
	if (fault)
	{
		y_1_3 = value;
	}
	else
	{
		y_1_3 = y_3;
	}

	return 0;
}

int MULT::set_y_2_3(bool fault, int value)	// = y_3
{
	if (fault)
	{
		y_2_3 = value;
	}
	else
	{
		y_2_3 = y_3;
	}

	return 0;
}

int MULT::set_z_1(bool fault, int value)	// = x_2_1 ⋀ y_1_1
{
	if (fault)
	{
		z_1 = value;
	}
	else
	{
		z_1 = x_2_1 & y_1_1;
	}

	return 0;
}

int MULT::set_a_2(bool fault, int value)	// = x_3_1 ⋀ y_1_2
{
	if (fault)
	{
		a_2 = value;
	}
	else
	{
		a_2 = x_3_1 & y_1_2;
	}

	return 0;
}
	
int MULT::set_a_1_2(bool fault, int value)	// = a_2
{
	if (fault)
	{
		a_1_2 = value;
	}
	else
	{
		a_1_2 = a_2;
	}

	return 0;
}

int MULT::set_a_2_2(bool fault, int value)	// = a_2
{
	if (fault)
	{
		a_2_2 = value;
	}
	else
	{
		a_2_2 = a_2;
	}

	return 0;
}

int MULT::set_a_3(bool fault, int value)	// = x_4_1 ⋀ y_1_3
{
	if (fault)
	{
		a_3 = value;
	}
	else
	{
		a_3 = x_4_1 & y_1_3;
	}

	return 0;
}
	
int MULT::set_a_1_3(bool fault, int value)	// = a_3
{
	if (fault)
	{
		a_1_3 = value;
	}
	else
	{
		a_1_3 = a_3;
	}

	return 0;
}
	
int MULT::set_a_2_3(bool fault, int value)	// = a_3
{
	if (fault)
	{
		a_2_3 = value;
	}
	else
	{
		a_2_3 = a_3;
	}

	return 0;
}
	
int MULT::set_b_1(bool fault, int value)	// = x_2_2 ⋀ y_2_1
{
	if (fault)
	{
		b_1 = value;
	}
	else
	{
		b_1 = x_2_2 & y_2_1;
	}

	return 0;
}
	
int MULT::set_b_1_1(bool fault, int value)	// = b_1
{
	if (fault)
	{
		b_1_1 = value;
	}
	else
	{
		b_1_1  = b_1;
	}

	return 0;
}
	
int MULT::set_b_2_1(bool fault, int value)	// = b_1
{
	if (fault)
	{
		b_2_1 = value;
	}
	else
	{
		b_2_1 = b_1;
	}

	return 0;
}
	
int MULT::set_b_2(bool fault, int value)	// = x_3_2 ⋀ y_2_2
{
	if (fault)
	{
		b_2 = value;
	}
	else
	{
		b_2 = x_3_2 & y_2_2;
	}

	return 0;
}
	
int MULT::set_b_1_2(bool fault, int value)	// = b_2
{
	if (fault)
	{
		b_1_2 = value;
	}
	else
	{
		b_1_2 = b_2;
	}

	return 0;
}
	
int MULT::set_b_2_2(bool fault, int value)	// = b_2
{
	if (fault)
	{
		b_2_2 = value;
	}
	else
	{
		b_2_2 = b_2;
	}

	return 0;
}

int MULT::set_b_3(bool fault, int value)	// = x_4_2 ⋀ y_2_3
{
	if (fault)
	{
		b_3 = value;
	}
	else
	{
		b_3 = x_4_2 & y_2_3;
	}

	return 0;
}

int MULT::set_b_1_3(bool fault, int value)	// = b_3
{
	if (fault)
	{
		b_1_3 = value;
	}
	else
	{
		b_1_3 = b_3;
	}

	return 0;
}
	
int MULT::set_b_2_3(bool fault, int value)	// = b_3
{
	if (fault)
	{
		b_2_3 = value;
	}
	else
	{
		b_2_3 = b_3;
	}

	return 0;
}
	
int MULT::set_z_2(bool fault, int value)	// = a_1_2 ⊕ b_1_1
{
	if (fault)
	{
		z_2 = value;
	}
	else
	{
		z_2 = a_1_2 ^ b_1_1;
	}

	return 0;
}

int MULT::set_c_1(bool fault, int value)	// = a_2_2 ⋀ b_2_1
{
	if (fault)
	{
		c_1 = value;
	}
	else
	{
		c_1 = a_2_2 & b_2_1;
	}

	return 0;
}
	
int MULT::set_c_1_1(bool fault, int value)	// = c_1
{
	if (fault)
	{
		c_1_1 = value;
	}
	else
	{
		c_1_1 = c_1;
	}

	return 0;
}

int MULT::set_c_2_1(bool fault, int value)	// = c_1
{
	if (fault)
	{
		c_2_1 = value;
	}
	else
	{
		c_2_1 = c_1;
	}

	return 0;
}
	
int MULT::set_s(bool fault, int value)		// = a_1_3 ⊕ b_1_2
{
	if (fault)
	{
		s = value;
	}
	else
	{
		s = a_1_3 ^ b_1_2;
	}

	return 0;
}

int MULT::set_s_1(bool fault, int value)	// = s
{
	if (fault)
	{
		s_1 = value;
	}
	else
	{
		s_1 = s;
	}

	return 0;
}

int MULT::set_s_2(bool fault, int value)	// = s
{
	if (fault)
	{
		s_2 = value;
	}
	else
	{
		s_2 = s;
	}

	return 0;
}

int MULT::set_p(bool fault, int value)		// = a_2_3 ⋀ b_2_2
{
	if (fault)
	{
		p = value;
	}
	else
	{
		p = a_2_3 & b_2_2;
	}

	return 0;
}

int MULT::set_z_3(bool fault, int value)	// = s_1 ⊕ c_1_1
{
	if (fault)
	{
		z_3 = value;
	}
	else
	{
		z_3 = s_1 ^ c_1_1;
	}

	return 0;
}

int MULT::set_q(bool fault, int value)		// = s_2 ⋀ c_2_1
{
	if (fault)
	{
		q = value;
	}
	else
	{
		q = s_2 & c_2_1;
	}

	return 0;
}

int MULT::set_c_2(bool fault, int value)	// = p ∨ q
{
	if (fault)
	{
		c_2 = value;
	}
	else
	{
		c_2 = p | q;
	}

	return 0;
}

int MULT::set_c_1_2(bool fault, int value)	// = c_2
{
	if (fault)
	{
		c_1_2 = value;
	}
	else
	{
		c_1_2 = c_2;
	}

	return 0;
}

int MULT::set_c_2_2(bool fault, int value)	// = c_2
{
	if (fault)
	{
		c_2_2 = value;
	}
	else
	{
		c_2_2 = c_2;
	}

	return 0;
}

int MULT::set_z_4(bool fault, int value)	// = b_1_3 ⊕ c_1_2
{
	if (fault)
	{
		z_4 = value;
	}
	else
	{
		z_4 = b_1_3 ^ c_1_2;
	}

	return 0;
}

int MULT::set_z_5(bool fault, int value)	// = b_2_3 ⋀ c_2_2
{
	if (fault)
	{
		z_5 = value;
	}
	else
	{
		z_5 = b_2_3 & c_2_2;
	}

	return 0;
}

int calc(bool* fa, int* va, int pattern, int* zf);

int simulate()
{
	int x1;
	int x2;
	int y1;
	int y2;
	int y3;
	x1 = 1;
	x2 = 1;
	y1 = 0;
	y2 = 1;
	y3 = 1;
	


	/*	49. [24] Write a program that determines exactly which of the 100 single-
		stuck-at faults of the circuit in Fig. 34 are detected by each of the 32 possible
		input patterns. Also find all the minimum sets of test patterns that will
		discover every such fault (unless it's not detectable).

	*/

	int record[32][100];

	memset(record, 0, 32*100*sizeof(int));

	for (int pattern=0; pattern <32; pattern++)
	{
		bool fa[50];
		int va[50];
		int z[5];
		int zf[5];

		for (int j=0; j<50; j++)
		{
			fa[j] = false;
			va[j] = 1;
		}

		calc(fa, va, pattern, z);

		cout<<pattern<<endl;

		for (int f=0; f<50; f++)
		{
			for (int v=0; v<2; v++)
			{
				for (int j=0; j<50; j++)
				{
					fa[j] = false;
					va[j] = 1;
				}

				fa[f] = true;
				va[f] = v;

				calc(fa, va, pattern, zf);
				if ( (z[0]==zf[0]) && (z[1]==zf[1]) && (z[2]==zf[2]) 
				  && (z[3]==zf[3]) && (z[4]==zf[4]))
				{
					//cout<<"0 ";
					record[pattern][f*2+v] = 0;
				}
				else
				{
					//cout<<"1 ";
					record[pattern][f*2+v] = 1;
				}

			}
		}

		//cout<<endl;
	}

	for (int s=0; s<100; s++)
	{
		int r = 0;
		for (int t=0; t<32; t++)
		{
			r |= record[t][s];
		}

		cout<<r<<" ";
	}

	return 0;
}

int calc(bool* fa, int* va, int pattern, int* zf)
{
	int x1 = pattern & 1;
	int x2 = (pattern>>1) & 1;
	int y1 = (pattern>>2) & 1;
	int y2 = (pattern>>3) & 1;
	int y3 = (pattern>>4) & 1;
	MULT holder;
	MULT* m = &holder;

	int i;
	i=0;
	m->set_x_1(fa[i], va[i], x1);	// input

	i=1;
	m->set_x_1_1(fa[i], va[i]);	// = x_1
	
	i=2;
	m->set_x_2_1(fa[i], va[i]);	// = x_1
	
	i=3;
	m->set_x_3_1(fa[i], va[i]);	// = x_1_1
	
	i=4;
	m->set_x_4_1(fa[i], va[i]);	// = x_1_1
	
	i=5;
	m->set_x_2(fa[i], va[i], x2);	// input
	
	i=6;
	m->set_x_1_2(fa[i], va[i]);	// = x_2
	
	i=7;
	m->set_x_2_2(fa[i], va[i]);	// = x_2

	i=8;
	m->set_x_3_2(fa[i], va[i]);	// = x_1_2

	i=9;
	m->set_x_4_2(fa[i], va[i]);	// = x_1_2

	i=10;
	m->set_y_1(fa[i], va[i], y1);	// input

	i=11;
	m->set_y_1_1(fa[i], va[i]);	// = y_1

	i=12;
	m->set_y_2_1(fa[i], va[i]);	// = y_1

	i=13;
	m->set_y_2(fa[i], va[i], y2);	// input

	i=14;
	m->set_y_1_2(fa[i], va[i]);	// = y_2

	i=15;
	m->set_y_2_2(fa[i], va[i]);	// = y_2

	i=16;
	m->set_y_3(fa[i], va[i], y3);	// input

	i=17;
	m->set_y_1_3(fa[i], va[i]);	// = y_3

	i=18;
	m->set_y_2_3(fa[i], va[i]);	// = y_3

	i=19;
	m->set_z_1(fa[i], va[i]);	// = x_2_1 ⋀ y_1_1

	i=20;
	m->set_a_2(fa[i], va[i]);	// = x_3_1 ⋀ y_1_2

	i=21;
	m->set_a_1_2(fa[i], va[i]);	// = a_2

	i=22;
	m->set_a_2_2(fa[i], va[i]);	// = a_2

	i=23;
	m->set_a_3(fa[i], va[i]);	// = x_4_1 ⋀ y_1_3

	i=24;
	m->set_a_1_3(fa[i], va[i]);	// = a_3

	i=25;
	m->set_a_2_3(fa[i], va[i]);	// = a_3

	i=26;
	m->set_b_1(fa[i], va[i]);	// = x_2_2 ⋀ y_2_1

	i=27;
	m->set_b_1_1(fa[i], va[i]);	// = b_1

	i=28;
	m->set_b_2_1(fa[i], va[i]);	// = b_1

	i=29;
	m->set_b_2(fa[i], va[i]);	// = x_3_2 ⋀ y_2_2

	i=30;
	m->set_b_1_2(fa[i], va[i]);	// = b_2

	i=31;
	m->set_b_2_2(fa[i], va[i]);	// = b_2

	i=32;
	m->set_b_3(fa[i], va[i]);	// = x_4_2 ⋀ y_2_3

	i=33;
	m->set_b_1_3(fa[i], va[i]);	// = b_3

	i=34;
	m->set_b_2_3(fa[i], va[i]);	// = b_3

	i=35;
	m->set_z_2(fa[i], va[i]);	// = a_1_2 ⊕ b_1_1

	i=36;
	m->set_c_1(fa[i], va[i]);	// = a_2_2 ⋀ b_2_1

	i=37;
	m->set_c_1_1(fa[i], va[i]);	// = c_1

	i=38;
	m->set_c_2_1(fa[i], va[i]);	// = c_1

	i=39;
	m->set_s(fa[i], va[i]);		// = a_1_3 ⊕ b_1_2

	i=40;
	m->set_s_1(fa[i], va[i]);	// = s

	i=41;
	m->set_s_2(fa[i], va[i]);	// = s

	i=42;
	m->set_p(fa[i], va[i]);		// = a_2_3 ⋀ b_2_2

	i=43;
	m->set_z_3(fa[i], va[i]);	// = s_1 ⊕ c_1_1

	i=44;
	m->set_q(fa[i], va[i]);		// = s_2 ⋀ c_2_1

	i=45;
	m->set_c_2(fa[i], va[i]);	// = p ∨ q

	i=46;
	m->set_c_1_2(fa[i], va[i]);	// = c_2

	i=47;
	m->set_c_2_2(fa[i], va[i]);	// = c_2

	i=48;
	m->set_z_4(fa[i], va[i]);	// = b_1_3 ⊕ c_1_2

	i=49;
	m->set_z_5(fa[i], va[i]);	// = b_2_3 ⋀ c_2_2


	zf[0] = m->get_z_1();
	zf[1] = m->get_z_2();
	zf[2] = m->get_z_3();
	zf[3] = m->get_z_4();
	zf[4] = m->get_z_5();

	//cout<<m->get_z_5()<<m->get_z_4()<<m->get_z_3()<<m->get_z_2()<<m->get_z_1()<<endl;

	return 0;
}


int main()
{
	simulate();



	cout<<"Fault testing"<<endl;
}