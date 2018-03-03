/* pento_generator.cpp

	Jacob 2017-10-16

	To create a utility program to generate options for 12 pentominoes
	which will be laid in 3 x 20 rectangular box
*/


#include<iostream>

using namespace std;

string box[3][20] = {
  {"00","01","02","03","04","05","06","07","08","09","0a","0b","0c","0d","0e","0f","0g","0h","0i","0j"},
  {"10","11","12","13","14","15","16","17","18","19","1a","1b","1c","1d","1e","1f","1g","1h","1i","1j"},
  {"20","21","22","23","24","25","26","27","28","29","2a","2b","2c","2d","2e","2f","2g","2h","2i","2j"},
};

void printO();
void printP();
void printQ();
void printR();
void printS();
void printT();
void printU();
void printV();
void printW();
void printX();
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
	printT_pro();
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
	/*	# #
		  #
		  # #	*/
	for (int i=0; i<=0; i++)
	{
		for (int j=0; j<=17; j++)
		{
			cout<<"Z "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i+1][j+1]<<" "<<box[i+2][j+1]<<" "<<box[i+2][j+2];
			cout<<endl;
		}
	}

	/*	  # #
		  #
		# #		*/
	for (int i=0; i<=0; i++)
	{
		for (int j=0; j<=17; j++)
		{
			cout<<"Z "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i+1][j+1]<<" "<<box[i+2][j]<<" "<<box[i+2][j+1];
			cout<<endl;
		}
	}

	/*	    #
		# # #
		#		*/
	for (int i=0; i<=0; i++)
	{
		for (int j=0; j<=17; j++)
		{
			cout<<"Z "<<box[i][j+2]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j];
			cout<<endl;
		}
	}

	/*	#
		# # #
		    #	*/
	for (int i=0; i<=0; i++)
	{
		for (int j=0; j<=17; j++)
		{
			cout<<"Z "<<box[i][j]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j+2];
			cout<<endl;
		}
	}

}

void printY()
{
	/*	    #
		# # # #		*/
	for (int i=0; i<=1; i++)
	{
		for (int j=0; j<=16; j++)
		{
			cout<<"Y "<<box[i][j+2]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+1][j+3];
			cout<<endl;
		}
	}

	/*	  #
		# # # #		*/
	for (int i=0; i<=1; i++)
	{
		for (int j=0; j<=16; j++)
		{
			cout<<"Y "<<box[i][j+1]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+1][j+3];
			cout<<endl;
		}
	}

	/*	# # # #
		    #		*/
	for (int i=0; i<=1; i++)
	{
		for (int j=0; j<=16; j++)
		{
			cout<<"Y "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i][j+3]<<" "<<box[i+1][j+2];
			cout<<endl;
		}
	}

	/*	# # # #
		  #			*/
	for (int i=0; i<=1; i++)
	{
		for (int j=0; j<=16; j++)
		{
			cout<<"Y "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i][j+3]<<" "<<box[i+1][j+1];
			cout<<endl;
		}
	}
}

void printX()
{
	/*	  #
		# # #
		  #		*/
	for (int i=0; i<=0; i++)
	{
		for (int j=0; j<=17; j++)
		{
			cout<<"X "<<box[i][j+1]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j+1];
			cout<<endl;
		}
	}
}

void printW()
{
	/*	  # #
		# #
		#		*/
	for (int i=0; i<=0; i++)
	{
		for (int j=0; j<=17; j++)
		{
			cout<<"W "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+2][j];
			cout<<endl;
		}
	}

	/*	# #
		  # #
		    #	*/
	for (int i=0; i<=0; i++)
	{
		for (int j=0; j<=17; j++)
		{
			cout<<"W "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j+2];
			cout<<endl;
		}
	}

	/*	#
		# #
		  # #	*/
	for (int i=0; i<=0; i++)
	{
		for (int j=0; j<=17; j++)
		{
			cout<<"W "<<box[i][j]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+2][j+1]<<" "<<box[i+2][j+2];
			cout<<endl;
		}
	}

	/*	    #
		  # #
		# #		*/
	for (int i=0; i<=0; i++)
	{
		for (int j=0; j<=17; j++)
		{
			cout<<"W "<<box[i][j+2]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j]<<" "<<box[i+2][j+1];
			cout<<endl;
		}
	}
}

void printV()
{
	/*	# # #
		#
		#		*/
	for (int i=0; i<=0; i++)
	{
		for (int j=0; j<=17; j++)
		{
			cout<<"V "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i+1][j]<<" "<<box[i+2][j];
			cout<<endl;
		}
	}

	/*	#
		#
		# #	#	*/
	for (int i=0; i<=0; i++)
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
	for (int i=0; i<=0; i++)
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
	for (int i=0; i<=0; i++)
	{
		for (int j=0; j<=17; j++)
		{
			cout<<"V "<<box[i][j+2]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j]<<" "<<box[i+2][j+1]<<" "<<box[i+2][j+2];
			cout<<endl;
		}
	}

}

void printU()
{
	/*	#   #
		# # #	*/
	for (int i=0; i<=1; i++)
	{
		for (int j=0; j<=17; j++)
		{
			cout<<"U "<<box[i][j]<<" "<<box[i][j+2]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2];
			cout<<endl;
		}
	}

	/*	# # #
		#   #	*/
	for (int i=0; i<=1; i++)
	{
		for (int j=0; j<=17; j++)
		{
			cout<<"U "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i+1][j]<<" "<<box[i+1][j+2];
			cout<<endl;
		}
	}

	/*	# #
		# 	
		# #		*/
	for (int i=0; i<=0; i++)
	{
		for (int j=0; j<=18; j++)
		{
			cout<<"U "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i+1][j]<<" "<<box[i+2][j]<<" "<<box[i+2][j+1];
			cout<<endl;
		}
	}


	/*	# #
		  #	
		# #		*/
	for (int i=0; i<=0; i++)
	{
		for (int j=0; j<=18; j++)
		{
			cout<<"U "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i+1][j+1]<<" "<<box[i+2][j]<<" "<<box[i+2][j+1];
			cout<<endl;
		}
	}
}


void printT()
{
	/*	# # #
		  #
		  #		*/
	for (int i=0; i<=0; i++)
	{
		for (int j=0; j<=17; j++)
		{
			cout<<"T "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i+1][j+1]<<" "<<box[i+2][j+1];
			cout<<endl;
		}
	}

	/*	  #
		  #
		# # #	*/	
	for (int i=0; i<=0; i++)
	{
		for (int j=0; j<=17; j++)
		{
			cout<<"T "<<box[i][j+1]<<" "<<box[i+1][j+1]<<" "<<box[i+2][j]<<" "<<box[i+2][j+1]<<" "<<box[i+2][j+2];
			cout<<endl;
		}
	}

	/*	#
		# # #
		#		*/
	for (int i=0; i<=0; i++)
	{
		for (int j=0; j<=17; j++)
		{
			cout<<"T "<<box[i][j]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j];
			cout<<endl;
		}
	}

	/*	    #
		# # #
		    #	*/
	for (int i=0; i<=0; i++)
	{
		for (int j=0; j<=17; j++)
		{
			cout<<"T "<<box[i][j+2]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j+2];
			cout<<endl;
		}
	}
}


void printS()
{
	/*	# # #
		 	# #		*/
	for (int i=0; i<=1; i++)
	{
		for (int j=0; j<=16; j++)
		{
			cout<<"S "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i+1][j+2]<<" "<<box[i+1][j+3];
			cout<<endl;
		}
	}

	/*	  # # #
		# #			*/
	for (int i=0; i<=1; i++)
	{
		for (int j=0; j<=16; j++)
		{
			cout<<"S "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i][j+3]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1];
			cout<<endl;
		}
	}

	/*		# #
		# #	#		*/
	for (int i=0; i<=1; i++)
	{
		for (int j=0; j<=16; j++)
		{
			cout<<"S "<<box[i][j+2]<<" "<<box[i][j+3]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2];
			cout<<endl;
		}
	}

	/*	# #
		  # # #		*/
	for (int i=0; i<=1; i++)
	{
		for (int j=0; j<=16; j++)
		{
			cout<<"S "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+1][j+3];
			cout<<endl;
		}
	}

}

void printR()
{
	/*	  # #
		# #
		  #		*/
	for (int i=0; i<=0; i++)
	{
		for (int j=0; j<=17; j++)
		{
			cout<<"R "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+2][j+1];
			cout<<endl;
		}
	}

	/*	# #
		  # #
		  #		*/
	for (int i=0; i<=0; i++)
	{
		for (int j=0; j<=17; j++)
		{
			cout<<"R "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j+1];
			cout<<endl;
		}
	}

	/*	  #
		# #
		  # #	*/
	for (int i=0; i<=0; i++)
	{
		for (int j=0; j<=17; j++)
		{
			cout<<"R "<<box[i][j+1]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+2][j+1]<<" "<<box[i+2][j+2];
			cout<<endl;
		}
	}

	/*	  #
		  # #
		# #		*/
	for (int i=0; i<=0; i++)
	{
		for (int j=0; j<=17; j++)
		{
			cout<<"R "<<box[i][j+1]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j]<<" "<<box[i+2][j+1];
			cout<<endl;
		}
	}

	/*	  #
		# # #
		    #	*/
	for (int i=0; i<=0; i++)
	{
		for (int j=0; j<=17; j++)
		{
			cout<<"R "<<box[i][j+1]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j+2];
			cout<<endl;
		}
	}

	/*	  #
		# # #
		#		*/
	for (int i=0; i<=0; i++)
	{
		for (int j=0; j<=17; j++)
		{
			cout<<"R "<<box[i][j+1]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j];
			cout<<endl;
		}
	}

	/*	    #
		# # #
		  #		*/
	for (int i=0; i<=0; i++)
	{
		for (int j=0; j<=17; j++)
		{
			cout<<"R "<<box[i][j+2]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j+1];
			cout<<endl;
		}
	}

	/*	#
		# # #
		  #		*/
	for (int i=0; i<=0; i++)
	{
		for (int j=0; j<=17; j++)
		{
			cout<<"R "<<box[i][j]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+2][j+1];
			cout<<endl;
		}
	}

}

void printQ()
{
	/*	####
		   #	*/
	for (int i=0; i<=1; i++)
	{
		for (int j=0; j<=16; j++)
		{
			cout<<"Q "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i][j+3]<<" "<<box[i+1][j+3];
			cout<<endl;
		}
	}

	/*	####
		#		*/
	for (int i=0; i<=1; i++)
	{
		for (int j=0; j<=16; j++)
		{
			cout<<"Q "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i][j+3]<<" "<<box[i+1][j];
			cout<<endl;
		}
	}


	/*	#
		####	*/
	for (int i=0; i<=1; i++)
	{
		for (int j=0; j<=16; j++)
		{
			cout<<"Q "<<box[i][j]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+1][j+3];
			cout<<endl;
		}
	}


	/*	   #
		####	*/		
	for (int i=0; i<=1; i++)
	{
		for (int j=0; j<=16; j++)
		{
			cout<<"Q "<<box[i][j+3]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2]<<" "<<box[i+1][j+3];
			cout<<endl;
		}
	}
}

void printP()
{
	/*	##
		##
		#	*/
	for (int i=0; i<=0; i++)
	{
		for (int j=0; j<=18; j++)
		{
			cout<<"P "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+2][j];
			cout<<endl;
		}
	}

	/*	##
		##
		 #
		    */
	for (int i=0; i<=0; i++)
	{
		for (int j=0; j<=18; j++)
		{
			cout<<"P "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+2][j+1];
			cout<<endl;
		}
	}

	/*	#
		##
		##	*/
	for (int i=0; i<=0; i++)
	{
		for (int j=0; j<=18; j++)
		{
			cout<<"P "<<box[i][j]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+2][j]<<" "<<box[i+2][j+1];
			cout<<endl;
		}
	}

	/*	 #
		##
		##	*/
	for (int i=0; i<=0; i++)
	{
		for (int j=0; j<=18; j++)
		{
			cout<<"P "<<box[i][j+1]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+2][j]<<" "<<box[i+2][j+1];
			cout<<endl;
		}
	}

	/*	###
		##	*/
	for (int i=0; i<=1; i++)
	{
		for (int j=0; j<=17; j++)
		{
			cout<<"P "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1];
			cout<<endl;
		}
	}


	/*	###
		 ##	*/
	for (int i=0; i<=1; i++)
	{
		for (int j=0; j<=17; j++)
		{
			cout<<"P "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2];
			cout<<endl;
		}
	}


	/*	##
		###	*/
	for (int i=0; i<=1; i++)
	{
		for (int j=0; j<=17; j++)
		{
			cout<<"P "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2];
			cout<<endl;
		}
	}

	/*	 ##
		###	*/
	for (int i=0; i<=1; i++)
	{
		for (int j=0; j<=17; j++)
		{
			cout<<"P "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i+1][j]<<" "<<box[i+1][j+1]<<" "<<box[i+1][j+2];
			cout<<endl;
		}
	}
}

void printO()
{
	for (int i=0; i<=2; i++)
	{
		for (int j=0; j<=15; j++)
		{
			cout<<"O "<<box[i][j]<<" "<<box[i][j+1]<<" "<<box[i][j+2]<<" "<<box[i][j+3]<<" "<<box[i][j+4];
			cout<<endl;
		}
	}	
}