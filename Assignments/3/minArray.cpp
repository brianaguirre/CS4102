#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


int findMax(int a [], int index){
    if (index > 0) {
        return max(a[index], findMax(a, index-1));
    } 

   else {
        return a[0];
    }
}

int max(vector<int> a){

	if (a.size()<=3){
		//BRUTE FORCE:
	}
	else{

	}
}

int main(){

	int array[10] = {-4, 34329, 231, 2493, 129, 0, 1, 39294, 7, 38382};
	int a[2] = {1, 2};
	cout<< a+1 << endl;

	int *b = &a[1];
	cout<< b << endl;

	cout<< findMax(array, 9) <<endl;



	return 0;
}