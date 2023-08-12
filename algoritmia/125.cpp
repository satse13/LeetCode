#include<iostream>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(remove_if(s.begin(), s.end(), [](char c) { return !isalnum(c); }), s.end());
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        string inv = "";
        for (int i = s.size() - 1; i >= 0;i--)
        {
            inv.push_back(s[i]);
        }

        return s == inv;
    }
};

int main(){

    Solution s;
    s.isPalindrome("A man, a plan, a canal: Panama");

    return 0;
}