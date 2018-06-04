/*	Code practice for 7.2.2.2 COMBINATORIAL ALGORITHMS
	Fault testing. 

	Jacob Yang 4-June-2018

*/

#include <iostream>

using namespace std;


class MULT
{
public:
	int set_x_1(int x1);	// input
	int set_x_1_1(bool fault, int value);	// = x_1
	int set_x_2_1(bool fault, int value);	// = x_1
	int set_x_3_1(bool fault, int value);	// = x_1_1
	int set_x_4_1(bool fault, int value);	// = x_1_1
	int set_x_2(int x2);	// input
	int set_x_1_2(bool fault, int value);	// = x_2
	int set_x_2_2(bool fault, int value);	// = x_2
	int set_x_3_2(bool fault, int value);	// = x_1_2
	int set_x_4_2(bool fault, int value);	// = x_1_2
	int set_y_1(int y1);	// input
	int set_y_1_1(bool fault, int value);	// = y_1
	int set_y_2_1(bool fault, int value);	// = y_1
	int set_y_2(bool fault, int value);	// input
	int set_y_1_2(bool fault, int value);	// = y_2
	int set_y_2_2(bool fault, int value);	// = y_2
	int set_y_3(int y3);	// input
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
	int set_p(bool fault, int value);		// = a_2_3 ⊕ b_2_2
	int set_z_3(bool fault, int value);	// = s_1 ⊕ c_1_1
	int set_q(bool fault, int value);		// = s_2 ⋀ c_2_1
	int set_c_2(bool fault, int value);	// = p ∨ q
	int set_c_1_2(bool fault, int value);	// = c_2
	int set_c_2_2(bool fault, int value);	// = c_2
	int set_z_4(bool fault, int value);	// = b_1_3 ⊕ b_1_2
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
}


int MULT::set_x_1(int x1)	// input
{
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

int MULT::set_x_2(int x2)	// input
{
	x_2 = x2;
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

int MULT::set_y_1(int y1)	// input
{
	y_1 = y1;

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

int MULT::set_y_2(int y2)	// input
{
	y_2 = y2;

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

int MULT::set_y_3(int y3)	// input
{
	y_3 = y3;

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

int set_b_3(bool fault, int value)	// = x_4_2 ⋀ y_2_3
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

int MULT::set_p(bool fault, int value)		// = a_2_3 ⊕ b_2_2
{
	if (fault)
	{
		p = value;
	}
	else
	{
		p = a_2_3 ^ b_2_2;
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

int MULT::set_z_4(bool fault, int value)	// = b_1_3 ⊕ b_1_2
{
	if (fault)
	{
		z_4 = value;
	}
	else
	{
		z_4 = b_1_3 ^ b_1_2;
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

int main()
{
	// x_2 x_1 = 11, y_3 y_2 y_1 = 110
	int x_1 = 1;



	cout<<"Fault testing"<<endl;
}