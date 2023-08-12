#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> sol;
        for(int num: nums){
            vector<int> vtemp;
            int temp = num;
            while(temp > 0){
                vtemp.push_back(temp % 10);
                temp /= 10;
            }
            for (int i = vtemp.size()-1; i >= 0;i--)
                sol.push_back(vtemp[i]);
        }
        return sol;
    }
};

