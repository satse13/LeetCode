#include<iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
    int cont = 0;
    while (n != 0)
    {
        if(n%2 == 1)
            cont++;

        n /= 2;
    }
    return cont;
}
};

int main(){


    return 0;
}