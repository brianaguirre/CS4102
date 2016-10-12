/**
Brian Aguirre
ba5bx
CS 4102
ASSIGNMENT 3
02/20/2015
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
#include <math.h>

using namespace std;

//-----------GLOBAL VARIABLES-------------------


//CONVERTS INPUT INTO A NUMBER:
bool stringToInt(string &s, double &result){
	istringstream myString(s);

	if (myString>>result){
		return true;
	}
	else
		return false;
}

struct Point{
	double x, y;
};

vector<Point> newxP;

double distPs(Point a, Point b){
	double xDis = a.x - b.x;
	double yDis = a.y - b.y;
	return sqrt(pow((xDis), 2) + pow((yDis),2));
}



//HORIZONTAL LINE ALGORITHM STEP:
double closestYPoint(vector<Point> ySortedPoints, int sizeOfVector, double delta ){

	double min = delta;
	for (int i = 0; i < sizeOfVector; ++i){
      for (int j = i+1; j < sizeOfVector && (ySortedPoints[j].y - ySortedPoints[i].y) < min; ++j){
         if (distPs(ySortedPoints[i],ySortedPoints[j]) < min){
          	min = distPs(ySortedPoints[i], ySortedPoints[j]);
          }
      }
  }

    return min;
}


//METHODS PARTITION AND QUICKSORT WERE A COMBINATION OF PREVIOUS PERSONAL CODE
//AND INFORMATION FROM FROM THE 
//C++ LIBRARY AND http://www.cplusplus.com/

int partition(vector<double>& A, vector<double>&B, int p,int q)
{
    double x = A[p];
    int i = p;
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



void quickSort(vector<double>& A, vector<double>& B, double p,double q)
{
    double r;
    if(p<q)
    {
        r=partition(A,B,p,q);
        quickSort(A,B,p,r);  
        quickSort(A,B,r+1,q);

    }
}

//GIVEN SORTED VECTORS CONTAINING POINTS:
double distance(double xOne, double yOne, double xTwo, double yTwo){
	double xThree = xOne - xTwo;
	double yThree = yOne - yTwo;
	double d = sqrt(pow((xThree), 2) + pow((yThree),2));
	return d;
}

double minDistace(double one, double two){
	if (one<two)
		return one;
	else
		return two;
}

double minD(vector<double> d){
	double min = 0;

	if (d.size()>0){
		min = d[0];
		for (int i=1; i<d.size();i++){
			if (d[i]<min)
				min = d[i];
		}

		return min;	
	}

	else{
		return -1;
	}
}


//MAIN RECURSIVE METHOD:
//USING CLASS NOTES, SLIDES AND TA'S HELP TO FINALIZE THE METHOD:
double recursiveXPoint(vector<Point> xP, vector<Point> yP, int n){

    int half = n/2;
    Point midPointx = xP[half];
    Point midPointy = yP[half];
 
 
    // Divide points in y sorted array around the vertical line.
    // Assumption: All x coordinates are distinct.
    int left = half+1;
    int right = n-half-1;
   	vector<Point> halfYLeft;
   	vector<Point> halfYRight; 


	newxP.clear();
	halfYRight.clear();
	halfYLeft.clear();

   	int l, r;
   	l=0;
   	r=0;

   	//SPLIT THE VECTORS AND GO TROUGH THEM TO FIND SMALLER VALUES:
    for (int i = 0; i <= n/2; i++){
         halfYLeft.push_back(yP[i]);
    }
    for (int i = n/2 + 1; i <n; i++){
         halfYRight.push_back(yP[i]);
    }
   
   	for (int i = n/2 + 1; i <n; i++){
         newxP.push_back(xP[i]);
    }

    //RECUSIVELY SPLIT THE LEFT AND RIGHT VECTORS:
    double deltaLeft = recursiveXPoint(xP, halfYLeft, half);
    double deltaRight = recursiveXPoint(newxP, halfYRight, n-half);
 
    //MATH METHOD: min - Finds the smaller of the two deltas:
    double delta = min(deltaLeft, deltaRight);

    vector<Point> smallerDistances;
    int j = 0;
    for (int i = 0; i < n; i++)
        if (sqrt((yP[i].x - midPointx.x)*(yP[i].x - midPointx.x)) < delta)
            smallerDistances.push_back(yP[i]), j++;
 
    // Find the closest points in strip.  Return the minimum of d and closest
    // distance is strip[]

    return min(delta, closestYPoint(smallerDistances, j, delta));
}

double findClosestPair(vector<Point> xSorted, vector<Point> ySorted, int n){
	
    return recursiveXPoint(xSorted, ySorted, n);
}


//SORT VECTORS:
void initializeVectors(vector<string>& all, vector<double>& stars, vector<double>& x, vector<double>& y){
	double starNum = -1;
	stringToInt(all[0], starNum);
	stars.push_back(starNum);

	int count = 0;
	int currentPos = 0;
	double xcor = 0;
	double ycor = 0;

	int xPos = 0;
	int yPos = 0;

	vector<double> distances;
	double answer;
	string infinity = "Infinity";



	vector<Point> points;
	vector<Point> xPoints;
	vector<Point> yPoints;
	if (starNum>0){
		while (starNum>0){
			count++;
			currentPos++;
			for (int i=0; i<starNum; i++){
				xPos = currentPos;
				xcor = std::stod(all[xPos]);
				x.push_back(xcor);
				currentPos++;

				yPos = currentPos;
				ycor = std::stod(all[yPos]);
				y.push_back(ycor);
				currentPos++;
			}//FOR


			//CALCULATIONS:
			double localDistance = -1;
			if (starNum <= 3){ //CALCULATE USING THE BASE CASE:
				for (int i=0; i<starNum; i++){
					double x1 = x[i];
					double y1 = y[i];
					for (int j=i+1; j<starNum; j++){
						double x2 = x[j];
						double y2 = y[j];
						localDistance = distance(x1,y1,x2,y2);
						distances.push_back(localDistance);
					}
				}

				answer = minD(distances);
				if(answer>10000){
					cout<<"infinity"<<endl;
				}
				else if(answer<0){
					cout<<"Wrong input. Negative distance calculated."<<endl;
				}
				else{
					cout<<answer<<endl;
				}
			}
			

			//MAIN ALGORITHM:
			else if(starNum >3){
				//ALGORITHM:
				/*
				1. Sort the arrays.
				2. Recursively find shortest distance on each side
				3. Find min of DL and DR
				4. Consider Min(DL, DR) to be Delta
				5. No from -Delta, +Delta, find all the distances between those points.
				**/
				//1. X-SORTING:
				quickSort(x, y, 0, x.size());
				vector<double> copyOfX = x;
				vector<double> copyOfY = y;

				//1. Y-SORTING:
				quickSort(copyOfY, copyOfX, 0, copyOfY.size());


				//ADD POINTS TO A VECTOR OF X-SORTED POINTS
				for(int i=0;i<x.size(); i++){
					Point temp;
					temp.x = x[i];
					temp.y = y[i];
					xPoints.push_back(temp);
				} 
				//ADD POINTS TO A VECTOR OF Y-SORTED POINTS
				for(int i=0;i<copyOfY.size(); i++){
					Point temp;
					temp.x = copyOfX[i];
					temp.y = copyOfY[i];
					yPoints.push_back(temp);
				}

				//RETURN THE CLOSEST POINT OF THE SORTED ARRAYS:
				cout << recursiveXPoint(xPoints, yPoints, xPoints.size()) << endl;

			}

			stars.clear();
			distances.clear();
			x.clear();
			y.clear();




			stringToInt(all[currentPos], starNum);
			stars.push_back(starNum);
			count++;

		}//WHILE





	}//IF

}



int main(int argc, char** argv){
	

	//FILE INPUT:
	string line, tempString;
	string data = argv[1]; //Used to take file as command arguement:
	ifstream file(data.c_str());

	double case1 = -1;


	vector<string> allText; //Contains all of the text within a vector:
	vector<double> starNum;
	vector<double> X;
	vector<double> Y;

	while (!file.eof()){
		tempString = "";
		int count = 0; //LINE NUMBER:
		getline(file, tempString);
		count++;	

		istringstream line(tempString);
		while (line) { //LOOP THAT PLACES INDIVIDUAL WORDS INTO VECTOR:
	        string word;
	        line >> word;
	        char a = word[0];
	        if (word == " " || word=="\n" || word ==""){
	        	//DO NOTHING
	        }
	        else{
	        	allText.push_back(word);
	        	stringToInt(allText[0], case1);
	        }
	    }//PLACE IN allText<> WHILE LOOP

	} //FILE READ WHILE LOOP

	file.close();


	//SORT ALL INPUT TEXT INTO CORRESPONDING VECTORS:




	//--------------CALCULATIONS-------------------
	if(case1<0){
		cout << "Input was invalid. Either spacing or star number was not correct." << endl;
	}
	else if (case1 > 0){


	initializeVectors(allText, starNum, X, Y);
	
	


	}//MAIN ELSE IF - CALCULATIONS
	else{
		cout<<"There were not stars inputted. Program will end here." << endl;
	}

	
	return 0;
}