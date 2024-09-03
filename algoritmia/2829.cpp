#include <iostream>
#include <unordered_set>
using namespace std;

int minimumSum(int n, int k);

int main(){

	cout << minimumSum(3,5);

	return 0;
}

int minimumSum(int n, int k) {

	int sum = 0;
	unordered_set<int> set;

	int nums = 1;
	set.insert(1);
	sum = 1;
	int i = 2;
	while(nums < n){
		if(set.count(k - i)){
			i++;
		}
		else{
			sum += i;
			nums++;
			set.insert(i);
			i++;
		}
		
	}
	
	
	return sum;
}