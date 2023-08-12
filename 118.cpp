#include<iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> sol;

        sol.push_back({1});

        if(numRows == 1)
            return sol;

        sol.push_back({1, 1});

        for (int i = 2; i < numRows; i++){
            vector<int> temp;
            temp.push_back(1);
            for (int j = 1; j < sol[i - 1].size();j++){
                temp.push_back(sol[i-1][j] + sol[i-1][j - 1]);
            }
            temp.push_back({1});
            sol.push_back(temp);
        }

        return sol;
    }
};

int main(){

    return 0;
}