#include <iostream>
#include <string>
#include <vector>
#include "myMethods.h"
using namespace std;

int maxPath(int n, int m){

	int arr[n][m];
	
}

int main(){
	//MATRIX:
	int n = 2;
	int m = 2;
	int mat[n][m];
	int count  = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			mat[i][j] = count;
			count++;
		}
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout<< mat[i][j] << " ";
		}
		cout<<endl;
	}

	

	return 0;
}