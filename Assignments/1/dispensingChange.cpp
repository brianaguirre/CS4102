/**
brian aguirre
ba5bx
Assignment 1
Spring 2015 - 4102
**/


#include <iostream>
#include <stdio.h>
#include <sstream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <locale>
#include <fstream>
#include <stdlib.h>
#include <vector>

using namespace std;

//GETS RID OF DOLLAR AMOUNT:
int floorIt(double x){
	int intValue = (int) x;
	return intValue;
}

//CONVERTS INPUT INTO A NUMBER:
bool stringToInt(string &s, double &result){
	istringstream myString(s);

	if (myString>>result){
		return true;
	}
	else
		return false;
}

//COMMAND LINE INPUT:
int main(int argc, char ** argv){

	//FILE INPUT:
	string line, temp, tempString;
	string data = argv[1];

	ifstream file1(data.c_str());
	double currentInput;
	int addition = 0;
	double fullAmount=0;
	int dollarAmount;
	int change;
	long long intAmount=0;

	vector<int> dollars;
	int threes;
	bool quit = false;

	while(!file1.eof()){
		//GET LINE, CONVERT TO INT:
		tempString = "";
		dollars.clear();
		getline(file1, tempString);
		stringToInt(tempString, currentInput);
		if(currentInput>=0){
			//SET VARIABLES:
			fullAmount = currentInput;
			dollarAmount = (int) currentInput;
			//NOTE: For accuracy, the number is first multiplied
			//times 1000 then divided by 10.00
			change = 1000*currentInput - 1000*dollarAmount;
			change = change/10.00;
			intAmount = dollarAmount;

			/* 
			VERIFICATION OF CODE WORKING:
			TEST PRINT STATEMENTS:


			cout<< "Current Input: " << currentInput << endl;
			printf("$%.2f", fullAmount);
			cout<< "change " << change << endl;
			cout<< "Dollar Amount " << dollarAmount << endl;
			cout<< "Int Amount: " << intAmount << endl;
			*/ 

			/**LOGIC ADAPTED FROM ORIGINALLY THINKING ABOUT 
			CONVERTING TO THE REMAINDER OF %1000, BUT A BETTER METHOD
			WAS DEVELOPED THROUGH C++ DOCUMENTATION READING FROM: WWW.CPLUSPLUS.COM/REFERENCE/*/
			while (intAmount != 0){
				threes = intAmount%1000;			
				dollars.push_back(threes);
				intAmount = intAmount / 1000;
			}

			cout<<"$";
			//ALGORITHM REVERSE METHOD: FROM CPLUSPLUS.COM
			std::reverse(dollars.begin(), dollars.end());
			for (size_t i=0; i<dollars.size()-1; ++i){
				if (dollars[i] == 0){
					cout<<"000"<<",";
				}
				else{
					cout<<dollars[i]<<",";
				}
			}
			if(dollars[dollars.size() - 1] == 0){
				cout << "000";
			}
			else{
				if(dollars[dollars.size()-1] < 0){
					cout<<endl;
					cout<<"Note: The dollar amount you have entered may be too large to be stored in an int/double." <<endl;
				}
				cout << dollars[dollars.size()-1];
			}
			if(change<10){
				cout<< "." << "0" << change << " ";
			}
			else{
				cout<< "." << change << " ";
			}





		//COINS:
		int Q = 0;
		int D = 0;
		int N = 0;
		int P = 0;

		//printf("$%.2f", fullAmount);

		//CALCULATE NUMBER OF COINS:
		if(change>0){
			while (change>0){
				if (change >= 25){
					change -= 25;
					Q++;
				}
				else if (change >= 10){
					change -= 10;
					D++;
				}
				else if (change >= 5){
					change -= 5;
					N++;
				}
				else if (change >= 1){
					change -= 1;
					P++;
				}
				else{
					change = 0;
				}
			}
		}


		//CALCULATE AMOUNT OF COIN OUTPUT:
		if (Q>0){
			for (int i=0; i<Q; i++){
				cout << " Q";
			}
		}
		if (D>0){
			for (int i=0; i<D; i++){
				cout << " D";
			}
		}
		if (N>0){
			for (int i=0; i<N; i++){
				cout << " N";
			}
		}
		if (P>0){
			for (int i=0; i<P; i++){
				cout << " P";
			}
		}

		cout<<endl;
		}
		else{
			if (quit == false){
				cout<<"You have entered a negative dollar amount, which terminates this program." << endl;
				cout<<"Goodbye."<<endl;
				quit = true;
				file1.close();
			}
		}

	}	
	file1.close();
	return 0;
}
