//
//  main.cpp
//  CS4102
//
//  Created by Brian Aguirre on 3/4/15.
//  Copyright (c) 2015 Brian Aguirre. All rights reserved.
//

/**
 Brian Aguirre
 ba5bx
 Coding Assignment 4
 March 3, 2015
 */

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
    
    vector<string> all;
    
    while (!file.eof()){
        tempString = "";
        int count = 0; //LINE NUMBER:
        getline(file, tempString);
        count++;	
        
    }	
    file.close();
    
    
    return 0;
}