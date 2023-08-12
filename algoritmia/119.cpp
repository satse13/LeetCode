#include<iostream>
#include <vector>
using namespace std;


class Solution {
public:

    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0)
            return {1};
        else if(rowIndex == 1)
            return {1, 1};
        else{
            vector<int> filaActual;
            vector<int> filaAnterior = {1, 1};
            int contador = 2;

            while(contador <= rowIndex){
                filaActual.resize(0);
                filaActual.push_back(1);
                for (int i = 1; i < filaAnterior.size(); i++){
                    filaActual.push_back(filaAnterior[i] + filaAnterior[i - 1]);
                }
                filaActual.push_back(1);
                filaAnterior = filaActual;
                contador++;
            }
            return filaActual;
        }
    }

};

int main(){
    Solution s;
    auto x = s.getRow(3);
    for(int i: x)
        cout << i;
    return 0;
}