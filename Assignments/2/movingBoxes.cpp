/**
Brian Aguirre
ba5bx
CS4102
Assignment 2: Moving Boxes (sounds so labor intensive)
**/

#include <iostream>
#include <stdio.h>
#include <sstream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <cstring>
#include <locale>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <iterator>

using namespace std;

//GLOBAL VARIABLES:

//CONVERTS INPUT INTO A NUMBER:
bool stringToInt(string &s, int &result){
	istringstream myString(s);

	if (myString>>result){
		return true;
	}
	else
		return false;
}


//WORKS AND CALCULATES COST!
int calculateCost(int boxes, int bring, int one, int half){
	int currentBoxes = boxes;
	int roundUp = (int) (boxes/2) + 1;
	int boxesLeft = boxes;
	int total = 0;
	while (boxesLeft>bring){
		if ((boxesLeft - roundUp) > bring){
			total += half;
			boxesLeft = boxesLeft - roundUp;
			roundUp = (int) (boxesLeft/2) + 1;
		}
		else if (boxesLeft == 1){
			total += half;
			boxesLeft = 0;
		}
		else{
			while (boxesLeft>bring){
				boxesLeft--;
				total+= one;
			}
		}
	}
	return total;
}

//METHODS PARTITION AND QUICKSORT WERE A COMBINATION OF PREVIOUS PERSONAL CODE
//AND INFORMATION FROM FROM THE 
//C++ LIBRARY AND http://www.cplusplus.com/

int partition(vector<int>& A, vector<string>&B, int p,int q)
{
    int x= A[p];
    int i=p;
    int j;

    for(j=p+1; j<q; j++)
    {
        if(A[j]<=x)
        {
            i=i+1;
            swap(A[i],A[j]);
            swap(B[i],B[j]);
        }

    }

    swap(A[i],A[p]);
    swap(B[i],B[p]);
    return i;
}



void quickSort(vector<int>& A, vector<string>& B, int p,int q)
{
    int r;
    if(p<q)
    {
        r=partition(A,B,p,q);
        quickSort(A,B,p,r);  
        quickSort(A,B,r+1,q);

    }
}






//TEST:
int main(int argc, char** argv){
	

	//FILE INPUT:
	string line, tempString;
	string data = argv[1]; //Used to take file as command arguement:
	ifstream file(data.c_str());

	int numOfCases = 0;
	int boxes = 0;
	int takeWithMe = 0;
	int numOfComp = 0;

	int costPerBox = 0;
	int costForHalf = 0;

	vector <string> companies;
	vector <int> costForMoving1;
	vector <int> costForMovingHalf;
	vector <int> totalCost;
	vector <int> tempCost;

	vector<string> all;

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
	        	stringToInt(all[0], numOfCases);
	        }
	    }	
	}	
	file.close();

	/**SAMPLE INPUT:
	2 - Number of Cases
	75 10 6 - #Boxes, #takeWithMe #Companies (b c m)
	DHL 5 3	- #1BoxCost #HalfBoxCost
	UPS 9 9
	USPS 3 2
	FEDEX 3 5
	COURIER 2 7
	UHAUL 1 2
	2246 2245 5
	AMERICAN 100 600
	USAIR 2 2000
	SOUTHWEST 20 20
	DELTA 2 100
	UNITED 0 0
	*/

	//CALCULATIONS:
	//numOfCases = all[0];
	int casePos = 0;
	if (numOfCases>=1){
		for (int i=0; i<numOfCases; i++){
			companies.clear();
			costForMovingHalf.clear();
			costForMoving1.clear();
			totalCost.clear();



			//DETERMINE INITIAL CONDITIONS:
			casePos++;
			int forTake = casePos*3-1;
			int forBox = casePos*3-2;
			int forNumComp = casePos*3;
			stringToInt(all[forTake], takeWithMe);
			stringToInt(all[forBox], boxes);
			stringToInt(all[forBox], boxes);
			stringToInt(all[forNumComp], numOfComp);

			int currentCase = i+1;
			cout<<"Case " << currentCase << endl;
			for (int j=0; j<(numOfComp);j++){
				string name;
				int tempCost1;
				int tempCostHalf;

				name = all[(casePos*3+1)];
				companies.push_back(name);
				
				stringToInt(all[(casePos*3+2)], tempCost1);
				costForMoving1.push_back(tempCost1);
		
				stringToInt(all[(casePos*3+3)], tempCostHalf);
				costForMovingHalf.push_back(tempCostHalf);

				//OUTPUT CURRENT COST:
				//UNSORTED OUTPUT:
			
				//cout << name << " ";
				int currentTotalCost = calculateCost(boxes, takeWithMe, tempCost1, tempCostHalf);

				totalCost.push_back(currentTotalCost);
				//cout << currentTotalCost << endl;
		

				casePos++;
				
			}

			//SORTING COST AND COMPANY NAMES:
			quickSort(totalCost,companies,0,totalCost.size());
    		for (int i=0; i<totalCost.size(); i++){
    			cout << companies[i] << " " << totalCost[i] << endl;
    		}
   			
		}
	}

	return 0;
}