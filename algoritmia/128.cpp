#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int longestConsecutive(vector<int>& nums);

int main(){



	vector<int> v = {100,4,200,1,3,2};
	longestConsecutive(v);
	return 0;
}

int longestConsecutive(vector<int>& nums) {
    if(nums.empty()) return 0;

	priority_queue<int> cola;

	for(int i: nums){
		cola.push(i);
	}

	int max_cur = 1;
	int curr_length = 1;
	int prev = cola.top();
	cola.pop();
	while(!cola.empty()){

		int currN = cola.top();
		cola.pop();
		if(currN == prev - 1){
			curr_length++;
		}
		else if(currN != prev){
			curr_length = 1;
		}
		prev = currN;

		if(max_cur < curr_length){
			max_cur = curr_length;
		}

	}
	return max_cur;

}