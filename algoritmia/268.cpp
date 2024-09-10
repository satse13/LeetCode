#include <iostream>
#include <vector>
using namespace std;

int missingNumber(vector<int>& nums);

int main(){


	return 0;
}

int missingNumber(vector<int>& nums) {


	int cont1 = 0;
	int cont2 = 0;
	for(int i = 0; i <= nums.size();i++){
		if(i < nums.size())
			cont1 += nums[i];
		cont2 += i;
	}

	return cont2 - cont1;;    
}
