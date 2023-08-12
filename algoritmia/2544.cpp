#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int alternateDigitSum(int n) {

        int cont = 0;
        int primPos = 1;
        int res = 0;

        while(n>0){
            res += (n % 10) * primPos;
            n /= 10;
            primPos *= -1;
            cont++;
        }
        if(cont % 2 == 0)
            res *= -1;
        return res;
    }
};

int main(){

}