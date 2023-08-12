#include<iostream> 
#include <cmath>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        unordered_map<char, int> map;
        for(int i = 1; i <= 26; i++){
            map['A' + i - 1] = i;
        }

        int ans = 0;

        int acum = 1;
        for (int i = columnTitle.size() - 1; i >= 0; i--)
        {
            ans += map[columnTitle[i]] * acum;
            acum *= 26;
        }
        return ans;
    }
};

int main(){
    return 0;
}