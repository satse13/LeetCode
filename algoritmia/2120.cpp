#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int cont = 0;
        vector<int> sol;
        for (int i = 0; i < s.size(); i++){
            int x = startPos[0];
            int y = startPos[1];
            for (int j = i; j < s.size();j++){
                if(s[j] == 'L'){
                    y--;
                }
                else if(s[j] == 'U'){
                    x--;
                }
                else if(s[j] == 'D'){
                    x++;
                }
                else if(s[j] == 'R'){
                    y++;
                }
                if(!(x < 0 || x >= n || y < 0 || y >= n)){
                    cont++;
                    if(j == s.size()-1){
                        sol.push_back(cont);
                        cont = 0;
                        break;
                    }
                }
                else{
                    sol.push_back(cont);
                    cont = 0;
                    break;
                }
            }
        }
        return sol;
    }
};

int main(){

    Solution s;
    vector<int> n = {0, 1};
    string se = "RRDDLU";
    s.executeInstructions(3, n, se);
    return 0;
}