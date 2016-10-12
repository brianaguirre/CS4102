/**
Brian Aguirre
ba5bx
CS4102
Assignment 2: Moving Boxes (sounds so labor intensive)
**/

#include "myMethods.h"

using namespace std;

//GLOBAL VARIABLES:

//TEST:
int main(int argc, char** argv){
	

	//FILE INPUT:
	string line, tempString;
	string data = argv[1]; 		//Used to take file as command arguement:
	ifstream file(data.c_str());//Read file from command line.

	int numOfCases = 0;
	string cityName;
	int rows = 0;
	int columns = 0;

	vector <string> cities;
	vector <string> all;

	while (!file.eof()){
		tempString = "";
		int count = 0; //LINE NUMBER:
		getline(file, tempString);
		count++;	
		//LOGIC:
		/*
		1. Read Num of Cases:
		2. Get Next Line and file Boxes, Carry, Companies
		3. For however many companies there are, 


		*/

		//all TEXT:
		istringstream line(tempString);
		while (line) {
	        string word;
	        line >> word;
	        char a = word[0];
	        if (word == " " || word=="\n" || word ==""){
	        	//DO NOTHING
	        }
	        else{
	        	all.push_back(word);
	       		myMethods::stringToInt(all[0], numOfCases);
	        }

	        cout<<word<<endl;
	    }	
	}	
	file.close();

	/**SAMPLE INPUT:
	1
	Charlottesville 5 5
	66 78 41 3 77
	4 90 41 8 68
	12 11 29 24 53
	0 51 58 9 28
	97 99 96 58 92
	*/

	//CALCULATIONS:
	int count = 1;//Location on all array
	int n, m = 0; //Dimensions of grid
	int tempInt;

	if (numOfCases > 0){
		for (int i=0; i<numOfCases;i++){
			
			//INITIALIZE THE MATRIX:
			cityName = all[count];
			count++;
			myMethods::stringToInt(all[count], n);
			count++;
			myMethods::stringToInt(all[count], m);
			count++;

			//**********CONDITION: If n=m=0, then return 0;
			if(n==0 && m==0){
				cout<< cityName << " " << "0" <<endl;
			}

			//**********CONDITION: If n=m=1, then return 1;
			else if(n==1 && m==1){
				cout<< cityName << " " << "1" <<endl;
				count++;
			}

			//**********CONDITION: If n=m>1, then return the following:;
			else if(n>1 && m>1){
				int matrix [n][m];

				for (int j=0; j<n;j++){
					for (int k=0; k<m;k++){
						myMethods::stringToInt(all[count], tempInt);
						matrix[j][k] = tempInt;
						count++;
					}	
				}//Initializing Matrix For Loop
					

				//PRINT THE INPUT:
				cout<<cityName<< " " << n <<" "<< m <<endl;
				for (int a=0; a<n;a++){
					for (int b=0; b<m;b++){
						cout<< matrix[a][b] << " ";
					}
					cout<<endl;
				}//Printing For Loop

			}//NON BASE CASE CALCULATION IF

		}//First For Loop - Individual Matrix Calculation:

	//TEST GRID:
		


	}//IF numOfCases>0 condition
	


	//TESTING:


	return 0;
}