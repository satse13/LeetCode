#include<iostream>
#include<unordered_map>
using namespace std;


class Solution {
public:
    string convertToTitle(int columnNumber) {
        
        unordered_map<int, char> map;
        for(int i = 1; i <= 26; i++){
            map[i] = 'A' + i - 1;
        }
        
        string ans = "";
        while(columnNumber > 0){
            int rem = columnNumber % 26;
            if(rem == 0){
                ans = 'Z' + ans;
                columnNumber = columnNumber / 26 - 1;
            }
            else{
                ans = map[rem] + ans;
                columnNumber = columnNumber / 26;
            }
        }
        return ans;
    }
};