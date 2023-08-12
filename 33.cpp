#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
       int n=nums.size();
        int l=0, r=n-1;
        
        while(l<=r){
            int m=(l+r)/2;
            if(nums[m]==target) return m;
            if(nums[m]>nums[n-1]){ // left side of peak element
                if(target>nums[m] || target<nums[0]){
                    l=m+1;
                }else{
                    r=m-1;
                }
            }else{ // right side of peak element
                if(target<nums[m] || target>nums[n-1]){
                    r=m-1;
                }else{
                    l=m+1;
                }
            }
        }
      return -1;
    }
};