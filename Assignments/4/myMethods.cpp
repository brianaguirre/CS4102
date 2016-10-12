#include "myMethods.h"

using namespace std;

bool myMethods::stringToInt(string &s, int &result){//Converts string to int;
	istringstream myString(s);

	if (myString>>result){
		return true;
	}
	else
		return false;

}
void myMethods::quickSort(vector<int>& A, vector<string>& B, int p,int q){
	int r;
    if(p<q)
    {
        r=partition(A,B,p,q);
        quickSort(A,B,p,r);  
        quickSort(A,B,r+1,q);

    }

}

int myMethods::partition(vector<int>& A, vector<string>&B, int p,int q){
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




