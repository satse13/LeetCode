#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
					
		int total = nums1.size() + nums2.size();
		int medianaPos =  total / 2;
		int contandor = 0;

		int i = 0;
		int j = 0; 

		float ret;
		while(contandor < medianaPos){

			if(i >= nums1.size()){
				j++;
				continue;
			}
			else if(j >= nums2.size()){
				i++;
				continue;
			}

			if(nums1[i] < nums2[j]){
				i++;
			}
			else {
				j++;
			}
			contandor++;
		}


		if(i >= nums1.size()){
			ret = nums2[j];
			j++;
		}
		else if(j >= nums2.size()){
			ret = nums1[i];
			i++;
		}

		else if(nums1[i] < nums2[j]){
			ret = nums1[i];
			i++;
		}
		else{
			ret = nums2[j];
			j++;
		}

		if(total % 2 == 1){

			if(i >= nums1.size()){
				ret += nums2[j];
			}

			else if(j >= nums2.size()){
				ret += nums1[i];
			}

			else if(nums1[i] < nums2[j]){
				ret += nums1[i];
			}

			else{

				ret += nums2[j];
			}

			ret /= 2;
		}

		return ret;

	}
};

int main(){

	Solution s;

	vector<int> a = {1,2};
	vector<int> b = {3,4};

	cout << s.findMedianSortedArrays(a,b);

	return 0;
}