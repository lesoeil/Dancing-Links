/* chess_pento_generator.cpp

	Jacob 2017-11-02

	To create a utility program to generate options for 12 pentominoes
	which will be laid in 8 x 8 chessboard box leaving the center four squares vacant. 
*/


#include<iostream>

using namespace std;
/*
string box[3][20] = {
  {"00","01","02","03","04","05","06","07","08","09","0a","0b","0c","0d","0e","0f","0g","0h","0i","0j"},
  {"10","11","12","13","14","15","16","17","18","19","1a","1b","1c","1d","1e","1f","1g","1h","1i","1j"},
  {"20","21","22","23","24","25","26","27","28","29","2a","2b","2c","2d","2e","2f","2g","2h","2i","2j"},
};
*/

#if 0 // 8x8 Chessboard with 33,34,43,44 left empty.
const int row = 8;
const int col = 8;

string box[row][col] = {
	{"00","01","02","03","04","05","06","07"},
	{"10","11","12","13","14","15","16","17"},
	{"20","21","22","23","24","25","26","27"},
	{"30","31","32","NA","NA","35","36","37"},
	{"40","41","42","NA","NA","45","46","47"},
	{"50","51","52","53","54","55","56","57"},
	{"60","61","62","63","64","65","66","67"},
	{"70","71","72","73","74","75","76","77"},
};

bool check(int i, int j)
{
	bool bPass = false;

	if ( ((i==3) && (j==3)) || ((i==3) && (j==4)) || ((i==4) && (j==3)) || ((i==4) && (j==4)))
	{
		bPass = false;
	}
	else
	{
		bPass = true;
	}

	return bPass;
}
#endif

#if 0
const int row = 5;
const int col = 12;

string box[row][col] = {
	{"00","01","02","03","04","05","06","07","08","09","0a","0b"},
	{"10","11","12","13","14","15","16","17","18","19","1a","1b"},
	{"20","21","22","23","24","25","26","27","28","29","2a","2b"},
	{"30","31","32","33","34","35","36","37","38","39","3a","3b"},
	{"40","41","42","43","44","45","46","47","48","49","4a","4b"},
};

bool check(int i, int j)
{
	bool bPass = true;
	return bPass;
}

int main_5x12()
{
	printO();
	//printO_half();
	//printO_half_5x12();
	//printO_hmiddle_vertical_5x12();
	printP();
	printQ();
	//printQ_half_5x12();
	printR();
	printS();
	printT();
	printU();
	printV();
	//printV_half();
	printW();
	printX();
	//printX_unify();
	//printX_h1_5x12();
	//printX_hmid_5x12();
	printY();
	printZ();

	return 0;
}
#endif


const int row = 6;
const int col = 10;

string box[row][col] = {
	{"00","01","02","03","04","05","06","07","08","09"},
	{"10","11","12","13","14","15","16","17","18","19"},
	{"20","21","22","23","24","25","26","27","28","29"},
	{"30","31","32","33","34","35","36","37","38","39"},
	{"40","41","42","43","44","45","46","47","48","49"},
	{"50","51","52","53","54","55","56","57","58","59"},
};

bool check(int i, int j)
{
	bool bPass = true;
	return bPass;
}

/* This version of mega
bool megaCheck(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int x5, int y5)
{
	bool bMegaPass = false;

	if ((x1==0) || (x2==0) || (x3==0) || (x4==0) || (x5==0) ||		
		(y1==0) || (y2==0) || (y3==0) || (y4==0) || (y5==0) ||
		(x1==row-1) || (x2==row-1) || (x3==row-1) || (x4==row-1) || (x5==row-1) ||
		(y1==col-1) || (y2==col-1) || (y3==col-1) || (y4==col-1) || (y5==col-1))
	{
		bMegaPass = false;
	}
	else
	{
		bMegaPass = true;
	}

	return bMegaPass;
}
*/

void printO();
void printO_half();
void printO_half_5x12();
void printO_hmiddle_vertical_5x12();
void printP();
void printQ();
void printQ_half_5x12();
void printR();
void printS();
void printT();
void printU();
void printV();
void printV_half();
void printW();
void printX();
void printX_unify();
void printX_h1_5x12();
void printX_hmid_5x12();
void printX_OneFourth_6x10();
void printY();
void printZ();


void printP_pro();
void printQ_pro();
void printR_pro();
void printS_pro();
void printT_pro();
void printU_pro();
void printV_pro();
void printW_pro();
void printX_pro();
void printY_pro();
void printZ_pro();


int main()
{
	printZ();
#if 0
	printO();
	printP();
	printQ();
	printR();
	printS();
	printT();
	printU();
	printV();
	printW();
	//printX();
	printX_OneFourth_6x10();
	printY();
	printZ();
#endif

	return 0;
}


//	cout<<"Number of Options for P: "<<count<<endl;

void printZ_pro()
{
	int count = 0;

	/*	# #
		  #
		  # #	*/
	for (int i=0; i<1; i++)
	{
		for (int j=0; j<=17; j++)
		{
			if ((j*3+2)%5==0)
			{
				cout<<"Z "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i+1][j+1]<<" "<<box[i+2][j+1]<<" "<<box[i+2][j+2];
				cout<<endl;
				count++;
			}
		}
	}

	/*	  # #
		  #
		# #		*/
	for (int i=0; i<1; i++)
	{
		for (int j=0; j<=17; j++)
		{
			if ((j*3+2)%5==0)
			{
				cout<<"Z "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i+1][j+1]<<" "<<box[i+2][j]<<" "<<box[i+2][j+1];
				cout<<endl;
				count++;
			}
		}
	}

	/*	    #
		# # #
		#		*/
	for (int i=0; i<1; i++)
	{
		for (int j=0; j<=17; j++)
		{
			if ((j*3+2)%5==0)
			{
				cout<<"Z "<<box[i][j+2]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j];
				cout<<endl;
				count++;
			}
		}
	}

	/*	#
		# # #
		    #	*/
	for (int i=0; i<1; i++)
	{
		for (int j=0; j<=17; j++)
		{
			if ((j*3+2)%5==0)
			{
				cout<<"Z "<<box[i][j]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j+2];
				cout<<endl;
				count++;
			}
		}
	}

	cout<<"Number of Options for Z: "<<count<<endl;
}

void printY_pro()
{
	int count=0;

	/*	    #
		# # # #		*/
	for (int i=0; i<=1; i++)
	{
		for (int j=0; j<=16; j++)
		{
			if ( ((i==0)&&(j==0)) || ((i==0)&&(j==16)))
			{
				continue;
			}
			cout<<"Y "<<box[i][j+2]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+1][j+3];
			cout<<endl;
			count++;
		}
	}

	/*	  #
		# # # #		*/
	for (int i=0; i<=1; i++)
	{
		for (int j=0; j<=16; j++)
		{
			if ( ((i==0)&&(j==0)) || ((i==0)&&(j==16)))
			{
				continue;
			}
			cout<<"Y "<<box[i][j+1]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+1][j+3];
			cout<<endl;
			count++;
		}
	}

	/*	# # # #
		    #		*/
	for (int i=0; i<=1; i++)
	{
		for (int j=0; j<=16; j++)
		{
			if ( ((i==1)&&(j==0)) || ((i==1)&&(j==16)))
			{
				continue;
			}
			cout<<"Y "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i][j+3]<<" "<<box[i+1][j+2];
			cout<<endl;
			count++;
		}
	}

	/*	# # # #
		  #			*/
	for (int i=0; i<=1; i++)
	{
		for (int j=0; j<=16; j++)
		{
			if ( ((i==1)&&(j==0)) || ((i==1)&&(j==16)))
			{
				continue;
			}
			cout<<"Y "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i][j+3]<<" "<<box[i+1][j+1];
			cout<<endl;
			count++;
		}
	}

	cout<<"Number of Options for Y: "<<count<<endl;
}

void printX_pro()
{
	int count = 0;
	/*	  #
		# # #
		  #		*/
	for (int i=0; i<1; i++)
	{
		for (int j=0; j<=17; j++)
		{
			if ((j*3+2)%5==0)
			{	
				cout<<"X "<<box[i][j+1]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j+1];
				cout<<endl;
				count++;
			}
		}
	}

	cout<<"Number of Options for X: "<<count<<endl;
}


void printW_pro()
{
	int count = 0;

	/*	  # #
		# #
		#		*/
	for (int i=0; i<1; i++)
	{
		for (int j=0; j<=17; j++)
		{
			if ((j*3+1)%5==0)
			{
				cout<<"W "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+2][j];
				cout<<endl;
				count++;
			}
		}
	}

	/*	# #
		  # #
		    #	*/
	for (int i=0; i<1; i++)
	{
		for (int j=0; j<=17; j++)
		{
			if ((j*3+3)%5==0)
			{
				cout<<"W "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j+2];
				cout<<endl;
				count++;
			}
		}
	}

	/*	#
		# #
		  # #	*/
	for (int i=0; i<1; i++)
	{
		for (int j=0; j<=17; j++)
		{
			if ((j*3+1)%5==0)
			{
				cout<<"W "<<box[i][j]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+2][j+1]<<" "<<box[i+2][j+2];
				cout<<endl;
				count++;
			}
		}
	}

	/*	    #
		  # #
		# #		*/
	for (int i=0; i<1; i++)
	{
		for (int j=0; j<=17; j++)
		{
			if ((j*3+3)%5==0)
			{
				cout<<"W "<<box[i][j+2]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j]<<" "<<box[i+2][j+1];
				cout<<endl;
				count++;
			}
		}
	}

	cout<<"Number of Options for W: "<<count<<endl;
}

void printV_pro()
{
	int count = 0;

	/*	# # #
		#
		#		*/
	for (int i=0; i<1; i++)
	{
		for (int j=0; j<=17; j++)
		{
			if ((j*3)%5==0)
			{
				cout<<"V "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i+1][j]<<" "<<box[i+2][j];
				cout<<endl;
				count++;
			}
		}
	}
#if 0
	/*	#
		#
		# #	#	*/
	for (int i=0; i<1; i++)
	{
		for (int j=0; j<=17; j++)
		{
			cout<<"V "<<box[i][j]<<" "<<box[i+1][j]<<" "<<box[i+2][j]<<" "<<box[i+2][j+1]<<" "<<box[i+2][j+2];
			cout<<endl;
		}
	}

	/*	# # #
		    #
		    #	*/
	for (int i=0; i<1; i++)
	{
		for (int j=0; j<=17; j++)
		{
			cout<<"V "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j+2];
			cout<<endl;
		}
	}

	/*	    #
		    #
		# # #	*/
	for (int i=0; i<1; i++)
	{
		for (int j=0; j<=17; j++)
		{
			cout<<"V "<<box[i][j+2]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j]<<" "<<box[i+2][j+1]<<" "<<box[i+2][j+2];
			cout<<endl;
		}
	}
#endif
	cout<<"Number of Options for V: "<<count<<endl;
}

void printU_pro()
{
	int count = 0;

	/*	#   #
		# # #	*/
	for (int i=1; i<=1; i++)
	{
		for (int j=0; j<=17; j++)
		{
			cout<<"U "<<box[i][j]<<" "<<box[i][j+2]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2];
			cout<<endl;
			count++;
		}
	}

	/*	# # #
		#   #	*/
	for (int i=0; i<=0; i++)
	{
		for (int j=0; j<=17; j++)
		{
			cout<<"U "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i+1][j]<<" "<<box[i+1][j+2];
			cout<<endl;
			count++;
		}
	}

	/*	# #
		# 	
		# #		*/
	for (int i=0; i<1; i++)
	{
		for (int j=0; j<=18; j++)
		{
			if ((j*3)%5==0)
			{
				cout<<"U "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i+1][j]<<" "<<box[i+2][j]<<" "<<box[i+2][j+1];
				cout<<endl;
				count++;
			}
		}
	}


	/*	# #
		  #	
		# #		*/
	for (int i=0; i<1; i++)
	{
		for (int j=0; j<=18; j++)
		{
			if ((j*3+1)%5==0)
			{
				cout<<"U "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i+1][j+1]<<" "<<box[i+2][j]<<" "<<box[i+2][j+1];
				cout<<endl;
				count++;
			}
		}
	}

	cout<<"Number of Options for U: "<<count<<endl;
}

void printT_pro()
{
	int count = 0;

	/*	# # #
		  #
		  #		*/
	for (int i=0; i<=0; i++)
	{
		for (int j=0; j<=17; j++)
		{
			if (((j*3+2)%5)==0)
			{
				cout<<"T "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i+1][j+1]<<" "<<box[i+2][j+1];
				cout<<endl;
				count++;
			}
		}
	}

	/*	  #
		  #
		# # #	*/	
	for (int i=0; i<=0; i++)
	{
		for (int j=0; j<=17; j++)
		{
			if (((j*3+2)%5)==0)
			{
				cout<<"T "<<box[i][j+1]<<" "<<box[i+1][j+1]<<" "<<box[i+2][j]<<" "<<box[i+2][j+1]<<" "<<box[i+2][j+2];
				cout<<endl;
				count++;
			}
		}
	}

	/*	#
		# # #
		#		*/
	for (int i=0; i<=0; i++)
	{
		for (int j=0; j<=17; j++)
		{
			if (((j*3)%5)==0)
			{
				cout<<"T "<<box[i][j]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j];
				cout<<endl;
				count++;
			}
		}
	}

	/*	    #
		# # #
		    #	*/
	for (int i=0; i<=0; i++)
	{
		for (int j=0; j<=17; j++)
		{
			if (((j*3+4)%5)==0)
			{
				cout<<"T "<<box[i][j+2]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j+2];
				cout<<endl;
				count++;
			}
		}
	}

	cout<<"Number of Options for T: "<<count<<endl;
}

void printS_pro()
{
	int count = 0;

	/*	# # #
		 	# #		*/
	for (int i=0; i<=1; i++)
	{
		for (int j=0; j<=16; j++)
		{
			if ( ((i==0) && (j==0)) || ((i==0) && (j==16)))
			{
				continue;
			}
			cout<<"S "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i+1][j+2]<<" "<<box[i+1][j+3];
			cout<<endl;
			count++;
		}
	}

	/*	  # # #
		# #			*/
	for (int i=0; i<=1; i++)
	{
		for (int j=0; j<=16; j++)
		{
			if ( ((i==0) && (j==0)) || ((i==1) && (j==16)))
			{
				continue;
			}
			cout<<"S "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i][j+3]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1];
			cout<<endl;
			count++;
		}
	}

	/*		# #
		# #	#		*/
	for (int i=0; i<=1; i++)
	{
		for (int j=0; j<=16; j++)
		{
			if ( ((i==0) && (j==0)) || ((i==1) && (j==16)))
			{
				continue;
			}
			cout<<"S "<<box[i][j+2]<<" "<<box[i][j+3]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2];
			cout<<endl;
			count++;
		}
	}

	/*	# #
		  # # #		*/
	for (int i=0; i<=1; i++)
	{
		for (int j=0; j<=16; j++)
		{
			if ( ((i==1) && (j==0)) || ((i==0) && (j==16)))
			{
				continue;
			}
			cout<<"S "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+1][j+3];
			cout<<endl;
			count++;
		}
	}

	cout<<"Number of Options for S: "<<count<<endl;
}

void printR_pro()
{
	int count = 0;
	/*	  # #
		# #
		  #		*/
	for (int i=0; i<1; i++)
	{
		for (int j=0; j<=17; j++)
		{
			if (((j*3+2)%5) == 0)
			{
				cout<<"R "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+2][j+1];
				cout<<endl;
				count++;
			}
		}
	}

	/*	# #
		  # #
		  #		*/
	for (int i=0; i<1; i++)
	{
		for (int j=0; j<=17; j++)
		{
			if (((j*3+2)%5) == 0)
			{
				cout<<"R "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j+1];
				cout<<endl;
				count++;
			}
		}
	}

	/*	  #
		# #
		  # #	*/
	for (int i=0; i<1; i++)
	{
		for (int j=0; j<=17; j++)
		{
			if (((j*3+2)%5) == 0)
			{
				cout<<"R "<<box[i][j+1]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+2][j+1]<<" "<<box[i+2][j+2];
				cout<<endl;
				count++;
			}
		}
	}

	/*	  #
		  # #
		# #		*/
	for (int i=0; i<1; i++)
	{
		for (int j=0; j<=17; j++)
		{
			if (((j*3+2)%5) == 0)
			{
				cout<<"R "<<box[i][j+1]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j]<<" "<<box[i+2][j+1];
				cout<<endl;
				count++;
			}
		}
	}

	/*	  #
		# # #
		    #	*/
	for (int i=0; i<1; i++)
	{
		for (int j=0; j<=17; j++)
		{
			if (((j*3+3)%5) == 0)
			{
				cout<<"R "<<box[i][j+1]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j+2];
				cout<<endl;
				count++;
			}
		}
	}

	/*	  #
		# # #
		#		*/
	for (int i=0; i<1; i++)
	{
		for (int j=0; j<=17; j++)
		{
			if (((j*3+1)%5) == 0)
			{
				cout<<"R "<<box[i][j+1]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j];
				cout<<endl;
				count++;
			}
		}
	}

	/*	    #
		# # #
		  #		*/
	for (int i=0; i<1; i++)
	{
		for (int j=0; j<=17; j++)
		{
			if (((j*3+3)%5) == 0)
			{
				cout<<"R "<<box[i][j+2]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j+1];
				cout<<endl;
				count++;
			}
		}
	}

	/*	#
		# # #
		  #		*/
	for (int i=0; i<1; i++)
	{
		for (int j=0; j<=17; j++)
		{
			if (((j*3+1)%5) == 0)
			{
				cout<<"R "<<box[i][j]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j+1];
				cout<<endl;
				count++;
			}
		}
	}

	cout<<"Number of Options for R: "<<count<<endl;
}

void printQ_pro()
{
	int count = 0;

	/*	####
		   #	*/
	for (int i=0; i<=1; i++)
	{
		for (int j=0; j<=16; j++)
		{
			if ((i==1) && (j==0))
			{
				continue;
			}
			cout<<"Q "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i][j+3]<<" "<<box[i+1][j+3];
			cout<<endl;
			count++;
		}
	}

	/*	####
		#		*/
	for (int i=0; i<=1; i++)
	{
		for (int j=0; j<=16; j++)
		{
			if ((i==1) && (j==16))
			{
				continue;
			}
			cout<<"Q "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i][j+3]<<" "<<box[i+1][j];
			cout<<endl;
			count++;
		}
	}


	/*	#
		####	*/
	for (int i=0; i<=1; i++)
	{
		for (int j=0; j<=16; j++)
		{
			if ((i==0) && (j==16))
			{
				continue;
			}
			cout<<"Q "<<box[i][j]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+1][j+3];
			cout<<endl;
			count++;
		}
	}


	/*	   #
		####	*/		
	for (int i=0; i<=1; i++)
	{
		for (int j=0; j<=16; j++)
		{
			if ((i==0) && (j==0))
			{
				continue;
			}
			cout<<"Q "<<box[i][j+3]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+1][j+3];
			cout<<endl;
			count++;
		}
	}

	cout<<"Number of Options for Q: "<<count<<endl;
}

void printP_pro()
{
	int count = 0;
	/*	##
		##
		#	*/
	for (int i=0; i<1; i++)
	{
		for (int j=0; j<=18; j++)
		{
			if ( ((j*3) % 5) == 0)
			{
				cout<<"P "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+2][j];
				cout<<endl;
				count++;
			}
		}
	}

	/*	##
		##
		 #
		    */
	for (int i=0; i<1; i++)
	{
		for (int j=0; j<=18; j++)
		{
			if ( (((19-(j+1))*3) % 5) == 0)
			{	
				cout<<"P "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+2][j+1];
				cout<<endl;
				count++;
			}
		}
	}

	/*	#
		##
		##	*/
	for (int i=0; i<1; i++)
	{
		for (int j=0; j<=18; j++)
		{
			if ( ((j*3) % 5) == 0)
			{
				cout<<"P "<<box[i][j]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+2][j]<<" "<<box[i+2][j+1];
				cout<<endl;
				count++;
			}
		}
	}

	/*	 #
		##
		##	*/
	for (int i=0; i<1; i++)
	{
		for (int j=0; j<=18; j++)
		{
			if ( (((19-(j+1))*3) % 5) == 0)
			{
				cout<<"P "<<box[i][j+1]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+2][j]<<" "<<box[i+2][j+1];
				cout<<endl;
				count++;
			}
		}
	}

	/*	###
		##	*/
	for (int i=0; i<=1; i++)
	{
		for (int j=0; j<=17; j++)
		{
			if ((i==1) && (j==17))
			{
				continue;
				//Because there is only 1 cell (2,19) in right bottom corner which can not be filled.
			}
			cout<<"P "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1];
			cout<<endl;
			count++;
		}
	}


	/*	###
		 ##	*/
	for (int i=0; i<=1; i++)
	{
		for (int j=0; j<=17; j++)
		{
			if ((i==1) && (j==0))
			{
				continue;
				//Because there is only 1 cell (2,0) in left bottom corner which can not be filled.
			}
			cout<<"P "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2];
			cout<<endl;
			count++;
		}
	}


	/*	##
		###	*/
	for (int i=0; i<=1; i++)
	{
		for (int j=0; j<=17; j++)
		{
			if ((i==0) && (j==17))
			{
				continue;
				//Because there is only 1 cell (0,19) in right top corner which can not be filled.
			}
			cout<<"P "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2];
			cout<<endl;
			count++;
		}
	}

	/*	 ##
		###	*/
	for (int i=0; i<=1; i++)
	{
		for (int j=0; j<=17; j++)
		{
			if ((i==0) && (j==0))
			{
				continue;
				//Because there is only 1 cell (0,0) in left top corner which can not be filled.
			}
			cout<<"P "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2];
			cout<<endl;
			count++;
		}
	}

	cout<<"Number of Options for P: "<<count<<endl;
}


/*************************************************************************************************
**************************************************************************************************
**************************************************************************************************
**************************************************************************************************/


void printZ()
{
	int count = 0;

	/*	# #
		  #
		  # #	*/
	for (int i=0; i<=(row-3); i++)
	{
		for (int j=0; j<=(col-3); j++)
		{
			//if (check(i,j) && check(i,j+1) && check(i+1,j+1) && check(i+2,j+1) && check(i+2,j+2))
			if (megaCheck(i,j, i,j+1, i+1,j+1, i+2,j+1, i+2,j+2))
			{
				cout<<"Z "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i+1][j+1]<<" "<<box[i+2][j+1]<<" "<<box[i+2][j+2];
				cout<<endl;
				count++;
			}
		}
	}

	/*	  # #
		  #
		# #		*/
	for (int i=0; i<=(row-3); i++)
	{
		for (int j=0; j<=(col-3); j++)
		{
			//if (check(i,j+1) && check(i,j+2) && check(i+1,j+1) && check(i+2,j) && check(i+2,j+1))
			if (megaCheck(i,j+1, i,j+2, i+1,j+1, i+2,j, i+2,j+1))
			{
				cout<<"Z "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i+1][j+1]<<" "<<box[i+2][j]<<" "<<box[i+2][j+1];
				cout<<endl;
				count++;
			}
		}
	}

	/*	    #
		# # #
		#		*/
	for (int i=0; i<=(row-3); i++)
	{
		for (int j=0; j<=(col-3); j++)
		{
			//if (check(i,j+2) && check(i+1,j) && check(i+1,j+1) && check(i+1,j+2) && check(i+2,j))
			if (megaCheck(i,j+2, i+1,j, i+1,j+1, i+1,j+2, i+2,j))
			{
				cout<<"Z "<<box[i][j+2]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j];
				cout<<endl;
				count++;
			}
		}
	}

	/*	#
		# # #
		    #	*/
	for (int i=0; i<=(row-3); i++)
	{
		for (int j=0; j<=(col-3); j++)
		{
			//if (check(i,j) && check(i+1,j) && check(i+1,j+1) && check(i+1,j+2) && check(i+2,j+2))
			if (megaCheck(i,j, i+1,j, i+1,j+1, i+1,j+2, i+2,j+2))
			{
				cout<<"Z "<<box[i][j]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j+2];
				cout<<endl;
				count++;
			}
		}
	}

	//cout<<"Number of Options for Z: "<<count<<endl;
}

void printY()
{
	int count = 0;

	/*	    #
		# # # #		*/
	for (int i=0; i<=(row-2); i++)
	{
		for (int j=0; j<=(col-4); j++)
		{
			//if (check(i,j+2) && check(i+1,j) && check(i+1,j+1) && check(i+1,j+2) && check(i+1,j+3))
			if (megaCheck(i,j+2, i+1,j, i+1,j+1, i+1,j+2, i+1,j+3))
			{
				cout<<"Y "<<box[i][j+2]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+1][j+3];
				cout<<endl;
				count++;
			}
		}
	}

	/*	  #
		# # # #		*/
	for (int i=0; i<=(row-2); i++)
	{
		for (int j=0; j<=(col-4); j++)
		{
			//if (check(i,j+1) && check(i+1,j) && check(i+1,j+1) && check(i+1,j+2) && check(i+1,j+3))
			if (megaCheck(i,j+1, i+1,j, i+1,j+1, i+1,j+2, i+1,j+3))
			{
				cout<<"Y "<<box[i][j+1]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+1][j+3];
				cout<<endl;
				count++;
			}
		}
	}

	/*	# # # #
		    #		*/
	for (int i=0; i<=(row-2); i++)
	{
		for (int j=0; j<=(col-4); j++)
		{
			//if (check(i,j) && check(i,j+1) && check(i,j+2) && check(i,j+3) && check(i+1,j+2))
			if (megaCheck(i,j, i,j+1, i,j+2, i,j+3, i+1,j+2))
			{
				cout<<"Y "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i][j+3]<<" "<<box[i+1][j+2];
				cout<<endl;
				count++;
			}
		}
	}

	/*	# # # #
		  #			*/
	for (int i=0; i<=(row-2); i++)
	{
		for (int j=0; j<=(col-4); j++)
		{
			//if (check(i,j) && check(i,j+1) && check(i,j+2) && check(i,j+3) && check(i+1,j+1))
			if (megaCheck(i,j, i,j+1, i,j+2, i,j+3, i+1,j+1))
			{
				cout<<"Y "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i][j+3]<<" "<<box[i+1][j+1];
				cout<<endl;
				count++;
			}
		}
	}

	/*	#
		# #
		#
		#		*/
	for (int i=0; i<=(row-4); i++)
	{
		for (int j=0; j<=(col-2); j++)
		{
			//if (check(i,j) && check(i+1,j) && check(i+1,j+1) && check(i+2,j) && check(i+3,j))
			if (megaCheck(i,j, i+1,j, i+1,j+1, i+2,j, i+3,j))
			{
				cout<<"Y "<<box[i][j]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+2][j]<<" "<<box[i+3][j];
				cout<<endl;
				count++;
			}
		}
	}


	/*	#
		#
		# #
		#		*/
	for (int i=0; i<=(row-4); i++)
	{
		for (int j=0; j<=(col-2); j++)
		{
			//if (check(i,j) && check(i+1,j) && check(i+2,j) && check(i+2,j+1) && check(i+3,j))
			if (megaCheck(i,j, i+1,j, i+2,j, i+2,j+1, i+3,j))
			{
				cout<<"Y "<<box[i][j]<<" "<<box[i+1][j]<<" "<<box[i+2][j]<<" "<<box[i+2][j+1]<<" "<<box[i+3][j];
				cout<<endl;
				count++;
			}
		}
	}

	/*   #
	   # #
		 #
		 #		*/
	for (int i=0; i<=(row-4); i++)
	{
		for (int j=0; j<=(col-2); j++)
		{
			//if (check(i,j+1) && check(i+1,j) && check(i+1,j+1) && check(i+2,j+1) && check(i+3,j+1))
			if (megaCheck(i,j+1, i+1,j, i+1,j+1, i+2,j+1, i+3,j+1))
			{
				cout<<"Y "<<box[i][j+1]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+2][j+1]<<" "<<box[i+3][j+1];
				cout<<endl;
				count++;
			}
		}
	}

	/*   #
	     #
	   # #
		 #		*/
	for (int i=0; i<=(row-4); i++)
	{
		for (int j=0; j<=(col-2); j++)
		{
			//if (check(i,j+1) && check(i+1,j+1) && check(i+2,j) && check(i+2,j+1) && check(i+3,j+1))
			if (megaCheck(i,j+1, i+1,j+1, i+2,j, i+2,j+1, i+3,j+1))
			{
				cout<<"Y "<<box[i][j+1]<<" "<<box[i+1][j+1]<<" "<<box[i+2][j]<<" "<<box[i+2][j+1]<<" "<<box[i+3][j+1];
				cout<<endl;
				count++;
			}
		}
	}

	//cout<<"Number of Options for Y: "<<count<<endl;
}

void printX_hmid_5x12()
{
	int count = 0;

	/*	  #
		# # #
		  #		*/
	for (int i=(row-3)/2; i<=(row-3)/2; i++)
	{
		for (int j=0; j<=(col-3); j++)
		{
			//if (check(i,j+1) && check(i+1,j) && check(i+1,j+1) && check(i+1,j+2) && check(i+2,j+1))
			if (megaCheck(i,j+1, i+1,j, i+1,j+1, i+1,j+2, i+2,j+1))
			{
				cout<<"X "<<box[i][j+1]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j+1];
				cout<<endl;
				count++;
			}
		}
	}

	//cout<<"Number of Options for X: "<<count<<endl;	
}

void printX_h1_5x12()
{
	int count = 0;

	/*	  #
		# # #
		  #		*/
	for (int i=0; i<=(((row-3)/2)-1); i++)
	{
		for (int j=0; j<=(col-3); j++)
		{
			//if (check(i,j+1) && check(i+1,j) && check(i+1,j+1) && check(i+1,j+2) && check(i+2,j+1))
			if (megaCheck(i,j+1, i+1,j, i+1,j+1, i+1,j+2, i+2,j+1))
			{
				cout<<"X "<<box[i][j+1]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j+1];
				cout<<endl;
				count++;
			}
		}
	}

	//cout<<"Number of Options for X: "<<count<<endl;
}

void printX_unify()
{
	int count = 0;

	/*	  #
		# # #
		  #		*/
	for (int i=0; i<=((row-3)/2); i++)
	{
		for (int j=i; j<=((col-3)/2); j++)
		{
			//if (check(i,j+1) && check(i+1,j) && check(i+1,j+1) && check(i+1,j+2) && check(i+2,j+1))
			if (megaCheck(i,j+1, i+1,j, i+1,j+1, i+1,j+2, i+2,j+1))
			{
				cout<<"X "<<box[i][j+1]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j+1];
				cout<<endl;
				count++;
			}
		}
	}

	//cout<<"Number of Options for X: "<<count<<endl;
}


/* left-up corner: i=0..1, j=0..3
	as a result, X will be placed in area of (0..3) x (0..5)
	row = 6 
	col = 10

*/

void printX_OneFourth_6x10()
{
	int count = 0;

	/*	  #
		# # #
		  #		*/
	for (int i=0; i<=(row-3)/2; i++)
	{
		for (int j=0; j<=(col-3)/2; j++)
		{
			//if (check(i,j+1) && check(i+1,j) && check(i+1,j+1) && check(i+1,j+2) && check(i+2,j+1))
			if (megaCheck(i,j+1, i+1,j, i+1,j+1, i+1,j+2, i+2,j+1))
			{
				cout<<"X "<<box[i][j+1]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j+1];
				cout<<endl;
				count++;
			}
		}
	}

	//cout<<"Number of Options for X: "<<count<<endl;
}


void printX()
{
	int count = 0;

	/*	  #
		# # #
		  #		*/
	for (int i=0; i<=(row-3); i++)
	{
		for (int j=0; j<=(col-3); j++)
		{
			//if (check(i,j+1) && check(i+1,j) && check(i+1,j+1) && check(i+1,j+2) && check(i+2,j+1))
			if (megaCheck(i,j+1, i+1,j, i+1,j+1, i+1,j+2, i+2,j+1))
			{
				cout<<"X "<<box[i][j+1]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j+1];
				cout<<endl;
				count++;
			}
		}
	}

	//cout<<"Number of Options for X: "<<count<<endl;
}

void printW()
{
	int count = 0;

	/*	  # #
		# #
		#		*/
	for (int i=0; i<=(row-3); i++)
	{
		for (int j=0; j<=(col-3); j++)
		{
			//if (check(i,j+1) && check(i,j+2) && check(i+1,j) && check(i+1,j+1) && check(i+2,j))
			if (megaCheck(i,j+1, i,j+2, i+1,j, i+1,j+1, i+2,j))
			{
				cout<<"W "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+2][j];
				cout<<endl;
				count++;
			}
		}
	}

	/*	# #
		  # #
		    #	*/
	for (int i=0; i<=(row-3); i++)
	{
		for (int j=0; j<=(col-3); j++)
		{
			//if (check(i,j) && check(i,j+1) && check(i+1,j+1) && check(i+1,j+2) && check(i+2,j+2))
			if (megaCheck(i,j, i,j+1, i+1,j+1, i+1,j+2, i+2,j+2))
			{
				cout<<"W "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j+2];
				cout<<endl;
				count++;
			}
		}
	}

	/*	#
		# #
		  # #	*/
	for (int i=0; i<=(row-3); i++)
	{
		for (int j=0; j<=(col-3); j++)
		{
			//if (check(i,j) && check(i+1,j) && check(i+1,j+1) && check(i+2,j+1) && check(i+2,j+2))
			if (megaCheck(i,j, i+1,j, i+1,j+1, i+2,j+1, i+2,j+2))
			{
				cout<<"W "<<box[i][j]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+2][j+1]<<" "<<box[i+2][j+2];
				cout<<endl;
				count++;
			}
		}
	}

	/*	    #
		  # #
		# #		*/
	for (int i=0; i<=(row-3); i++)
	{
		for (int j=0; j<=(col-3); j++)
		{
			//if (check(i,j+2) && check(i+1,j+1) && check(i+1,j+2) && check(i+2,j) && check(i+2,j+1))
			if (megaCheck(i,j+2, i+1,j+1, i+1,j+2, i+2,j, i+2,j+1))
			{
				cout<<"W "<<box[i][j+2]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j]<<" "<<box[i+2][j+1];
				cout<<endl;
				count++;
			}
		}
	}

	//cout<<"Number of Options for W: "<<count<<endl;
}

void printV_half()
{
	int count = 0;

	/*	# # #
		#
		#		*/
	for (int i=0; i<=(row-3); i++)
	{
		for (int j=0; j<i; j++)
		{
			//if (check(i,j) && check(i,j+1) && check(i,j+2) && check(i+1,j) && check(i+2,j))
			if (megaCheck(i,j, i,j+1, i,j+2, i+1,j, i+2,j))
			{
				cout<<"V "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i+1][j]<<" "<<box[i+2][j];
				cout<<endl;
				count++;
			}
		}
	}

	/*	#
		#
		# #	#	*/
	for (int i=0; i<=(row-3); i++)
	{
		for (int j=0; j<i; j++)
		{
			//if (check(i,j) && check(i+1,j) && check(i+2,j) && check(i+2,j+1) && check(i+2,j+2))
			if (megaCheck(i,j, i+1,j, i+2,j, i+2,j+1, i+2,j+2))
			{
				cout<<"V "<<box[i][j]<<" "<<box[i+1][j]<<" "<<box[i+2][j]<<" "<<box[i+2][j+1]<<" "<<box[i+2][j+2];
				cout<<endl;
				count++;
			}
		}
	}

	/*	# # #
		    #
		    #	*/
	for (int i=0; i<=(row-3); i++)
	{
		for (int j=0; j<i; j++)
		{
			//if (check(i,j) && check(i,j+1) && check(i,j+2) && check(i+1,j+2) && check(i+2,j+2))
			if (megaCheck(i,j, i,j+1, i,j+2, i+1,j+2, i+2,j+2))
			{
				cout<<"V "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j+2];
				cout<<endl;
				count++;
			}
		}
	}

	/*	    #
		    #
		# # #	*/
	for (int i=0; i<=(row-3); i++)
	{
		for (int j=0; j<=i; j++)
		{
			//if (check(i,j+2) && check(i+1,j+2) && check(i+2,j) && check(i+2,j+1) && check(i+2,j+2))
			if (megaCheck(i,j+2, i+1,j+2, i+2,j, i+2,j+1, i+2,j+2))
			{
				cout<<"V "<<box[i][j+2]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j]<<" "<<box[i+2][j+1]<<" "<<box[i+2][j+2];
				cout<<endl;
				count++;
			}
		}
	}

	//cout<<"Number of Options for V: "<<count<<endl;
}

void printV()
{
	int count = 0;

	/*	# # #
		#
		#		*/
	for (int i=0; i<=(row-3); i++)
	{
		for (int j=0; j<=(col-3); j++)
		{
			//if (check(i,j) && check(i,j+1) && check(i,j+2) && check(i+1,j) && check(i+2,j))
			if (megaCheck(i,j, i,j+1, i,j+2, i+1,j, i+2,j))
			{
				cout<<"V "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i+1][j]<<" "<<box[i+2][j];
				cout<<endl;
				count++;
			}
		}
	}

	/*	#
		#
		# #	#	*/
	for (int i=0; i<=(row-3); i++)
	{
		for (int j=0; j<=(col-3); j++)
		{
			//if (check(i,j) && check(i+1,j) && check(i+2,j) && check(i+2,j+1) && check(i+2,j+2))
			if (megaCheck(i,j, i+1,j, i+2,j, i+2,j+1, i+2,j+2))
			{
				cout<<"V "<<box[i][j]<<" "<<box[i+1][j]<<" "<<box[i+2][j]<<" "<<box[i+2][j+1]<<" "<<box[i+2][j+2];
				cout<<endl;
				count++;
			}
		}
	}

	/*	# # #
		    #
		    #	*/
	for (int i=0; i<=(row-3); i++)
	{
		for (int j=0; j<=(col-3); j++)
		{
			//if (check(i,j) && check(i,j+1) && check(i,j+2) && check(i+1,j+2) && check(i+2,j+2))
			if (megaCheck(i,j, i,j+1, i,j+2, i+1,j+2, i+2,j+2))
			{
				cout<<"V "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j+2];
				cout<<endl;
				count++;
			}
		}
	}

	/*	    #
		    #
		# # #	*/
	for (int i=0; i<=(row-3); i++)
	{
		for (int j=0; j<=(col-3); j++)
		{
			//if (check(i,j+2) && check(i+1,j+2) && check(i+2,j) && check(i+2,j+1) && check(i+2,j+2))
			if (megaCheck(i,j+2, i+1,j+2, i+2,j, i+2,j+1, i+2,j+2))
			{
				cout<<"V "<<box[i][j+2]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j]<<" "<<box[i+2][j+1]<<" "<<box[i+2][j+2];
				cout<<endl;
				count++;
			}
		}
	}

	//cout<<"Number of Options for V: "<<count<<endl;
}

void printU()
{
	int count = 0;

	/*	#   #
		# # #	*/
	for (int i=0; i<=(row-2); i++)
	{
		for (int j=0; j<=(col-3); j++)
		{
			//if (check(i,j) && check(i,j+2) && check(i+1,j) && check(i+1,j+1) && check(i+1,j+2))
			if (megaCheck(i,j, i,j+2, i+1,j, i+1,j+1, i+1,j+2))
			{
				cout<<"U "<<box[i][j]<<" "<<box[i][j+2]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2];
				cout<<endl;
				count++;
			}
		}
	}

	/*	# # #
		#   #	*/
	for (int i=0; i<=(row-2); i++)
	{
		for (int j=0; j<=(col-3); j++)
		{
			//if (check(i,j) && check(i,j+1) && check(i,j+2) && check(i+1,j) && check(i+1,j+2))
			if (megaCheck(i,j, i,j+1, i,j+2, i+1,j, i+1,j+2))
			{
				cout<<"U "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i+1][j]<<" "<<box[i+1][j+2];
				cout<<endl;
				count++;
			}
		}
	}

	/*	# #
		# 	
		# #		*/
	for (int i=0; i<=(row-3); i++)
	{
		for (int j=0; j<=(col-2); j++)
		{
			//if (check(i,j) && check(i,j+1) && check(i+1,j) && check(i+2,j) && check(i+2,j+1))
			if (megaCheck(i,j, i,j+1, i+1,j, i+2,j, i+2,j+1))
			{
				cout<<"U "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i+1][j]<<" "<<box[i+2][j]<<" "<<box[i+2][j+1];
				cout<<endl;
				count++;
			}
		}
	}


	/*	# #
		  #	
		# #		*/
	for (int i=0; i<=(row-3); i++)
	{
		for (int j=0; j<=(col-2); j++)
		{
			//if (check(i,j) && check(i,j+1) && check(i+1,j+1) && check(i+2,j) && check(i+2,j+1))
			if (megaCheck(i,j, i,j+1, i+1,j+1, i+2,j, i+2,j+1))
			{
				cout<<"U "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i+1][j+1]<<" "<<box[i+2][j]<<" "<<box[i+2][j+1];
				cout<<endl;
				count++;
			}
		}
	}

	//cout<<"Number of Options for U: "<<count<<endl;
}


void printT()
{
	int count = 0;

	/*	# # #
		  #
		  #		*/
	for (int i=0; i<=(row-3); i++)
	{
		for (int j=0; j<=(col-3); j++)
		{
			//if (check(i,j) && check(i,j+1) && check(i,j+2) && check(i+1,j+1) && check(i+2,j+1))
			if (megaCheck(i,j, i,j+1, i,j+2, i+1,j+1, i+2,j+1))
			{
				cout<<"T "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i+1][j+1]<<" "<<box[i+2][j+1];
				cout<<endl;
				count++;
			}
		}
	}

	/*	  #
		  #
		# # #	*/	
	for (int i=0; i<=(row-3); i++)
	{
		for (int j=0; j<=(col-3); j++)
		{
			//if (check(i,j+1) && check(i+1,j+1) && check(i+2,j) && check(i+2,j+1) && check(i+2,j+2))
			if (megaCheck(i,j+1, i+1,j+1, i+2,j, i+2,j+1, i+2,j+2))
			{
				cout<<"T "<<box[i][j+1]<<" "<<box[i+1][j+1]<<" "<<box[i+2][j]<<" "<<box[i+2][j+1]<<" "<<box[i+2][j+2];
				cout<<endl;
				count++;
			}
		}
	}

	/*	#
		# # #
		#		*/
	for (int i=0; i<=(row-3); i++)
	{
		for (int j=0; j<=(col-3); j++)
		{
			//if (check(i,j) && check(i+1,j) && check(i+1,j+1) && check(i+1,j+2) && check(i+2,j))
			if (megaCheck(i,j, i+1,j, i+1,j+1, i+1,j+2, i+2,j))
			{
				cout<<"T "<<box[i][j]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j];
				cout<<endl;
				count++;
			}
		}
	}

	/*	    #
		# # #
		    #	*/
	for (int i=0; i<=(row-3); i++)
	{
		for (int j=0; j<=(col-3); j++)
		{
			//if (check(i,j+2) && check(i+1,j) && check(i+1,j+1) && check(i+1,j+2) && check(i+2,j+2))
			if (megaCheck(i,j+2, i+1,j, i+1,j+1, i+1,j+2, i+2,j+2))
			{
				cout<<"T "<<box[i][j+2]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j+2];
				cout<<endl;
				count++;
			}
		}
	}

	//cout<<"Number of Options for T: "<<count<<endl;
}


void printS()
{
	int count = 0;

	/*	# # #
		 	# #		*/
	for (int i=0; i<=(row-2); i++)
	{
		for (int j=0; j<=(col-4); j++)
		{
			//if (check(i,j) && check(i,j+1) && check(i,j+2) && check(i+1,j+2) && check(i+1,j+3))
			if (megaCheck(i,j, i,j+1, i,j+2, i+1,j+2, i+1,j+3))
			{
				cout<<"S "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i+1][j+2]<<" "<<box[i+1][j+3];
				cout<<endl;
				count++;
			}
		}
	}

	/*	  # # #
		# #			*/
	for (int i=0; i<=(row-2); i++)
	{
		for (int j=0; j<=(col-4); j++)
		{
			//if (check(i,j+1) && check(i,j+2) && check(i,j+3) && check(i+1,j) && check(i+1,j+1))
			if (megaCheck(i,j+1, i,j+2, i,j+3, i+1,j, i+1,j+1))
			{
				cout<<"S "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i][j+3]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1];
				cout<<endl;
				count++;
			}
		}
	}

	/*		# #
		# #	#		*/
	for (int i=0; i<=(row-2); i++)
	{
		for (int j=0; j<=(col-4); j++)
		{
			//if (check(i,j+2) && check(i,j+3) && check(i+1,j) && check(i+1,j+1) && check(i+1,j+2))
			if (megaCheck(i,j+2, i,j+3, i+1,j, i+1,j+1, i+1,j+2))
			{
				cout<<"S "<<box[i][j+2]<<" "<<box[i][j+3]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2];
				cout<<endl;
				count++;
			}
		}
	}

	/*	# #
		  # # #		*/
	for (int i=0; i<=(row-2); i++)
	{
		for (int j=0; j<=(col-4); j++)
		{
			//if (check(i,j) && check(i,j+1) && check(i+1,j+1) && check(i+1,j+2) && check(i+1,j+3))
			if (megaCheck(i,j, i,j+1, i+1,j+1, i+1,j+2, i+1,j+3))
			{
				cout<<"S "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+1][j+3];
				cout<<endl;
				count++;
			}
		}
	}


	/*	
		#
		#
		##
		 #	
		 	*/
	for (int i=0; i<=(row-4); i++)
	{
		for (int j=0; j<=(col-2); j++)
		{
			//if (check(i,j) && check(i+1,j) && check(i+2,j) && check(i+2,j+1) && check(i+3,j+1))
			if (megaCheck(i,j, i+1,j, i+2,j, i+2,j+1, i+3,j+1))
			{
				cout<<"S "<<box[i][j]<<" "<<box[i+1][j]<<" "<<box[i+2][j]<<" "<<box[i+2][j+1]<<" "<<box[i+3][j+1];
				cout<<endl;
				count++;
			}
		}
	}

	/*	
		#
		#
	   ##
	   #	
		 	*/
	for (int i=0; i<=(row-4); i++)
	{
		for (int j=0; j<=(col-2); j++)
		{
			//if (check(i,j+1) && check(i+1,j+1) && check(i+2,j) && check(i+2,j+1) && check(i+3,j))
			if (megaCheck(i,j+1, i+1,j+1, i+2,j, i+2,j+1, i+3,j))
			{
				cout<<"S "<<box[i][j+1]<<" "<<box[i+1][j+1]<<" "<<box[i+2][j]<<" "<<box[i+2][j+1]<<" "<<box[i+3][j];
				cout<<endl;
				count++;
			}
		}
	}

	/*	 #
		##
		#
		#	
		 	*/
	for (int i=0; i<=(row-4); i++)
	{
		for (int j=0; j<=(col-2); j++)
		{
			//if (check(i,j+1) && check(i+1,j) && check(i+1,j+1) && check(i+2,j) && check(i+3,j))
			if (megaCheck(i,j+1, i+1,j, i+1,j+1, i+2,j, i+3,j))
			{
				cout<<"S "<<box[i][j+1]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+2][j]<<" "<<box[i+3][j];
				cout<<endl;
				count++;
			}
		}
	}

	/* #
	   ##
		#
		#	
			*/
	for (int i=0; i<=(row-4); i++)
	{
		for (int j=0; j<=(col-2); j++)
		{
			//if (check(i,j) && check(i+1,j) && check(i+1,j+1) && check(i+2,j+1) && check(i+3,j+1))
			if (megaCheck(i,j, i+1,j, i+1,j+1, i+2,j+1, i+3,j+1))
			{
				cout<<"S "<<box[i][j]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+2][j+1]<<" "<<box[i+3][j+1];
				cout<<endl;
				count++;
			}
		}
	}


	//cout<<"Number of Options for S: "<<count<<endl;
}

void printR()
{
	int count = 0;

	/*	  # #
		# #
		  #		*/
	for (int i=0; i<=(row-3); i++)
	{
		for (int j=0; j<=(col-3); j++)
		{
			//if (check(i,j+1) && check(i,j+2) && check(i+1,j) && check(i+1,j+1) && check(i+2,j+1))
			if (megaCheck(i,j+1, i,j+2, i+1,j, i+1,j+1, i+2,j+1))
			{
				cout<<"R "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+2][j+1];
				cout<<endl;
				count++;
			}
		}
	}

	/*	# #
		  # #
		  #		*/
	for (int i=0; i<=(row-3); i++)
	{
		for (int j=0; j<=(col-3); j++)
		{
			//if (check(i,j) && check(i,j+1) && check(i+1,j+1) && check(i+1,j+2) && check(i+2,j+1))
			if (megaCheck(i,j, i,j+1, i+1,j+1, i+1,j+2, i+2,j+1))
			{
				cout<<"R "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j+1];
				cout<<endl;
				count++;
			}
		}
	}

	/*	  #
		# #
		  # #	*/
	for (int i=0; i<=(row-3); i++)
	{
		for (int j=0; j<=(col-3); j++)
		{
			//if (check(i,j+1) && check(i+1,j) && check(i+1,j+1) && check(i+2,j+1) && check(i+2,j+2))
			if (megaCheck(i,j+1, i+1,j, i+1,j+1, i+2,j+1, i+2,j+2))
			{
				cout<<"R "<<box[i][j+1]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+2][j+1]<<" "<<box[i+2][j+2];
				cout<<endl;
				count++;
			}
		}
	}

	/*	  #
		  # #
		# #		*/
	for (int i=0; i<=(row-3); i++)
	{
		for (int j=0; j<=(col-3); j++)
		{
			//if (check(i,j+1) && check(i+1,j+1) && check(i+1,j+2) && check(i+2,j) && check(i+2,j+1))
			if (megaCheck(i,j+1, i+1,j+1, i+1,j+2, i+2,j, i+2,j+1))
			{
				cout<<"R "<<box[i][j+1]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j]<<" "<<box[i+2][j+1];
				cout<<endl;
				count++;
			}
		}
	}

	/*	  #
		# # #
		    #	*/
	for (int i=0; i<=(row-3); i++)
	{
		for (int j=0; j<=(col-3); j++)
		{
			//if (check(i,j+1) && check(i+1,j) && check(i+1,j+1) && check(i+1,j+2) && check(i+2,j+2))
			if (megaCheck(i,j+1, i+1,j, i+1,j+1, i+1,j+2, i+2,j+2))
			{
				cout<<"R "<<box[i][j+1]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j+2];
				cout<<endl;
				count++;
			}
		}
	}

	/*	  #
		# # #
		#		*/
	for (int i=0; i<=(row-3); i++)
	{
		for (int j=0; j<=(col-3); j++)
		{
			//if (check(i,j+1) && check(i+1,j) && check(i+1,j+1) && check(i+1,j+2) && check(i+2,j))
			if (megaCheck(i,j+1, i+1,j, i+1,j+1, i+1,j+2, i+2,j))
			{
				cout<<"R "<<box[i][j+1]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j];
				cout<<endl;
				count++;
			}
		}
	}

	/*	    #
		# # #
		  #		*/
	for (int i=0; i<=(row-3); i++)
	{
		for (int j=0; j<=(col-3); j++)
		{
			//if (check(i,j+2) && check(i+1,j) && check(i+1,j+1) && check(i+1,j+2) && check(i+2,j+1))
			if (megaCheck(i,j+2, i+1,j, i+1,j+1, i+1,j+2, i+2,j+1))
			{
				cout<<"R "<<box[i][j+2]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j+1];
				cout<<endl;
				count++;
			}
		}
	}

	/*	#
		# # #
		  #		*/
	for (int i=0; i<=(row-3); i++)
	{
		for (int j=0; j<=(col-3); j++)
		{
			//if (check(i,j) && check(i+1,j) && check(i+1,j+1) && check(i+1,j+2) && check(i+2,j+1))
			if (megaCheck(i,j, i+1,j, i+1,j+1, i+1,j+2, i+2,j+1))
			{
				cout<<"R "<<box[i][j]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j+1];
				cout<<endl;
				count++;
			}
		}
	}

	//cout<<"Number of Options for R: "<<count<<endl;
}

void printQ_half_5x12()
{
	int count=0;

	/*	####
		   #	*/
	for (int i=0; i<=(row-2)/2; i++)
	{
		for (int j=0; j<=(col-4); j++)
		{
			//if (check(i,j) && check(i,j+1) && check(i,j+2) && check(i,j+3) && check(i+1,j+3))
			if (megaCheck(i,j, i,j+1, i,j+2, i,j+3, i+1,j+3))
			{
				cout<<"Q "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i][j+3]<<" "<<box[i+1][j+3];
				cout<<endl;
				count++;
			}
		}
	}

	/*	####
		#		*/
	for (int i=0; i<=(row-2)/2; i++)
	{
		for (int j=0; j<=(col-4); j++)
		{
			//if (check(i,j) && check(i,j+1) && check(i,j+2) && check(i,j+3) && check(i+1,j))
			if (megaCheck(i,j, i,j+1, i,j+2, i,j+3, i+1,j))
			{
				cout<<"Q "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i][j+3]<<" "<<box[i+1][j];
				cout<<endl;
				count++;
			}
		}
	}


	/*	#
		####	*/
	for (int i=0; i<=(row-2)/2; i++)
	{
		for (int j=0; j<=(col-4); j++)
		{
			//if (check(i,j) && check(i+1,j) && check(i+1,j+1) && check(i+1,j+2) && check(i+1,j+3))
			if (megaCheck(i,j, i+1,j, i+1,j+1, i+1,j+2, i+1,j+3))
			{
				cout<<"Q "<<box[i][j]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+1][j+3];
				cout<<endl;
				count++;
			}
		}
	}


	/*	   #
		####	*/		
	for (int i=0; i<=(row-2)/2; i++)
	{
		for (int j=0; j<=(col-4); j++)
		{
			//if (check(i,j+3) && check(i+1,j) && check(i+1,j+1) && check(i+1,j+2) && check(i+1,j+3))
			if (megaCheck(i,j+3, i+1,j, i+1,j+1, i+1,j+2, i+1,j+3))
			{
				cout<<"Q "<<box[i][j+3]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+1][j+3];
				cout<<endl;
				count++;
			}
		}
	}


	/*	#
		#
		#
		##	*/
	for (int i=0; i<=(row-4)/2; i++)
	{
		for (int j=0; j<=(col-2); j++)
		{
			//if (check(i,j) && check(i+1,j) && check(i+2,j) && check(i+3,j) && check(i+3,j+1))
			if (megaCheck(i,j, i+1,j, i+2,j, i+3,j, i+3,j+1))
			{
				cout<<"Q "<<box[i][j]<<" "<<box[i+1][j]<<" "<<box[i+2][j]<<" "<<box[i+3][j]<<" "<<box[i+3][j+1];
				cout<<endl;
				count++;
			}
		}
	}

	/*	#
		#
		#
	   ##	*/
	for (int i=0; i<=(row-4)/2; i++)
	{
		for (int j=0; j<=(col-2); j++)
		{
			//if (check(i,j+1) && check(i+1,j+1) && check(i+2,j+1) && check(i+3,j+1) && check(i+3,j))
			if (megaCheck(i,j+1, i+1,j+1, i+2,j+1, i+3,j+1, i+3,j))
			{
				cout<<"Q "<<box[i][j+1]<<" "<<box[i+1][j+1]<<" "<<box[i+2][j+1]<<" "<<box[i+3][j+1]<<" "<<box[i+3][j];
				cout<<endl;
				count++;
			}
		}
	}

	/*	##
		#
		#
		#	*/
	for (int i=0; i<=(row-4)/2; i++)
	{
		for (int j=0; j<=(col-2); j++)
		{
			//if (check(i,j) && check(i,j+1) && check(i+1,j) && check(i+2,j) && check(i+3,j))
			if (megaCheck(i,j, i,j+1, i+1,j, i+2,j, i+3,j))
			{
				cout<<"Q "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i+1][j]<<" "<<box[i+2][j]<<" "<<box[i+3][j];
				cout<<endl;
				count++;
			}
		}
	}

	/* ##
		#
		#
		#	*/
	for (int i=0; i<=(row-4)/2; i++)
	{
		for (int j=0; j<=(col-2); j++)
		{
			//if (check(i,j) && check(i,j+1) && check(i+1,j+1) && check(i+2,j+1) && check(i+3,j+1))
			if (megaCheck(i,j, i,j+1, i+1,j+1, i+2,j+1, i+3,j+1))
			{
				cout<<"Q "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i+1][j+1]<<" "<<box[i+2][j+1]<<" "<<box[i+3][j+1];
				cout<<endl;
				count++;
			}
		}
	}

	//cout<<"Number of Options for Q: "<<count<<endl;
}

void printQ()
{
	int count=0;

	/*	####
		   #	*/
	for (int i=0; i<=(row-2); i++)
	{
		for (int j=0; j<=(col-4); j++)
		{
			//if (check(i,j) && check(i,j+1) && check(i,j+2) && check(i,j+3) && check(i+1,j+3))
			if (megaCheck(i,j, i,j+1, i,j+2, i,j+3, i+1,j+3))
			{
				cout<<"Q "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i][j+3]<<" "<<box[i+1][j+3];
				cout<<endl;
				count++;
			}
		}
	}

	/*	####
		#		*/
	for (int i=0; i<=(row-2); i++)
	{
		for (int j=0; j<=(col-4); j++)
		{
			//if (check(i,j) && check(i,j+1) && check(i,j+2) && check(i,j+3) && check(i+1,j))
			if (megaCheck(i,j, i,j+1, i,j+2, i,j+3, i+1,j))
			{
				cout<<"Q "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i][j+3]<<" "<<box[i+1][j];
				cout<<endl;
				count++;
			}
		}
	}


	/*	#
		####	*/
	for (int i=0; i<=(row-2); i++)
	{
		for (int j=0; j<=(col-4); j++)
		{
			//if (check(i,j) && check(i+1,j) && check(i+1,j+1) && check(i+1,j+2) && check(i+1,j+3))
			if (megaCheck(i,j, i+1,j, i+1,j+1, i+1,j+2, i+1,j+3))
			{
				cout<<"Q "<<box[i][j]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+1][j+3];
				cout<<endl;
				count++;
			}
		}
	}


	/*	   #
		####	*/		
	for (int i=0; i<=(row-2); i++)
	{
		for (int j=0; j<=(col-4); j++)
		{
			//if (check(i,j+3) && check(i+1,j) && check(i+1,j+1) && check(i+1,j+2) && check(i+1,j+3))
			if (megaCheck(i,j+3, i+1,j, i+1,j+1, i+1,j+2, i+1,j+3))
			{
				cout<<"Q "<<box[i][j+3]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+1][j+3];
				cout<<endl;
				count++;
			}
		}
	}


	/*	#
		#
		#
		##	*/
	for (int i=0; i<=(row-4); i++)
	{
		for (int j=0; j<=(col-2); j++)
		{
			//if (check(i,j) && check(i+1,j) && check(i+2,j) && check(i+3,j) && check(i+3,j+1))
			if (megaCheck(i,j, i+1,j, i+2,j, i+3,j, i+3,j+1))
			{
				cout<<"Q "<<box[i][j]<<" "<<box[i+1][j]<<" "<<box[i+2][j]<<" "<<box[i+3][j]<<" "<<box[i+3][j+1];
				cout<<endl;
				count++;
			}
		}
	}

	/*	#
		#
		#
	   ##	*/
	for (int i=0; i<=(row-4); i++)
	{
		for (int j=0; j<=(col-2); j++)
		{
			//if (check(i,j+1) && check(i+1,j+1) && check(i+2,j+1) && check(i+3,j+1) && check(i+3,j))
			if (megaCheck(i,j+1, i+1,j+1, i+2,j+1, i+3,j+1, i+3,j))
			{
				cout<<"Q "<<box[i][j+1]<<" "<<box[i+1][j+1]<<" "<<box[i+2][j+1]<<" "<<box[i+3][j+1]<<" "<<box[i+3][j];
				cout<<endl;
				count++;
			}
		}
	}

	/*	##
		#
		#
		#	*/
	for (int i=0; i<=(row-4); i++)
	{
		for (int j=0; j<=(col-2); j++)
		{
			//if (check(i,j) && check(i,j+1) && check(i+1,j) && check(i+2,j) && check(i+3,j))
			if (megaCheck(i,j, i,j+1, i+1,j, i+2,j, i+3,j))
			{
				cout<<"Q "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i+1][j]<<" "<<box[i+2][j]<<" "<<box[i+3][j];
				cout<<endl;
				count++;
			}
		}
	}

	/* ##
		#
		#
		#	*/
	for (int i=0; i<=(row-4); i++)
	{
		for (int j=0; j<=(col-2); j++)
		{
			//if (check(i,j) && check(i,j+1) && check(i+1,j+1) && check(i+2,j+1) && check(i+3,j+1))
			if (megaCheck(i,j, i,j+1, i+1,j+1, i+2,j+1, i+3,j+1))
			{
				cout<<"Q "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i+1][j+1]<<" "<<box[i+2][j+1]<<" "<<box[i+3][j+1];
				cout<<endl;
				count++;
			}
		}
	}

	//cout<<"Number of Options for Q: "<<count<<endl;
}

void printP()
{
	int count = 0;

	/*	##
		##
		#	*/
	for (int i=0; i<=(row-3); i++)
	{
		for (int j=0; j<=(col-2); j++)
		{			
			//if (check(i,j) && check(i,j+1) && check(i+1,j) && check(i+1,j+1) && check(i+2,j))
			if (megaCheck(i,j, i,j+1, i+1,j, i+1,j+1, i+2,j))
			{
				cout<<"P "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+2][j];
				cout<<endl;
				count++;
			}
		}
	}

	/*	##
		##
		 #
		    */
	for (int i=0; i<=(row-3); i++)
	{
		for (int j=0; j<=(col-2); j++)
		{
			//if (check(i,j) && check(i,j+1) && check(i+1,j) && check(i+1,j+1) && check(i+2,j+1))
			if (megaCheck(i,j, i,j+1, i+1,j, i+1,j+1, i+2,j+1))
			{
				cout<<"P "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+2][j+1];
				cout<<endl;
				count++;
			}
		}
	}

	/*	#
		##
		##	*/
	for (int i=0; i<=(row-3); i++)
	{
		for (int j=0; j<=(col-2); j++)
		{
			//if (check(i,j) && check(i+1,j) && check(i+1,j+1) && check(i+2,j) && check(i+2,j+1))
			if (megaCheck(i,j, i+1,j, i+1,j+1, i+2,j, i+2,j+1))
			{
				cout<<"P "<<box[i][j]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+2][j]<<" "<<box[i+2][j+1];
				cout<<endl;
				count++;
			}
		}
	}

	/*	 #
		##
		##	*/
	for (int i=0; i<=(row-3); i++)
	{
		for (int j=0; j<=(col-2); j++)
		{
			//if (check(i,j+1) && check(i+1,j) && check(i+1,j+1) && check(i+2,j) && check(i+2,j+1))
			if (megaCheck(i,j+1, i+1,j, i+1,j+1, i+2,j, i+2,j+1))
			{
				cout<<"P "<<box[i][j+1]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+2][j]<<" "<<box[i+2][j+1];
				cout<<endl;
				count++;
			}
		}
	}

	/*	###
		##	*/
	for (int i=0; i<=(row-2); i++)
	{
		for (int j=0; j<=(col-3); j++)
		{
			//if (check(i,j) && check(i,j+1) && check(i,j+2) && check(i+1,j) && check(i+1,j+1))
			if (megaCheck(i,j, i,j+1, i,j+2, i+1,j, i+1,j+1))
			{
				cout<<"P "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1];
				cout<<endl;
				count++;
			}
		}
	}


	/*	###
		 ##	*/
	for (int i=0; i<=(row-2); i++)
	{
		for (int j=0; j<=(col-3); j++)
		{
			//if (check(i,j) && check(i,j+1) && check(i,j+2) && check(i+1,j+1) && check(i+1,j+2))
			if (megaCheck(i,j, i,j+1, i,j+2, i+1,j+1, i+1,j+2))
			{
				cout<<"P "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2];
				cout<<endl;
				count++;
			}
		}
	}


	/*	##
		###	*/
	for (int i=0; i<=(row-2); i++)
	{
		for (int j=0; j<=(col-3); j++)
		{
			//if (check(i,j) && check(i,j+1) && check(i+1,j) && check(i+1,j+1) && check(i+1,j+2))
			if (megaCheck(i,j, i,j+1, i+1,j, i+1,j+1, i+1,j+2))
			{
				cout<<"P "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2];
				cout<<endl;
				count++;
			}
		}
	}

	/*	 ##
		###	*/
	for (int i=0; i<=(row-2); i++)
	{
		for (int j=0; j<=(col-3); j++)
		{
			//if (check(i,j+1) && check(i,j+2) && check(i+1,j) && check(i+1,j+1) && check(i+1,j+2))
			if (megaCheck(i,j+1, i,j+2, i+1,j, i+1,j+1, i+1,j+2))
			{
				cout<<"P "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2];
				cout<<endl;
				count++;
			}
		}
	}

	//cout<<"Number of Options for P: "<<count<<endl;
}

void printO_hmiddle_vertical_5x12()
{
	int count = 0;

	/*
		#####
	*/
	for (int i=row/2; i<=row/2; i++)
	{
		for (int j=0; j<=((col-5)/2); j++)
		{
			//if (check(i,j) && check(i,j+1) && check(i,j+2) && check(i,j+3) && check(i,j+4))
			if (megaCheck(i,j, i,j+1, i,j+2, i,j+3, i,j+4))
			{
				cout<<"O "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i][j+3]<<" "<<box[i][j+4];
				cout<<endl;
				count++;
			}
		}
	}

	/*
		#
		#
		#
		#
		#
	*/

	for (int i=0; i<=(row-5); i++)
	{
		for (int j=0; j<=((col-1)/2); j++)
		{
			//if (check(i,j) && check(i+1,j) && check(i+2,j) && check(i+3,j) && check(i+4,j))
			if (megaCheck(i,j, i+1,j, i+2,j, i+3,j, i+4,j))
			{
				cout<<"O "<<box[i][j]<<" "<<box[i+1][j]<<" "<<box[i+2][j]<<" "<<box[i+3][j]<<" "<<box[i+4][j];
				cout<<endl;
				count++;
			}
		}
	}

	//cout<<"Number of Options for O: "<<count<<endl;
}


void printO_half_5x12()
{
	int count = 0;

	/*
		#####
	*/
	for (int i=0; i<=(((row-1)/2)-1); i++)
	{
		for (int j=0; j<=((col-5)/2); j++)
		{
			//if (check(i,j) && check(i,j+1) && check(i,j+2) && check(i,j+3) && check(i,j+4))
			if (megaCheck(i,j, i,j+1, i,j+2, i,j+3, i,j+4))
			{
				cout<<"O "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i][j+3]<<" "<<box[i][j+4];
				cout<<endl;
				count++;
			}
		}
	}

	/*
		#
		#
		#
		#
		#
	*/
#if	0
	for (int i=0; i<=(row-5); i++)
	{
		for (int j=0; j<=((col-1)/2); j++)
		{
			if (check(i,j) && check(i+1,j) && check(i+2,j) && check(i+3,j) && check(i+4,j))
			{
				cout<<"O "<<box[i][j]<<" "<<box[i+1][j]<<" "<<box[i+2][j]<<" "<<box[i+3][j]<<" "<<box[i+4][j];
				cout<<endl;
				count++;
			}
		}
	}
#endif
	//cout<<"Number of Options for O: "<<count<<endl;
}


void printO_half()
{
	int count = 0;

	/*
		#####
	*/
	for (int i=0; i<=(row-1); i++)
	{
		for (int j=0; j<=(col-5); j++)
		{
			//if (check(i,j) && check(i,j+1) && check(i,j+2) && check(i,j+3) && check(i,j+4))
			if (megaCheck(i,j, i,j+1, i,j+2, i,j+3, i,j+4))
			{
				cout<<"O "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i][j+3]<<" "<<box[i][j+4];
				cout<<endl;
				count++;
			}
		}
	}

	//cout<<"Number of Options for O: "<<count<<endl;
}

void printO()
{
	int count = 0;

	/*
		#####
	*/
	for (int i=0; i<=(row-1); i++)
	{
		for (int j=0; j<=(col-5); j++)
		{
			//if (check(i,j) && check(i,j+1) && check(i,j+2) && check(i,j+3) && check(i,j+4))
			if (megaCheck(i,j, i,j+1, i,j+2, i,j+3, i,j+4))
			{
				cout<<"O "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i][j+3]<<" "<<box[i][j+4];
				cout<<endl;
				count++;
			}
		}
	}

	/*
		#
		#
		#
		#
		#
	*/
	for (int i=0; i<=(row-5); i++)
	{
		for (int j=0; j<=(col-1); j++)
		{
			//if (check(i,j) && check(i+1,j) && check(i+2,j) && check(i+3,j) && check(i+4,j))
			if (megaCheck(i,j, i+1,j, i+2,j, i+3,j, i+4,j))
			{
				cout<<"O "<<box[i][j]<<" "<<box[i+1][j]<<" "<<box[i+2][j]<<" "<<box[i+3][j]<<" "<<box[i+4][j];
				cout<<endl;
				count++;
			}
		}
	}

	//cout<<"Number of Options for O: "<<count<<endl;
}