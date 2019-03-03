/*
Scott Weller
SID: 1379630
Email: welle108@mail.chapman.edu
CPSC 350-01
HW#3
*/

#include "DelimiterChecker.h"
using namespace std;

DelimiterChecker::DelimiterChecker()
{
	OpenStream();
}

DelimiterChecker::DelimiterChecker(std::string fileName)
{
	OpenStream();
}

DelimiterChecker::~DelimiterChecker()
{
	
}

void DelimiterChecker::OpenStream()
{
	if(filename.empty())
	{
		cout<<"Input filename: ";
		getline(cin,filename);
	}
	inf.open(filename.c_str());
	while(inf.fail())
	{
		if(filename.compare("quit")==0)
		{
			exit(0);
		}
		cerr<<"Error opening file. Enter valid filename or 'Quit' to exit program."<<endl;
		getline(cin,filename);
		inf.open(filename.c_str());			
	}
	cout<<"--------------------------------------------------"<<endl;
}


bool DelimiterChecker::CheckFile()
{
	bool lineComment;
	bool inComment;
	char topDelim;
	std::string line;
	int curLocation;
	int curLine=0;
	while(!inf.eof())
	{
		++curLine;
		getline(inf,line);
		for(int i=0;i<line.length();++i)
		{
			if(((line[i]=='/'&&line[i+1]=='/')||(line[i]=='/'&&line[i+1]=='*'))&&inComment!=true)
			{
				inComment = true;
				if(line[i]=='/'&&line[i+1]=='/')
				{
					lineComment = true;
				}
				i+=2;
				
				
				
			}
			else if((line[i]=='*'&&line[i+1]=='/')&&inComment==true)
			{
				i+=2;
				inComment = false;
				
				
			}
			if((line[i]=='{'||line[i]=='('||line[i]=='[')&&inComment!=true)
			{
				position.Push(curLine);
				stack.Push(line[i]);
			}
			else if((line[i]=='}'||line[i]==')'||line[i]==']')&&inComment!=true)
			{
				try
				{
					topDelim=stack.Pop();
					curLocation=position.Pop();
				}
				catch(std::runtime_error& e)
				{
					cout<<"ERROR: '"<<endl;
					cout<<endl;
					cout<<line[i]<<"' found on line: "<<curLine<<". "<<endl;
					cout<<"'"<<GetOpposite(line[i])<<"' expected."<<endl;
					cout<<endl;
					inf.close();
					return false;
				}
				if(GetOpposite(topDelim)!=line[i])
				{
					cout<<"ERROR:"<<endl;
					cout<<endl;
					cout<<"'"<<topDelim<<"' found on line: "<<curLocation<<endl;
					cout<<"Expected: '"<<GetOpposite(topDelim)<<"' Found: '"<<line[i]<<"' on line: "<<curLine<<endl;
					cout<<endl;
					inf.close();
					return false;
				}	
			}
		}
		if(lineComment == true)
		{
			lineComment = false;
			inComment = false;
		}

	}
	if(!stack.IsEmpty())
	{
		topDelim = stack.Pop();
		cout<<"ERROR:"<<endl;
		cout<<endl;
		cout<<"Reached End of File"<<endl;
		cout<<"'"<<topDelim<<"' found on line: "<<position.Pop()<<endl;
		cout<<"Expected: "<<GetOpposite(topDelim)<<endl;
		cout<<endl;
		inf.close();
		return false;
	}
	else
	{
		cout<<"Analysis complete.  Delimiters are correct."<<endl;
		inf.close();
		return true;
	}
}

char DelimiterChecker::GetOpposite(char input)
{
	char output;
	if(input=='{'||input=='}')
	{
		if(input=='{')
		{
			return '}';
		}
		else
		{
			return '{';
		}
	}
	else if(input=='('||input==')')
	{
		if(input=='(')
		{
			return ')';
		}
		else
		{
			return '(';
		}
	}
	else if(input=='['||input==']')
	{
		if(input=='[')
		{
			return ']';
		}
		else
		{
			return '[';
		}
	}
	return output;
}