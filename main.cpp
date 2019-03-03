/*
Scott Weller
SID: 1379630
Email: welle108@mail.chapman.edu
CPSC 350-01
HW#3

Main method for Delimiter Checker.  Creates a DelimiterChecker object and
andalyzes given file, then prompts for another file.
*/
int main (int argc, char *argv[]) 
{
	std::string again;
	cout<<endl;
	cout<<"     The Great American Delimiter Checker"<<endl;
	while(true)
	{
		cout<<"--------------------------------------------------"<<endl;
		DelimiterChecker checker;
		checker.CheckFile();
		cout<<"--------------------------------------------------"<<endl;
		cout<<"Would you like to analyze another file? y/n"<<endl;
		getline(cin,again);
		while(again.compare("y")!=0&&again.compare("n")!=0)
		{
			cerr<<"Error:  Please only enter 'y' to continue or 'n' to quit."<<endl;
			getline(cin,again);
		}
		cin.clear();
		if(again=="n")
		{
			exit(0);
		}

	}
}