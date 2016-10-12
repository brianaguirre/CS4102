/**
Brian Aguirre
University of Virginia

This program takes in the input from the command line.
It also then prints out the document as it appears.

*/

#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

//TEST:
int main(int argc, char** argv){
	

	//FILE INPUT:
	string line, tempString;
	string data = argv[1]; //Used to take file as command arguement:
	ifstream file(data.c_str());

	while (!file.eof()){
		tempString = "";
		int count = 0; //LINE NUMBER:
		getline(file, tempString);
		count++;	
		
		cout << tempString<< " " << endl;
	}	
	file.close();


	return 0;
}