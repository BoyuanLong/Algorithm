#include <iostream>
using namespace std;

//Fibonacci Sequence: 1,1,2,3,5,8,...
//find nth number of this sequence using dynamic programming
//complexity: O(n)
//space: O(1)
int main(){
	int p = 0;
	int q = 1;

	int n = 64;

	while(--n > 0){
		q = p + q;
		p = q - p;
	}
	cout << q << endl;
	return 0;

}