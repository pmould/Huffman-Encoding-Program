#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

	using namespace std;

// This Struct  stores the integer value of a character and the code for this character for each of the decimal and code on each line in the input file
struct Table
{
	string dec;// Stores decimal value of character
	string code;

};

int main(int argc, char *argv[])
{		

                if(argc==1)// if no input file is found it terminates the program
                {
                        exit(1);
                        return 0;
                } 

               char *fileName = argv[1];

		string fileN;
		fileN  = argv[1];

		string zipPart;
		zipPart= fileN.substr(fileN.length()-4);
		//If the file is not a .zip file then terminate the program with an error message
                if(zipPart != ".zip")
                {
	                cout << "Incorrect FileName: Source FileName does not contain the .zip extension"<<endl;
        	        return 0;
                }
	
//			cout<<"File Successfully Inflated Back To Original"<< endl;
		
	        ifstream infile;
       		infile.open(fileName);
		ofstream outfile;
		string fileUnzip = fileN.substr(0, fileN.length()-4);
		outfile.open(fileUnzip.c_str());
       		string aline;
		bool found = false;
		int numChar;
		int count=0;


		getline(infile,aline);//GETS THE NUMBER OF CHARACTERS INTHE ORIGINAL FILE AND STORES IT AS A STRING IN aline

        	numChar = atoi(aline.c_str());
		Table array[numChar];
       
		int space;
		string Vdec;
		int decV;
		
		// Storing in the array of Table structs, array,  the integer value of the character and its code equivalent in the tree
		for(int i = 0; i< numChar; i++)
		{
				getline(infile,aline);  //Gets the next decimal and code value in tree stored as a string in aline
				space = aline.find_first_of( " ");	
				array[i].dec = aline.substr(0, space );
				array[i].code = aline.substr(space+1);
				cout << endl;
		}
		
		string token = ""; char ch;
		infile >> ch; token = token + ch;
		
		while(infile)// Contue while there is still something to output
		{
			for (int i =0; i< numChar ; i++)
			{
				if( token == array[i].code)// if FOUND MATCHING CODE. if the token is equal to the the code equivalent in the part of the array[i],
							   // then output the character of the code equivalent into the output file.
				{
					Vdec = array[i].dec;
					decV = atoi( Vdec.c_str() );
					outfile << (char)decV;
					token = "";
				}
			}
					infile >> ch;
					token = token + ch;
		}
		cout <<" File Successfully Inflated Back To Original"	<<endl;
		return 0;
}


