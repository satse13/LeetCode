#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int index1 = 0, index2 = 0;

        int minim = min(nums1.size(), nums2.size());

        while(index1 < nums1.size() && index2 < nums2.size()){
            if(nums1[index1] == nums2[index2])
                return nums1[index1];
            else if(nums1[index1] > nums2[index2])
                index2++;
            else
                index1++;
        }
        return -1;
    }
};

int main(){
    return 0;
}