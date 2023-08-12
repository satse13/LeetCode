#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map; // mapa que guarda el numero y su frecuencia

        for (int i = 0; i < nums.size(); i++){
            map[nums[i]]++;
        }

        int max = 0;

        for (auto it = map.begin(); it != map.end();++it){
            if(it->second > map[max]){
                max = it->first;
            }
        }
        return max;
    }
};


int main(){

    return 0;
}