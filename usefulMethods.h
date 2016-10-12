#ifndef USEFUL_METHODS
#define USEFUL_METHODS

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

class usefulMethods{





public:
	usefulMethods();
	bool stringToInt(string &s, int &result); //Converts string to int;
	void quickSort(vector<int>& A, vector<string>& B, int p,int q);//Quick sort, given vectors:
	int partition(vector<int>& A, vector<string>&B, int p,int q);

};

#endif