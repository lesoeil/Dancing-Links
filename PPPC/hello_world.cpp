
#include "std_lib_facilities.h"

int main()	//C++ programs start by executing the function
{
	//cout<<"Hello, World!\n";	// output "Hello, World!"
	//cout<<"Hello, programming!\n";
	//cout<<"Here we go!\n";
	//keep_window_open();			// wait for a character to be entered

	//read and write a first name
	//cout<<"Please enter your first name (followed by 'enter'):\n";
	//string first_name;	// first_name is a variable of type string
	//cin>>first_name;	// read characters into first_name
	//getline(cin, first_name);
	//cout<<"Hello, "<<first_name<<"!\n";

	//string name = "Annemarie";
	//int number_of_steps = 39;

	//string name2 = static_cast<string>(39);	// error: 39 isn't a string.
												// Also, static_cast can not convert int to string
	//int number_of_steps2 = "Annemarie";		// error: "Annemarie" is not an int

	//char ch = 39;	// char can be initialized with integer
	//cout<<static_cast<int>(ch)<<endl;
	
	//char ch2 = 10000000;
	//cout<<ch2<<endl;

	int number_of_steps = 39;	// int for integers
	double flying_time = 3.5;	// double for floating point numbers
	char decimal_point = '.';	// char for individual characters
	string name = "Annemarie";	// string for character strings
	bool tap_on = true;			// bool for logical variables

	cout<<"number_of_steps: "<<number_of_steps<<endl;
	cout<<"flying_time: "<<flying_time<<endl;
	cout<<"decimal_point: "<<decimal_point<<endl;
	cout<<"name: "<<name<<endl;
	cout<<"tap_on: "<<tap_on<<endl;
	cout<<"true: "<<true<<endl;
	cout<<"false: "<<false<<endl;

	//double check;
	/*INPUT: 112345678901234567890123456789012345678901234567891234567890123456789012345678900987654321234567890987654321234567890123456789098765432123456789000009876543233333333333333333333333333555555555555555555555555555555555555553333333333333333333333333333333333333333333333333555555555555555555555555558888888888888888888888866666666666666666666666666666
	  OUTPUT: inf
	*/
	//cin>>check;
	//cout<<check<<endl;

#if 0
	int x = 9900;

	char sh0 = ("a")[0];
	char sh1 = ("a")[1];
	char sh2 = ("a")[x];		//[2000000]; //Segmentation fault: 11

	cout<<"sh0: "<<sh0<<endl;
	cout<<"sh1: "<<sh1<<endl;
	cout<<"sh2: "<<sh2<<endl;

	for (;x<12000; x++)
	{
		cout<<("a")[x];
	}

	cout<<endl;
#endif

	cout<<"Please enter your first name and age\n";
	string first_name;	// string variable
	int age;			// integer variable
	cin>>first_name;	// read a string
	cin>>age;			// read an integer
	cout<<"Hello, "<<first_name<<" (age "<<age<<")\n";



	return 0;
}