
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

#if 0
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
#endif

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


#if 0
	cout<<"Please enter your first name and age\n";
	string first_name = "???";	// string variable
	int age = 0;			// integer variable
	cin>>first_name>>age;	// read a string
	//cin>>age;			// read an integer
	cout<<"Hello, "<<first_name<<" (age "<<age<<")\n";

#endif


#if 0
	cout<<"Please enter your first and second names\n";
	string first;
	string second;
	cin>>first>>second;	// read two strings
	cout<<"Hello, "<<first<<" "<<second<<endl;
#endif

#if 0
	cout<<"Please enter your first name and age\n";
	string first_name = "???";	// string variable
	double age = 0;			// integer variable
	cin>>first_name>>age;	// read a string
	//cin>>age;			// read an integer
	cout<<"Hello, "<<first_name<<" (months "<<age*12<<")\n";
#endif


#if 0
	cout<<"Please enter count and name"<<endl;;
	int count;
	cin>>count;		// >> reads an integer into count
	string name;
	cin>>name;		// >> reades a string into name

	cout<<"count: "<<count<<endl;
	cout<<"name: "<<name<<endl;
#endif


#if 0
	int c2 = count+2;			// + adds integers
	string s2 = name + " Jr. ";	// + appends characters

	int c3 = count-2;			// - subtracts integers
	string s3 = name + " Jr. ";	// error: - isn't defined for strings

	cout<<name<<endl;
	cout<<s2<<endl;
	cout<<s3<<endl;
#endif

	//cout<<"Please enter a floating-point value: ";
	//double n;


#if 0
	cout<<"Please enter an integer value: ";
	int n;
	string s("greencard");
	//double n;

	cout<<'\n';

	if (cin)
	{
		cout<<"cin is good before \"cin>>n\""<<endl;
	}
	else
	{
		cout<<"cin is bad before \"cin>>n\""<<endl;
	}

	cin>>n;

	if (cin)
	{
		cout<<"cin is good after \"cin>>n\""<<endl;
	}
	else
	{
		cout<<"cin is bad after \"cin>>n\""<<endl;
	}
	//cout<<'\n';

	cin>>s;

	//*(static_cast<char*>(const_cast<char*>(s.c_str()))) = 'h';
	(const_cast<char*>(s.c_str())[1]) = "b"[n];//'a';
	//(const_cast<char*>(s.c_str())[1]) = 
	//(char*)(s.c_str()) = 'c';  // always does not work... 

	//cin>>n;
	cout<<"n == "<<n
		<<"\nn+1 == "<<n+1
		<<"\nthree times n == "<<3*n
		<<"\ntwice times n == "<<n+n
		<<"\nn squared == "<<n*n
		<<"\nhalf of n == "<<static_cast<double>(n)/2
		<<"\nsquare root of n == "<<sqrt(n)
		<<"\nn divide by 2 == "<<n/2
		//<<"\nn modulo of 2 == "<<n%2
		<<"\nn divide by -2 == "<<static_cast<double>(n)/(-2)
		//<<"\nn modulo of -2 == "<<(n) % (-2)
		<<"\nstatic_cast<string&> n == "<< static_cast<char*>(const_cast<char*>(s.c_str()))
		<<"\n";
		//<<'\n'; // name for newline ("end of line") in output
#endif

#if 0
	int id;

	cout<<"Please enter an integer for your ID\n";
	
	if (!(cin>>id))
	{
		cout<<"cin turn into bad state after cin>>id. Try to clear() the state below\n";
		cin.clear();
		//cin.ignore();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		//cout<<"cin.width() == "<<cin.width()<<'\n';
		//cin.ignore(cin.width());
	}
	else
	{
		cout<<"Good news! cin remains in good state after cin>>id. Can continue\n";
	}


	string first;
	string second;

	cout<<"Please enter your first and second names\n";
	cin>>first>>second;		//read two strings
	string name = first + ' ' + second;		//concatenate strings
	cout<<"Hello, "<<name<<'\n';
#endif

#if 0
	cout<<"Please enter two names\n";
	string first;
	string second;
	//cin>>first>>second;		// read two strings
	getline(cin, first);
	getline(cin, second);
	if (first == second) cout<<"that's the same name twice\n";
	if (first < second)
			cout<<first<<" is alphabetically before "<<second<<'\n';
	if (first > second)
			cout<<first<<" is alphabetically after "<<second<<'\n'; 
#endif

#if 0
	int a = 3;	// a starts out with the value 3
	a = 4;
	int b = a;
	b = a+5;
	a = a+7;

	cout<<"a: "<<a<<'\n';
	cout<<"b: "<<b<<'\n';
#endif

#if 0
	string a = "alpha";
	a = "beta";
	//cout<<a<<endl;
	string b = a;
	b = a+"gamma";
	a = a+"delta";

	cout<<"a: "<<a<<'\n';
	cout<<"b: "<<b<<'\n';
#endif

#if 0
	int x=41;
	cout<<"int x before initialized: "<<x<<'\n';

	string s;// = (char*)&x;
	//cout<<"string s before initialized: "<<s<<'\n';

	string t = "howdy!";
	s = "G'day";
	cout<<"t: "<<t<<"\ns: "<<s<<'\n';

	int y = 8;
#endif


#if 0
	//3.5.1 An example: detect repeated words
	//3.6.1 An exmaple: find repeated words
	int number_of_words = 0;
	string previous = " ";			// previous word; initialized to "not a word"
	string current;					// current word
	while (cin>>current) {			// read a stream of words
		++number_of_words;
		if (previous == current)	// check if the word is the same as last
		{
			cout<<"word number "<<number_of_words<<" repeated word: "<<current<<'\n';
		}
		//else
		//{
			//cout<<"previous word: "<<previous<<"  vs current word: "<<current<<'\n';
		//}

		previous = current;
	}
#endif

#if 0

	string s;

	s = "今年１年の世相を４字で振り返る恒例の「創作四字熟語」の優秀・入選５０作品を発表した";

	string t;

	t = "Vélo, sac, appareil photo: bleu en un «Klein» d'œil pour Noël";

	cout<<s<<'\n';

	cout<<t<<'\n';

#endif
	//static const int a=1;
	//#define a -1

	//string dd("qafdaf");
	//#define a 'x'

#if 0 //a // (a==2)
	//int counter;
	double counter;
	double post;

	//do
	cout<<"Please enter an number: \n";
	while (cin>>counter)
	{
		#if 0
		if (!cin)
		{
			//cin.clear();
			cin.ignore();
		}
		#endif

		//cout<<"Please enter an number: \n";
		//cin>>counter;
		//cout<<"counter before ++: "<<counter<<'\n';

		post = counter+1;

		cout<<std::to_string(counter)<<'\n';
		cout<<std::to_string(post)<<'\n';

		if (counter == post)
		{
			cout<<"OMG\n";
		}
		else
		{
			cout<<"Yes it's true: "<<counter<<" != "<<post<<'\n';
		}
		//++counter;
		//cout<<"counter after  ++: "<<counter<<'\n';
		cout<<"Please enter an number: \n";
	}
	//while (cin); //(1);
#endif

#if 0
	STRING s = "Goodbye, cruel world! ";
	cOut<<S<<'\n';
#endif

#if 0
	int if = 7;		// error: if is a keyword
	int string = 7;		// this will lead to trouble
	cout<<string<<endl;
#endif

#if 0
	string s;

	s = "今年１年の世相を４字で振り返る恒例の「創作四字熟語」の優秀・入選５０作品を発表した";

	cout<<s.length()<<'\n';

	cout<<(s.substr(0,3)).c_str()<<'\n';
	cout<<(s.substr(120,3)).c_str()<<'\n';
#endif

#if 0
	int t;

	while (1)
	{
		cin>>t;
		cout<<t<<'\n';
		if (!cin)
		{
			cin.clear();
		}
	}
#endif

#if 0
	double x;
	double y = x;
	double z = 2.0+x;
	cout<<"x: "<<x<<"  y: "<<y<<"  z: "<<z<<endl;
#endif

#if 0
	char c = 'x';
	int i1 = c;
	int i2 = 'x';
	char c2 = i1;
	char c3 = ' ';

	cout<<c<<' '<<i1<<' '<<i2<<' '<<c2<<'\n';

	if (c3 ==' ')
	{
		cout<<"c3 ==''\n";
	}
	else
	{
		cout<<"c3 !=''\n";
	}

	int 2018ch;
#endif

#if 0
	//3.9.1 Safe conversions
	double d1 = 2.3;
	while (cin>>d1)
	{
		double d2 = d1+2;	// 2 is converted to 2.0 before adding

		d2 = d1*d1;

		if (d1<0)			// 0 is converted to 0.0 before comparison
		{
			cout<<"d1 is negative "<<d1<<'\n';
		}
		else if (d1 > 0)
		{
			cout<<"d1 is positive "<<d1<<'\n';
		}
		else
		{
			cout<<"d1 is zero "<<d1<<'\n';	
		}
		cout<<"d1 in string: "<<std::to_string(d1)<<'\n';

		cout<<"d2 is always non-negative "<<d2<<'\n';
		cout<<"d2 in string: "<<std::to_string(d2)<<'\n';
	}
#endif

#if 0
	//3.9.2 Unsafe conversions
	int a = 20000;
	char c = a;		// try to squeeze a large int to a small char
	int b = c;
	if (a!=b)		// != means "not equal"
		cout<<hex<<"oops!: 0x"<<a<<"!=0x"<<b<<'\n';
	else
		cout<<"Wow! We have large characters\n";
	//cout<<hex<<"0x"<<a<<'\n';

	double d = 0;
	while (cin>>d) {	// repeat the statement below
						// as long as we type in numbers
		unsigned int i = d;		// try to squeeze a double into an int
		char c = i;		// try to squeeze an int into a char
		int i2 = c;		// get the integer value of the character
		cout<<"d=="<<d				// the original double
			<<" i=="<<i				// converted to int
			<<" i2=="<<i2			// int value of char
			<<" char("<<c<<")\n";	// the char
	}

	double x = 2.7;

	while (cin>>x)
	{
		// lots of code
		int y = x;		// y becomes 2

		cout<<"x: "<<x<<" y:"<<y<<'\n';
	}

	int a = 1000;
	char b = a;		// b becomes -24 (on some machines)
	int c = b;
	cout<<"a: "<<a<<" b: "<<b<<" c: "<<c<<'\n';
#endif

	int a;
	while (cin>>a)
	{
		char b = a;
		char c = -b;
		int d = b;
		int e = c;
		cout<<"a: "<<a<<" b: "<<b<<" c: "<<c<<" c+256:"<<(char)(c+256)<<'\n';
		cout<<"d: "<<d<<" e: "<<e<<'\n';
	}

	return 0;
}






