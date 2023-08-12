#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int cont = 0;
        for(int i : hours){
            if(i >= target) cont++;
        }
        return cont;
    }
};