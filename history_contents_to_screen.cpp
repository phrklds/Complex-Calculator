//Send History to Screen and/or Form. Will need to be modified to work in Gui. 
#include<fstream>

int main()
{
	char data [100];
	
	//Open a file in read mode.
	ifstream infile;
	infile.open("history.txt");
	
	//read data from file and display it.
	infile >> data;
	cout<<data<<end1;
	
	//close the opened file
	infile.close();
	
	//return 0;
	
	
}